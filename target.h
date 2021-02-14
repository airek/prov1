#ifndef TARGET_H
#define TARGET_H

#include <QObject>
#include <QTimer>

class Target : public QObject
{
    Q_OBJECT

public:

    explicit Target(QObject *parent = nullptr);
    void start();
    void setInterval(uint tPhr);
    void stop();
    uint shiftTarget();
    void setShiftTarget(uint sTarget);
    void setHourTarget(uint hTarget);
    uint hourTarget();
    bool isRunning;


signals:

    void targetsIncreased();
    void targetsZero();

private slots:

   void checkIfReset();
   void increaseTarget();
   void checkClockTimer();

private:
    uint mTargetPerH;
    uint mTargetPerS;
    int mInterval;
    int clockInterval;

    QTimer *timer;
    QTimer *clockTimer;

    void setTargetVal();

};

#endif // TARGET_H
