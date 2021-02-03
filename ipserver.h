#ifndef IPSERVER_H
#define IPSERVER_H

#include <QObject>
#include <QTcpServer>

#include <QList>
#include <global.h>



class IpServer : public QObject
{
    Q_OBJECT

public:
    explicit IpServer(QObject *parent = nullptr);
    bool listen(QString ipAddr,int portNr=0,QString name="test");
    void close();
    bool isServerListening();
    bool startListening(QString ipAddr,int portNr);

    QString ipaddr() const;
    void setIpaddr(const QString &ipaddr);

    int portnr() const;
    void setPortnr(int portnr);

signals:

    void ipaddrChanged();
    void portNrChanged();
    void clientConnected(QString ipAddr);
    void clientDisconnected(QString ipAddr);
    void partOK();

private slots:

    void onNewConnection();
    void readData(QTcpSocket *socket);
    void removeConnection(QTcpSocket *socket);
    void onReadyRead();
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);

private:
    QTcpServer mServer;
    QList<QTcpSocket *>socketList;

    QString mIpaddr;
    int mPortnr;
    QString mServerName;
    bool isListening;
    Global global;
    QString parseMsg(QByteArray &br);
    void sendProgNr(QTcpSocket *socket);
    void sendindividual(QTcpSocket *socket);
    void writeLog(QString msg);




};

#endif // IPSERVER_H
