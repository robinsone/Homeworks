/********************************************************************************
** Form generated from reading UI file 'uigtc.ui'
**
** Created: Tue Mar 29 04:53:40 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIGTC_H
#define UI_UIGTC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_uigtc
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QGroupBox *groupBox_5;
    QLabel *label_16;
    QLineEdit *DelayedMins;
    QPushButton *okDelayFlight;
    QLabel *label_17;
    QComboBox *DelayFlightId;
    QGroupBox *groupBox_4;
    QLabel *label_34;
    QPushButton *btn_unallocate;
    QComboBox *comboBox_gateUn;
    QListWidget *list_unallocate;
    QGroupBox *groupBox_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_22;
    QPushButton *btn_allocateInc;
    QLabel *label_23;
    QComboBox *comboBox_aidInc;
    QComboBox *comboBox_gateInc;
    QListWidget *list_typesInc;
    QLabel *label_9;
    QLabel *lb_aidInc;
    QLabel *label_6;
    QLabel *Label3;
    QLabel *lb_Origin;
    QLabel *lb_arrival;
    QLabel *lb_atInc;
    QLabel *Label2;
    QWidget *tab_2;
    QPushButton *btn_allocateOut;
    QLabel *label_32;
    QLabel *label_33;
    QComboBox *comboBox_aidOut;
    QLabel *label;
    QListWidget *list_typesOut;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *lb_aid;
    QLabel *lb_at;
    QLabel *lb_dest;
    QLabel *lb_dep;
    QComboBox *comboBox_gateOut;
    QRadioButton *buttonUnscheduled;
    QRadioButton *buttonScheduled;
    QPushButton *Logout;

    void setupUi(QMainWindow *uigtc)
    {
        if (uigtc->objectName().isEmpty())
            uigtc->setObjectName(QString::fromUtf8("uigtc"));
        uigtc->resize(550, 492);
        centralwidget = new QWidget(uigtc);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 531, 441));
        groupBox->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(270, 230, 241, 131));
        groupBox_5->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        label_16 = new QLabel(groupBox_5);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 57, 131, 19));
        DelayedMins = new QLineEdit(groupBox_5);
        DelayedMins->setObjectName(QString::fromUtf8("DelayedMins"));
        DelayedMins->setGeometry(QRect(130, 51, 91, 29));
        okDelayFlight = new QPushButton(groupBox_5);
        okDelayFlight->setObjectName(QString::fromUtf8("okDelayFlight"));
        okDelayFlight->setGeometry(QRect(90, 87, 61, 31));
        label_17 = new QLabel(groupBox_5);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(70, 30, 101, 19));
        DelayFlightId = new QComboBox(groupBox_5);
        DelayFlightId->setObjectName(QString::fromUtf8("DelayFlightId"));
        DelayFlightId->setGeometry(QRect(130, 25, 91, 27));
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(270, 20, 241, 201));
        groupBox_4->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 0, 0);"));
        label_34 = new QLabel(groupBox_4);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(20, 20, 51, 19));
        btn_unallocate = new QPushButton(groupBox_4);
        btn_unallocate->setObjectName(QString::fromUtf8("btn_unallocate"));
        btn_unallocate->setGeometry(QRect(80, 160, 80, 29));
        comboBox_gateUn = new QComboBox(groupBox_4);
        comboBox_gateUn->setObjectName(QString::fromUtf8("comboBox_gateUn"));
        comboBox_gateUn->setGeometry(QRect(98, 20, 131, 22));
        list_unallocate = new QListWidget(groupBox_4);
        list_unallocate->setObjectName(QString::fromUtf8("list_unallocate"));
        list_unallocate->setGeometry(QRect(20, 50, 211, 101));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 20, 211, 411));
        groupBox_2->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 0, 0);"));
        tabWidget = new QTabWidget(groupBox_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 50, 191, 351));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_22 = new QLabel(tab);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 150, 51, 20));
        btn_allocateInc = new QPushButton(tab);
        btn_allocateInc->setObjectName(QString::fromUtf8("btn_allocateInc"));
        btn_allocateInc->setGeometry(QRect(50, 290, 80, 29));
        label_23 = new QLabel(tab);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(10, 10, 51, 21));
        comboBox_aidInc = new QComboBox(tab);
        comboBox_aidInc->setObjectName(QString::fromUtf8("comboBox_aidInc"));
        comboBox_aidInc->setGeometry(QRect(80, 150, 101, 21));
        comboBox_gateInc = new QComboBox(tab);
        comboBox_gateInc->setObjectName(QString::fromUtf8("comboBox_gateInc"));
        comboBox_gateInc->setGeometry(QRect(70, 10, 111, 21));
        list_typesInc = new QListWidget(tab);
        list_typesInc->setObjectName(QString::fromUtf8("list_typesInc"));
        list_typesInc->setGeometry(QRect(10, 40, 161, 101));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 220, 61, 16));
        lb_aidInc = new QLabel(tab);
        lb_aidInc->setObjectName(QString::fromUtf8("lb_aidInc"));
        lb_aidInc->setGeometry(QRect(130, 180, 46, 13));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 240, 81, 16));
        Label3 = new QLabel(tab);
        Label3->setObjectName(QString::fromUtf8("Label3"));
        Label3->setGeometry(QRect(10, 200, 71, 16));
        lb_Origin = new QLabel(tab);
        lb_Origin->setObjectName(QString::fromUtf8("lb_Origin"));
        lb_Origin->setGeometry(QRect(130, 220, 46, 13));
        lb_arrival = new QLabel(tab);
        lb_arrival->setObjectName(QString::fromUtf8("lb_arrival"));
        lb_arrival->setGeometry(QRect(130, 240, 46, 13));
        lb_atInc = new QLabel(tab);
        lb_atInc->setObjectName(QString::fromUtf8("lb_atInc"));
        lb_atInc->setGeometry(QRect(130, 200, 46, 13));
        Label2 = new QLabel(tab);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(10, 180, 50, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        btn_allocateOut = new QPushButton(tab_2);
        btn_allocateOut->setObjectName(QString::fromUtf8("btn_allocateOut"));
        btn_allocateOut->setGeometry(QRect(50, 290, 80, 29));
        label_32 = new QLabel(tab_2);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(10, 10, 51, 21));
        label_33 = new QLabel(tab_2);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(10, 150, 51, 20));
        comboBox_aidOut = new QComboBox(tab_2);
        comboBox_aidOut->setObjectName(QString::fromUtf8("comboBox_aidOut"));
        comboBox_aidOut->setGeometry(QRect(80, 150, 101, 21));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 40, 101, 20));
        list_typesOut = new QListWidget(tab_2);
        list_typesOut->setObjectName(QString::fromUtf8("list_typesOut"));
        list_typesOut->setGeometry(QRect(10, 40, 161, 101));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 180, 50, 16));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 200, 71, 16));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 220, 61, 16));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 240, 81, 16));
        lb_aid = new QLabel(tab_2);
        lb_aid->setObjectName(QString::fromUtf8("lb_aid"));
        lb_aid->setGeometry(QRect(130, 180, 46, 13));
        lb_at = new QLabel(tab_2);
        lb_at->setObjectName(QString::fromUtf8("lb_at"));
        lb_at->setGeometry(QRect(130, 200, 46, 13));
        lb_dest = new QLabel(tab_2);
        lb_dest->setObjectName(QString::fromUtf8("lb_dest"));
        lb_dest->setGeometry(QRect(130, 220, 46, 13));
        lb_dep = new QLabel(tab_2);
        lb_dep->setObjectName(QString::fromUtf8("lb_dep"));
        lb_dep->setGeometry(QRect(130, 240, 46, 13));
        comboBox_gateOut = new QComboBox(tab_2);
        comboBox_gateOut->setObjectName(QString::fromUtf8("comboBox_gateOut"));
        comboBox_gateOut->setGeometry(QRect(80, 10, 85, 27));
        tabWidget->addTab(tab_2, QString());
        buttonUnscheduled = new QRadioButton(groupBox_2);
        buttonUnscheduled->setObjectName(QString::fromUtf8("buttonUnscheduled"));
        buttonUnscheduled->setGeometry(QRect(100, 20, 91, 25));
        buttonScheduled = new QRadioButton(groupBox_2);
        buttonScheduled->setObjectName(QString::fromUtf8("buttonScheduled"));
        buttonScheduled->setGeometry(QRect(10, 20, 81, 25));
        Logout = new QPushButton(groupBox);
        Logout->setObjectName(QString::fromUtf8("Logout"));
        Logout->setGeometry(QRect(310, 370, 211, 61));
        uigtc->setCentralWidget(centralwidget);

        retranslateUi(uigtc);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(uigtc);
    } // setupUi

    void retranslateUi(QMainWindow *uigtc)
    {
        uigtc->setWindowTitle(QApplication::translate("uigtc", "MainWindow", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("uigtc", "Ground Traffic Controller", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("uigtc", "Report Delay", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("uigtc", "Delayed (mins):", 0, QApplication::UnicodeUTF8));
        okDelayFlight->setText(QApplication::translate("uigtc", "OK", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("uigtc", "Flight \342\200\217ID:", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("uigtc", "Reallocate Stand", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("uigtc", "Gate:", 0, QApplication::UnicodeUTF8));
        btn_unallocate->setText(QApplication::translate("uigtc", "Unallocate", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("uigtc", "Allocate Stand", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QApplication::translate("uigtc", "Employee", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_22->setText(QApplication::translate("uigtc", "Flight ID:", 0, QApplication::UnicodeUTF8));
        btn_allocateInc->setText(QApplication::translate("uigtc", "Allocate", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("uigtc", "Gate:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("uigtc", "Origin", 0, QApplication::UnicodeUTF8));
        lb_aidInc->setText(QString());
        label_6->setText(QApplication::translate("uigtc", "Arrival Time", 0, QApplication::UnicodeUTF8));
        Label3->setText(QApplication::translate("uigtc", "Aircraft Type", 0, QApplication::UnicodeUTF8));
        lb_Origin->setText(QString());
        lb_arrival->setText(QString());
        lb_atInc->setText(QString());
        Label2->setText(QApplication::translate("uigtc", "Aircraft ID", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("uigtc", "Incoming", 0, QApplication::UnicodeUTF8));
        btn_allocateOut->setText(QApplication::translate("uigtc", "Allocate", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("uigtc", "Gate:", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("uigtc", "Flight ID:", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QApplication::translate("uigtc", "Aircraft ID", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("uigtc", "Aircraft Type", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("uigtc", "Destination", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("uigtc", "Departure Time", 0, QApplication::UnicodeUTF8));
        lb_aid->setText(QString());
        lb_at->setText(QString());
        lb_dest->setText(QString());
        lb_dep->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("uigtc", "Outgoing", 0, QApplication::UnicodeUTF8));
        buttonUnscheduled->setText(QApplication::translate("uigtc", "Unscheduled", 0, QApplication::UnicodeUTF8));
        buttonScheduled->setText(QApplication::translate("uigtc", "Scheduled", 0, QApplication::UnicodeUTF8));
        Logout->setText(QApplication::translate("uigtc", "LOGOUT", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class uigtc: public Ui_uigtc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIGTC_H
