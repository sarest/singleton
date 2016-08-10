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
    view = new MyQGraphicsView;
    speed_view = new MyQGraphicsView;
    length_view = new MyQGraphicsView;
    ui->view_layout->addWidget(view);
    ui->view_layout->addWidget(speed_view);
    ui->view_layout->addWidget(length_view);
    set_grid();
}

WindowTarget::~WindowTarget()
{
    delete ui;
}

//Functions

void WindowTarget::loadTable()
{
    Target *mytarget = Mediator::Instance()->getTarget();
    QList<Segment*> segment_list = mytarget->getSegment();
    QString velocity,acceleration,radius,x,y,time;

    mytable->setItem(0, 3, new QTableWidgetItem(mytarget->getStartVelocity()));
    for(int i=0; i<segment_list.count(); i++){
        if(segment_list.at(i)->getType()=="straight"){
            velocity = segment_list.at(i)->getVelocity_straight();
            acceleration = segment_list.at(i)->getAcceleration_straight();
            x = segment_list.at(i)->getX_straight();
            y = segment_list.at(i)->getY_straight();
            time = segment_list.at(i)->getTime_straight();
            radius = "0";
        }
        else if(segment_list.at(i)->getType()=="curve"){
            radius = segment_list.at(i)->getRadius();
            velocity = segment_list.at(i)->getVelocity_curve();
            acceleration = segment_list.at(i)->getAcceleration_curve();
            x = segment_list.at(i)->getX_curve();
            y = segment_list.at(i)->getY_curve();
            time = segment_list.at(i)->getTime_curve();
        }
        addRow(acceleration,velocity,radius,x,y,time);
    }
}

void WindowTarget::updateTable()
{
    Target *mytarget = Mediator::Instance()->getTarget();
    QList<Segment*> segment_list = mytarget->getSegment();
    QString velocity,acceleration,radius,x,y,time;

    if(segment_list.last()->getType()=="straight"){
        velocity = segment_list.last()->getVelocity_straight();
        acceleration = segment_list.last()->getAcceleration_straight();
        x = segment_list.last()->getX_straight();
        y = segment_list.last()->getY_straight();
        time = segment_list.last()->getTime_straight();
    }
    else if(segment_list.last()->getType()=="curve"){
        radius = segment_list.last()->getRadius();
        velocity = segment_list.last()->getVelocity_curve();
        acceleration = segment_list.last()->getAcceleration_curve();
        x = segment_list.last()->getX_curve();
        y = segment_list.last()->getY_curve();
        time = segment_list.last()->getTime_curve();
    }
    addRow(acceleration,velocity,radius,x,y,time);
}

void WindowTarget::addRow(QString acceleration, QString velocity, QString radius, QString x, QString y, QString time)
{
    mytable->insertRow(mytable->rowCount());
    mytable->setItem(mytable->rowCount()-1, 0, new QTableWidgetItem(QString::number(mytable->rowCount()-1)));
    mytable->setItem(mytable->rowCount()-1, 1, new QTableWidgetItem(acceleration));
    mytable->setItem(mytable->rowCount()-1, 2, new QTableWidgetItem(time));
    mytable->setItem(mytable->rowCount()-1, 3, new QTableWidgetItem(velocity));
    mytable->setItem(mytable->rowCount()-1, 4, new QTableWidgetItem(x));
    mytable->setItem(mytable->rowCount()-1, 5, new QTableWidgetItem(y));
    mytable->setItem(mytable->rowCount()-1, 6, new QTableWidgetItem(radius));
}

bool WindowTarget::checkStartVelocity()
{
    if(ui->start_velocity->text()!=""){
        Target *mytarget = Mediator::Instance()->getTarget();
        mytarget->setStartVelocity(ui->start_velocity->text());
        ui->start_velocity->setDisabled(true);
        mytable->setItem(0, 0, new QTableWidgetItem("0"));
        mytable->setItem(0, 1, new QTableWidgetItem("0"));
        mytable->setItem(0, 2, new QTableWidgetItem("0"));
        mytable->setItem(0, 3, new QTableWidgetItem(ui->start_velocity->text()));
        mytable->setItem(0, 4, new QTableWidgetItem("0"));
        mytable->setItem(0, 5, new QTableWidgetItem("0"));
        mytable->setItem(0, 6, new QTableWidgetItem("0"));
        return true;
    }
    else{
        return false;
    }
}

void WindowTarget::drawTarget()
{
    view->scene->clear();
    set_grid();
    Target *mytarget = Mediator::Instance()->getTarget();
    QList<Segment*> segment_list = mytarget->getSegment();
    QPainterPath path;
    //float k = 0.551915024494;
    float x0 = 0,y0 = 0, x1, y1;
    //float radius;
    path.moveTo(x0,y0);
    for(int i=0; i<segment_list.count(); i++){
        if(segment_list.at(i)->getType() == "straight"){
            x1 = segment_list.at(i)->getX_straight().toFloat();
            y1 = segment_list.at(i)->getY_straight().toFloat();
            path.lineTo(x1,-y1);
        }
        else if(segment_list.at(i)->getType() == "curve"){
            x0 = path.currentPosition().x();
            y0 = path.currentPosition().y();
            //radius = segment_list.at(i)->getRadius().toFloat();
            x1 = segment_list.at(i)->getX_curve().toFloat();
            y1 = segment_list.at(i)->getY_curve().toFloat();
            //path.quadTo(x0+radius,y0,x1,-y1);
            //path.cubicTo(x0+(x0*k),-y0,x1,-((y1*k)+y1),x1,-y1);
            path.lineTo(x1,-y1);
        }
    }
    view->scene->addPath(path);
}

