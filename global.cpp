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
#include <windows.h>
#include <QFile>
#include <string>

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
int Global::mAckSignal;
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
bool Global::isDebug;
QString Global::mPartsQty;
QString Global::mPersQty;
QString Global::mTimeToProduce;
uint Global::mTargetPerH;
uint Global::mOrderCntr;
QString Global::mOrderID;
int Global::mAuxTime;
QString Global::mAuxDate;
int Global::mProdTime;
int Global::mBreakTime;
QString Global::mTeam;
int Global::mCheckList;


Global::Global()
{
    readSettings();
    //getDeviceStatus();
}
/*!
 * \brief Global::connectToDb
 * \return
 */
bool Global::connectToDb()
{
    qDebug()<<"driver "<<mdbDriver<<"\nConnection "<<mDbConnection
           <<"\nhostName "<<mDbServer<<"\nUser "<<mDbUser<<"\ndbName "<<mDbName;

    QSqlDatabase db=QSqlDatabase::addDatabase(mdbDriver,mDbConnection);
    db.setHostName(mDbServer);
    db.setUserName(mDbUser);
    db.setDatabaseName(mDbName);
    db.setPassword("@ccess.PL_s0pp");

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

    if(status==true)
    {
        writeLog("Baza połączona  ");
    }else
    {

        writeLog("Baza jest nie połączona");
    }



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
    mDbUser=settings.value("dbuser").toString();
    mDbServer=settings.value("dbHost").toString();
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
    isDebug=settings.value("debug").toBool();
    mPersQty=settings.value("persQty").toString();
    mPartsQty=settings.value("qtyToProduce").toString();
    mTimeToProduce=settings.value("timeToProduce").toString();
    mTargetPerH=settings.value("targetPerH").toUInt();
    mOrderCntr=settings.value("orderCntr").toUInt();
    mOrderID=settings.value("orderId").toString();
    mAuxTime=settings.value("auxTime").toInt();
    mAuxDate=settings.value("auxDate").toString();
    mProdTime=settings.value("prodTime").toInt();
    mBreakTime=settings.value("breakTime").toInt();
    mTeam=settings.value("team").toString();



    settings.endGroup();


}
/*!
 * \brief Global::readNIOFile
 */
void Global::readNIOFile()
{
    QString strQContent;
    QString firstRec;
    QStringList sqlList;

    QFile file("nio.log");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        QString strLine=line.toStdString().c_str();
        sqlList<<strLine;

     }

    insertNIOQry(sqlList);

    file.remove();

}
/*!
 * \brief Global::insertNIOQry
 * \param lista
 *
 * inserting qry from nio file
 */

void Global::insertNIOQry(QStringList &lista)
{

    QString strQry;
    //loop till end of list
    for(int i=0;i<lista.size();i++)
    {
       strQry=lista.at(i);
       execQuery(strQry);
    }
}
/*!
 * \brief Global::writeSettingsLog
 *
 * writing app setting to log file
 */
void Global::writeSettingsLog()
{

    writeLog("dbDriver "+mdbDriver);
    writeLog("dbConnection "+mDbConnection);
    writeLog("dbName "+mDbName);
    writeLog("Line name "+mLine);
    writeLog("log name "+mFileName);
    writeLog("magic nr "+mMagicNumber);
    writeLog("Part nr "+mPartNr);
    writeLog("target per H "+mTargetH);
    writeLog("target per shift "+mTargetS);
    writeLog("Status "+mStatus);
    writeLog("result per H "+mResH);
    writeLog("result per shift "+mResS);
    if(mBackendTimer)
        writeLog("backend is true");


}
/*!
 * \brief Global::writeDataSettings
 */
void Global::writeDataSettings()
{
    //writeLog("signal ok "+mSignal);
    writeLog("shiftFactor "+mShiftFactor);
    writeLog("minVal "+minVal);
    writeLog("midVal "+midVal);
    writeLog("maxVal "+maxVal);
    writeLog("firstShift "+fshft);
    writeLog("second shift "+sshft);
    writeLog("third shift "+tshft);

}

