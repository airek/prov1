#include "backend.h"
#include "auxclass/dbinterface.h"
#include <QTime>

Backend::Backend(QObject *parent) : QObject(parent)
{
    cntr=new Counters;
    connect(cntr,&Counters::countersInZero,
            this,&Backend::setCntrZero);

    cntr->setHourCounter(Global::mResH.toUInt());
    cntr->setShiftCounter(Global::mResS.toUInt());
    cntr->setOrderCounter(Global::mOrderCntr);

    target=new Target;

    connect(target,&Target::targetsIncreased,
            this,&Backend::targetIncreased);
    connect(target,&Target::targetsZero,
            this,&Backend::setTargetsZero);

    target->setHourTarget(Global::mTargetH.toUInt());
    target->setShiftTarget(Global::mTargetS.toUInt());

    if(Global::mBackendTimer)
    {
        writeLog("backendtime jest true ");
        timer=new QTimer;

        connect(timer,&QTimer::timeout,
                this,&Backend::checkIfsetZero);
        timer->start(1000);


    }else
    {
        writeLog("backendtimer false ");
        //qDebug()<<"backendtimer is false";
    }

}
/*!
 * \brief Backend::Listen
 * \param ipAddr
 * \param portNr
 * \param name
 * \return
 */
bool Backend::listen(QString serverName, QString IPAddr, int portNr)
{

    //
    mServer=new IpServer;
    bool isListening;
    qDebug()<<"ip "<<IPAddr<<"portNr "<<portNr<<"serverName  "<<serverName;
    if(mServer->listen(IPAddr,portNr,serverName))
    {
        isListening=true;

    }else {
        isListening=false;
    }

    return isListening;

}
/*!
 * \brief Backend::startServer
 */
void Backend::startServer()
{
   QString strQry;
   QStringList devList;
   QString temp;
   dbInterface dbi(Global::mDbConnection);
   QStringList tempList;

   strQry="select ipAddr,portNr,conStatus from lineCom "
           "where line='"+Global::mLine+"'";
   qDebug()<<"strQry "<<strQry;
   devList=dbi.returnCompressedQueryResult(strQry,"@");

   // jezeli lista nie jest pusta
   if(!devList.isEmpty())
   {
       temp=devList.at(0);
       qDebug()<<temp;

       tempList=temp.split("@");
       writeLog("Ip addr "+tempList.at(0)+" portNr "+tempList.at(1));
       if(startListening(tempList.at(0),tempList.at(1).toInt()))
       {
           emit serverListening();
       }

   }
}

uint Backend::getShiftCntr()
{
    return cntr->shiftCounter();
}

uint Backend::getHourCntr()
{
    return  cntr->hourCounter();
}

uint Backend::getOrderCntr()
{
    return cntr->orderCounter();
}

void Backend::setOrderCntr(uint orderCntr)
{
    cntr->setOrderCounter(orderCntr);
}
/*!
 * \brief Backend::getTarget
 * \param partNr
 * \return
 */
QString Backend::getTarget(QString partNr)
{
    dbInterface dbi(Global::mDbConnection);
    uint shiftTarget;
    uint targetPerHour;
    uint packagingi;
    uint shiftTargetVE;

    float shiftFactor;
    QString strTargetPerHour;
    QString strQryPack;
    QString packaging;

    //strQry
    QString strQry("Select shiftTarget from targets where "
                   " partNr='"+partNr+"'");

    //qDebug()<<"backend get Target "<<strQry;
    QString res=dbi.returnOneColumn(strQry);
    //qDebug()<<"Otrzymany res "<<res;

    // pobieranie opakowania
    strQryPack="Select packaging from partNumbers "
    "where partnr='"+partNr+"'";
    //qDebug()<<"qry pack "<<strQryPack;
    packaging=dbi.returnOneColumn(strQryPack);
    //qDebug()<<"packaging "<<packaging;

    // oblicznie shiftTarget
    shiftTargetVE=res.toUInt();

    packagingi=packaging.toUInt();
    shiftTarget=shiftTargetVE*packagingi;

    shiftFactor=Global::mShiftFactor.toFloat();
    //qDebug()<<"Shift Factor "<<shiftFactor;

    // setting targetPerHour in target to calculate interval
    targetPerHour=shiftTarget/shiftFactor;
    target->setInterval(targetPerHour);

    //
    //qDebug()<<"target per Hour "<<targetPerHour;
    strTargetPerHour=strTargetPerHour.setNum(targetPerHour);
    return strTargetPerHour;

}
/*!
 * \brief Backend::status
 * \param status
 * setting current status
 */
