#include "mediator.h"

Mediator::Mediator()
{

}

Mediator* Mediator::instance = 0;

Mediator* Mediator::Instance()
{
    if(instance == 0)
        instance = new Mediator;
    return instance;
}

void Mediator::setPosition(QString position_name)
{
    for(int i=0;i<mediator_position_list.count(); i++){
        if(mediator_position_list.at(i)->getName() == position_name)
                mediator_position = mediator_position_list.at(i);
    }
}

void Mediator::addSegmentToTarget(Segment *segment_instance)
{
    mediator_target->addSegment(segment_instance);
}

void Mediator::showWindowTarget()
{
    mediator_window_target->show();
}

bool Mediator::execPositionDialog()
{
    if(mediator_position_dialog->exec()==QDialog::Accepted)
        return true;
    else
        return false;
}
