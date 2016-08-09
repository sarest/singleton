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
        out_angle = QString::number(-angle.toFloat());
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
        out_angle = QString::number(segment_list.last()->getAngle_straight().toFloat() - angle.toFloat());
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
        out_angle = QString::number(segment_list.last()->getOutAngle_curve().toFloat() - angle.toFloat());
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
    x = last_x; //calculate X
    y = last_y; //calculate Y
    xy.setX(x);
    xy.setY(y);
    return xy;
}

//void Functions::function_rect_calculations(float x0, float y0, float x1, float y1)
//{
//    float x = abs(x1-x0);
//    float y = abs(y1-y0);
//    rect_length = sqrt(x*x+y*y);
//    bool first=0,second=0,third=0,fourth=0;
//    if(((x1-x0)>=0)&&((y1-y0)>=0)){
//        first=1;
//        rect_angle = atan(y/x)*180/pi;
//    }
//    if(((x1-x0)<=0)&&((y1-y0)>=0)){
//        second=1;
//        rect_angle = 180-(atan(y/x)*180/pi);
//    }
//    if(((x1-x0)<=0)&&((y1-y0)<=0)){
//        third=1;
//        rect_angle = 180+(atan(y/x)*180/pi);
//    }
//    if(((x1-x0)>=0)&&((y1-y0)<=0)){
//        fourth=1;
//        rect_angle = 360-(atan(y/x)*180/pi);
//    }
//    if(first && fourth)
//        rect_angle = 0;
//    if(first && second)
//        rect_angle = 90;
//    if(second && third)
//        rect_angle = 180;
//    if(third && fourth)
//        rect_angle = 270;
//}

void Functions::function_curve_calculations(float x_start, float y_start, float length, float radius)
{
//    Target *mytarget = Mediator::Instance()->getTarget();
//    QList<Segment*> segment_list = mytarget->getSegment();
//    float spanAngle_rads = length/radius;
//    float spanAngle_degrees = -(spanAngle_rads*180)/pi; //negative to move clockwise
//    float last_angle;

//    if(segment_list.isEmpty()){
//        last_angle = 0;
//    }
//    else if(segment_list.last()->getType() == "straight"){
//        last_angle = segment_list.last()->getAngle_straight().toFloat();
//    }
//    else if(segment_list.last()->getType() == "curve"){
//        last_angle = segment_list.last()->getOutAngle_curve().toFloat();
//    }

//    float last_angle_rads = (last_angle*pi)/180;
//    float x_A_I,y_A_I,angle,x_C,y_C,x_C_I,y_C_I,x_B,y_B,x_B_I,y_B_I,x_D_I,y_D_I,
//            vector_CB_x,vector_CB_y,vector_CB_modulus,vector_CB_angle,
//            vector_CB_angle_rotated,vector_x_rotated,vector_y_rotated,
//            vector_CA_x,vector_CA_y,vector_CA_angle;

//    x_A_I = x_start;
//    y_A_I = y_start;
//    angle = last_angle_rads;

//    //Compute C point (with respect to the inertial system)
//    x_C = 0.0;
//    y_C = -radius;
//    x_C_I = x_A_I + cos(angle)*x_C - sin(angle)*y_C;
//    y_C_I = y_A_I + sin(angle)*x_C + cos(angle)*y_C;

//    //Compute B point (with respect to the inertial system)
//    x_B = -radius;
//    y_B = 0;
//    x_B_I = x_A_I + cos(angle)*x_B - sin(angle)*y_B;
//    y_B_I = y_A_I + sin(angle)*x_B + cos(angle)*y_B;

//    //Compute vector CB an rotate it
//    vector_CB_x = x_B_I - x_C_I;
//    vector_CB_y = y_B_I - y_C_I;
//    vector_CB_modulus = sqrt(vector_CB_x*vector_CB_x + vector_CB_y*vector_CB_y);
//    vector_CB_angle = atan2(vector_CB_y,vector_CB_x);
//    vector_CB_angle_rotated = vector_CB_angle - angle;
//    vector_x_rotated = vector_CB_modulus*cos(vector_CB_angle_rotated);
//    vector_y_rotated = vector_CB_modulus*sin(vector_CB_angle_rotated);

//    //Compute D point (with respect to the inertial system)
//    x_D_I = x_C_I + vector_x_rotated;
//    y_D_I = y_C_I + vector_y_rotated;
//    float x_displace = x_D_I;
//    float y_displace = y_D_I;

//    //Compute vector CA
//    vector_CA_x = x_A_I - x_C_I;
//    vector_CA_y = y_A_I - y_C_I;
//    vector_CA_angle = atan2(vector_CA_y,vector_CA_x);
//    float start_angle_degrees = vector_CA_angle*180/pi;
}
