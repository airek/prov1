#include "dbinterface.h"
#include <QSqlQuery>
#include <QStringList>
#include <QSqlRecord>
#include <QVariant>
#include <QSqlError>
#include <QDebug>

/*! **********************************************************
  \ Class dbInterface
    an interface for db returning results according given query

  \ Author:Ireneusz Karbownik

  \ Date: November 2014

  **********************************************************/

dbInterface::dbInterface(QString dbConnectionName)
{

    mDbConnectionName=dbConnectionName;

}

QStringList dbInterface::returnQueryResult(QString sqry)
{
    QString data;
    QStringList lista;
    QSqlRecord record;
    int i;
    int nrColumns;
    mqry=sqry;

   // getting db name according given argument
    QSqlDatabase db;
    db=QSqlDatabase::database(mDbConnectionName);
    QSqlQuery query(mqry,db);

    while(query.next())
    {
        // getting nr. of Columns
        record=query.record();
        nrColumns=record.count();

        for(i=0;i<nrColumns;i++)
        {
            data=query.value(i).toString();

            lista<<data;
            data.clear();
        }


    }

    return lista;
}

QStringList dbInterface::returnOneRowResult(QString sqry)
{
    QString data;
    QStringList lista;
    QSqlRecord record;
    int nrColumns;
    mqry=sqry;

   /*! creating query */
    QSqlQuery query(mqry);

   /*! executing recived query */
    query.exec();


    while(query.next())
    {
        // getting nr. of Columns
        record=query.record();
        nrColumns=record.count();

        for(int i=0;i<nrColumns;i++)
        {
            data=query.value(i).toString();
           /*! writing record to QStringList */
            lista<<data;
            data.clear();
        }
    }




    return lista;
}
/*! getting one column from database acoording given query */
QString dbInterface::returnOneColumn(QString sqry)
{
    QString data;
    mqry=sqry;

   // getting db name according given argument
    QSqlDatabase db;
    db=QSqlDatabase::database(mDbConnectionName);
    QSqlQuery query(mqry,db);

    if(query.next())
    {
        data=query.value(0).toString();
    }else
    {
        data="0";
    }

    return data;
}
/*! returning query result as QStringlist each record in one list each
 *  String seprated with given argument */
QStringList dbInterface::returnCompressedQueryResult(QString qry,QString separator)
{
    QString data;
    QStringList lista;
    QString temp;
    QSqlRecord record;
    int i;
    int nrColumns;
    mqry=qry;

   // getting db name according given argument
    QSqlDatabase db;
    db=QSqlDatabase::database(mDbConnectionName);
    QSqlQuery query(mqry,db);

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
        //log->writeLog(temp);
        temp.clear();

    }

    return lista;
}
/*!
 * \brief dbInterface::insertToDb inserting data to database asscording given query
 * \param sqry query as QString
 * \return bool
 */
bool dbInterface::insertToDb(QString sqry)
{
    mqry=sqry;
    QSqlDatabase db;
    db=QSqlDatabase::database(mDbConnectionName);
    QSqlQuery query(mqry,db);


    if(query.numRowsAffected()!=1)
    {
        mDbError=query.lastError().text();
        return false;
    }
    else
    {

        return true;
    }
}
/*!
 * \brief dbInterface::execQuery
 * \param sqry
 * \return bool
 *
 * executing query this function is dedicated for  insert,delete or update
 * statements
 */
bool dbInterface::execQuery(QString sqry)
{
    mqry=sqry;
    QSqlDatabase db;
    db=QSqlDatabase::database(mDbConnectionName);
    QSqlQuery query(mqry,db);

    if(query.numRowsAffected()!=-1)
    {
        return true;
    }
    else
    {
        mDbError=query.lastError().text();
        return false;

    }
}
/*!
 * \brief dbInterface::dbError
 * \return
 *
 *
 */
QString dbInterface::dbError()
{
    return mDbError;
}
