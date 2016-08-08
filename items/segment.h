#ifndef SEGMENT_H
#define SEGMENT_H

#include <QObject>

class Segment
{
public:
    Segment();
    void setValues_curve(QString type, QString angle, QString radius, QString acceleration, QString velocity, QString x, QString y, QString time);
    void setValues_straight(QString type, QString length, QString acceleration, QString velocity, QString x, QString y, QString time);
    void setAngle_straight(QString angle){straight_angle = angle;}
    void setOutAngle_curve(QString angle){curve_out_angle = angle;}

    QString getType(){return segment_type;}

    QString getAcceleration_straight(){return straight_acceleration;}
    QString getVelocity_straight(){return straight_velocity;}
    QString getLength(){return straight_length;}
    QString getX_straight(){return straight_x;}
    QString getY_straight(){return straight_y;}
    QString getTime_straight(){return straight_time;}
    QString getAngle_straight(){return straight_angle;}

    QString getAngle(){return curve_angle;}
    QString getRadius(){return curve_radius;}
    QString getAcceleration_curve(){return curve_acceleration;}
    QString getVelocity_curve(){return curve_velocity;}
    QString getX_curve(){return curve_x;}
    QString getY_curve(){return curve_y;}
    QString getTime_curve(){return curve_time;}
    QString getOutAngle_curve(){return curve_out_angle;}

private:
    QString segment_type;
    QString curve_angle,curve_radius,curve_acceleration,curve_velocity,curve_x,curve_y,curve_time,curve_out_angle;
    QString straight_length,straight_acceleration,straight_velocity,straight_x,straight_y,straight_time,straight_angle;
};

#endif // SEGMENT_H
