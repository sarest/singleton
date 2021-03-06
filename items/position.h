#ifndef POSITION_H
#define POSITION_H

#include <QObject>

class Position
{
public:
    Position();
    void setPosition(QString name, QString longitude, QString latitude, QString direction, QString height);
    QString getName(){return position_name;}
    QString getLongitude(){return position_longitude;}
    QString getLatitude(){return position_latitude;}
    QString getDirection(){return position_direction;}
    QString getHeight(){return position_height;}

private:
    QString position_name,position_longitude,position_latitude,position_direction,position_height;
};

#endif // POSITION_H
