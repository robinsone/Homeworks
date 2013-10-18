/********************************************************************************
** Form generated from reading UI file 'uiairlinerep.ui'
**
** Created: Tue Mar 29 02:30:28 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIAIRLINEREP_H
#define UI_UIAIRLINEREP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTimeEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_uiairlinerep
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QGroupBox *groupBox_5;
    QTabWidget *tabWidget_2;
    QWidget *tab_7;
    QLabel *label_53;
    QLabel *label_54;
    QLabel *label_55;
    QLineEdit *exceptInSource;
    QLabel *label_19;
    QComboBox *exceptInFlightID;
    QLineEdit *exceptInAircraftID;
    QPushButton *exceptInUpdate;
    QPushButton *inCancel;
    QLineEdit *exceptInDelay;
    QWidget *tab_8;
    QLabel *label_58;
    QLabel *label_59;
    QLineEdit *exceptOutDestination;
    QComboBox *exceptOutFlightID;
    QLabel *label;
    QLineEdit *exceptOutAircraftID;
    QPushButton *exceptOutUpdate;
    QPushButton *outCancel;
    QLabel *label_56;
    QLineEdit *exceptOutDelay;
    QGroupBox *groupBox_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QRadioButton *reqInWeekly;
    QRadioButton *reqInOne;
    QRadioButton *reqInDaily;
    QLabel *label_28;
    QLabel *label_26;
    QLabel *label_29;
    QLineEdit *reqInFlightID;
    QLabel *label_30;
    QLabel *label_31;
    QPushButton *reqInSubmit;
    QLabel *label_9;
    QLabel *label_10;
    QDateEdit *reqInDate;
    QComboBox *reqInDay;
    QComboBox *reqInSource;
    QTimeEdit *reqInGate;
    QTimeEdit *reqInLand;
    QComboBox *FlightRequestAircraft;
    QWidget *tab_2;
    QRadioButton *reqOutWeekly;
    QRadioButton *reqOutOne;
    QRadioButton *reqOutDaily;
    QLabel *label_27;
    QLabel *label_23;
    QLabel *label_22;
    QLabel *label_24;
    QLabel *label_25;
    QLineEdit *reqOutFlightID;
    QPushButton *reqOutSubmit;
    QDateEdit *reqOutDate;
    QComboBox *reqOutDay;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *reqOutDestination;
    QTimeEdit *reqOutGate;
    QTimeEdit *reqOutTakeOff;
    QComboBox *FlightRequestAircraft_2;
    QGroupBox *groupBox_4;
    QPushButton *editaircraftid;
    QComboBox *cbaircraftid;
    QListWidget *aircraftlist;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *newAircraftID;
    QLabel *label_4;
    QComboBox *deleteAircraftcomboBox;
    QPushButton *deleteAircraft;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *AircraftIdlineEdit;
    QComboBox *aircrafttypeid;
    QLineEdit *AircraftStatuslineEdit;
    QPushButton *addAircraft;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *pushButton_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *uiairlinerep)
    {
        if (uiairlinerep->objectName().isEmpty())
            uiairlinerep->setObjectName(QString::fromUtf8("uiairlinerep"));
        uiairlinerep->resize(995, 648);
        centralwidget = new QWidget(uiairlinerep);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 961, 591));
        groupBox->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(360, 30, 321, 281));
        groupBox_5->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        tabWidget_2 = new QTabWidget(groupBox_5);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(20, 20, 281, 251));
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        label_53 = new QLabel(tab_7);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(45, 42, 101, 19));
        label_54 = new QLabel(tab_7);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setGeometry(QRect(39, 70, 101, 20));
        label_55 = new QLabel(tab_7);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setGeometry(QRect(60, 95, 151, 20));
        exceptInSource = new QLineEdit(tab_7);
        exceptInSource->setObjectName(QString::fromUtf8("exceptInSource"));
        exceptInSource->setGeometry(QRect(155, 64, 113, 29));
        label_19 = new QLabel(tab_7);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(53, 15, 121, 19));
        exceptInFlightID = new QComboBox(tab_7);
        exceptInFlightID->setObjectName(QString::fromUtf8("exceptInFlightID"));
        exceptInFlightID->setGeometry(QRect(156, 10, 111, 27));
        exceptInAircraftID = new QLineEdit(tab_7);
        exceptInAircraftID->setObjectName(QString::fromUtf8("exceptInAircraftID"));
        exceptInAircraftID->setGeometry(QRect(155, 36, 113, 29));
        exceptInUpdate = new QPushButton(tab_7);
        exceptInUpdate->setObjectName(QString::fromUtf8("exceptInUpdate"));
        exceptInUpdate->setGeometry(QRect(70, 137, 131, 29));
        inCancel = new QPushButton(tab_7);
        inCancel->setObjectName(QString::fromUtf8("inCancel"));
        inCancel->setGeometry(QRect(70, 170, 131, 29));
        exceptInDelay = new QLineEdit(tab_7);
        exceptInDelay->setObjectName(QString::fromUtf8("exceptInDelay"));
        exceptInDelay->setGeometry(QRect(155, 93, 113, 20));
        tabWidget_2->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        label_58 = new QLabel(tab_8);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setGeometry(QRect(45, 42, 101, 19));
        label_59 = new QLabel(tab_8);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setGeometry(QRect(17, 70, 131, 20));
        exceptOutDestination = new QLineEdit(tab_8);
        exceptOutDestination->setObjectName(QString::fromUtf8("exceptOutDestination"));
        exceptOutDestination->setGeometry(QRect(155, 64, 113, 29));
        exceptOutFlightID = new QComboBox(tab_8);
        exceptOutFlightID->setObjectName(QString::fromUtf8("exceptOutFlightID"));
        exceptOutFlightID->setGeometry(QRect(156, 10, 111, 27));
        label = new QLabel(tab_8);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(53, 15, 121, 19));
        exceptOutAircraftID = new QLineEdit(tab_8);
        exceptOutAircraftID->setObjectName(QString::fromUtf8("exceptOutAircraftID"));
        exceptOutAircraftID->setGeometry(QRect(155, 36, 113, 29));
        exceptOutUpdate = new QPushButton(tab_8);
        exceptOutUpdate->setObjectName(QString::fromUtf8("exceptOutUpdate"));
        exceptOutUpdate->setGeometry(QRect(70, 137, 131, 29));
        outCancel = new QPushButton(tab_8);
        outCancel->setObjectName(QString::fromUtf8("outCancel"));
        outCancel->setGeometry(QRect(70, 170, 131, 29));
        label_56 = new QLabel(tab_8);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setGeometry(QRect(60, 95, 151, 20));
        exceptOutDelay = new QLineEdit(tab_8);
        exceptOutDelay->setObjectName(QString::fromUtf8("exceptOutDelay"));
        exceptOutDelay->setGeometry(QRect(155, 94, 113, 20));
        tabWidget_2->addTab(tab_8, QString());
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(30, 30, 301, 321));
        tabWidget = new QTabWidget(groupBox_3);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 281, 291));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        reqInWeekly = new QRadioButton(tab);
        reqInWeekly->setObjectName(QString::fromUtf8("reqInWeekly"));
        reqInWeekly->setGeometry(QRect(180, 8, 80, 25));
        reqInOne = new QRadioButton(tab);
        reqInOne->setObjectName(QString::fromUtf8("reqInOne"));
        reqInOne->setGeometry(QRect(30, 8, 90, 25));
        reqInOne->setChecked(true);
        reqInDaily = new QRadioButton(tab);
        reqInDaily->setObjectName(QString::fromUtf8("reqInDaily"));
        reqInDaily->setGeometry(QRect(120, 8, 60, 25));
        label_28 = new QLabel(tab);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(32, 158, 101, 19));
        label_26 = new QLabel(tab);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(45, 74, 101, 19));
        label_29 = new QLabel(tab);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(39, 102, 101, 20));
        reqInFlightID = new QLineEdit(tab);
        reqInFlightID->setObjectName(QString::fromUtf8("reqInFlightID"));
        reqInFlightID->setGeometry(QRect(156, 42, 113, 29));
        label_30 = new QLabel(tab);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(21, 130, 151, 20));
        label_31 = new QLabel(tab);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(53, 46, 101, 19));
        reqInSubmit = new QPushButton(tab);
        reqInSubmit->setObjectName(QString::fromUtf8("reqInSubmit"));
        reqInSubmit->setGeometry(QRect(72, 230, 131, 29));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(57, 185, 46, 13));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(41, 207, 101, 16));
        reqInDate = new QDateEdit(tab);
        reqInDate->setObjectName(QString::fromUtf8("reqInDate"));
        reqInDate->setEnabled(true);
        reqInDate->setGeometry(QRect(156, 181, 110, 22));
        reqInDate->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        reqInDay = new QComboBox(tab);
        reqInDay->setObjectName(QString::fromUtf8("reqInDay"));
        reqInDay->setEnabled(false);
        reqInDay->setGeometry(QRect(156, 204, 69, 22));
        reqInDay->setEditable(false);
        reqInSource = new QComboBox(tab);
        reqInSource->setObjectName(QString::fromUtf8("reqInSource"));
        reqInSource->setGeometry(QRect(157, 100, 69, 20));
        reqInGate = new QTimeEdit(tab);
        reqInGate->setObjectName(QString::fromUtf8("reqInGate"));
        reqInGate->setGeometry(QRect(156, 128, 118, 22));
        reqInLand = new QTimeEdit(tab);
        reqInLand->setObjectName(QString::fromUtf8("reqInLand"));
        reqInLand->setGeometry(QRect(156, 155, 118, 22));
        FlightRequestAircraft = new QComboBox(tab);
        FlightRequestAircraft->setObjectName(QString::fromUtf8("FlightRequestAircraft"));
        FlightRequestAircraft->setGeometry(QRect(157, 74, 69, 22));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        reqOutWeekly = new QRadioButton(tab_2);
        buttonGroup = new QButtonGroup(uiairlinerep);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(reqOutWeekly);
        reqOutWeekly->setObjectName(QString::fromUtf8("reqOutWeekly"));
        reqOutWeekly->setGeometry(QRect(180, 8, 80, 25));
        reqOutOne = new QRadioButton(tab_2);
        buttonGroup->addButton(reqOutOne);
        reqOutOne->setObjectName(QString::fromUtf8("reqOutOne"));
        reqOutOne->setGeometry(QRect(30, 8, 90, 25));
        reqOutOne->setChecked(true);
        reqOutDaily = new QRadioButton(tab_2);
        buttonGroup->addButton(reqOutDaily);
        reqOutDaily->setObjectName(QString::fromUtf8("reqOutDaily"));
        reqOutDaily->setGeometry(QRect(120, 8, 60, 25));
        label_27 = new QLabel(tab_2);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(32, 158, 101, 19));
        label_23 = new QLabel(tab_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(45, 74, 101, 19));
        label_22 = new QLabel(tab_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(17, 102, 131, 20));
        label_24 = new QLabel(tab_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 130, 151, 20));
        label_25 = new QLabel(tab_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(53, 46, 101, 19));
        reqOutFlightID = new QLineEdit(tab_2);
        reqOutFlightID->setObjectName(QString::fromUtf8("reqOutFlightID"));
        reqOutFlightID->setGeometry(QRect(156, 42, 113, 29));
        reqOutSubmit = new QPushButton(tab_2);
        reqOutSubmit->setObjectName(QString::fromUtf8("reqOutSubmit"));
        reqOutSubmit->setGeometry(QRect(72, 230, 131, 29));
        reqOutDate = new QDateEdit(tab_2);
        reqOutDate->setObjectName(QString::fromUtf8("reqOutDate"));
        reqOutDate->setGeometry(QRect(155, 181, 110, 22));
        reqOutDay = new QComboBox(tab_2);
        reqOutDay->setObjectName(QString::fromUtf8("reqOutDay"));
        reqOutDay->setEnabled(false);
        reqOutDay->setGeometry(QRect(155, 204, 69, 22));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(56, 185, 46, 13));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 207, 101, 16));
        reqOutDestination = new QComboBox(tab_2);
        reqOutDestination->setObjectName(QString::fromUtf8("reqOutDestination"));
        reqOutDestination->setGeometry(QRect(156, 99, 69, 22));
        reqOutGate = new QTimeEdit(tab_2);
        reqOutGate->setObjectName(QString::fromUtf8("reqOutGate"));
        reqOutGate->setGeometry(QRect(155, 129, 118, 22));
        reqOutTakeOff = new QTimeEdit(tab_2);
        reqOutTakeOff->setObjectName(QString::fromUtf8("reqOutTakeOff"));
        reqOutTakeOff->setGeometry(QRect(155, 156, 118, 22));
        FlightRequestAircraft_2 = new QComboBox(tab_2);
        FlightRequestAircraft_2->setObjectName(QString::fromUtf8("FlightRequestAircraft_2"));
        FlightRequestAircraft_2->setGeometry(QRect(156, 73, 69, 22));
        tabWidget->addTab(tab_2, QString());
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(30, 360, 451, 221));
        editaircraftid = new QPushButton(groupBox_4);
        editaircraftid->setObjectName(QString::fromUtf8("editaircraftid"));
        editaircraftid->setGeometry(QRect(350, 90, 80, 29));
        cbaircraftid = new QComboBox(groupBox_4);
        cbaircraftid->setObjectName(QString::fromUtf8("cbaircraftid"));
        cbaircraftid->setGeometry(QRect(280, 30, 151, 27));
        aircraftlist = new QListWidget(groupBox_4);
        aircraftlist->setObjectName(QString::fromUtf8("aircraftlist"));
        aircraftlist->setGeometry(QRect(10, 20, 256, 192));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(280, 10, 121, 17));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 60, 41, 17));
        newAircraftID = new QLineEdit(groupBox_4);
        newAircraftID->setObjectName(QString::fromUtf8("newAircraftID"));
        newAircraftID->setGeometry(QRect(320, 60, 113, 27));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(490, 370, 111, 17));
        deleteAircraftcomboBox = new QComboBox(groupBox);
        deleteAircraftcomboBox->setObjectName(QString::fromUtf8("deleteAircraftcomboBox"));
        deleteAircraftcomboBox->setGeometry(QRect(490, 390, 141, 27));
        deleteAircraft = new QPushButton(groupBox);
        deleteAircraft->setObjectName(QString::fromUtf8("deleteAircraft"));
        deleteAircraft->setGeometry(QRect(530, 420, 98, 27));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(660, 370, 101, 17));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(680, 390, 21, 20));
        AircraftIdlineEdit = new QLineEdit(groupBox);
        AircraftIdlineEdit->setObjectName(QString::fromUtf8("AircraftIdlineEdit"));
        AircraftIdlineEdit->setGeometry(QRect(720, 390, 113, 27));
        aircrafttypeid = new QComboBox(groupBox);
        aircrafttypeid->setObjectName(QString::fromUtf8("aircrafttypeid"));
        aircrafttypeid->setGeometry(QRect(700, 450, 131, 27));
        AircraftStatuslineEdit = new QLineEdit(groupBox);
        AircraftStatuslineEdit->setObjectName(QString::fromUtf8("AircraftStatuslineEdit"));
        AircraftStatuslineEdit->setGeometry(QRect(720, 420, 113, 27));
        addAircraft = new QPushButton(groupBox);
        addAircraft->setObjectName(QString::fromUtf8("addAircraft"));
        addAircraft->setGeometry(QRect(730, 480, 98, 27));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(650, 450, 67, 17));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(650, 420, 67, 17));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(750, 30, 181, 91));
        uiairlinerep->setCentralWidget(centralwidget);
        menubar = new QMenuBar(uiairlinerep);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 995, 25));
        uiairlinerep->setMenuBar(menubar);
        statusbar = new QStatusBar(uiairlinerep);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        uiairlinerep->setStatusBar(statusbar);

        retranslateUi(uiairlinerep);

        tabWidget_2->setCurrentIndex(1);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(uiairlinerep);
    } // setupUi

    void retranslateUi(QMainWindow *uiairlinerep)
    {
        uiairlinerep->setWindowTitle(QApplication::translate("uiairlinerep", "MainWindow", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("uiairlinerep", "Airline Representative", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("uiairlinerep", "Issue an Exception", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tabWidget_2->setToolTip(QApplication::translate("uiairlinerep", "Employee", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_53->setText(QApplication::translate("uiairlinerep", "Aircraft \342\200\217ID:", 0, QApplication::UnicodeUTF8));
        label_54->setText(QApplication::translate("uiairlinerep", "Source Airport:", 0, QApplication::UnicodeUTF8));
        label_55->setText(QApplication::translate("uiairlinerep", "Delay:", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("uiairlinerep", "Flight \342\200\217ID:", 0, QApplication::UnicodeUTF8));
        exceptInUpdate->setText(QApplication::translate("uiairlinerep", "Update", 0, QApplication::UnicodeUTF8));
        inCancel->setText(QApplication::translate("uiairlinerep", "Cancel Flight", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("uiairlinerep", "Incoming", 0, QApplication::UnicodeUTF8));
        label_58->setText(QApplication::translate("uiairlinerep", "Aircraft \342\200\217ID:", 0, QApplication::UnicodeUTF8));
        label_59->setText(QApplication::translate("uiairlinerep", "Destination Airport:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("uiairlinerep", "Flight \342\200\217ID:", 0, QApplication::UnicodeUTF8));
        exceptOutUpdate->setText(QApplication::translate("uiairlinerep", "Update", 0, QApplication::UnicodeUTF8));
        outCancel->setText(QApplication::translate("uiairlinerep", "Cancel Flight", 0, QApplication::UnicodeUTF8));
        label_56->setText(QApplication::translate("uiairlinerep", "Delay:", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QApplication::translate("uiairlinerep", "Outgoing", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("uiairlinerep", "Schedule a Flight Request", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QApplication::translate("uiairlinerep", "Employee", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        reqInWeekly->setText(QApplication::translate("uiairlinerep", "Weekly", 0, QApplication::UnicodeUTF8));
        reqInOne->setText(QApplication::translate("uiairlinerep", "One-Time", 0, QApplication::UnicodeUTF8));
        reqInDaily->setText(QApplication::translate("uiairlinerep", "Daily", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("uiairlinerep", "Landing Time:", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("uiairlinerep", "Aircraft \342\200\217ID:", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("uiairlinerep", "Source Airport:", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("uiairlinerep", "Gate Arrival Time:", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("uiairlinerep", "Flight ID:", 0, QApplication::UnicodeUTF8));
        reqInSubmit->setText(QApplication::translate("uiairlinerep", "Submit Request", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("uiairlinerep", "Date:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("uiairlinerep", "Day of the week:", 0, QApplication::UnicodeUTF8));
        reqInDay->clear();
        reqInDay->insertItems(0, QStringList()
         << QApplication::translate("uiairlinerep", "Monday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("uiairlinerep", "Tuesday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("uiairlinerep", "Wednesday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("uiairlinerep", "Thursday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("uiairlinerep", "Friday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("uiairlinerep", "Saturday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("uiairlinerep", "Sunday", 0, QApplication::UnicodeUTF8)
        );
        reqInSource->clear();
        reqInSource->insertItems(0, QStringList()
         << QApplication::translate("uiairlinerep", "BCN", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("uiairlinerep", "JFK", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("uiairlinerep", "LAX", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("uiairlinerep", "YVR", 0, QApplication::UnicodeUTF8)
        );
        reqInGate->setDisplayFormat(QApplication::translate("uiairlinerep", "hh:mm", 0, QApplication::UnicodeUTF8));
        reqInLand->setDisplayFormat(QApplication::translate("uiairlinerep", "hh:mm", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("uiairlinerep", "Incoming", 0, QApplication::UnicodeUTF8));
        reqOutWeekly->setText(QApplication::translate("uiairlinerep", "Weekly", 0, QApplication::UnicodeUTF8));
        reqOutOne->setText(QApplication::translate("uiairlinerep", "One-Time", 0, QApplication::UnicodeUTF8));
        reqOutDaily->setText(QApplication::translate("uiairlinerep", "Daily", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("uiairlinerep", "Takeoff Time:", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("uiairlinerep", "Aircraft \342\200\217ID:", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("uiairlinerep", "Destination Airport:", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("uiairlinerep", "Gate Departure Time:", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("uiairlinerep", "Flight ID:", 0, QApplication::UnicodeUTF8));
        reqOutSubmit->setText(QApplication::translate("uiairlinerep", "Submit Request", 0, QApplication::UnicodeUTF8));
        reqOutDay->clear();
        reqOutDay->insertItems(0, QStringList()
         << QApplication::translate("uiairlinerep", "Monday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("uiairlinerep", "Tuesday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("uiairlinerep", "Wednesday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("uiairlinerep", "Thursday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("uiairlinerep", "Friday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("uiairlinerep", "Saturday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("uiairlinerep", "Sunday", 0, QApplication::UnicodeUTF8)
        );
        label_7->setText(QApplication::translate("uiairlinerep", "Date:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("uiairlinerep", "Day of the week:", 0, QApplication::UnicodeUTF8));
        reqOutDestination->clear();
        reqOutDestination->insertItems(0, QStringList()
         << QApplication::translate("uiairlinerep", "BCN", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("uiairlinerep", "JFK", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("uiairlinerep", "LAX", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("uiairlinerep", "YVR", 0, QApplication::UnicodeUTF8)
        );
        reqOutGate->setDisplayFormat(QApplication::translate("uiairlinerep", "hh:mm", 0, QApplication::UnicodeUTF8));
        reqOutTakeOff->setDisplayFormat(QApplication::translate("uiairlinerep", "hh:mm", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("uiairlinerep", "Outgoing", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("uiairlinerep", "Aircraft", 0, QApplication::UnicodeUTF8));
        editaircraftid->setText(QApplication::translate("uiairlinerep", "edit", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("uiairlinerep", "Edit Aircraft ID", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("uiairlinerep", "New:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("uiairlinerep", "Delete Aircraft", 0, QApplication::UnicodeUTF8));
        deleteAircraft->setText(QApplication::translate("uiairlinerep", "Delete", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("uiairlinerep", "Add Aircraft", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("uiairlinerep", "ID:", 0, QApplication::UnicodeUTF8));
        addAircraft->setText(QApplication::translate("uiairlinerep", "Add", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("uiairlinerep", "Type:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("uiairlinerep", "Status:", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("uiairlinerep", "LOGOUT", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class uiairlinerep: public Ui_uiairlinerep {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIAIRLINEREP_H
