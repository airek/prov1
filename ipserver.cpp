#include "ipserver.h"
#include <QHostAddress>
#include <QTcpSocket>
#include <QDebug>
#include <QByteArray>
#include <auxclass/dbinterface.h>


IpServer::IpServer(QObject *parent) : QObject(parent)
{



}

bool IpServer::listen(QString ipAddr,int portNr,QString name)
{
    mIpaddr=ipAddr;
    mPortnr=portNr;
    QHostAddress hostAd(mIpaddr);
    QString temp;
    QString strQry;
    mServerName=name;
    dbInterface dbi(Global::mDbConnection);
    qDebug()<<hostAd.toString();

    if(mServer.listen(hostAd,mPortnr))
    {

        connect(&mServer,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
        writeLog("Server nasłuchuje "+hostAd.toString()+" port "+temp.setNum(mPortnr));

        strQry="insert into devices (devname,ipaddr,portnr,status,line)"
               "values('"+mServerName+"','"+mIpaddr+"','"+temp.setNum(mPortnr)+"','true','"+Global::mLine+"')";
        qDebug()<<"strqry "<<strQry;

        if(!dbi.execQuery(strQry))
        {
              writeLog("Nie dodano servera do tabeli hrsdevice");
              isListening=false;
              mServer.close();

        }else
            isListening=true;


    }
    else
        isListening=false;

    return isListening;
}
/*!
 * \brief IpServer::close
 */
void IpServer::close()
{
    foreach (QTcpSocket *socket, socketList) {
        socket->close();
        socketList.removeOne(socket);
        global.writeLog("Klient "+socket->peerAddress().toString()+" rozłączony");
    }
    mServer.close();
}
/*!
 * \brief IpServer::isListening
 * \return
 */
bool IpServer::isServerListening()
{
    bool res=mServer.isListening();

    return res;
}
/*!
 * \brief IpServer::listen
 * \param ipAddr
 * \param portNr
 * \return
 */
bool IpServer::startListening(QString ipAddr, int portNr)
{
    mIpaddr=ipAddr;
    mPortnr=portNr;
    QHostAddress hostAd(mIpaddr);
    QString temp;

    //dbInterface dbi(Global::mDbConnection);
    //qDebug()<<hostAd.toString();

    if(mServer.listen(hostAd,mPortnr))
    {

        connect(&mServer,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
        writeLog("Server nasłuchuje "+hostAd.toString()+" port "+temp.setNum(mPortnr));

        isListening=true;

    }
    else
        isListening=false;

    return isListening;
}

QString IpServer::ipaddr() const
{
    return mIpaddr;
}

void IpServer::setIpaddr(const QString &ipaddr)
{
    mIpaddr = ipaddr;
    emit ipaddrChanged();
}

int IpServer::portnr() const
{
    return mPortnr;
}

void IpServer::setPortnr(int portnr)
{
    mPortnr = portnr;
    emit portNrChanged();
}
/*!
 * \brief IpServer::onNewConnection
 */
void IpServer::onNewConnection()
{


    while(mServer.hasPendingConnections())
    {
        QTcpSocket *socket=mServer.nextPendingConnection();

        // signal slot
        //connect(socket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
        //connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
                 //this, SLOT(onSocketStateChanged(QAbstractSocket::SocketState)));
        connect(socket,&QTcpSocket::readyRead,
                [=] {readData(socket);});

        connect(socket,&QTcpSocket::disconnected,[=] { removeConnection(socket); });


        //
        socketList.push_back(socket);
        qDebug()<<"connected to  server "<<socket->peerAddress().toString();
        writeLog("Klient "+socket->peerAddress().toString()+" podłączony" );
        emit clientConnected(socket->peerAddress().toString());
        //sendProgNr(socket);
    }

}



/*!
 * \brief IpServer::readData
 * \param socket
 */
void IpServer::readData(QTcpSocket *socket)
{
    QString temp;
    QByteArray resposnse;
    QByteArray array=socket->readAll();
    temp=array.toStdString().c_str();
    //qDebug()<<"Otrzymano "<<temp;

    if(temp==Global::mSignal)
    {
        if(Global::mAckSignal==true)
            socket->write(resposnse.append(char(6)));

        emit partOK();

    }


}
/*!
 * \brief IpServer::removeConnection
 * \param socket
 */
void IpServer::removeConnection(QTcpSocket *socket)
{
    if(!socket)
        return;

    qDebug()<<"Rozłaczono z "<<socket->peerAddress().toString();
    socketList.removeOne(socket);
    qDebug()<<socketList.size();
    emit clientDisconnected(socket->peerAddress().toString());

    socket->deleteLater();

}

void IpServer::onReadyRead()
{
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
    QByteArray datas = sender->readAll();
    qDebug()<<"onReadyRead "<<datas;
}

void IpServer::onSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    if (socketState == QAbstractSocket::UnconnectedState)
    {
        QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
        socketList.removeOne(sender);
    }

    qDebug()<<"All clients removed ";
}
/*!
 * \brief IpServer::parseMsg
 * \param br
 */
QString IpServer::parseMsg(QByteArray &br)
{
    QString msg(br);
    QString signal;

    int posSt,posEnd;

    posSt=msg.indexOf("<Command>");
    if(posSt>-1)
    {
        posEnd=msg.indexOf("</Command>");

        if(posEnd>-1)
        {
            signal=msg.mid(posSt+9,posEnd-posSt-9);

            return signal;
        }
    }



    return "0";

}
/*!
 * \brief IpServer::sendProgNr
 * \param socket
 */
void IpServer::sendProgNr(QTcpSocket *socket)
{
   QByteArray arr;
   arr.append("<Response><Command>ProgNr</Command><Nr>001</Nr></Response>");
   socket->write(arr);
}
/*!
 * \brief IpServer::sendindividual
 * \param socket
 */
void IpServer::sendindividual(QTcpSocket *socket)
{
    QByteArray arr;
    arr.append("<Response><Command>MatrixData</Command><Individual>#02120#100415#1168393 #00001#</Individual></Response>");
    socket->write(arr);
}
/*!
 * \brief IpServer::writeLog
 * \param msg
 */
void IpServer::writeLog(QString msg)
{
    Global global;
    global.setFileName("sopp.log");
}


