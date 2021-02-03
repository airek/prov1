#ifndef KLOG_H
#define KLOG_H

#include <QString>
#include <QFile>
#include "filep.h"
#include <string>
#include <QFileInfo>

using namespace std;

class Klog:public FileP
{
public:

    Klog(string filePath);
    Klog(QString &  filePath);
    virtual ~Klog();

    virtual bool writeLogWithcpName(QString msg);
    virtual bool writeLogWithUserName(QString msg);
    virtual bool writeLog(QString msg);
    virtual bool writeLogWithAllInformation(QString msg);
    virtual bool writeSimpleLog(QString msg);


protected:
    void getComputerName();
    void getUserName();

    QString m_computerName;
    QString m_userName;
};

#endif // KLOG_H
