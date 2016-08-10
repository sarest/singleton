#include "functions.h"

#include "mediator.h"

Functions::Functions()
{

}

void Functions::straightCalculations(QString length, QString acceleration, QString velocity)
{
    Target *mytarget = Mediator::Instance()->getTarget();
    QList<Segment*> segment_list = mytarget->getSegment();
    float time,start_velocity_ms,end_velocity_ms,acc,distance;
    distance = length.toFloat();
    QString straight_angle;
    QPointF xy;

    if(segment_list.isEmpty()){
        xy = calculateXY_straight(distance);
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
        xy = calculateXY_straight(distance);
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
        xy = calculateXY_straight(distance);
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
    newsegment->setValues_straight("straight",length,acceleration,velocity,QString::number(xy.x()),QString::number(xy.y()),QString::number(time));
    newsegment->setAngle_straight(straight_angle);
    qDebug()<<"new segment->straight out angle"<<straight_angle;
    Mediator::Instance()->addSegmentToTarget(newsegment);
}

void Functions::curveCalculations(QString angle, QString radius, QString acceleration, QString velocity)
{
    Target *mytarget = Mediator::Instance()->getTarget();
    QList<Segment*> segment_list = mytarget->getSegment();
    float time,start_velocity_ms,end_velocity_ms,acc,distance;
    distance = (angle.toFloat()*pi/180) * radius.toFloat();
    QString out_angle;
    QPointF xy;

    if(segment_list.isEmpty()){
        qDebug()<<"segment list empty";
        xy = calculateXY_curve(angle.toFloat(),radius.toFloat());
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
        out_angle = QString::number(-angle.toFloat());
    }
    else if(segment_list.last()->getType() == "straight"){
        qDebug()<<"last segment straight";
        xy = calculateXY_curve(angle.toFloat(),radius.toFloat());
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
        out_angle = QString::number(segment_list.last()->getAngle_straight().toFloat() - angle.toFloat());
    }
    else if(segment_list.last()->getType() == "curve"){
        qDebug()<<"last segment curve";
        xy = calculateXY_curve(angle.toFloat(),radius.toFloat());
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
        out_angle = QString::number(segment_list.last()->getOutAngle_curve().toFloat() - angle.toFloat());
    }

    Segment *newsegment = new Segment;
    newsegment->setValues_curve("curve",angle,radius,acceleration,velocity,QString::number(xy.x()),QString::number(xy.y()),QString::number(time));
    newsegment->setOutAngle_curve(out_angle);
    qDebug()<<"new segment->out angle curve"<<out_angle;
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
    float last_angle,last_x,last_y;

    if(segment_list.isEmpty()){
        last_angle = 0;
        last_x = 0;
        last_y = 0;
    }
    else if(segment_list.last()->getType() == "straight"){
        last_angle = segment_list.last()->getAngle_straight().toFloat();
        last_x = segment_list.last()->getX_straight().toFloat();
        last_y = segment_list.last()->getY_straight().toFloat();
    }
    else if(segment_list.last()->getType() == "curve"){
        last_angle = segment_list.last()->getOutAngle_curve().toFloat();
        last_x = segment_list.last()->getX_curve().toFloat();
        last_y = segment_list.last()->getY_curve().toFloat();
    }
    xy = function_curve_calculations(last_x,last_y,radius,last_angle,angle);
    return xy;
}

QPointF Functions::function_curve_calculations(float last_x, float last_y, float radius, float last_angle, float span_angle)
{
    float last_angle_rads = (last_angle*pi)/180;
    float span_angle_rads = (span_angle*pi)/180;
    qDebug()<<"last_angle"<<last_angle;
    qDebug()<<"span_angle"<<span_angle;

    float x_A_I,y_A_I,angle,x_C,y_C,x_C_I,y_C_I,vector_x_rotated,vector_y_rotated,
            vector_CA_x,vector_CA_y,vector_CA_angle;

    x_A_I = last_x;
    y_A_I = last_y;
    angle = last_angle_rads;

    //Compute C point (with respect to the inertial system)
    x_C = 0.0;
    y_C = -radius;
    x_C_I = x_A_I + cos(angle)*x_C - sin(angle)*y_C;
    y_C_I = y_A_I + sin(angle)*x_C + cos(angle)*y_C;
    qDebug()<<"c_x"<<x_C_I;
    qDebug()<<"c_y"<<y_C_I;


    //Compute vector CA and rotate it
    vector_CA_x = x_A_I - x_C_I;
    vector_CA_y = y_A_I - y_C_I;
    qDebug()<<"vector_ca_x"<<vector_CA_x;
    qDebug()<<"vector_ca_y"<<vector_CA_y;
    float vector_CA_modulus = sqrt(vector_CA_x*vector_CA_x + vector_CA_y*vector_CA_y);
    qDebug()<<"vector ca modulus"<<vector_CA_modulus;
    vector_CA_angle = atan2(vector_CA_y,vector_CA_x);
    qDebug()<<"vector ca angle"<<vector_CA_angle*180/pi;
    float vector_CA_angle_rotated = vector_CA_angle - span_angle_rads;
    qDebug()<<"vector ca angle rotated"<<vector_CA_angle_rotated*180/pi;
    vector_x_rotated = vector_CA_modulus*cos(vector_CA_angle_rotated);
    vector_y_rotated = vector_CA_modulus*sin(vector_CA_angle_rotated);
    qDebug()<<"vector x rotated"<<vector_x_rotated;
    qDebug()<<"vector y rotated"<<vector_y_rotated;

    //Compute A2 point
    float A2_x = x_C_I + vector_x_rotated;
    float A2_y = y_C_I + vector_y_rotated;
    qDebug()<<"last_X,last_Y"<<x_A_I<<y_A_I;
    qDebug()<<"final_X,final_Y"<<A2_x<<A2_y;
    QPointF xy(A2_x,A2_y);
    return xy;
}
