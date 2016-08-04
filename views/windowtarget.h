#ifndef WINDOWTARGET_H
#define WINDOWTARGET_H

#include <QMainWindow>
#include <QDir>
#include <QFileDialog>
#include <QTableWidget>

#include "myqgraphicsview.h"

namespace Ui {
class WindowTarget;
}

class WindowTarget : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowTarget(QWidget *parent = 0);
    ~WindowTarget();

private slots:
    void on_bSave_clicked();
    void on_bLoad_clicked();
    void on_bConfirm_straight_clicked();
    void on_bConfirm_curve_clicked();
    void on_rAcceleration_straight_clicked();
    void on_rVelocity_straight_clicked();
    void on_rAcceleration_curve_clicked();
    void on_rVelocity_curve_clicked();
    void on_bClearTable_clicked();
    void on_bDeleteLast_clicked();

private:
    Ui::WindowTarget *ui;
    void updateTable();
    void initTable();
    void cleanValues();
    void loadTable();
    void addRow(QString acceleration, QString velocity, QString radius);
    bool checkStartVelocity();
    QTableWidget *mytable = new QTableWidget;
    MyQGraphicsView *view = new MyQGraphicsView;

};

#endif // WINDOWTARGET_H
