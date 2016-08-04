#include "windowtarget.h"
#include "ui_windowtarget.h"

#include "mediator.h"

WindowTarget::WindowTarget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowTarget)
{
    ui->setupUi(this);
    initTable();
    ui->rAcceleration_straight->click();
    ui->rAcceleration_curve->click();
    ui->view_layout->addWidget(view);
}

WindowTarget::~WindowTarget()
{
    delete ui;
}

void WindowTarget::loadTable()
{
    Mediator *mediator = Mediator::Instance();
    Target *mytarget = mediator->getTarget();
    QList<Segment*> segment_list = mytarget->getSegment();
    QString velocity,acceleration,radius,length,angle;

    for(int i=0; i<segment_list.count(); i++){
        if(segment_list.at(i)->getType()=="straight"){
            length = segment_list.at(i)->getLength();
            velocity = segment_list.at(i)->getVelocity_straight();
            acceleration = segment_list.at(i)->getAcceleration_straight();
        }
        else if(segment_list.at(i)->getType()=="curve"){
            angle = segment_list.at(i)->getAngle();
            radius = segment_list.at(i)->getRadius();
            velocity = segment_list.at(i)->getVelocity_curve();
            acceleration = segment_list.at(i)->getAcceleration_curve();
        }
        addRow(acceleration,velocity,radius);
    }
}

void WindowTarget::addRow(QString acceleration, QString velocity, QString radius)
{
    mytable->insertRow(mytable->rowCount());
    mytable->setItem(mytable->rowCount()-1, 0, new QTableWidgetItem(QString::number(mytable->rowCount()-1)));
    mytable->setItem(mytable->rowCount()-1, 1, new QTableWidgetItem(acceleration));
    mytable->setItem(mytable->rowCount()-1, 2, new QTableWidgetItem("time"));
    mytable->setItem(mytable->rowCount()-1, 3, new QTableWidgetItem(velocity));
    mytable->setItem(mytable->rowCount()-1, 4, new QTableWidgetItem("x"));
    mytable->setItem(mytable->rowCount()-1, 5, new QTableWidgetItem("y"));
    mytable->setItem(mytable->rowCount()-1, 6, new QTableWidgetItem(radius));
}

bool WindowTarget::checkStartVelocity()
{
    if(ui->start_velocity->text()!=""){
        ui->start_velocity->setDisabled(true);
        return true;
    }
    else
        return false;
}

void WindowTarget::updateTable()
{
    Mediator *mediator = Mediator::Instance();
    Target *mytarget = mediator->getTarget();
    QList<Segment*> segment_list = mytarget->getSegment();
    QString velocity,acceleration,radius,length,angle;

    if(segment_list.last()->getType()=="straight"){
        length = segment_list.last()->getLength();
        velocity = segment_list.last()->getVelocity_straight();
        acceleration = segment_list.last()->getAcceleration_straight();
    }
    else if(segment_list.last()->getType()=="curve"){
        angle = segment_list.last()->getAngle();
        radius = segment_list.last()->getRadius();
        velocity = segment_list.last()->getVelocity_curve();
        acceleration = segment_list.last()->getAcceleration_curve();
    }
    addRow(acceleration,velocity,radius);
}

void WindowTarget::initTable()
{
    mytable->setColumnCount(7);

    mytable->insertRow(0);
    mytable->setItem(0, 0, new QTableWidgetItem("0"));
    mytable->setItem(0, 1, new QTableWidgetItem("0"));
    mytable->setItem(0, 2, new QTableWidgetItem("0"));
    mytable->setItem(0, 3, new QTableWidgetItem("0"));
    mytable->setItem(0, 4, new QTableWidgetItem("0"));
    mytable->setItem(0, 5, new QTableWidgetItem("0"));
    mytable->setItem(0, 6, new QTableWidgetItem("0"));

    QStringList lista_labels;
    lista_labels.append("ID");
    lista_labels.append("Acceleration in m/s2");
    lista_labels.append("Time in s");
    lista_labels.append("Velocity in km/h");
    lista_labels.append("x in m");
    lista_labels.append("y in m");
    lista_labels.append("Radius in m");
    mytable->setHorizontalHeaderLabels(lista_labels);

    ui->table_layout->addWidget(mytable);
}

