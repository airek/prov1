#ifndef DATAOBJECT_H
#define DATAOBJECT_H
#include<QObject>

class DataObject:public QObject
{

    Q_OBJECT
    Q_PROPERTY(QString txt READ txt WRITE setTxt NOTIFY txtChanged)
    Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)

public:

    explicit DataObject(QObject *parent=0);
    QString txt() const;
    void setTxt(const QString &txt);

    QString source() const;
    void setSource(const QString &source);

signals:

    void txtChanged();
    void sourceChanged();

public slots:


private:
    QString mtxt;
    QString mSource;
};

#endif // DATAOBJECT_H
