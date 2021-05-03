#ifndef BACKENDDBCON_H
#define BACKENDDBCON_H

#include <QObject>
#include <ipserver.h>

class BackendDbCon : public QObject
{
    Q_OBJECT
public:

    explicit BackendDbCon(QObject *parent = nullptr);
    Q_INVOKABLE bool execQry(QString strQry);
    Q_INVOKABLE int getMinVal();
    Q_INVOKABLE int getMaxVal();
    Q_INVOKABLE int getMidVal();
    Q_INVOKABLE QString getSHiftFactor();
    Q_INVOKABLE QString getSignal();
    Q_INVOKABLE QString getEFShift();
    Q_INVOKABLE QString getESShift();
    Q_INVOKABLE QString getETShift();
    Q_INVOKABLE bool getAckSignal();
    Q_INVOKABLE bool listen(QString serverName, QString IPAddr, int portNr);
    Q_INVOKABLE QString getDevName();
    Q_INVOKABLE QString getIpAddr();
    Q_INVOKABLE QString getPortNr();
    Q_INVOKABLE bool getServerStatus();
    Q_INVOKABLE QString getLine();
    Q_INVOKABLE QStringList getDbData(QString separator,QString sqry);


signals:

private:
    IpServer *mServer;
};

#endif // BACKENDDBCON_H
