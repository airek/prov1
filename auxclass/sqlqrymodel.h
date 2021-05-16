#ifndef SQLQRYMODEL_H
#define SQLQRYMODEL_H
#include <QSqlQueryModel>


class sqlqryModel:public QSqlQueryModel
{

    Q_OBJECT

public:
    sqlqryModel();
    Q_INVOKABLE void setQuery(const QString &query);
    void setQuery(const QSqlQuery &query);
    Q_INVOKABLE int nrOfRows();
    Q_INVOKABLE void clearModel();
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const {	return m_roleNames;	}

private:
    void generateRoleNames();
    QHash<int, QByteArray> m_roleNames;
};

#endif // SQLQRYMODEL_H
