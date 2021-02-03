#include "klog.h"
#include <QFile>
#include <QDate>
#include <windows.h>
#include <string>
#include <QTextStream>
#include <QDebug>



using namespace std;
/*! class Klog

  / offer possibility to write data to log file
  / inherits after: fileP
  / I.Karbownik   2012-09-05

      */

/*! second constructor */
Klog::Klog(QString &filePath)
{

   setFile(filePath.toStdString());

   /*! getting comp name */
   getComputerName();
   /*! getting user name */
   getUserName();

}
Klog::Klog(string filePath)
{
   setFile(filePath);
   /*! getting comp name */
   getComputerName();
   /*! getting user name */
   getUserName();
}
Klog::~Klog()
{

}
/*!
/ writing to Log File with computer name
/ standard msg is:
/ date(yyyy-MM-dd)  time(hh:mm:ss)  computer name   msg
 */
bool Klog::writeLogWithcpName(QString msg)
{
    QDate curDate;
    QTime curTime;
    QString strDate;
    QString strTime;
    string strmsg;


    curDate=QDate::currentDate();
    curTime=QTime::currentTime();

    strDate=curDate.toString("yyyy-MM-dd");
    strTime=curTime.toString("hh:mm:ss");

    /*! preparing text to write */
    strmsg=strDate.toStdString()+"\t"+strTime.toStdString()+"\t"+m_computerName.toStdString()+"\t"+msg.toStdString();
    /*! writing via reference */
    if(addRefLine(strmsg))
        return true;
    else
        return false;


}
/*! getting computerName */
void Klog::getComputerName()
{

    TCHAR nameBuf[MAX_COMPUTERNAME_LENGTH + 2];
    DWORD nameBufSize=100;

    GetComputerName(nameBuf, &nameBufSize);

    /*! must have conversion from TChar to std string */
    #ifdef UNICODE
    size_t size = wcslen(nameBuf);
    char * buffer = new char [2*size+2];
    wcstombs(buffer,nameBuf,2*size+2);
    std::string compName(buffer);
    delete [] buffer;
    #else
    std::string compName(nameBuf);
    #endif


    m_computerName=compName.c_str();


}
/*!
  / getting actual user name only in windows using winApi function
  */
void Klog::getUserName()
{
    TCHAR nameBuf[255];
    DWORD nameBufSize=sizeof(nameBuf);

    GetUserName(nameBuf,&nameBufSize);
     /*! must have conversion from TChar to std string */
    #ifdef UNICODE
    size_t size = wcslen(nameBuf);
    char * buffer = new char [2*size+2];
    wcstombs(buffer,nameBuf,2*size+2);
    std::string userName(buffer);
    delete [] buffer;
    #else
    std::string userName(nameBuf);
    #endif

    m_userName=userName.c_str();

}
/*!
/ writing to Log File with all information
/ standard msg is:
/ date(yyyy-MM-dd)  time(hh:mm:ss)  computerName   userName msg
*/
bool Klog::writeLogWithAllInformation(QString msg)
{
    QDate curDate;
    QTime curTime;
    QString strDate;
    QString strTime;
    string strmsg;


    curDate=QDate::currentDate();
    curTime=QTime::currentTime();

    strDate=curDate.toString("yyyy-MM-dd");
    strTime=curTime.toString("hh:mm:ss");
    /*! preparing text to write */
    strmsg=strDate.toStdString()+"\t"+strTime.toStdString()+"\t"+m_computerName.toStdString()+"\t"+m_userName.toStdString()+"\t"+msg.toStdString();
    /*! writing via reference */
    if(addRefLine(strmsg))
        return true;
    else
        return false;
}
/*!
 * \brief Klog::writeSimpleLog
 * \param msg
 * \return bool
 * writing simple log without date and time
 */
bool Klog::writeSimpleLog(QString msg)
{
    string strMsg;

    strMsg=msg.toStdString();

    if(addRefLine(strMsg))
    {
        return true;
    }
    else
    {
        return false;
    }
}


/*!
/ writing to Log File only text
/ standard msg is:
/ date(yyyy-MM-dd)  time(hh:mm:ss)  computerName   userName msg
*/
bool Klog::writeLog(QString msg)
{
    QDate curDate;
    QTime curTime;
    QString strDate;
    QString strTime;
    string strmsg;


    curDate=QDate::currentDate();
    curTime=QTime::currentTime();

    strDate=curDate.toString("yyyy-MM-dd");
    strTime=curTime.toString("hh:mm:ss.mmm");
    /*! preparing text to write */
    strmsg=strDate.toStdString()+"\t"+strTime.toStdString()+"\t"+msg.toStdString();
    /*! writing via reference */
    if(addRefLine(strmsg))
        return true;
    else
        return false;
}
/*!
/ writing to Log File with user name
/ standard msg is:
/ date(yyyy-MM-dd)  time(hh:mm:ss)  computerName   userName msg
*/
bool Klog::writeLogWithUserName(QString msg)
{
    QDate curDate;
    QTime curTime;
    QString strDate;
    QString strTime;
    string strmsg;


    curDate=QDate::currentDate();
    curTime=QTime::currentTime();

    strDate=curDate.toString("yyyy-MM-dd");
    strTime=curTime.toString("hh:mm:ss");
    /*! preparing text to write */
    strmsg=strDate.toStdString()+"\t"+strTime.toStdString()+"\t"+m_userName.toStdString()+"\t"+msg.toStdString();
    /*! writing via reference */
    if(addRefLine(strmsg))
        return true;
    else
        return false;
}