void WindowTarget::initTable()
{
    mytable = new QTableWidget;
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
    lista_labels.append("Acceleration");
    lista_labels.append("Time");
    lista_labels.append("Velocity");
    lista_labels.append("x");
    lista_labels.append("y");
    lista_labels.append("Radius");
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

void WindowTarget::set_grid()
{
    //view->scene->setBackgroundBrush(QBrush(QPixmap(":/imgs/grid.png")));

    /*for (int x=-90; x<=90; x+=10)
        view->scene->addLine(x,-90,x,90, QPen(Qt::green,0.5,Qt::DashLine));
    for (int y=-90; y<=90; y+=10)
        view->scene->addLine(-90,y,90,y, QPen(Qt::green,0.5,Qt::DashLine));*/

    view->scene->addLine(-10,0,10,0,QPen(Qt::red,1.5));
    view->scene->addLine(0,-10,0,10,QPen(Qt::red,1.5));


    /*for (int x=-1000; x<=1000; x+=100){
        QGraphicsTextItem *meters = new QGraphicsTextItem;
        meters->setPos(x,0);
        meters->setPlainText(QString::number(x)+"m");
        view->scene->addItem(meters);
        view->scene->addLine(x,0,x,0);
    }
    for (int y=-1000; y<=1000; y+=100){
        QGraphicsTextItem *meters = new QGraphicsTextItem;
        meters->setPos(0,y);
        meters->setPlainText(QString::number(-y)+"m");
        view->scene->addItem(meters);
        view->scene->addLine(0,y,0,y);
    }*/
}

//Buttons

void WindowTarget::on_bSave_clicked()
{
    QWidget *ventana_save = new QWidget;
    QString fileName = QFileDialog::getSaveFileName(ventana_save,"Save file",ui->target_name->text()+".xml","XML (*.xml)");
    Files *mydoc = Mediator::Instance()->getFiles();
    Target *mytarget = Mediator::Instance()->getTarget();
    mytarget->setID(ui->target_name->text());
    mydoc->xml_writer(fileName);
}

void WindowTarget::on_bLoad_clicked()
{
    on_bClearTable_clicked();
    QWidget *ventana_load = new QWidget;
    QString fileName = QFileDialog::getOpenFileName(ventana_load,"Open file",QDir::currentPath(),"XML (*.xml)");
    Files *mydoc = Mediator::Instance()->getFiles();
    Target *mytarget = mydoc->xml_reader(fileName);
    Mediator::Instance()->setTarget(mytarget);
    ui->start_velocity->setText(mytarget->getStartVelocity());
    ui->start_velocity->setDisabled(true);
    loadTable();
    drawTarget();
}

void WindowTarget::on_bConfirm_straight_clicked()
{
    if(checkStartVelocity()){
        if(ui->straight_length->text() == "" || (ui->straight_acceleration->text() == "" && ui->straight_velocity->text() == "")){
            ui->invalid_segment_label->setText("INVALID SEGMENT");
        }
        else{
            ui->invalid_segment_label->clear();
            Functions *myfunctions = Mediator::Instance()->getFunctions();
            myfunctions->straightCalculations(ui->straight_length->text(),ui->straight_acceleration->text(),ui->straight_velocity->text());
            updateTable();
            cleanValues();
            ui->statusbar->showMessage("");
            drawTarget();
        }
    }
    else{
        ui->statusbar->showMessage("Enter a start velocity");
    }
}

void WindowTarget::on_bConfirm_curve_clicked()
{   
    if(checkStartVelocity()){
        if(ui->curve_angle->text() == "" || ui->curve_radius->text() == "" || (ui->curve_acceleration->text() == "" && ui->curve_velocity->text() == "")){
            ui->invalid_segment_label_curve->setText("INVALID SEGMENT");
        }
        else{
            ui->invalid_segment_label_curve->clear();
            Functions *myfunctions = Mediator::Instance()->getFunctions();
            myfunctions->curveCalculations(ui->curve_angle->text(),ui->curve_radius->text(),ui->curve_acceleration->text(),ui->curve_velocity->text());
            updateTable();
            cleanValues();
            ui->statusbar->showMessage("");
            drawTarget();
        }
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
    ui->start_velocity->setEnabled(true);
    ui->start_velocity->setText("0");
    mytable->setItem(0, 3, new QTableWidgetItem("0"));
    Target *mytarget = Mediator::Instance()->getTarget();
    mytarget->deleteTarget();
    view->scene->clear();
    set_grid();
}

void WindowTarget::on_bDeleteLast_clicked()
{
    if(mytable->rowCount()>1){
        mytable->removeRow(mytable->rowCount()-1);
        Target *mytarget = Mediator::Instance()->getTarget();
        mytarget->deleteLastSegment();
    }
}

