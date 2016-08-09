#include "mainwindow.h"
#include "mediator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Mediator *main_mediator = Mediator::Instance();

    MainWindow *MW = new MainWindow;
    Functions *main_functions = new Functions;
    Files *main_files = new Files;
    WindowTarget *main_window_target = new WindowTarget;
    Target *main_target = new Target;
    position_dialog *main_position_dialog = new position_dialog;

    main_mediator->setMainWindow(MW);
    main_mediator->setFiles(main_files);
    main_mediator->setFunctions(main_functions);
    main_mediator->setWindowTarget(main_window_target);
    main_mediator->setTarget(main_target);
    main_mediator->setPositionDialog(main_position_dialog);

    MW->show();
    //main_window_target->show();

    return a.exec();
}
