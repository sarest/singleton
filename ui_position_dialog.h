/********************************************************************************
** Form generated from reading UI file 'position_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSITION_DIALOG_H
#define UI_POSITION_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_position_dialog
{
public:
    QFrame *frame;
    QLabel *label;
    QListWidget *listWidget;
    QPushButton *bSelect;
    QPushButton *bNew;
    QPushButton *bDelete;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QGridLayout *gridLayout;
    QLineEdit *latitude;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *direction;
    QLineEdit *name;
    QLineEdit *longitude;
    QLabel *label_5;
    QLineEdit *height;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *bClose;

    void setupUi(QDialog *position_dialog)
    {
        if (position_dialog->objectName().isEmpty())
            position_dialog->setObjectName(QStringLiteral("position_dialog"));
        position_dialog->resize(702, 541);
        frame = new QFrame(position_dialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(9, 9, 684, 305));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 156, 16));
        listWidget = new QListWidget(frame);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 44, 578, 251));
        bSelect = new QPushButton(frame);
        bSelect->setObjectName(QStringLiteral("bSelect"));
        bSelect->setGeometry(QRect(594, 214, 80, 23));
        bNew = new QPushButton(frame);
        bNew->setObjectName(QStringLiteral("bNew"));
        bNew->setGeometry(QRect(594, 243, 80, 23));
        bDelete = new QPushButton(frame);
        bDelete->setObjectName(QStringLiteral("bDelete"));
        bDelete->setGeometry(QRect(594, 272, 80, 23));
        frame_2 = new QFrame(position_dialog);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(9, 320, 421, 211));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        latitude = new QLineEdit(frame_2);
        latitude->setObjectName(QStringLiteral("latitude"));

        gridLayout->addWidget(latitude, 2, 1, 1, 1);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        direction = new QLineEdit(frame_2);
        direction->setObjectName(QStringLiteral("direction"));

        gridLayout->addWidget(direction, 3, 1, 1, 1);

        name = new QLineEdit(frame_2);
        name->setObjectName(QStringLiteral("name"));

        gridLayout->addWidget(name, 0, 1, 1, 1);

        longitude = new QLineEdit(frame_2);
        longitude->setObjectName(QStringLiteral("longitude"));

        gridLayout->addWidget(longitude, 1, 1, 1, 1);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        height = new QLineEdit(frame_2);
        height->setObjectName(QStringLiteral("height"));

        gridLayout->addWidget(height, 4, 1, 1, 1);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 1, 2, 1, 1);

        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 2, 2, 1, 1);

        label_11 = new QLabel(frame_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 3, 2, 1, 1);

        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 4, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 2);

        pushButton_4 = new QPushButton(frame_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_2->addWidget(pushButton_4, 2, 1, 1, 1);

        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 2, 0, 1, 1);

        bClose = new QPushButton(position_dialog);
        bClose->setObjectName(QStringLiteral("bClose"));
        bClose->setGeometry(QRect(520, 400, 80, 51));

        retranslateUi(position_dialog);

        QMetaObject::connectSlotsByName(position_dialog);
    } // setupUi

    void retranslateUi(QDialog *position_dialog)
    {
        position_dialog->setWindowTitle(QApplication::translate("position_dialog", "Reference positions", 0));
        label->setText(QApplication::translate("position_dialog", "List of reference positions", 0));
        bSelect->setText(QApplication::translate("position_dialog", "SELECT", 0));
        bNew->setText(QApplication::translate("position_dialog", "ADD NEW", 0));
        bDelete->setText(QApplication::translate("position_dialog", "DELETE", 0));
        label_2->setText(QApplication::translate("position_dialog", "Edit a position", 0));
        label_4->setText(QApplication::translate("position_dialog", "Longitude", 0));
        label_3->setText(QApplication::translate("position_dialog", "Name", 0));
        label_5->setText(QApplication::translate("position_dialog", "Latitude", 0));
        label_6->setText(QApplication::translate("position_dialog", "Direction", 0));
        label_7->setText(QApplication::translate("position_dialog", "Height", 0));
        label_9->setText(QApplication::translate("position_dialog", "\302\272 (east)", 0));
        label_10->setText(QApplication::translate("position_dialog", "\302\272 (north)", 0));
        label_11->setText(QApplication::translate("position_dialog", "\302\272 (0=north; >0=east)", 0));
        label_12->setText(QApplication::translate("position_dialog", "m", 0));
        pushButton_4->setText(QApplication::translate("position_dialog", "APPLY", 0));
        pushButton->setText(QApplication::translate("position_dialog", "Set Current Position", 0));
        bClose->setText(QApplication::translate("position_dialog", "CLOSE", 0));
    } // retranslateUi

};

namespace Ui {
    class position_dialog: public Ui_position_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSITION_DIALOG_H
