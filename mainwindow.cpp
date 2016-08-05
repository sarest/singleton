#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mediator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->bCommunication->setStyleSheet("background-color: red;");
    ui->rRemote->clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bNewTarget_clicked()
{
    Mediator::Instance()->showWindowTarget();
}

void MainWindow::on_bLoadTarget_clicked()
{
    QWidget *ventana_load = new QWidget;
    QString fileName = QFileDialog::getOpenFileName(ventana_load,"Open file",QDir::currentPath(),"XML (*.xml)");
    Files *mydoc = Mediator::Instance()->getFiles();
    Target *mytarget = mydoc->xml_reader(fileName);
    Mediator::Instance()->setTarget(mytarget);
    ui->loaded_target_label->setText("LOADED TARGET\n"+mytarget->getID());
    ui->loaded_target_label->setStyleSheet("background-color: green;");
}

void MainWindow::on_bCommunication_clicked()
{
    if(!communication_enabled){
        ui->bCommunication->setStyleSheet("background-color: green;");
        ui->bCommunication->setText("COMMUNICATION\nClick to Stop");
        if(ui->rRemote->isChecked())
            ui->connection_label->setText("Remote Control");
        else if(ui->rManual->isChecked())
            ui->connection_label->setText("Manual Control");
        ui->status_label->setText("Communication established");
        communication_enabled = true;
    }
    else{
        ui->bCommunication->setStyleSheet("background-color: red;");
        ui->bCommunication->setText("COMMUNICATION\nClick to Start");
        communication_enabled = false;
    }

}

void MainWindow::on_bStart_clicked()
{
    if(communication_enabled){
        ui->status_label->setText("Test in progress");
        ui->speed_label->setStyleSheet("background-color: green;");
        ui->speed_label->setText("0.00 km/h");
    }
}

void MainWindow::on_bStop_clicked()
{
    if(communication_enabled){
        ui->status_label->setText("Test stopped");
        ui->speed_label->setStyleSheet("background-color: red;");
    }
}

void MainWindow::on_rRemote_clicked()
{
    ui->acc_limit_control->setEnabled(true);
    ui->speed_control->setDisabled(true);
    ui->steering_control->setDisabled(true);
}

void MainWindow::on_rManual_clicked()
{
    ui->acc_limit_control->setEnabled(true);
    ui->steering_control->setEnabled(true);
    ui->speed_control->setEnabled(true);
}

void MainWindow::on_bReferencePosition_clicked()
{
    Mediator::Instance()->execPositionDialog();
}
