#ifndef POSITION_DIALOG_H
#define POSITION_DIALOG_H

#include <QDialog>
#include <QListWidgetItem>
#include <QMessageBox>

namespace Ui {
class position_dialog;
}

class position_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit position_dialog(QWidget *parent = 0);
    ~position_dialog();

private slots:
    void on_bClose_clicked();
    void on_bApply_clicked();
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_bSelect_clicked();
    void on_bDelete_clicked();

    void on_bNew_clicked();

private:
    Ui::position_dialog *ui;
    void showPositions();
    void cleanDialog();
    bool checkPositionValues();
};

#endif // POSITION_DIALOG_H
