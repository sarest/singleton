/********************************************************************************
** Form generated from reading UI file 'windowtarget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWTARGET_H
#define UI_WINDOWTARGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowTarget
{
public:
    QAction *actionMax_acceleration_in_m_s2;
    QWidget *centralwidget;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *target_name;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *bLoad;
    QPushButton *bSave;
    QGridLayout *view_layout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *start_velocity;
    QLabel *label_11;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTabWidget *tabWidget;
    QWidget *straight_tab;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLineEdit *straight_velocity;
    QLineEdit *straight_length;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *straight_acceleration;
    QGridLayout *gridLayout_2;
    QRadioButton *rAcceleration_straight;
    QRadioButton *rVelocity_straight;
    QPushButton *bConfirm_straight;
    QLabel *invalid_segment_label;
    QWidget *curve_tab;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QLineEdit *curve_acceleration;
    QLineEdit *curve_angle;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *curve_radius;
    QLabel *label_10;
    QLineEdit *curve_velocity;
    QGridLayout *gridLayout_4;
    QRadioButton *rAcceleration_curve;
    QRadioButton *rVelocity_curve;
    QPushButton *bConfirm_curve;
    QLabel *invalid_segment_label_curve;
    QPushButton *bClearTable;
    QPushButton *bDeleteLast;
    QGridLayout *table_layout;
    QMenuBar *menubar;
    QMenu *menuSet_Path;
    QMenu *menuCrashpoint;
    QMenu *menuLimitations;
    QMenu *menuMax_velocity_in_km_h;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WindowTarget)
    {
        if (WindowTarget->objectName().isEmpty())
            WindowTarget->setObjectName(QStringLiteral("WindowTarget"));
        WindowTarget->resize(1062, 652);
        actionMax_acceleration_in_m_s2 = new QAction(WindowTarget);
        actionMax_acceleration_in_m_s2->setObjectName(QStringLiteral("actionMax_acceleration_in_m_s2"));
        centralwidget = new QWidget(WindowTarget);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_7 = new QGridLayout(centralwidget);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        target_name = new QLineEdit(centralwidget);
        target_name->setObjectName(QStringLiteral("target_name"));

        horizontalLayout->addWidget(target_name);


        gridLayout_7->addLayout(horizontalLayout, 0, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        bLoad = new QPushButton(centralwidget);
        bLoad->setObjectName(QStringLiteral("bLoad"));

        horizontalLayout_2->addWidget(bLoad);

        bSave = new QPushButton(centralwidget);
        bSave->setObjectName(QStringLiteral("bSave"));

        horizontalLayout_2->addWidget(bSave);


        gridLayout_7->addLayout(horizontalLayout_2, 0, 2, 1, 1);

        view_layout = new QGridLayout();
        view_layout->setObjectName(QStringLiteral("view_layout"));

        gridLayout_7->addLayout(view_layout, 0, 3, 4, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        start_velocity = new QLineEdit(centralwidget);
        start_velocity->setObjectName(QStringLiteral("start_velocity"));

        horizontalLayout_3->addWidget(start_velocity);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_3->addWidget(label_11);


        gridLayout_7->addLayout(horizontalLayout_3, 1, 0, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        straight_tab = new QWidget();
        straight_tab->setObjectName(QStringLiteral("straight_tab"));
        gridLayout_3 = new QGridLayout(straight_tab);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        straight_velocity = new QLineEdit(straight_tab);
        straight_velocity->setObjectName(QStringLiteral("straight_velocity"));

        gridLayout->addWidget(straight_velocity, 2, 1, 1, 1);

        straight_length = new QLineEdit(straight_tab);
        straight_length->setObjectName(QStringLiteral("straight_length"));

        gridLayout->addWidget(straight_length, 0, 1, 1, 1);

        label_5 = new QLabel(straight_tab);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_4 = new QLabel(straight_tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(straight_tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        straight_acceleration = new QLineEdit(straight_tab);
        straight_acceleration->setObjectName(QStringLiteral("straight_acceleration"));

        gridLayout->addWidget(straight_acceleration, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        rAcceleration_straight = new QRadioButton(straight_tab);
        rAcceleration_straight->setObjectName(QStringLiteral("rAcceleration_straight"));
        rAcceleration_straight->setChecked(true);

        gridLayout_2->addWidget(rAcceleration_straight, 0, 0, 1, 1);

        rVelocity_straight = new QRadioButton(straight_tab);
        rVelocity_straight->setObjectName(QStringLiteral("rVelocity_straight"));

        gridLayout_2->addWidget(rVelocity_straight, 1, 0, 1, 1);

        bConfirm_straight = new QPushButton(straight_tab);
        bConfirm_straight->setObjectName(QStringLiteral("bConfirm_straight"));

        gridLayout_2->addWidget(bConfirm_straight, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        invalid_segment_label = new QLabel(straight_tab);
        invalid_segment_label->setObjectName(QStringLiteral("invalid_segment_label"));
        invalid_segment_label->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        invalid_segment_label->setFont(font);
        invalid_segment_label->setStyleSheet(QStringLiteral("color:red;"));
        invalid_segment_label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(invalid_segment_label, 1, 0, 1, 2);

        tabWidget->addTab(straight_tab, QString());
        curve_tab = new QWidget();
        curve_tab->setObjectName(QStringLiteral("curve_tab"));
        gridLayout_6 = new QGridLayout(curve_tab);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        curve_acceleration = new QLineEdit(curve_tab);
        curve_acceleration->setObjectName(QStringLiteral("curve_acceleration"));

        gridLayout_5->addWidget(curve_acceleration, 2, 1, 1, 1);

        curve_angle = new QLineEdit(curve_tab);
        curve_angle->setObjectName(QStringLiteral("curve_angle"));

        gridLayout_5->addWidget(curve_angle, 0, 1, 1, 1);

        label_7 = new QLabel(curve_tab);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_5->addWidget(label_7, 2, 0, 1, 1);

        label_8 = new QLabel(curve_tab);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_5->addWidget(label_8, 1, 0, 1, 1);

        label_9 = new QLabel(curve_tab);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_5->addWidget(label_9, 0, 0, 1, 1);

        curve_radius = new QLineEdit(curve_tab);
        curve_radius->setObjectName(QStringLiteral("curve_radius"));

        gridLayout_5->addWidget(curve_radius, 1, 1, 1, 1);

        label_10 = new QLabel(curve_tab);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_5->addWidget(label_10, 3, 0, 1, 1);

        curve_velocity = new QLineEdit(curve_tab);
        curve_velocity->setObjectName(QStringLiteral("curve_velocity"));

        gridLayout_5->addWidget(curve_velocity, 3, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        rAcceleration_curve = new QRadioButton(curve_tab);
        rAcceleration_curve->setObjectName(QStringLiteral("rAcceleration_curve"));
        rAcceleration_curve->setChecked(true);

        gridLayout_4->addWidget(rAcceleration_curve, 0, 0, 1, 1);

        rVelocity_curve = new QRadioButton(curve_tab);
        rVelocity_curve->setObjectName(QStringLiteral("rVelocity_curve"));

        gridLayout_4->addWidget(rVelocity_curve, 1, 0, 1, 1);

        bConfirm_curve = new QPushButton(curve_tab);
        bConfirm_curve->setObjectName(QStringLiteral("bConfirm_curve"));

        gridLayout_4->addWidget(bConfirm_curve, 2, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_4, 0, 0, 1, 1);

        invalid_segment_label_curve = new QLabel(curve_tab);
        invalid_segment_label_curve->setObjectName(QStringLiteral("invalid_segment_label_curve"));
        invalid_segment_label_curve->setMaximumSize(QSize(16777215, 40));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        invalid_segment_label_curve->setFont(font1);
        invalid_segment_label_curve->setStyleSheet(QStringLiteral("color:red;"));
        invalid_segment_label_curve->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(invalid_segment_label_curve, 1, 0, 1, 2);

        tabWidget->addTab(curve_tab, QString());

        verticalLayout->addWidget(tabWidget);


        gridLayout_7->addLayout(verticalLayout, 2, 0, 1, 3);

        bClearTable = new QPushButton(centralwidget);
        bClearTable->setObjectName(QStringLiteral("bClearTable"));

        gridLayout_7->addWidget(bClearTable, 3, 0, 1, 1);

        bDeleteLast = new QPushButton(centralwidget);
        bDeleteLast->setObjectName(QStringLiteral("bDeleteLast"));

        gridLayout_7->addWidget(bDeleteLast, 3, 1, 1, 1);

        table_layout = new QGridLayout();
        table_layout->setObjectName(QStringLiteral("table_layout"));
        table_layout->setSizeConstraint(QLayout::SetDefaultConstraint);

        gridLayout_7->addLayout(table_layout, 4, 0, 1, 4);

        WindowTarget->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WindowTarget);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1062, 20));
        menuSet_Path = new QMenu(menubar);
        menuSet_Path->setObjectName(QStringLiteral("menuSet_Path"));
        menuCrashpoint = new QMenu(menubar);
        menuCrashpoint->setObjectName(QStringLiteral("menuCrashpoint"));
        menuLimitations = new QMenu(menubar);
        menuLimitations->setObjectName(QStringLiteral("menuLimitations"));
        menuMax_velocity_in_km_h = new QMenu(menuLimitations);
        menuMax_velocity_in_km_h->setObjectName(QStringLiteral("menuMax_velocity_in_km_h"));
        WindowTarget->setMenuBar(menubar);
        statusbar = new QStatusBar(WindowTarget);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WindowTarget->setStatusBar(statusbar);
        QWidget::setTabOrder(target_name, start_velocity);
        QWidget::setTabOrder(start_velocity, straight_length);
        QWidget::setTabOrder(straight_length, straight_acceleration);
        QWidget::setTabOrder(straight_acceleration, straight_velocity);
        QWidget::setTabOrder(straight_velocity, curve_angle);
        QWidget::setTabOrder(curve_angle, curve_radius);
        QWidget::setTabOrder(curve_radius, curve_acceleration);
        QWidget::setTabOrder(curve_acceleration, curve_velocity);
        QWidget::setTabOrder(curve_velocity, rAcceleration_curve);
        QWidget::setTabOrder(rAcceleration_curve, rVelocity_curve);
        QWidget::setTabOrder(rVelocity_curve, bConfirm_curve);
        QWidget::setTabOrder(bConfirm_curve, rVelocity_straight);
        QWidget::setTabOrder(rVelocity_straight, tabWidget);
        QWidget::setTabOrder(tabWidget, rAcceleration_straight);
        QWidget::setTabOrder(rAcceleration_straight, bConfirm_straight);
        QWidget::setTabOrder(bConfirm_straight, bLoad);
        QWidget::setTabOrder(bLoad, bClearTable);
        QWidget::setTabOrder(bClearTable, bDeleteLast);
        QWidget::setTabOrder(bDeleteLast, bSave);

        menubar->addAction(menuSet_Path->menuAction());
        menubar->addAction(menuCrashpoint->menuAction());
        menubar->addAction(menuLimitations->menuAction());
        menuLimitations->addAction(actionMax_acceleration_in_m_s2);
        menuLimitations->addAction(menuMax_velocity_in_km_h->menuAction());

        retranslateUi(WindowTarget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WindowTarget);
    } // setupUi

    void retranslateUi(QMainWindow *WindowTarget)
    {
        WindowTarget->setWindowTitle(QApplication::translate("WindowTarget", "Create Target", 0));
        actionMax_acceleration_in_m_s2->setText(QApplication::translate("WindowTarget", "Max. acceleration in m/s2 ", 0));
        label->setText(QApplication::translate("WindowTarget", "Target Name", 0));
        bLoad->setText(QApplication::translate("WindowTarget", "LOAD", 0));
        bSave->setText(QApplication::translate("WindowTarget", "SAVE", 0));
        label_6->setText(QApplication::translate("WindowTarget", "Start Velocity", 0));
        start_velocity->setText(QApplication::translate("WindowTarget", "0", 0));
        label_11->setText(QApplication::translate("WindowTarget", "km/h", 0));
        label_2->setText(QApplication::translate("WindowTarget", "Segment Type", 0));
        label_5->setText(QApplication::translate("WindowTarget", "End velocity in km/h", 0));
        label_4->setText(QApplication::translate("WindowTarget", "Acceleration in m/s2", 0));
        label_3->setText(QApplication::translate("WindowTarget", "Length in m", 0));
        rAcceleration_straight->setText(QApplication::translate("WindowTarget", "Acceleration", 0));
        rVelocity_straight->setText(QApplication::translate("WindowTarget", "Velocity", 0));
        bConfirm_straight->setText(QApplication::translate("WindowTarget", "CONFIRM", 0));
        invalid_segment_label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(straight_tab), QApplication::translate("WindowTarget", "Straight", 0));
        label_7->setText(QApplication::translate("WindowTarget", "Acceleration in m/s2", 0));
        label_8->setText(QApplication::translate("WindowTarget", "Radius in m", 0));
        label_9->setText(QApplication::translate("WindowTarget", "Angle in degree", 0));
        label_10->setText(QApplication::translate("WindowTarget", "End velocity in km/h", 0));
        rAcceleration_curve->setText(QApplication::translate("WindowTarget", "Acceleration", 0));
        rVelocity_curve->setText(QApplication::translate("WindowTarget", "Velocity", 0));
        bConfirm_curve->setText(QApplication::translate("WindowTarget", "CONFIRM", 0));
        invalid_segment_label_curve->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(curve_tab), QApplication::translate("WindowTarget", "Curve", 0));
        bClearTable->setText(QApplication::translate("WindowTarget", "Clear Target", 0));
        bDeleteLast->setText(QApplication::translate("WindowTarget", "Remove Last", 0));
        menuSet_Path->setTitle(QApplication::translate("WindowTarget", "Set Path", 0));
        menuCrashpoint->setTitle(QApplication::translate("WindowTarget", "Crashpoint", 0));
        menuLimitations->setTitle(QApplication::translate("WindowTarget", "Limitations", 0));
        menuMax_velocity_in_km_h->setTitle(QApplication::translate("WindowTarget", "Max. velocity in km/h", 0));
    } // retranslateUi

};

namespace Ui {
    class WindowTarget: public Ui_WindowTarget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWTARGET_H
