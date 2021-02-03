#include "backenddbcon.h"
#include "global.h"

BackendDbCon::BackendDbCon(QObject *parent) : QObject(parent)
{

}
/*!
 * \brief BackendDbCon::execQry
 * \param strQry
 * \return
 */
bool BackendDbCon::execQry(QString strQry)
{

    Global global;

    if(global.execQuery(strQry))
        return true;

    return false;
}

int BackendDbCon::getMinVal()
{
    return Global::minVal.toInt();
}

int BackendDbCon::getMaxVal()
{
    return Global::maxVal.toInt();
}

int BackendDbCon::getMidVal()
{
    return Global::midVal.toInt();
}

QString BackendDbCon::getSHiftFactor()
{
    return Global::mShiftFactor;
}

QString BackendDbCon::getSignal()
{
   return Global::mSignal;
}

QString BackendDbCon::getEFShift()
{
   return Global::fshft;
}

QString BackendDbCon::getESShift()
{
   return Global::sshft;
}

QString BackendDbCon::getETShift()
{
    return Global::tshft;
}

bool BackendDbCon::getAckSignal()
{
    return Global::mAckSignal;
}

bool BackendDbCon::listen(QString serverName, QString IPAddr, int portNr)
{
    //
    mServer=new IpServer;
    bool isListening;
    //qDebug()<<"ip "<<IPAddr<<"portNr "<<portNr<<"serverName  "<<serverName;
    if(mServer->listen(IPAddr,portNr,serverName))
    {
        isListening=true;

    }else {
        isListening=false;
    }

    return isListening;
}

QString BackendDbCon::getDevName()
{
    return Global::mDevName;
}

QString BackendDbCon::getIpAddr()
{
    return Global::mIpAddr;
}

QString BackendDbCon::getPortNr()
{
    return Global::mPortNr;
}

bool BackendDbCon::getServerStatus()
{
    return Global::mServerStatus;
}

QString BackendDbCon::getLine()
{
    return Global::mLine;
}
