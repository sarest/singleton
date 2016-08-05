#include "position_dialog.h"
#include "ui_position_dialog.h"

#include "mediator.h"

position_dialog::position_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::position_dialog)
{
    ui->setupUi(this);
}

position_dialog::~position_dialog()
{
    delete ui;
}
