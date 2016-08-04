#ifndef SEGMENT_H
#define SEGMENT_H

#include <QObject>

class Segment
{
public:
    Segment();
    void setValues_curve(QString type, QString angle, QString radius, QString acceleration, QString velocity);
    void setValues_straight(QString type, QString length, QString acceleration, QString velocity);

    QString getType(){return segment_type;}

    QString getAcceleration_straight(){return straight_acceleration;}
    QString getVelocity_straight(){return straight_velocity;}
    QString getLength(){return straight_length;}

    QString getAngle(){return curve_angle;}
    QString getRadius(){return curve_radius;}
    QString getAcceleration_curve(){return curve_acceleration;}
    QString getVelocity_curve(){return curve_velocity;}
private:
    QString segment_type;
    QString curve_angle,curve_radius,curve_acceleration,curve_velocity;
    QString straight_length,straight_acceleration,straight_velocity;
};

#endif // SEGMENT_H
