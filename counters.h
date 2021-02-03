#ifndef COUNTERS_H
#define COUNTERS_H

#include <QObject>
#include <QTimer>

class Counters : public QObject
{
    Q_OBJECT
public:
    explicit Counters(QObject *parent = nullptr);
    void increaseCounter();
    uint hourCounter() const;
    uint shiftCounter() const;

    void setHourCounter(const uint &hourCounter);
    void setShiftCounter(const uint &shiftCounter);

signals:
    void countersIncreasd();
    void countersInZero();

private slots:
    void checkIfReset();

private:
    uint mAuxCounter;
    uint mHourCounter;
    uint mShiftCounter;
    QTimer *timer;

    void readCounterVal();
};

#endif // COUNTERS_H
