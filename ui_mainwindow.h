/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QGridLayout *title_layout;
    QLabel *connection_label;
    QLabel *status_label;
    QLabel *speed_label;
    QFrame *target_frame;
    QGridLayout *gridLayout_2;
    QPushButton *bLoadTarget;
    QPushButton *bNewTarget;
    QLabel *label_5;
    QFrame *buttons_fram;
    QGridLayout *gridLayout_4;
    QPushButton *bStop;
    QPushButton *bManualControl;
    QPushButton *bStart;
    QPushButton *bTimerStart;
    QPushButton *bReturnToStart;
    QFrame *manual_frame;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLineEdit *acc_limit_control;
    QLineEdit *steering_control;
    QLabel *label;
    QRadioButton *rRemote;
    QLineEdit *speed_control;
    QLabel *label_2;
    QRadioButton *rManual;
    QLabel *label_6;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QFrame *info_frame;
    QGridLayout *gridLayout_6;
    QLabel *loaded_target_label;
    QPushButton *bCommunication;
    QPushButton *bLogging;
    QLabel *gps_label;
    QLabel *remote_control_label;
    QPushButton *bLightgate;
    QLabel *target_platform_label;
    QPushButton *bSyncVehicle;
    QPushButton *bPlatformBatteries;
    QPushButton *bHDLogging;
    QPushButton *bReferencePosition;
    QPushButton *bPlatformState;
    QLabel *start_position_label;
    QLabel *motor_temperatures_label;
    QFrame *control_frame;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QRadioButton *rAS_AD;
    QRadioButton *rAS_AS;
    QRadioButton *rFS;
    QCheckBox *endless_check;
    QRadioButton *rAS_MS;
    QRadioButton *rFT_SS;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        title_layout = new QGridLayout();
        title_layout->setSpacing(0);
        title_layout->setObjectName(QStringLiteral("title_layout"));
        connection_label = new QLabel(centralwidget);
        connection_label->setObjectName(QStringLiteral("connection_label"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        connection_label->setFont(font);
        connection_label->setFrameShape(QFrame::Box);
        connection_label->setAlignment(Qt::AlignCenter);

        title_layout->addWidget(connection_label, 2, 0, 1, 1);

        status_label = new QLabel(centralwidget);
        status_label->setObjectName(QStringLiteral("status_label"));
        status_label->setFont(font);
        status_label->setFrameShape(QFrame::Box);
        status_label->setAlignment(Qt::AlignCenter);

        title_layout->addWidget(status_label, 3, 0, 1, 1);

        speed_label = new QLabel(centralwidget);
        speed_label->setObjectName(QStringLiteral("speed_label"));
        speed_label->setFont(font);
        speed_label->setFrameShape(QFrame::Box);
        speed_label->setAlignment(Qt::AlignCenter);

        title_layout->addWidget(speed_label, 2, 1, 2, 1);


        gridLayout_5->addLayout(title_layout, 0, 0, 1, 3);

        target_frame = new QFrame(centralwidget);
        target_frame->setObjectName(QStringLiteral("target_frame"));
        target_frame->setFrameShape(QFrame::Box);
        target_frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(target_frame);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        bLoadTarget = new QPushButton(target_frame);
        bLoadTarget->setObjectName(QStringLiteral("bLoadTarget"));

        gridLayout_2->addWidget(bLoadTarget, 2, 1, 1, 1);

        bNewTarget = new QPushButton(target_frame);
        bNewTarget->setObjectName(QStringLiteral("bNewTarget"));

        gridLayout_2->addWidget(bNewTarget, 2, 0, 1, 1);

        label_5 = new QLabel(target_frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font1;
        font1.setPointSize(11);
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_5, 0, 0, 1, 2);


        gridLayout_5->addWidget(target_frame, 1, 0, 1, 1);

        buttons_fram = new QFrame(centralwidget);
        buttons_fram->setObjectName(QStringLiteral("buttons_fram"));
        buttons_fram->setFrameShape(QFrame::Box);
        buttons_fram->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(buttons_fram);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        bStop = new QPushButton(buttons_fram);
        bStop->setObjectName(QStringLiteral("bStop"));

        gridLayout_4->addWidget(bStop, 0, 1, 1, 1);

        bManualControl = new QPushButton(buttons_fram);
        bManualControl->setObjectName(QStringLiteral("bManualControl"));

        gridLayout_4->addWidget(bManualControl, 1, 1, 1, 1);

        bStart = new QPushButton(buttons_fram);
        bStart->setObjectName(QStringLiteral("bStart"));

        gridLayout_4->addWidget(bStart, 0, 0, 1, 1);

        bTimerStart = new QPushButton(buttons_fram);
        bTimerStart->setObjectName(QStringLiteral("bTimerStart"));

        gridLayout_4->addWidget(bTimerStart, 1, 0, 1, 1);

        bReturnToStart = new QPushButton(buttons_fram);
        bReturnToStart->setObjectName(QStringLiteral("bReturnToStart"));

        gridLayout_4->addWidget(bReturnToStart, 2, 0, 1, 2);


        gridLayout_5->addWidget(buttons_fram, 1, 1, 1, 1);

        manual_frame = new QFrame(centralwidget);
        manual_frame->setObjectName(QStringLiteral("manual_frame"));
        manual_frame->setFrameShape(QFrame::Box);
        manual_frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(manual_frame);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_3 = new QLabel(manual_frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 4, 1, 1, 1);

        acc_limit_control = new QLineEdit(manual_frame);
        acc_limit_control->setObjectName(QStringLiteral("acc_limit_control"));

        gridLayout_3->addWidget(acc_limit_control, 4, 2, 1, 1);

        steering_control = new QLineEdit(manual_frame);
        steering_control->setObjectName(QStringLiteral("steering_control"));

        gridLayout_3->addWidget(steering_control, 3, 2, 1, 1);

        label = new QLabel(manual_frame);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 2, 1, 1, 1);

        rRemote = new QRadioButton(manual_frame);
        rRemote->setObjectName(QStringLiteral("rRemote"));
        rRemote->setChecked(true);

        gridLayout_3->addWidget(rRemote, 1, 1, 1, 1);

        speed_control = new QLineEdit(manual_frame);
        speed_control->setObjectName(QStringLiteral("speed_control"));

        gridLayout_3->addWidget(speed_control, 2, 2, 1, 1);

        label_2 = new QLabel(manual_frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 3, 1, 1, 1);

        rManual = new QRadioButton(manual_frame);
        rManual->setObjectName(QStringLiteral("rManual"));

        gridLayout_3->addWidget(rManual, 1, 2, 1, 1);

        label_6 = new QLabel(manual_frame);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 0, 1, 1, 1);

        label_13 = new QLabel(manual_frame);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_3->addWidget(label_13, 2, 3, 1, 1);

        label_14 = new QLabel(manual_frame);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_3->addWidget(label_14, 3, 3, 1, 1);

        label_15 = new QLabel(manual_frame);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_3->addWidget(label_15, 4, 3, 1, 1);


        gridLayout_5->addWidget(manual_frame, 1, 2, 1, 1);

        info_frame = new QFrame(centralwidget);
        info_frame->setObjectName(QStringLiteral("info_frame"));
        info_frame->setFrameShape(QFrame::Box);
        info_frame->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(info_frame);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        loaded_target_label = new QLabel(info_frame);
        loaded_target_label->setObjectName(QStringLiteral("loaded_target_label"));
        loaded_target_label->setFrameShape(QFrame::Box);
        loaded_target_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(loaded_target_label, 2, 0, 1, 2);

        bCommunication = new QPushButton(info_frame);
        bCommunication->setObjectName(QStringLiteral("bCommunication"));

        gridLayout_6->addWidget(bCommunication, 0, 0, 1, 1);

        bLogging = new QPushButton(info_frame);
        bLogging->setObjectName(QStringLiteral("bLogging"));

        gridLayout_6->addWidget(bLogging, 0, 2, 1, 1);

        gps_label = new QLabel(info_frame);
        gps_label->setObjectName(QStringLiteral("gps_label"));
        gps_label->setFrameShape(QFrame::Box);
        gps_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(gps_label, 2, 2, 1, 2);

        remote_control_label = new QLabel(info_frame);
        remote_control_label->setObjectName(QStringLiteral("remote_control_label"));
        remote_control_label->setFrameShape(QFrame::Box);
        remote_control_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(remote_control_label, 4, 0, 1, 2);

        bLightgate = new QPushButton(info_frame);
        bLightgate->setObjectName(QStringLiteral("bLightgate"));

        gridLayout_6->addWidget(bLightgate, 0, 1, 1, 1);

        target_platform_label = new QLabel(info_frame);
        target_platform_label->setObjectName(QStringLiteral("target_platform_label"));
        target_platform_label->setFrameShape(QFrame::Box);
        target_platform_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(target_platform_label, 3, 0, 1, 2);

        bSyncVehicle = new QPushButton(info_frame);
        bSyncVehicle->setObjectName(QStringLiteral("bSyncVehicle"));

        gridLayout_6->addWidget(bSyncVehicle, 1, 1, 1, 1);

        bPlatformBatteries = new QPushButton(info_frame);
        bPlatformBatteries->setObjectName(QStringLiteral("bPlatformBatteries"));

        gridLayout_6->addWidget(bPlatformBatteries, 1, 3, 1, 1);

        bHDLogging = new QPushButton(info_frame);
        bHDLogging->setObjectName(QStringLiteral("bHDLogging"));

        gridLayout_6->addWidget(bHDLogging, 1, 2, 1, 1);

        bReferencePosition = new QPushButton(info_frame);
        bReferencePosition->setObjectName(QStringLiteral("bReferencePosition"));

        gridLayout_6->addWidget(bReferencePosition, 1, 0, 1, 1);

        bPlatformState = new QPushButton(info_frame);
        bPlatformState->setObjectName(QStringLiteral("bPlatformState"));

        gridLayout_6->addWidget(bPlatformState, 0, 3, 1, 1);

        start_position_label = new QLabel(info_frame);
        start_position_label->setObjectName(QStringLiteral("start_position_label"));
        start_position_label->setFrameShape(QFrame::Box);
        start_position_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(start_position_label, 3, 2, 1, 2);

        motor_temperatures_label = new QLabel(info_frame);
        motor_temperatures_label->setObjectName(QStringLiteral("motor_temperatures_label"));
        motor_temperatures_label->setFrameShape(QFrame::Box);
        motor_temperatures_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(motor_temperatures_label, 4, 2, 1, 2);


        gridLayout_5->addWidget(info_frame, 2, 0, 1, 2);

        control_frame = new QFrame(centralwidget);
        control_frame->setObjectName(QStringLiteral("control_frame"));
        control_frame->setFrameShape(QFrame::Box);
        control_frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(control_frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(control_frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        rAS_AD = new QRadioButton(control_frame);
        rAS_AD->setObjectName(QStringLiteral("rAS_AD"));
        rAS_AD->setChecked(true);

        gridLayout->addWidget(rAS_AD, 1, 0, 1, 1);

        rAS_AS = new QRadioButton(control_frame);
        rAS_AS->setObjectName(QStringLiteral("rAS_AS"));

        gridLayout->addWidget(rAS_AS, 2, 0, 1, 1);

        rFS = new QRadioButton(control_frame);
        rFS->setObjectName(QStringLiteral("rFS"));

        gridLayout->addWidget(rFS, 4, 0, 1, 1);

        endless_check = new QCheckBox(control_frame);
        endless_check->setObjectName(QStringLiteral("endless_check"));

        gridLayout->addWidget(endless_check, 6, 0, 1, 1);

        rAS_MS = new QRadioButton(control_frame);
        rAS_MS->setObjectName(QStringLiteral("rAS_MS"));

        gridLayout->addWidget(rAS_MS, 3, 0, 1, 1);

        rFT_SS = new QRadioButton(control_frame);
        rFT_SS->setObjectName(QStringLiteral("rFT_SS"));

        gridLayout->addWidget(rFT_SS, 5, 0, 1, 1);


        gridLayout_5->addWidget(control_frame, 2, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuAbout->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        connection_label->setText(QApplication::translate("MainWindow", "Connection Label", 0));
        status_label->setText(QApplication::translate("MainWindow", "Status Label", 0));
        speed_label->setText(QApplication::translate("MainWindow", "Speed Label (km/h)", 0));
        bLoadTarget->setText(QApplication::translate("MainWindow", "Load Target", 0));
        bNewTarget->setText(QApplication::translate("MainWindow", "New Target", 0));
        label_5->setText(QApplication::translate("MainWindow", "Target Utilty \302\251 ", 0));
        bStop->setText(QApplication::translate("MainWindow", "STOP", 0));
        bManualControl->setText(QApplication::translate("MainWindow", "Manual Control", 0));
        bStart->setText(QApplication::translate("MainWindow", "START", 0));
        bTimerStart->setText(QApplication::translate("MainWindow", "Timer Start", 0));
        bReturnToStart->setText(QApplication::translate("MainWindow", "Return to start", 0));
        label_3->setText(QApplication::translate("MainWindow", "Acc Limit", 0));
        label->setText(QApplication::translate("MainWindow", "Speed", 0));
        rRemote->setText(QApplication::translate("MainWindow", "Remote Control", 0));
        label_2->setText(QApplication::translate("MainWindow", "Steering", 0));
        rManual->setText(QApplication::translate("MainWindow", "Manual", 0));
        label_6->setText(QApplication::translate("MainWindow", "Manual Control Mode", 0));
        label_13->setText(QApplication::translate("MainWindow", "kph", 0));
        label_14->setText(QApplication::translate("MainWindow", "%", 0));
        label_15->setText(QApplication::translate("MainWindow", "m/ss", 0));
        loaded_target_label->setText(QApplication::translate("MainWindow", "LOADED TARGET\n"
"", 0));
        bCommunication->setText(QApplication::translate("MainWindow", "COMMUNICATION\n"
"Click to Start", 0));
        bLogging->setText(QApplication::translate("MainWindow", "LOGGING\n"
"", 0));
        gps_label->setText(QApplication::translate("MainWindow", "GPS\n"
"", 0));
        remote_control_label->setText(QApplication::translate("MainWindow", "REMOTE CONTROL\n"
"", 0));
        bLightgate->setText(QApplication::translate("MainWindow", "LIGHTGATE\n"
"", 0));
        target_platform_label->setText(QApplication::translate("MainWindow", "TARGET IN PLATFORM\n"
"", 0));
        bSyncVehicle->setText(QApplication::translate("MainWindow", "SYNC VEHICLE\n"
"", 0));
        bPlatformBatteries->setText(QApplication::translate("MainWindow", "PLATFORM BATTERIES\n"
"", 0));
        bHDLogging->setText(QApplication::translate("MainWindow", "HD LOGGING\n"
"", 0));
        bReferencePosition->setText(QApplication::translate("MainWindow", "REFERENCE POSITION\n"
"", 0));
        bPlatformState->setText(QApplication::translate("MainWindow", "PLATFORM STATE\n"
"", 0));
        start_position_label->setText(QApplication::translate("MainWindow", "START POSITION\n"
"", 0));
        motor_temperatures_label->setText(QApplication::translate("MainWindow", "MOTOR TEMPERATURES\n"
"", 0));
        label_4->setText(QApplication::translate("MainWindow", "Control mode during test", 0));
        rAS_AD->setText(QApplication::translate("MainWindow", "Auto steering / Auto distance", 0));
        rAS_AS->setText(QApplication::translate("MainWindow", "Auto steering / Auto Speed", 0));
        rFS->setText(QApplication::translate("MainWindow", "Full synchronized", 0));
        endless_check->setText(QApplication::translate("MainWindow", "Endless Test", 0));
        rAS_MS->setText(QApplication::translate("MainWindow", "Auto steering / Manual Speed", 0));
        rFT_SS->setText(QApplication::translate("MainWindow", "Follow Target / Speed synchronized", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
