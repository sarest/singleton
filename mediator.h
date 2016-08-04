#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QDebug>

#include "mainwindow.h"
#include "functions.h"
#include "files.h"
#include "views/windowtarget.h"
#include "items/target.h"

class Mediator
{
public:
    static Mediator* Instance();

    void setMainWindow(MainWindow *MW_instance){mediator_MW = MW_instance;}
    void setFunctions(Functions *functions_instance){mediator_functions = functions_instance;}
    void setFiles(Files *files_instance){mediator_files = files_instance;}
    void setWindowTarget(WindowTarget *window_target_instance){mediator_window_target = window_target_instance;}
    void setTarget(Target *target_instance){mediator_target = target_instance;}

    void addSegmentToTarget(Segment *segment_instance);
    void showWindowTarget();

    Target *getTarget(){return mediator_target;}
    Files *getFiles(){return mediator_files;}

private:
    Mediator();
    static Mediator *instance;
    MainWindow *mediator_MW;
    Functions *mediator_functions;
    Files *mediator_files;
    WindowTarget *mediator_window_target;
    Target *mediator_target;
};

#endif // MEDIATOR_H
