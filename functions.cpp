#include "functions.h"

#include "mediator.h"

Functions::Functions()
{

}

void Functions::straightCalculations(QString length, QString acceleration, QString velocity)
{
    Target *mytarget = Mediator::Instance()->getTarget();
    QList<Segment*> segment_list = mytarget->getSegment();
    float time,start_velocity_ms,end_velocity_ms,acc,distance,x,y;
    distance = length.toFloat();

    if(segment_list.isEmpty()){
        x = length.toFloat();
        y = 0;
        start_velocity_ms = mytarget->getStartVelocity().toFloat()/3.6;
        if(velocity != ""){
            end_velocity_ms = velocity.toFloat()/3.6;
            acc = ((end_velocity_ms*end_velocity_ms)-(start_velocity_ms*start_velocity_ms))/(2*distance);
            acceleration = QString::number(acc);
            time = (end_velocity_ms-start_velocity_ms) / acc;
        }
        else if(acceleration != ""){
            acc = acceleration.toFloat();
            end_velocity_ms = sqrt((acc*2*distance)+(start_velocity_ms*start_velocity_ms));
            velocity = QString::number(end_velocity_ms*3.6);
            time = (end_velocity_ms-start_velocity_ms) / acc;
        }
    }
    else if(segment_list.last()->getType() == "straight"){
        x = segment_list.last()->getX_straight().toFloat() + distance;
        y = 0;
        start_velocity_ms = segment_list.last()->getVelocity_straight().toFloat()/3.6;
        if(velocity != ""){
            end_velocity_ms = velocity.toFloat()/3.6;
            acc = ((end_velocity_ms*end_velocity_ms)-(start_velocity_ms*start_velocity_ms))/(2*distance);
            acceleration = QString::number(acc);
            time = (end_velocity_ms-start_velocity_ms) / acc;
            time = segment_list.last()->getTime_straight().toFloat() + time;
        }
        else if(acceleration != ""){
            acc = acceleration.toFloat();
            end_velocity_ms = sqrt((acc*2*distance)+(start_velocity_ms*start_velocity_ms));
            velocity = QString::number(end_velocity_ms*3.6);
            time = (end_velocity_ms-start_velocity_ms) / acc;
            time = segment_list.last()->getTime_straight().toFloat() + time;
        }
    }
    else if(segment_list.last()->getType() == "straight"){
        qDebug()<<"anterior segmento curva";
    }


    Segment *newsegment = new Segment;
    newsegment->setValues_straight("straight",length,acceleration,velocity,QString::number(x),QString::number(y),QString::number(time));
    Mediator::Instance()->addSegmentToTarget(newsegment);
}

void Functions::curveCalculations(QString angle, QString radius, QString acceleration, QString velocity)
{
    Target *mytarget = Mediator::Instance()->getTarget();
    QList<Segment*> segment_list = mytarget->getSegment();
    QString x,y,time;



    Segment *newsegment = new Segment;
    newsegment->setValues_curve("curve",angle,radius,acceleration,velocity,x,y,time);
    Mediator::Instance()->addSegmentToTarget(newsegment);
}
