#include "counters.h"
#include <QDebug>
#include <QTime>
#include <global.h>



Counters::Counters(QObject *parent) : QObject(parent)
{
    readCounterVal();

    timer=new QTimer;
    connect(timer,SIGNAL(timeout()),
            this,SLOT(checkIfReset()));
    timer->setInterval(1000);
    timer->start();
}
/*!
 * \brief Counters::increaseCounter
 */
void Counters::increaseCounter()
{
    //mAuxCounter+=1;
    mHourCounter+=1;
    mShiftCounter+=1;
    emit countersIncreasd();
}
/*!
 * \brief Counters::checkIfReset
 */
void Counters::checkIfReset()
{
    QTime curTime=QTime::currentTime();
    QString strMinutes,strSeconds,strHour;

    strMinutes=curTime.toString("mm");
    strSeconds=curTime.toString("ss");
    strHour=curTime.toString("hh");
    ////qDebug()<<strMinutes<<" "<<strSeconds<<" "<<strHour;
    ////qDebug()<<"fshft "<<Global::fshft<<" sshft "<<Global::sshft<<" tshft "<<Global::tshft;

    if(strMinutes=="00" and strSeconds=="00")
    {
        mHourCounter=0;
        emit countersInZero();

        //setting 0 to both counters at shift change
        // first shift
        if(strHour==Global::fshft or strHour==Global::sshft or strHour==Global::tshft)
        {
            qDebug()<<"Koniec zmiany zerujemy liczniki ";

            mShiftCounter=0;
        }

        emit countersInZero();
    }



}

void Counters::setShiftCounter(const uint &shiftCounter)
{
    mShiftCounter = shiftCounter;

}

void Counters::setHourCounter(const uint &hourCounter)
{
    mHourCounter = hourCounter;
    emit countersIncreasd();
}

uint Counters::shiftCounter() const
{
    return mShiftCounter;
}

uint Counters::hourCounter() const
{
    return mHourCounter;
}


/*!
 * \brief Counters::readCounterVal
 *
 * read counters value at the app start
 *
 *
 *
 */
void Counters::readCounterVal()
{
    // currently only temp
    // all counters set to 0

    mAuxCounter=0;
    mHourCounter=0;
    mShiftCounter=0;

}
