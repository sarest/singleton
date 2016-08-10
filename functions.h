#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QObject>

#include "items/target.h"

class Functions
{
public:
    Functions();
    void straightCalculations(QString length, QString acceleration, QString velocity);
    void curveCalculations(QString angle, QString radius, QString acceleration, QString velocity);

private:
    const double pi = 3.141592653589793238463;
    QPointF calculateXY_straight(float length);
    QPointF calculateXY_curve(float angle, float radius);
    QPointF function_curve_calculations(float last_x, float last_y, float radius, float last_angle, float span_angle);
};

#endif // FUNCTIONS_H
