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
    QString straight_angle;

    if(segment_list.isEmpty()){
        x = calculateXY_straight(distance).x();
        y = calculateXY_straight(distance).y();
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
        straight_angle = "0";
    }
    else if(segment_list.last()->getType() == "straight"){
        x = calculateXY_straight(distance).x();
        y = calculateXY_straight(distance).y();
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
        straight_angle = segment_list.last()->getAngle_straight();
    }
    else if(segment_list.last()->getType() == "curve"){
        x = calculateXY_straight(distance).x();
        y = calculateXY_straight(distance).y();
        start_velocity_ms = segment_list.last()->getVelocity_curve().toFloat()/3.6;
        if(velocity != ""){
            end_velocity_ms = velocity.toFloat()/3.6;
            acc = ((end_velocity_ms*end_velocity_ms)-(start_velocity_ms*start_velocity_ms))/(2*distance);
            acceleration = QString::number(acc);
            time = (end_velocity_ms-start_velocity_ms) / acc;
            time = segment_list.last()->getTime_curve().toFloat() + time;
        }
        else if(acceleration != ""){
            acc = acceleration.toFloat();
            end_velocity_ms = sqrt((acc*2*distance)+(start_velocity_ms*start_velocity_ms));
            velocity = QString::number(end_velocity_ms*3.6);
            time = (end_velocity_ms-start_velocity_ms) / acc;
            time = segment_list.last()->getTime_curve().toFloat() + time;
        }
        straight_angle = segment_list.last()->getOutAngle_curve();
    }

    Segment *newsegment = new Segment;
    newsegment->setValues_straight("straight",length,acceleration,velocity,QString::number(x),QString::number(y),QString::number(time));
    newsegment->setAngle_straight(straight_angle);
    Mediator::Instance()->addSegmentToTarget(newsegment);
}

void Functions::curveCalculations(QString angle, QString radius, QString acceleration, QString velocity)
{
    Target *mytarget = Mediator::Instance()->getTarget();
    QList<Segment*> segment_list = mytarget->getSegment();
    float x,y,time,start_velocity_ms,end_velocity_ms,acc,distance;
    distance = (angle.toFloat()*pi/180) * radius.toFloat();
    QString out_angle;

    if(segment_list.isEmpty()){
        x = calculateXY_curve(angle.toFloat(),radius.toFloat()).x();
        y = calculateXY_curve(angle.toFloat(),radius.toFloat()).y();
        start_velocity_ms = mytarget->getStartVelocity().toFloat()/3.6;
        if(velocity != ""){
            end_velocity_ms = velocity.toFloat()/3.6;
            acc = ((end_velocity_ms*end_velocity_ms)-(start_velocity_ms*start_velocity_ms))/(2*distance);
            acceleration = QString::number(acc);
            time = (end_velocity_ms-start_velocity_ms)/acc;
        }
        else if(acceleration != ""){
            acc = acceleration.toFloat();
            end_velocity_ms = sqrt((acc*2*distance)+(start_velocity_ms*start_velocity_ms));
            velocity = QString::number(end_velocity_ms*3.6);
            time = (end_velocity_ms-start_velocity_ms)/acc;
        }
        out_angle = angle;
    }
    else if(segment_list.last()->getType() == "straight"){
        x = calculateXY_curve(angle.toFloat(),radius.toFloat()).x();
        y = calculateXY_curve(angle.toFloat(),radius.toFloat()).y();
        start_velocity_ms = segment_list.last()->getVelocity_straight().toFloat()/3.6;
        if(velocity != ""){
            end_velocity_ms = velocity.toFloat()/3.6;
            acc = ((end_velocity_ms*end_velocity_ms)-(start_velocity_ms*start_velocity_ms))/(2*distance);
            acceleration = QString::number(acc);
            time = (end_velocity_ms-start_velocity_ms)/acc;
            time = segment_list.last()->getTime_straight().toFloat() + time;
        }
        else if(acceleration != ""){
            acc = acceleration.toFloat();
            end_velocity_ms = sqrt((acc*2*distance)+(start_velocity_ms*start_velocity_ms));
            velocity = QString::number(end_velocity_ms*3.6);
            time = (end_velocity_ms-start_velocity_ms)/acc;
            time = segment_list.last()->getTime_straight().toFloat() + time;
        }
        out_angle = angle + segment_list.last()->getAngle_straight();
    }
    else if(segment_list.last()->getType() == "curve"){
        x = calculateXY_curve(angle.toFloat(),radius.toFloat()).x();
        y = calculateXY_curve(angle.toFloat(),radius.toFloat()).y();
        start_velocity_ms = segment_list.last()->getVelocity_curve().toFloat()/3.6;
        if(velocity != ""){
            end_velocity_ms = velocity.toFloat()/3.6;
            acc = ((end_velocity_ms*end_velocity_ms)-(start_velocity_ms*start_velocity_ms))/(2*distance);
            acceleration = QString::number(acc);
            time = (end_velocity_ms-start_velocity_ms)/acc;
            time = segment_list.last()->getTime_curve().toFloat() + time;
        }
        else if(acceleration != ""){
            acc = acceleration.toFloat();
            end_velocity_ms = sqrt((acc*2*distance)+(start_velocity_ms*start_velocity_ms));
            velocity = QString::number(end_velocity_ms*3.6);
            time = (end_velocity_ms-start_velocity_ms)/acc;
            time = segment_list.last()->getTime_curve().toFloat() + time;
        }
        out_angle = angle + segment_list.last()->getOutAngle_curve();
    }

    Segment *newsegment = new Segment;
    newsegment->setValues_curve("curve",angle,radius,acceleration,velocity,QString::number(x),QString::number(y),QString::number(time));
    newsegment->setOutAngle_curve(out_angle);
    Mediator::Instance()->addSegmentToTarget(newsegment);
}

