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
    static QString mPersQty;
    static QString mPartsQty;
    static QString mTimeToProduce;
    static uint mTargetPerH;
    static uint mOrderCntr;
    static bool mServerStatus;
    static int mTargetInterval;
    static int mCntrInterval;
    static bool mBackendTimer;
    static bool isDebug;
    static QString mOrderID;
    static int mAuxTime;
    static int mProdTime;
    static int mBreakTime;
    static QString mAuxDate;

    //
    QString dbError();
    static bool isDbConnected();
    void writeLog(QString msg);
    QString fileName() const;
    void setFileName(const QString &fileName);
    void readDataSettings();
    void getDeviceStatus();
    void writeAppSettings(QString partnr, QString targetH, QString targetS,
                          QString resH, QString resS, QString status, QString persQty,
                          QString partsQty, QString ttProduce, QString targetPerH, QString orderCntr,
                          QString orderId, QString auxTime, QString auxDate, QString prodTime, QString breakTime);

    static bool execQuery(QString strQry);
    static QStringList returnCompressedResults(QString separator,QString strQry);
    bool checkMagicNumber();
    void writeSettingsLog();
    void writeDataSettings();

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
