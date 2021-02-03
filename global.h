#ifndef GLOBAL_H
#define GLOBAL_H

#include <QObject>
#include <QString>

class Global
{
public:

    Global();
    bool connectToDb();
    // statics var
    static QString mLine;
    static QString mDbConnection;
    static QString mSignal;
    static QString mFileName;
    static QString mShiftFactor;
    static QString minVal;
    static QString midVal;
    static QString maxVal;
    static QString fshft;
    static QString sshft;
    static QString tshft;
    static bool mAckSignal;
    static QString mPartNr;
    static QString mTargetH;
    static QString mTargetS;
    static QString mStatus;
    static QString mResH;
    static QString mResS;
    static QString mDevName;
    static QString mIpAddr;
    static QString mPortNr;
    static bool mServerStatus;
    static int mTargetInterval;
    static int mCntrInterval;
    static bool mBackendTimer;
    //
    QString dbError();
    bool isDbConnected();
    void writeLog(QString msg);
    QString fileName() const;
    void setFileName(const QString &fileName);
    void readDataSettings();
    void getDeviceStatus();
    void writeAppSettings(QString partnr,QString targetH,QString targetS,
                          QString resH,QString resS,QString status);

    static bool execQuery(QString strQry);
    static QStringList returnCompressedResults(QString separator,QString strQry);
    bool checkMagicNumber();
private:

    void readSettings();
    //
    QString mDbName;
    QString mDbServer;
    QString mDbUser;
    QString mdbDriver;
    QString mMagicNumber;


};

#endif // GLOBAL_H
