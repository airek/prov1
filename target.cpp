#include "target.h"
#include <QDebug>
#include <QTime>
#include <global.h>



Target::Target(QObject *parent) : QObject(parent)
{
    setTargetVal();
    isRunning=false;
    timer=new QTimer;
    mTargetPerH=0;
    mTargetPerS=0;
    connect(timer,&QTimer::timeout,this,&Target::increaseTarget);

    clockTimer=new QTimer;
    connect(clockTimer,&QTimer::timeout,
            this,&Target::checkClockTimer);
    if(!Global::mBackendTimer)
        clockTimer->start(1000);


}
/*!
 * \brief Target::setInterval
 * \param tPhr
 *
 * calculate interval
 */
void Target::setInterval(uint tPhr)
{
    double interval;
    QString temp;
    Global global;
    qDebug()<<"tphr "<<tPhr;
    interval=3600.00/tPhr;
    qDebug()<<"interval "<<interval;


    mInterval=interval*1000;
    qDebug()<<mInterval;
    global.writeLog("Obliczony interval target "+temp.setNum(mInterval));
}

void Target::start()
{

    timer->start(mInterval);
    isRunning=true;

}

void Target::stop()
{
  timer->stop();
  isRunning=false;
}

uint Target::shiftTarget()
{
    return mTargetPerS;
}

void Target::setShiftTarget(uint sTarget)
{
    mTargetPerS=sTarget;
}

void Target::setHourTarget(uint hTarget)
{
    mTargetPerH=hTarget;
}

uint Target::hourTarget()
{
    return mTargetPerH;
}
/*!
 * \brief Target::checkIfReset
 */
void Target::checkIfReset()
{
    mTargetPerH+=1;
    mTargetPerS+=1;
}

void Target::increaseTarget()
{
    //qDebug()<<"Target Increased ";
    mTargetPerH+=1;
    mTargetPerS+=1;
    emit targetsIncreased();
    //qDebug()<<mTargetPerH<<" "<<mTargetPerS;
}
/*!
 * \brief Target::checkClockTimer
 *
 * checking clock timer if is exact hour then setting hourTarget
 */
void Target::checkClockTimer()
{
    QTime curTime=QTime::currentTime();
    QString strMinutes,strSeconds,strHour;

    strMinutes=curTime.toString("mm");
    strSeconds=curTime.toString("ss");
    strHour=curTime.toString("hh");
    //qDebug()<<strMinutes<<" "<<strSeconds;

    if(strMinutes=="00" and strSeconds=="00")
    {
        mTargetPerH=0;

        if(strHour==Global::fshft or strHour==Global::sshft or strHour==Global::tshft)
        {
            //qDebug()<<"Zerujemy targety koniec zmiany ";

            mTargetPerS=0;

        }

        emit targetsZero();
    }




}

/*!
 * \brief Target::setTargetVal
 */
void Target::setTargetVal()
{
    mTargetPerH=0;
    mTargetPerS=0;
}