void Global::writeNIO(QString qry)
{

    Klog *log=new Klog("nio.log");
    log->writeSimpleLog(qry);
    delete log;


}
/*!
 * \brief Global::checkNIO
 */
void Global::checkNIO()
{
    QFile file("nio.log");

    if(file.exists())
    {
        writeLog("Plik nio.log istnieje");
        readNIOFile();
        // czytamy i wprowadzamy
    }
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

        mShiftFactor=record.value("shiftFactor").toString();
        minVal=record.value("minVal").toString();
        midVal=record.value("midVal").toString();
        maxVal=record.value("maxVal").toString();
        fshft=record.value("fshift").toString();
        sshft=record.value("sshift").toString();
        tshft=record.value("tshift").toString();

    }





}
/*!
 * \brief Global::getDeviceStatus
 */
void Global::getDeviceStatus()
{
    QSqlDatabase db=QSqlDatabase::database(mDbConnection);
    qDebug()<<db;
    QSqlQuery qry(db);
    QString strQry;

    strQry="Select ipAddr,portNr,conStatus,descript,signal,checkList,ackSignal from lineCom where line ='"+mLine+"'";
    qDebug()<<strQry;
    //qry.prepare("Select devName,ipAddr,portNr,status from devices where line ='"+mLine+"'");
    //qry.prepare("Select ipAddr,portNr,conStatus from lineCom where line ='"+mLine+"'");

    qry.exec(strQry);

    while(qry.next())
    {
        QSqlRecord record=qry.record();
        mDevName=record.value("descript").toString();
        mIpAddr=record.value("ipAddr").toString();
        mPortNr=record.value("portNr").toString();
        mServerStatus=record.value("conStatus").toInt();
        mSignal=record.value("signal").toString();
        mCheckList=record.value("checkList").toInt();
        mAckSignal=record.value("ackSignal").toInt();

        //qDebug()<<"AckSignal"<<mAckSignal;

        //qDebug()<<mIpAddr<<"\n"<<mPortNr<<"\n"<<mServerStatus;
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
                              QString targetS, QString resH, QString resS, QString status,
                              QString persQty, QString partsQty, QString ttProduce, QString targetPerH, QString orderCntr,
                              QString orderId, QString auxTime, QString auxDate, QString prodTime, QString breakTime, QString team)
{

    QSettings settings("sopp.ini",QSettings::IniFormat);

    settings.beginGroup("appData");

    settings.setValue("partNr",partnr);
    settings.setValue("targetH",targetH);
    settings.setValue("targetS",targetS);
    settings.setValue("resH",resH);
    settings.setValue("resS",resS);
    settings.setValue("status",status);
    settings.setValue("persQty",persQty);
    settings.setValue("qtyToProduce",partsQty);
    settings.setValue("timeToProduce",ttProduce);
    settings.setValue("targetPerH",targetPerH);
    settings.setValue("orderCntr",orderCntr);
    settings.setValue("orderId",orderId);
    settings.setValue("auxTime",auxTime);
    settings.setValue("auxDate",auxDate);
    settings.setValue("prodTime",prodTime);
    settings.setValue("breakTime",breakTime);
    settings.setValue("team",team);
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

    bool res;
    // cehcking if db is open


    QSqlDatabase db=QSqlDatabase::database(mDbConnection);
    QSqlQuery qry(db);


        if(!qry.exec(strQry))
        {

            writeLog("Nie wprowadzono do bazy danych dla qry "+strQry+" raportowany błąd "+qry.lastError().text());
            writeNIO(strQry);
            //tutaj sprawdzamy połączenie
            if(qry.lastError().text().contains("Błąd łącza komunikacyjnego"))
            {
                if(connectToDb())
                {
                    writeLog("Nawiązano ponownie połaczenie z DB");

                }
            }

            res=false;
        }else
        {
            writeLog("Wprowadzono dla dla strQry "+strQry);
            res=true;
        }



    return res;


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
