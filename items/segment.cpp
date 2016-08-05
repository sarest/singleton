#include "segment.h"

Segment::Segment()
{

}

void Segment::setValues_curve(QString type, QString angle, QString radius, QString acceleration, QString velocity, QString x, QString y, QString time)
{
    segment_type = type;
    curve_angle = angle;
    curve_radius = radius;
    curve_acceleration = acceleration;
    curve_velocity = velocity;
    curve_x = x;
    curve_y = y;
    curve_time = time;
}

void Segment::setValues_straight(QString type, QString length, QString acceleration, QString velocity, QString x, QString y, QString time)
{
    segment_type = type;
    straight_length = length;
    straight_acceleration = acceleration;
    straight_velocity = velocity;
    straight_x = x;
    straight_y = y;
    straight_time = time;
}