void Backend::status(QString status)
{
    mStatus=status;
    qDebug()<<mStatus;
    if(mStatus=="PRODUKCJA")
        target->start();
    else
        target->stop();
}

uint Backend::getTargetPerH()
{
    return target->hourTarget();
}

uint Backend::getTargetPers()
{
    return target->shiftTarget();
}

QString Backend::getPartQty()
{
    return Global::mPartsQty;

}

QString Backend::getPersQty()
{
    return Global::mPersQty;
}

QString Backend::getTimeToProduce()
{
    return Global::mTimeToProduce;
}

void Backend::setTarget(uint targetPerHour)
{
    target->setInterval(targetPerHour);
}

uint Backend::getHourTarget()
{

    return Global::mTargetPerH;

}
bool Backend::execQry(QString strQry)
{
    Global global;

    if(global.execQuery(strQry))
        return true;

    return false;
}

void Backend::writeSettings(QString partNr,QString targetH,QString targetS,
                            QString resH,QString resS,QString status,QString persQty,
                            QString partQty,QString ttProduce,QString targetPerH,QString orderCntr,
                            QString orderId, QString auxTime, QString auxDate, QString prodTime, QString breakTime,
                            QString team)
{
    Global global;
    global.writeAppSettings(partNr,targetH,targetS,resH,resS,
                            status,persQty,partQty,ttProduce,targetPerH,orderCntr,
                            orderId,auxTime,auxDate,prodTime,breakTime,team);
}

QString Backend::getPartNr()
{
    return Global::mPartNr;
}

QString Backend::getStatus()
{
    return Global::mStatus;
}

QString Backend::getLine()
{
    return Global::mLine;
}

QString Backend::getDevName()
{
    return Global::mDevName;
}

QString Backend::getIpAddr()
{
    return Global::mIpAddr;
}

QString Backend::getPortNr()
{
    return Global::mPortNr;
}

bool Backend::getServerStatus()
{
    return Global::mServerStatus;
}

int Backend::getCheckList()
{
    return Global::mCheckList;
}

QString Backend::getOrderID()
{
    return Global::mOrderID;
}

int Backend::getAuxTime()
{
    return Global::mAuxTime;
}

QString Backend::getAuxDate()
{
    return Global::mAuxDate;
}

int Backend::getProdTime()
{
    return Global::mProdTime;
}

int Backend::getBreakTime()
{
    return Global::mBreakTime;
}

QString Backend::getTeam()
{
    return Global::mTeam;
}

bool Backend::isDbConnected()
{
    Global global;
    bool isConn;

    if(!global.isDbConnected())
    {
        isConn=false;
    }else
    {
        isConn=true;
    }

    return isConn;
}
/*!
 * \brief Backend::connectToDB
 * \return
 */
bool Backend::connectToDB()
{
   Global global;
   bool isConn;

   if(global.connectToDb())
       isConn=true;
   else
       isConn=false;


   return isConn;

}



/*!
 * \brief Backend::socketConnected
 * \param ipAddres
 */
void Backend::socketConnected(QString ipAddres)
{
    qDebug()<<"Client from Ip connected "<<ipAddres;

    emit clientServerConnected();
}

void Backend::clientDisconnected(QString ipAddres)
{
    qDebug()<<"Client from IP disconnected "<<ipAddres;
    emit clientServerDisconnected();
}
/*!
 * \brief Backend::countersIncreased
 */
