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

void Mediator::addSegmentToTarget(Segment *segment_instance)
{
    mediator_target->addSegment(segment_instance);
}

void Mediator::showWindowTarget()
{
    mediator_window_target->show();
}

void Mediator::execPositionDialog()
{
    mediator_position_dialog->exec();
}
