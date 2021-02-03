#ifndef IKSMODEL_H
#define IKSMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QHash>
#include <QList>

class ModelData
{
public:
    ModelData(QString usr1,QString usr2);
    ModelData();

    QString usrF1() const;
    void setUsrF1(const QString &usrF1);

    QString usrF2() const;
    void setUsrF2(const QString &usrF2);

private:
    QString mUsrF1;
    QString mUsrF2;

};

class IKSModel:public QAbstractListModel
{
    Q_OBJECT
public:
    enum IKSRoles
    {
        usr1Role=Qt::UserRole+1,
        usr2Role

    };

   explicit IKSModel(QObject *parent = 0);
   int rowCount(const QModelIndex & parent = QModelIndex()) const;
   QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
   Q_INVOKABLE void addData(QString sqlSt);

protected:

   QHash<int, QByteArray> roleNames() const;

private:
   QList<ModelData>modelList;

   void fillModelList(QStringList list);

};

#endif // IKSMODEL_H
