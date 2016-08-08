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
    QPointF calculateXY_straight(float length);
    QPointF calculateXY_curve(float angle, float radius);
private:
    const double pi = 3.141592653589793238463;
};

#endif // FUNCTIONS_H
