#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <ipserver.h>
#include <global.h>
#include <counters.h>
#include <target.h>
#include <QTimer>


/*!
 * \brief The Backend class
 * 
 * Backend class for QML object
 * 
 */
class Backend : public QObject
{
    Q_OBJECT
public:
    explicit Backend(QObject *parent = nullptr);

    Q_INVOKABLE bool listen(QString serverName, QString IPAddr, int portNr);
    Q_INVOKABLE void startServer();
    Q_INVOKABLE uint getShiftCntr();
    Q_INVOKABLE uint getHourCntr();
    Q_INVOKABLE uint getOrderCntr();
    Q_INVOKABLE void setOrderCntr(uint orderCntr);
    Q_INVOKABLE QString getTarget(QString partNr);
    Q_INVOKABLE void status(QString status);
    Q_INVOKABLE uint getTargetPerH();
    Q_INVOKABLE uint getTargetPers();
    Q_INVOKABLE QString getPartQty();
    Q_INVOKABLE QString getPersQty();
    Q_INVOKABLE QString getTimeToProduce();
    Q_INVOKABLE void setTarget(uint targetPerHour);
    Q_INVOKABLE uint getHourTarget();


    Q_INVOKABLE bool execQry(QString strQry);
    Q_INVOKABLE void writeSettings(QString partNr,QString targetH,QString targetS,
                                   QString resH,QString resS,QString status,QString persQty,
                                   QString partQty,QString ttProduce,QString targetPerH,QString orderCntr,
                                   QString orderId, QString auxTime, QString auxDate, QString prodTime, QString breakTime,
                                   QString team);
    Q_INVOKABLE QString getPartNr();
    Q_INVOKABLE QString getStatus();
    Q_INVOKABLE QString getLine();
    Q_INVOKABLE QString getDevName();
    Q_INVOKABLE QString getIpAddr();
    Q_INVOKABLE QString getPortNr();
    Q_INVOKABLE bool getServerStatus();
    Q_INVOKABLE int getCheckList();

    Q_INVOKABLE QString getOrderID();
    Q_INVOKABLE int getAuxTime();
    Q_INVOKABLE QString getAuxDate();
    Q_INVOKABLE int getProdTime();
    Q_INVOKABLE int getBreakTime();
    Q_INVOKABLE QString getTeam();
    Q_INVOKABLE bool isDbConnected();
    Q_INVOKABLE bool connectToDB();
    Q_INVOKABLE void writeLog(QString msg);

    /*settings.setValue("orderId",orderId);
    settings.setValue("auxTime",auxTime);
    settings.setValue("auxDate",auxDate);
    settings.setValue("prodTime",prodTime);
    settings.setValue("breakTime",breakTime);*/




public slots:


    void socketConnected(QString ipAddres);
    void clientDisconnected(QString ipAddres);
    void countersIncreased();
    void targetIncreased();
    void setCntrZero();
    void setTargetsZero();
    void checkIfsetZero();


signals:

    void serverListening();
    void clientServerConnected();
    void clientServerDisconnected();
    void cntrIncreased();
    void targetsIncreased();
    void cntrZero();
    void targetsZero();

private:


    IpServer *mServer;
    Counters *cntr;
    Target *target;
    QString mStatus;
    QTimer *timer;

    void createDevices();
    bool startListening(QString ipA,int portNr);


};

#endif // BACKEND_H
