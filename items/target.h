#ifndef TARGET_H
#define TARGET_H

#include <QObject>

#include "items/segment.h"

class Target
{
public:
    Target();
    void addSegment(Segment *segment_instance){segment_list.append(segment_instance);}
    QList<Segment*> getSegment(){return segment_list;}
    void setID(QString id){target_id = id;}
    void setStartVelocity(QString velocity){start_velocity = velocity;}
    QString getID(){return target_id;}
    QString getStartVelocity(){return start_velocity;}
    void deleteTarget();
    void deleteLastSegment();

private:
    QString target_id,start_velocity;
    QList<Segment*> segment_list;
};

#endif // TARGET_H
