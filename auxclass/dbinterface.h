#ifndef DBINTERFACE_H
#define DBINTERFACE_H
#include <QString>
//#include <klog.h>
#include <QSqlDatabase>

class dbInterface
{
public:

    dbInterface(QString dbConnectionName);

    QStringList returnQueryResult(QString sqry);
    QStringList returnOneRowResult(QString sqry);
    QString returnOneColumn(QString sqry);
    QStringList returnCompressedQueryResult(QString qry, QString separator);
    bool insertToDb(QString sqry);
    bool execQuery(QString sqry);
    QString dbError();

private:

    QString mqry;
    QString mDbConnectionName;
    //Klog *log;
    QSqlDatabase *db;
    QString mDbError;
};

#endif // DBINTERFACE_H
