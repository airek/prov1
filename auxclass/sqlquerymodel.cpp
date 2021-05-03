#include "sqlquerymodel.h"
#include <QSqlRecord>
#include <global.h>
#include <QDebug>

SqlQueryModel::SqlQueryModel(QObject *parent) :
    QSqlQueryModel(parent)
{
    //qDebug()<<"Start qry Model";
    // sqlServer ver setQuery("Select partNr from partNumbers");
    setQuery("Select partNr from targets");
    //qDebug()<<"sqlQueryModel";


}


void SqlQueryModel::setQuery(const QString &query)
{
    QSqlDatabase db=QSqlDatabase::database(Global::mDbConnection);
    QSqlQueryModel::setQuery(query, db);
    qDebug()<<"Qry Poszło"<<query;
    generateRoleNames();
}

void SqlQueryModel::setQuery(const QSqlQuery & query)
{
    QSqlQueryModel::setQuery(query);
    generateRoleNames();
}

int SqlQueryModel::nrOfRows()
{
    QModelIndex index;
    return rowCount(index);
}
/*!
 * \brief SqlQueryModel::generateRoleNames
 */
void SqlQueryModel::generateRoleNames()
{
    m_roleNames.clear();
    for( int i = 0; i < record().count(); i ++) {
        m_roleNames.insert(Qt::UserRole + i + 1, record().fieldName(i).toUtf8());
        qDebug()<<m_roleNames;
    }
}

QVariant SqlQueryModel::data(const QModelIndex &index, int role) const
{
    QVariant value;

    if(role < Qt::UserRole) {
        value = QSqlQueryModel::data(index, role);
    }
    else {
        int columnIdx = role - Qt::UserRole - 1;
        QModelIndex modelIndex = this->index(index.row(), columnIdx);
        value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
    }
    return value;
}
