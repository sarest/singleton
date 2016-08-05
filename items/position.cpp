#include "position.h"

Position::Position()
{

}

void Position::setPosition(QString name, QString longitude, QString latitude, QString direction, QString height)
{
    position_direction = direction;
    position_height = height;
    position_latitude = latitude;
    position_longitude = longitude;
    position_name = name;
}
