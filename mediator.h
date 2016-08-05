#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QDebug>

#include "mainwindow.h"
#include "functions.h"
#include "files.h"
#include "views/windowtarget.h"
#include "items/target.h"
#include "views/position_dialog.h"

class Mediator
{
public:
    static Mediator* Instance();

    void setMainWindow(MainWindow *MW_instance){mediator_MW = MW_instance;}
    void setFunctions(Functions *functions_instance){mediator_functions = functions_instance;}
    void setFiles(Files *files_instance){mediator_files = files_instance;}
    void setWindowTarget(WindowTarget *window_target_instance){mediator_window_target = window_target_instance;}
    void setTarget(Target *target_instance){mediator_target = target_instance;}
    void setPositionDialog(position_dialog *dialog_instance){mediator_position_dialog = dialog_instance;}

    void addSegmentToTarget(Segment *segment_instance);
    void showWindowTarget();
    void execPositionDialog();

    Target *getTarget(){return mediator_target;}
    Files *getFiles(){return mediator_files;}
    Functions *getFunctions(){return mediator_functions;}

private:
    Mediator();
    static Mediator *instance;
    MainWindow *mediator_MW;
    Functions *mediator_functions;
    Files *mediator_files;
    WindowTarget *mediator_window_target;
    Target *mediator_target;
    position_dialog *mediator_position_dialog;
};

#endif // MEDIATOR_H
