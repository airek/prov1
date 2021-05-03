#include "sqlqrymodel.h"
#include <QDebug>
#include <global.h>
#include <QSqlRecord>

sqlqryModel::sqlqryModel()
{

}

void sqlqryModel::setQuery(const QString &query)
{
    QSqlDatabase db=QSqlDatabase::database(Global::mDbConnection);
    QSqlQueryModel::setQuery(query, db);
    qDebug()<<"Qry sqlqry Poszło"<<query;
    generateRoleNames();
}

void sqlqryModel::setQuery(const QSqlQuery &query)
{
    QSqlQueryModel::setQuery(query);
    generateRoleNames();
}

int sqlqryModel::nrOfRows()
{
    QModelIndex index;
    return rowCount(index);
}

QVariant sqlqryModel::data(const QModelIndex &index, int role) const
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

void sqlqryModel::generateRoleNames()
{
    m_roleNames.clear();
    for( int i = 0; i < record().count(); i ++) {
        m_roleNames.insert(Qt::UserRole + i + 1, record().fieldName(i).toUtf8());
        qDebug()<<m_roleNames;
    }
}
