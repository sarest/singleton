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
};

#endif // FUNCTIONS_H
