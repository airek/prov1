#ifndef SQLQUERYMODEL_H
#define SQLQUERYMODEL_H
#include <QSqlQueryModel>

class SqlQueryModel:public QSqlQueryModel
{
    Q_OBJECT

public:
    explicit SqlQueryModel(QObject *parent = 0);

    //Q_INVOKABLE void setQuery(const QString &query, const QSqlDatabase &db = QSqlDatabase());
    Q_INVOKABLE void setQuery(const QString &query);
    void setQuery(const QSqlQuery &query);
    Q_INVOKABLE int nrOfRows();
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const {	return m_roleNames;	}

private:
    void generateRoleNames();
    QHash<int, QByteArray> m_roleNames;




};

#endif // SQLQUERYMODEL_H