void Backend::countersIncreased()
{
    cntr->increaseCounter();
    //qDebug()<<"cntr "<<cntr->hourCounter();
    //qDebug()<<"shift cntr "<<cntr->shiftCounter();

    if(!target->isRunning)
    {
        target->start();
    }

    emit cntrIncreased();
}
/*!
 * \brief Backend::targetIncreased
 */
void Backend::targetIncreased()
{
    //qDebug()<<"Backend targetIncreased ";
    emit targetsIncreased();
}
/*!
 * \brief Backend::setCntrZero
 * cntr value was set zero getting data
 */
void Backend::setCntrZero()
{
    emit cntrZero();
}
/*!
 * \brief Backend::setTargetsZero
 */
void Backend::setTargetsZero()
{
    emit targetsZero();
}

void Backend::checkIfsetZero()
{
    QTime curTime=QTime::currentTime();
    QString strMinutes,strSeconds,strHour;
    QString tshf;

    tshf=Global::tshft;



    //qDebug()<<"Check if Zero backend ";
    strMinutes=curTime.toString("mm");
    strSeconds=curTime.toString("ss");
    strHour=curTime.toString("hh");

    //qDebug()<<strHour<<" "<<strMinutes<<" "<<strSeconds;

    if(strMinutes=="00" and strSeconds=="00")
    {

            //target->stop();
            target->setHourTarget(0);
            cntr->setHourCounter(0);
            emit cntrZero();
            emit targetsZero();

            if(Global::isDebug)
            {

                writeLog("Zerujemy liczniki na pełną godzinę ");
                writeLog("Czas "+strHour+strMinutes+strSeconds);
            }

            if(strHour==Global::fshft)
            {

                target->setShiftTarget(0);
                cntr->setShiftCounter(0);
                emit cntrZero();
                emit targetsZero();
                if(Global::isDebug)
                    writeLog("Zerujemy liczniki na zmianę 1 ");

            }

            if(strHour==Global::sshft)
            {
                target->setShiftTarget(0);
                cntr->setShiftCounter(0);
                emit cntrZero();
                emit targetsZero();
                if(Global::isDebug)
                    writeLog("Zerujemy liczniki na zmianę 2 ");
            }

            // checking third shift
            if(tshf.length()<2)
            {
                tshf="0"+tshf;

                if(strHour==tshf)
                {
                    target->setShiftTarget(0);
                    cntr->setShiftCounter(0);
                    emit cntrZero();
                    emit targetsZero();
                    if(Global::isDebug)
                        writeLog("Zerujemy liczniki na zmianę 3 ");
                }
            }




    }
}



/*!
 * \brief Backend::writeLog
 * \param msg
 */
void Backend::writeLog(QString msg)
{
    Global global;
    global.setFileName(Global::mFileName);
    global.writeLog(msg);
}
/*!
 * \brief Backend::createDevices
 */
void Backend::createDevices()
{

}
/*!
 * \brief Backend::startListening
 */
bool Backend::startListening(QString ipA, int portNr)
{
    QString strQry;
    QString temp;
    Global global;
    global.getDeviceStatus();
    mServer=new IpServer;
    dbInterface dbi(Global::mDbConnection);
    connect(mServer,SIGNAL(clientConnected(QString)),
            this,SLOT(socketConnected(QString)));
    connect(mServer,SIGNAL(clientDisconnected(QString)),
            this,SLOT(clientDisconnected(QString)));
    connect(mServer,SIGNAL(partOK()),this,
            SLOT(countersIncreased()));


    if(mServer->startListening(ipA,portNr))
    {
        strQry="update lineCom set conStatus=1 where ipAddr='"+ipA+"'"
                " and line='"+Global::mLine+"'";

        //qDebug()<<strQry;
        if(!dbi.execQuery(strQry))
            writeLog("Server linii "+Global::mLine+"na IP "+ipA+" nasłuchuje");
        else
            writeLog("Nie wprowadzono danych dla kwerendy "+strQry);


        return true;

    }else
    {
        return false;
    }
}
