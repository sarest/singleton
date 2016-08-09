#include "position_dialog.h"
#include "ui_position_dialog.h"

#include "mediator.h"

position_dialog::position_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::position_dialog)
{
    ui->setupUi(this);
    Files *mydoc = Mediator::Instance()->getFiles();
    mydoc->position_reader();
    showPositions();
    ui->bCurrent->setDisabled(true);
}

position_dialog::~position_dialog()
{
    delete ui;
}

void position_dialog::on_bClose_clicked()
{
    position_dialog::close();
}

void position_dialog::on_bApply_clicked()
{
    Position *myposition = new Position;
    if(checkPositionValues()){
        myposition->setPosition(ui->name->text(),ui->longitude->text(),ui->latitude->text(),ui->direction->text(),ui->height->text());
        Mediator::Instance()->addPosition(myposition);
    }
    else{
        QMessageBox errorBox;
        errorBox.setText("Name already exists");
        errorBox.exec();
    }
    showPositions();
    Files *mydoc = Mediator::Instance()->getFiles();
    mydoc->position_writer();
    cleanDialog();
}

void position_dialog::on_bNew_clicked()
{
    ui->listWidget->addItem("New position");
    ui->name->setText("New position");
    ui->longitude->setText("0");
    ui->latitude->setText("0");
    ui->direction->setText("0");
    ui->height->setText("0");
}

bool position_dialog::checkPositionValues()
{
    bool exist = false;
    QList<Position*> mylist = Mediator::Instance()->getPositions();
    for(int i=0; i<mylist.count(); i++){
        QString name = mylist.at(i)->getName();
        if(ui->name->text() == name)
            exist = true;
    }
    if(ui->name->text() != "" && !exist)
        return true;
    else
        return false;
}

void position_dialog::showPositions()
{
    ui->listWidget->clear();
    QList<Position*> mylist = Mediator::Instance()->getPositions();
    for(int i=0; i<mylist.count(); i++){
        ui->listWidget->addItem(mylist.at(i)->getName());
    }
}

void position_dialog::cleanDialog()
{
    ui->name->clear();
    ui->latitude->clear();
    ui->longitude->clear();
    ui->latitude->clear();
    ui->direction->clear();
    ui->height->clear();
}

void position_dialog::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString name = item->text();
    QList<Position*> mylist = Mediator::Instance()->getPositions();
    for(int i=0; i<mylist.count(); i++){
        if(mylist.at(i)->getName() == name){
            ui->name->setText(mylist.at(i)->getName());
            ui->longitude->setText(mylist.at(i)->getLongitude());
            ui->latitude->setText(mylist.at(i)->getLatitude());
            ui->direction->setText(mylist.at(i)->getDirection());
            ui->height->setText(mylist.at(i)->getHeight());
        }
    }
}

void position_dialog::on_bSelect_clicked()
{
    if(ui->listWidget->currentItem()!=NULL){
        QString name = ui->listWidget->currentItem()->text();
        Mediator::Instance()->setPosition(name);
        position_dialog::accept();
    }
}

void position_dialog::on_bDelete_clicked()
{
    if(ui->listWidget->currentItem()!=NULL){
        QString name = ui->listWidget->currentItem()->text();
        ui->listWidget->removeItemWidget(ui->listWidget->currentItem());
        QList<Position*> mylist = Mediator::Instance()->getPositions();
        for(int i=0; i<mylist.count(); i++){
            if(mylist.at(i)->getName() == name){
                Mediator::Instance()->deletePosition(i);
                Files *mydoc = Mediator::Instance()->getFiles();
                mydoc->position_writer();
            }
        }
        showPositions();
        cleanDialog();
    }
}
