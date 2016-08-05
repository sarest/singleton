#ifndef POSITION_DIALOG_H
#define POSITION_DIALOG_H

#include <QDialog>

namespace Ui {
class position_dialog;
}

class position_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit position_dialog(QWidget *parent = 0);
    ~position_dialog();

private:
    Ui::position_dialog *ui;
};

#endif // POSITION_DIALOG_H