void WindowTarget::cleanValues()
{
    ui->curve_acceleration->clear();
    ui->curve_angle->clear();
    ui->curve_velocity->clear();
    ui->curve_radius->clear();
    ui->straight_acceleration->clear();
    ui->straight_length->clear();
    ui->straight_velocity->clear();
}


void WindowTarget::on_bSave_clicked()
{
    QWidget *ventana_save = new QWidget;
    QString fileName = QFileDialog::getSaveFileName(ventana_save,"Save file",ui->target_name->text()+".xml","XML (*.xml)");
    Mediator *mediator = Mediator::Instance();
    Files *mydoc = mediator->getFiles();
    Target *mytarget = mediator->getTarget();
    mytarget->setID(ui->target_name->text());
    mydoc->xml_writer(fileName);
}

void WindowTarget::on_bLoad_clicked()
{
    QWidget *ventana_load = new QWidget;
    QString fileName = QFileDialog::getOpenFileName(ventana_load,"Open file",QDir::currentPath(),"XML (*.xml)");
    Mediator *mediator = Mediator::Instance();
    Files *mydoc = mediator->getFiles();
    Target *mytarget = mydoc->xml_reader(fileName);
    mediator->setTarget(mytarget);
    on_bClearTable_clicked();
    loadTable();
}

void WindowTarget::on_bConfirm_straight_clicked()
{
    Mediator *mediator = Mediator::Instance();
    Segment *newsegment = new Segment;
    newsegment->setValues_straight("straight",ui->straight_length->text(),ui->straight_acceleration->text(),ui->straight_velocity->text());
    mediator->addSegmentToTarget(newsegment);
    if(checkStartVelocity()){
        updateTable();
        cleanValues();
        ui->statusbar->showMessage("");
    }
    else{
        ui->statusbar->showMessage("Enter a start velocity");
    }

}

void WindowTarget::on_bConfirm_curve_clicked()
{
    Mediator *mediator = Mediator::Instance();
    Segment *newsegment = new Segment;
    newsegment->setValues_curve("curve",ui->curve_angle->text(),ui->curve_radius->text(),ui->curve_acceleration->text(),ui->curve_velocity->text());
    mediator->addSegmentToTarget(newsegment);
    if(checkStartVelocity()){
        updateTable();
        cleanValues();
        ui->statusbar->showMessage("");
    }
    else{
        ui->statusbar->showMessage("Enter a start velocity");
    }
}

void WindowTarget::on_rAcceleration_straight_clicked()
{
    ui->straight_acceleration->setEnabled(true);
    ui->straight_velocity->setDisabled(true);
}

void WindowTarget::on_rVelocity_straight_clicked()
{
    ui->straight_velocity->setEnabled(true);
    ui->straight_acceleration->setDisabled(true);
}

void WindowTarget::on_rAcceleration_curve_clicked()
{
    ui->curve_acceleration->setEnabled(true);
    ui->curve_velocity->setDisabled(true);
}

void WindowTarget::on_rVelocity_curve_clicked()
{
    ui->curve_velocity->setEnabled(true);
    ui->curve_acceleration->setDisabled(true);
}


void WindowTarget::on_bClearTable_clicked()
{
    int row_count = mytable->rowCount();
    for(int i=row_count;i>0;i--)
        mytable->removeRow(i);
    cleanValues();
}

void WindowTarget::on_bDeleteLast_clicked()
{
    if(mytable->rowCount()>1)
        mytable->removeRow(mytable->rowCount()-1);
}
