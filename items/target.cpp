#include "target.h"

Target::Target()
{

}

void Target::deleteTarget()
{
    target_id.clear();
    start_velocity.clear();
    segment_list.clear();
}

void Target::deleteLastSegment()
{
    segment_list.removeLast();
}
