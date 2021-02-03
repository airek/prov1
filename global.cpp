#include "global.h"
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlError>
#include "auxclass/klog.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QSqlRecord>
#include <QDate>


QString Global::mDbConnection;
QString Global::mSignal;
QString Global::mLine;
QString Global::mFileName;
QString Global::mShiftFactor;
QString Global::minVal;
QString Global::midVal;
QString Global::maxVal;
QString Global::fshft;
QString Global::sshft;
QString Global::tshft;
bool Global::mAckSignal;
QString Global::mPartNr;
QString Global::mTargetH;
QString Global::mTargetS;
QString Global::mStatus;
QString Global::mResH;
QString Global::mResS;
QString Global::mDevName;
QString Global::mIpAddr;
QString Global::mPortNr;
bool Global::mServerStatus;
int Global::mTargetInterval;
int Global::mCntrInterval;
bool Global::mBackendTimer;

Global::Global()
{
    readSettings();
}
/*!
 * \brief Global::connectToDb
 * \return
 */
bool Global::connectToDb()
{

    QSqlDatabase db=QSqlDatabase::addDatabase(mdbDriver,mDbConnection);
    db.setHostName(mDbServer);
    db.setUserName(mDbUser);
    db.setDatabaseName(mDbName);
    db.setPassword("Takata1!");

    bool ok=db.open();

    return ok;

}
/*!
* \brief Global::dbError
* \return
*
* returning Db error in QString format
*/
QString Global::dbError()
{
    QSqlDatabase db=QSqlDatabase::database(mDbConnection);

    return db.lastError().text();
}
/*!
 * \brief Global::isDbConnected
 * \return connection status
 *
 */
bool Global::isDbConnected()
{

    QSqlDatabase db=QSqlDatabase::database(mDbConnection);

    bool status=db.isOpen();

    return status;
}
/*!
 * \brief Global::writeLog
 * \param msg
 */
void Global::writeLog(QString msg)
{
    Klog *log=new Klog(mFileName.toStdString());
    log->writeLog(msg);
    delete log;


}

void Global::readSettings()
{
    QSettings settings("sopp.ini",QSettings::IniFormat);

    settings.beginGroup("db");

    mdbDriver=settings.value("driver").toString();
    mDbConnection=settings.value("connection").toString();
    mDbName=settings.value("dbName").toString();
    mLine=settings.value("line").toString();
    mFileName=settings.value("logFile").toString();
    ///mDbUser=settings.value("dbuser").toString();
    //mDbServer=settings.value("dbHost").toString();
    mMagicNumber=settings.value("magic").toString();

    settings.endGroup();

    settings.beginGroup("appData");

    mPartNr=settings.value("partNr").toString();
    mTargetH=settings.value("targetH").toString();
    mTargetS=settings.value("targetS").toString();
    mStatus=settings.value("status").toString();
    mResH=settings.value("resH").toString();
    mResS=settings.value("resS").toString();
    mCntrInterval=settings.value("cntrInterval").toInt();
    mTargetInterval=settings.value("targetInterval").toInt();
    mBackendTimer=settings.value("backendtimer").toBool();

    settings.endGroup();

}

QString Global::fileName() const
{
    return mFileName;
}

void Global::setFileName(const QString &fileName)
{
    mFileName = fileName;
}
/*!
 * \brief Global::readDataSettings
 */
void Global::readDataSettings()
{
    QSqlDatabase db=QSqlDatabase::database(mDbConnection);
    QSqlQuery qry(db);
    qry.prepare("Select * from settings");
    qry.exec();

    while(qry.next())
    {
        QSqlRecord record=qry.record();
        mSignal=record.value("signal").toString();
        mShiftFactor=record.value("shiftFactor").toString();
        minVal=record.value("minVal").toString();
        midVal=record.value("midVal").toString();
        maxVal=record.value("maxVal").toString();
        fshft=record.value("fshift").toString();
        sshft=record.value("sshift").toString();
        tshft=record.value("tshift").toString();
        mAckSignal=record.value("ackSignal").toBool();

    }
}
/*!
 * \brief Global::getDeviceStatus
 */
void Global::getDeviceStatus()
{
    QSqlDatabase db=QSqlDatabase::database(mDbConnection);
    QSqlQuery qry(db);
    qry.prepare("Select devName,ipAddr,portNr,status from devices where line ='"+mLine+"'");
    qry.exec();

    while(qry.next())
    {
        QSqlRecord record=qry.record();
        mDevName=record.value("devName").toString();
        mIpAddr=record.value("ipAddr").toString();
        mPortNr=record.value("portNr").toString();
        mServerStatus=record.value("status").toBool();
    }
}
/*!
 * \brief Global::writeAppSettings
 * \param partnr
 * \param targetH
 * \param targetS
 * \param resH
 * \param resS
 * \param status
 */
void Global::writeAppSettings(QString partnr, QString targetH,
                              QString targetS, QString resH, QString resS, QString status)
{

    QSettings settings("sopp.ini",QSettings::IniFormat);

    settings.beginGroup("appData");

    settings.setValue("partNr",partnr);
    settings.setValue("targetH",targetH);
    settings.setValue("targetS",targetS);
    settings.setValue("resH",resH);
    settings.setValue("resS",resS);
    settings.setValue("status",status);


    settings.endGroup();





}
/*!
 * \brief Global::execQuery
 * \param strQry
 *
 * inserting data to database indicating by mDbConnection
 */
bool Global::execQuery(QString strQry)
{
    QSqlDatabase db=QSqlDatabase::database(mDbConnection);
    QSqlQuery qry(db);


    if(!qry.exec(strQry))
    {

        qDebug()<<qry.lastError().text();
        return false;
    }

    return true;


}
/*!
 * \brief Global::returnCompressedResults
 * \param seprator
 * \param strQry
 * \return
 */
QStringList Global::returnCompressedResults(QString separator,
                                             QString strQry)
{
    QString data;
    QStringList lista;
    QString temp;
    QSqlRecord record;
    int i;
    int nrColumns;


   // getting db name according given argument
    QSqlDatabase db;
    db=QSqlDatabase::database(mDbConnection);
    QSqlQuery query(strQry,db);

    while(query.next())
    {
        // getting nr. of Columns
        record=query.record();
        nrColumns=record.count();

        for(i=0;i<nrColumns;i++)
        {
            data=query.value(i).toString();
           /*! writing record to QStringList */
            temp+=data+separator;


        }

        lista<<temp;

        temp.clear();

    }

    return lista;
}

bool Global::checkMagicNumber()
{
    QDate ddate=QDate::currentDate();
    QDate sDate;
    sDate.setDate(2021,1,31);\
    bool res;
    QString strDate=ddate.toString("yyyy-MM-dd");

    if(mMagicNumber=="077528")
    {
        writeLog("Magic number is cool");
        return true;
    }
    qDebug()<<sDate;
    qDebug()<<ddate;
    if(ddate>=sDate)
    {
        if(mMagicNumber=="077528")
            return true;
        else
        {
            writeLog("magic kod jest nok");
            return false;
        }


    }




}