QPointF Functions::calculateXY_straight(float length)
{
    Target *mytarget = Mediator::Instance()->getTarget();
    QList<Segment*> segment_list = mytarget->getSegment();
    QPointF xy;
    float last_angle,last_x,last_y,x,y;

    if(segment_list.isEmpty()){
        x = length;
        y = 0;
    }
    else if(segment_list.last()->getType() == "straight"){
        last_angle = segment_list.last()->getAngle_straight().toFloat();
        last_x = segment_list.last()->getX_straight().toFloat();
        last_y = segment_list.last()->getY_straight().toFloat();
        x = last_x + (sin((90-last_angle)*pi/180)*length);
        y = last_y + (sin(last_angle*pi/180)*length);
    }
    else if(segment_list.last()->getType() == "curve"){
        last_angle = segment_list.last()->getOutAngle_curve().toFloat();
        last_x = segment_list.last()->getX_curve().toFloat();
        last_y = segment_list.last()->getY_curve().toFloat();
        x = last_x + (sin((90-last_angle)*pi/180)*length);
        y = last_y + (sin(last_angle*pi/180)*length);
    }
    xy.setX(x);
    xy.setY(y);
    return xy;
}

QPointF Functions::calculateXY_curve(float angle, float radius)
{
    Target *mytarget = Mediator::Instance()->getTarget();
    QList<Segment*> segment_list = mytarget->getSegment();
    QPointF xy;
    float last_angle,last_x,last_y,x,y;

    if(segment_list.isEmpty()){
        last_angle = 0;
        x = 0;
        y = 0;
    }
    else if(segment_list.last()->getType() == "straight"){
        last_angle = segment_list.last()->getAngle_straight().toFloat();
        last_x = segment_list.last()->getX_straight().toFloat();
        last_y = segment_list.last()->getY_straight().toFloat();
        x = last_x;
        y = last_y;
    }
    else if(segment_list.last()->getType() == "curve"){
        last_angle = segment_list.last()->getOutAngle_curve().toFloat();
        last_x = segment_list.last()->getX_curve().toFloat();
        last_y = segment_list.last()->getY_curve().toFloat();
        x = last_x;
        y = last_y;
    }
    xy.setX(x);
    xy.setY(y);
    return xy;
}
