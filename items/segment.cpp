#include "segment.h"

Segment::Segment()
{

}

void Segment::setValues_curve(QString type, QString angle, QString radius, QString acceleration, QString velocity)
{
    segment_type = type;
    curve_angle = angle;
    curve_radius = radius;
    curve_acceleration = acceleration;
    curve_velocity = velocity;
}

void Segment::setValues_straight(QString type, QString length, QString acceleration, QString velocity)
{
    segment_type = type;
    straight_length = length;
    straight_acceleration = acceleration;
    straight_velocity = velocity;
}
