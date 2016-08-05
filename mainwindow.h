#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_bNewTarget_clicked();

    void on_bLoadTarget_clicked();

    void on_bCommunication_clicked();

    void on_bStart_clicked();

    void on_bStop_clicked();

    void on_rRemote_clicked();

    void on_rManual_clicked();

    void on_bReferencePosition_clicked();

private:
    Ui::MainWindow *ui;
    bool communication_enabled = false;
};

#endif // MAINWINDOW_H
