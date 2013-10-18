/********************************************************************************
** Form generated from reading UI file 'uiairportmanager.ui'
**
** Created: Tue Mar 29 05:15:35 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIAIRPORTMANAGER_H
#define UI_UIAIRPORTMANAGER_H

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
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_uiairportmanager
{
public:
    QWidget *centralwidget;
    QGroupBox *airportManagerGroupBox;
    QLabel *flightRequestLabel;
    QGroupBox *standGroupBox;
    QTabWidget *standTab;
    QWidget *standCreateTab;
    QPushButton *standCreateAddStandButton;
    QLineEdit *standCreateNewTypeField;
    QComboBox *standCreateNewComboBox;
    QLabel *standCreateNewTypeLabel;
    QWidget *standUpdateTab;
    QListWidget *standUpdateExistingAircraftList;
    QListWidget *standUpdateAircrafAccommatedList;
    QPushButton *standUpdateAddButton;
    QPushButton *standUpdateDeleteButton;
    QComboBox *standUpdateIDComboBox;
    QLabel *standUpdateIDLabel;
    QLabel *standUpdateTypeLabel_2;
    QLabel *standUpdateTypeLabel_3;
    QWidget *standDeleteTab;
    QPushButton *standDeleteButton;
    QLabel *standDeleteIDLabel;
    QComboBox *standDeleteIDComboBox;
    QListWidget *flightRequestList;
    QPushButton *flightRequestDenyButton;
    QPushButton *flightRequestAcceptButton;
    QGroupBox *bulkfileGroup;
    QPushButton *bulkfileOutput;
    QPushButton *bulkfileUpload;
    QLineEdit *bulkfilePrefixField;
    QComboBox *bulkfileDataTypeComboBox;
    QLabel *bulkfileDataTypeLabel;
    QLabel *bulkfilePrefixLabel;
    QGroupBox *accountGroupBox;
    QTabWidget *accountTab;
    QWidget *AirlineTab;
    QRadioButton *accountAirlineAddButton;
    QRadioButton *accountAirlineDeleteButton;
    QLabel *accountAirlineNameLabel;
    QLineEdit *accountAirlineNameField;
    QLineEdit *accountAirlinePasswordField;
    QLabel *accountAirlinePasswordLabel;
    QPushButton *accountAirlineOKButton;
    QComboBox *accountAirlineComboBox;
    QWidget *GTCTab;
    QRadioButton *accountGTCAddButton;
    QRadioButton *accountGTCDeleteButton;
    QLineEdit *accountGTCPasswordField;
    QLineEdit *accountGTCNameField;
    QLabel *accountGTCPasswordLabel;
    QPushButton *accountGTCOKButton;
    QLabel *accountGTCNameLabel;
    QComboBox *accountGTCComboBox;
    QGroupBox *aircraftGroupBox;
    QLabel *aircraftManufacturerLabel;
    QLabel *aircraftModelLabel;
    QLabel *aircraftServiceTimeLabel;
    QLabel *aircraftCapacityLabel;
    QLabel *aircraftBoardingTimeLabel;
    QLineEdit *aircraftManufacturerField;
    QLineEdit *aircraftModelField;
    QLineEdit *aircraftCapacityField;
    QLineEdit *aircraftServiceTimeField;
    QLineEdit *aircraftBoardingTimeField;
    QPushButton *aircraftOKButton;
    QLabel *aircraftIDLabel;
    QComboBox *aircraftIDComboBox;
    QRadioButton *aircraftDeleteButton;
    QRadioButton *aircraftUpdateButton;
    QRadioButton *aircraftCreateButton;
    QGroupBox *PasswordGroup;
    QPushButton *passwordOKButton;
    QLineEdit *passwordNewField;
    QLineEdit *passwordRetypeField;
    QLabel *passwordNewLabel;
    QLabel *passwordRetypeLabel;
    QPushButton *airportManagerLOGOUT;
    QLabel *lb_error;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *uiairportmanager)
    {
        if (uiairportmanager->objectName().isEmpty())
            uiairportmanager->setObjectName(QString::fromUtf8("uiairportmanager"));
        uiairportmanager->resize(1056, 648);
        centralwidget = new QWidget(uiairportmanager);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        airportManagerGroupBox = new QGroupBox(centralwidget);
        airportManagerGroupBox->setObjectName(QString::fromUtf8("airportManagerGroupBox"));
        airportManagerGroupBox->setGeometry(QRect(0, 0, 1041, 631));
        airportManagerGroupBox->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        flightRequestLabel = new QLabel(airportManagerGroupBox);
        flightRequestLabel->setObjectName(QString::fromUtf8("flightRequestLabel"));
        flightRequestLabel->setGeometry(QRect(9, 31, 111, 20));
        standGroupBox = new QGroupBox(airportManagerGroupBox);
        standGroupBox->setObjectName(QString::fromUtf8("standGroupBox"));
        standGroupBox->setGeometry(QRect(20, 300, 531, 271));
        standGroupBox->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 0, 0);"));
        standTab = new QTabWidget(standGroupBox);
        standTab->setObjectName(QString::fromUtf8("standTab"));
        standTab->setGeometry(QRect(10, 20, 511, 241));
        standCreateTab = new QWidget();
        standCreateTab->setObjectName(QString::fromUtf8("standCreateTab"));
        standCreateAddStandButton = new QPushButton(standCreateTab);
        standCreateAddStandButton->setObjectName(QString::fromUtf8("standCreateAddStandButton"));
        standCreateAddStandButton->setGeometry(QRect(195, 120, 151, 29));
        standCreateNewTypeField = new QLineEdit(standCreateTab);
        standCreateNewTypeField->setObjectName(QString::fromUtf8("standCreateNewTypeField"));
        standCreateNewTypeField->setGeometry(QRect(265, 70, 81, 31));
        standCreateNewComboBox = new QComboBox(standCreateTab);
        standCreateNewComboBox->setObjectName(QString::fromUtf8("standCreateNewComboBox"));
        standCreateNewComboBox->setGeometry(QRect(195, 70, 71, 31));
        standCreateNewTypeLabel = new QLabel(standCreateTab);
        standCreateNewTypeLabel->setObjectName(QString::fromUtf8("standCreateNewTypeLabel"));
        standCreateNewTypeLabel->setGeometry(QRect(126, 74, 71, 19));
        standTab->addTab(standCreateTab, QString());
        standUpdateTab = new QWidget();
        standUpdateTab->setObjectName(QString::fromUtf8("standUpdateTab"));
        standUpdateExistingAircraftList = new QListWidget(standUpdateTab);
        standUpdateExistingAircraftList->setObjectName(QString::fromUtf8("standUpdateExistingAircraftList"));
        standUpdateExistingAircraftList->setGeometry(QRect(10, 50, 191, 161));
        standUpdateAircrafAccommatedList = new QListWidget(standUpdateTab);
        standUpdateAircrafAccommatedList->setObjectName(QString::fromUtf8("standUpdateAircrafAccommatedList"));
        standUpdateAircrafAccommatedList->setGeometry(QRect(309, 50, 191, 161));
        standUpdateAddButton = new QPushButton(standUpdateTab);
        standUpdateAddButton->setObjectName(QString::fromUtf8("standUpdateAddButton"));
        standUpdateAddButton->setGeometry(QRect(219, 70, 75, 23));
        standUpdateDeleteButton = new QPushButton(standUpdateTab);
        standUpdateDeleteButton->setObjectName(QString::fromUtf8("standUpdateDeleteButton"));
        standUpdateDeleteButton->setGeometry(QRect(219, 160, 75, 23));
        standUpdateIDComboBox = new QComboBox(standUpdateTab);
        standUpdateIDComboBox->setObjectName(QString::fromUtf8("standUpdateIDComboBox"));
        standUpdateIDComboBox->setGeometry(QRect(223, 14, 69, 22));
        standUpdateIDLabel = new QLabel(standUpdateTab);
        standUpdateIDLabel->setObjectName(QString::fromUtf8("standUpdateIDLabel"));
        standUpdateIDLabel->setGeometry(QRect(229, -6, 61, 20));
        standUpdateTypeLabel_2 = new QLabel(standUpdateTab);
        standUpdateTypeLabel_2->setObjectName(QString::fromUtf8("standUpdateTypeLabel_2"));
        standUpdateTypeLabel_2->setGeometry(QRect(314, 35, 191, 16));
        standUpdateTypeLabel_3 = new QLabel(standUpdateTab);
        standUpdateTypeLabel_3->setObjectName(QString::fromUtf8("standUpdateTypeLabel_3"));
        standUpdateTypeLabel_3->setGeometry(QRect(26, 35, 161, 16));
        standTab->addTab(standUpdateTab, QString());
        standDeleteTab = new QWidget();
        standDeleteTab->setObjectName(QString::fromUtf8("standDeleteTab"));
        standDeleteButton = new QPushButton(standDeleteTab);
        standDeleteButton->setObjectName(QString::fromUtf8("standDeleteButton"));
        standDeleteButton->setGeometry(QRect(195, 120, 151, 29));
        standDeleteIDLabel = new QLabel(standDeleteTab);
        standDeleteIDLabel->setObjectName(QString::fromUtf8("standDeleteIDLabel"));
        standDeleteIDLabel->setGeometry(QRect(210, 80, 31, 19));
        standDeleteIDComboBox = new QComboBox(standDeleteTab);
        standDeleteIDComboBox->setObjectName(QString::fromUtf8("standDeleteIDComboBox"));
        standDeleteIDComboBox->setGeometry(QRect(241, 75, 71, 31));
        standTab->addTab(standDeleteTab, QString());
        flightRequestList = new QListWidget(airportManagerGroupBox);
        flightRequestList->setObjectName(QString::fromUtf8("flightRequestList"));
        flightRequestList->setGeometry(QRect(20, 50, 631, 191));
        flightRequestDenyButton = new QPushButton(airportManagerGroupBox);
        flightRequestDenyButton->setObjectName(QString::fromUtf8("flightRequestDenyButton"));
        flightRequestDenyButton->setGeometry(QRect(110, 250, 80, 29));
        flightRequestAcceptButton = new QPushButton(airportManagerGroupBox);
        flightRequestAcceptButton->setObjectName(QString::fromUtf8("flightRequestAcceptButton"));
        flightRequestAcceptButton->setGeometry(QRect(20, 250, 80, 29));
        bulkfileGroup = new QGroupBox(airportManagerGroupBox);
        bulkfileGroup->setObjectName(QString::fromUtf8("bulkfileGroup"));
        bulkfileGroup->setGeometry(QRect(680, 170, 331, 111));
        bulkfileGroup->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 0, 0);"));
        bulkfileOutput = new QPushButton(bulkfileGroup);
        bulkfileOutput->setObjectName(QString::fromUtf8("bulkfileOutput"));
        bulkfileOutput->setGeometry(QRect(204, 63, 111, 29));
        bulkfileUpload = new QPushButton(bulkfileGroup);
        bulkfileUpload->setObjectName(QString::fromUtf8("bulkfileUpload"));
        bulkfileUpload->setGeometry(QRect(204, 24, 111, 29));
        bulkfilePrefixField = new QLineEdit(bulkfileGroup);
        bulkfilePrefixField->setObjectName(QString::fromUtf8("bulkfilePrefixField"));
        bulkfilePrefixField->setGeometry(QRect(80, 63, 111, 29));
        bulkfileDataTypeComboBox = new QComboBox(bulkfileGroup);
        bulkfileDataTypeComboBox->setObjectName(QString::fromUtf8("bulkfileDataTypeComboBox"));
        bulkfileDataTypeComboBox->setGeometry(QRect(79, 24, 111, 31));
        bulkfileDataTypeLabel = new QLabel(bulkfileGroup);
        bulkfileDataTypeLabel->setObjectName(QString::fromUtf8("bulkfileDataTypeLabel"));
        bulkfileDataTypeLabel->setGeometry(QRect(10, 30, 61, 16));
        bulkfilePrefixLabel = new QLabel(bulkfileGroup);
        bulkfilePrefixLabel->setObjectName(QString::fromUtf8("bulkfilePrefixLabel"));
        bulkfilePrefixLabel->setGeometry(QRect(30, 68, 41, 16));
        accountGroupBox = new QGroupBox(airportManagerGroupBox);
        accountGroupBox->setObjectName(QString::fromUtf8("accountGroupBox"));
        accountGroupBox->setGeometry(QRect(810, 300, 221, 261));
        accountTab = new QTabWidget(accountGroupBox);
        accountTab->setObjectName(QString::fromUtf8("accountTab"));
        accountTab->setGeometry(QRect(10, 20, 201, 231));
        AirlineTab = new QWidget();
        AirlineTab->setObjectName(QString::fromUtf8("AirlineTab"));
        accountAirlineAddButton = new QRadioButton(AirlineTab);
        accountAirlineAddButton->setObjectName(QString::fromUtf8("accountAirlineAddButton"));
        accountAirlineAddButton->setGeometry(QRect(10, 17, 105, 25));
        accountAirlineDeleteButton = new QRadioButton(AirlineTab);
        accountAirlineDeleteButton->setObjectName(QString::fromUtf8("accountAirlineDeleteButton"));
        accountAirlineDeleteButton->setGeometry(QRect(70, 17, 105, 25));
        accountAirlineNameLabel = new QLabel(AirlineTab);
        accountAirlineNameLabel->setObjectName(QString::fromUtf8("accountAirlineNameLabel"));
        accountAirlineNameLabel->setGeometry(QRect(10, 47, 101, 19));
        accountAirlineNameField = new QLineEdit(AirlineTab);
        accountAirlineNameField->setObjectName(QString::fromUtf8("accountAirlineNameField"));
        accountAirlineNameField->setGeometry(QRect(10, 67, 181, 29));
        accountAirlinePasswordField = new QLineEdit(AirlineTab);
        accountAirlinePasswordField->setObjectName(QString::fromUtf8("accountAirlinePasswordField"));
        accountAirlinePasswordField->setGeometry(QRect(10, 117, 181, 29));
        accountAirlinePasswordLabel = new QLabel(AirlineTab);
        accountAirlinePasswordLabel->setObjectName(QString::fromUtf8("accountAirlinePasswordLabel"));
        accountAirlinePasswordLabel->setGeometry(QRect(10, 97, 121, 19));
        accountAirlineOKButton = new QPushButton(AirlineTab);
        accountAirlineOKButton->setObjectName(QString::fromUtf8("accountAirlineOKButton"));
        accountAirlineOKButton->setGeometry(QRect(10, 151, 80, 29));
        accountAirlineComboBox = new QComboBox(AirlineTab);
        accountAirlineComboBox->setObjectName(QString::fromUtf8("accountAirlineComboBox"));
        accountAirlineComboBox->setEnabled(true);
        accountAirlineComboBox->setGeometry(QRect(10, 67, 181, 29));
        accountAirlineComboBox->setFrame(true);
        accountTab->addTab(AirlineTab, QString());
        GTCTab = new QWidget();
        GTCTab->setObjectName(QString::fromUtf8("GTCTab"));
        accountGTCAddButton = new QRadioButton(GTCTab);
        accountGTCAddButton->setObjectName(QString::fromUtf8("accountGTCAddButton"));
        accountGTCAddButton->setGeometry(QRect(10, 17, 51, 25));
        accountGTCDeleteButton = new QRadioButton(GTCTab);
        accountGTCDeleteButton->setObjectName(QString::fromUtf8("accountGTCDeleteButton"));
        accountGTCDeleteButton->setGeometry(QRect(70, 17, 81, 25));
        accountGTCPasswordField = new QLineEdit(GTCTab);
        accountGTCPasswordField->setObjectName(QString::fromUtf8("accountGTCPasswordField"));
        accountGTCPasswordField->setGeometry(QRect(10, 117, 181, 29));
        accountGTCNameField = new QLineEdit(GTCTab);
        accountGTCNameField->setObjectName(QString::fromUtf8("accountGTCNameField"));
        accountGTCNameField->setGeometry(QRect(10, 68, 181, 29));
        accountGTCPasswordLabel = new QLabel(GTCTab);
        accountGTCPasswordLabel->setObjectName(QString::fromUtf8("accountGTCPasswordLabel"));
        accountGTCPasswordLabel->setGeometry(QRect(10, 97, 121, 19));
        accountGTCOKButton = new QPushButton(GTCTab);
        accountGTCOKButton->setObjectName(QString::fromUtf8("accountGTCOKButton"));
        accountGTCOKButton->setGeometry(QRect(10, 151, 80, 29));
        accountGTCNameLabel = new QLabel(GTCTab);
        accountGTCNameLabel->setObjectName(QString::fromUtf8("accountGTCNameLabel"));
        accountGTCNameLabel->setGeometry(QRect(10, 47, 101, 19));
        accountGTCComboBox = new QComboBox(GTCTab);
        accountGTCComboBox->setObjectName(QString::fromUtf8("accountGTCComboBox"));
        accountGTCComboBox->setEnabled(true);
        accountGTCComboBox->setGeometry(QRect(10, 67, 181, 29));
        accountGTCComboBox->setFrame(true);
        accountTab->addTab(GTCTab, QString());
        aircraftGroupBox = new QGroupBox(airportManagerGroupBox);
        aircraftGroupBox->setObjectName(QString::fromUtf8("aircraftGroupBox"));
        aircraftGroupBox->setGeometry(QRect(560, 300, 241, 261));
        aircraftGroupBox->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        aircraftManufacturerLabel = new QLabel(aircraftGroupBox);
        aircraftManufacturerLabel->setObjectName(QString::fromUtf8("aircraftManufacturerLabel"));
        aircraftManufacturerLabel->setGeometry(QRect(19, 78, 101, 19));
        aircraftModelLabel = new QLabel(aircraftGroupBox);
        aircraftModelLabel->setObjectName(QString::fromUtf8("aircraftModelLabel"));
        aircraftModelLabel->setGeometry(QRect(57, 107, 62, 19));
        aircraftServiceTimeLabel = new QLabel(aircraftGroupBox);
        aircraftServiceTimeLabel->setObjectName(QString::fromUtf8("aircraftServiceTimeLabel"));
        aircraftServiceTimeLabel->setGeometry(QRect(24, 135, 91, 19));
        aircraftCapacityLabel = new QLabel(aircraftGroupBox);
        aircraftCapacityLabel->setObjectName(QString::fromUtf8("aircraftCapacityLabel"));
        aircraftCapacityLabel->setGeometry(QRect(43, 163, 62, 19));
        aircraftBoardingTimeLabel = new QLabel(aircraftGroupBox);
        aircraftBoardingTimeLabel->setObjectName(QString::fromUtf8("aircraftBoardingTimeLabel"));
        aircraftBoardingTimeLabel->setGeometry(QRect(18, 190, 101, 19));
        aircraftManufacturerField = new QLineEdit(aircraftGroupBox);
        aircraftManufacturerField->setObjectName(QString::fromUtf8("aircraftManufacturerField"));
        aircraftManufacturerField->setGeometry(QRect(120, 74, 113, 29));
        aircraftModelField = new QLineEdit(aircraftGroupBox);
        aircraftModelField->setObjectName(QString::fromUtf8("aircraftModelField"));
        aircraftModelField->setGeometry(QRect(120, 101, 113, 29));
        aircraftCapacityField = new QLineEdit(aircraftGroupBox);
        aircraftCapacityField->setObjectName(QString::fromUtf8("aircraftCapacityField"));
        aircraftCapacityField->setGeometry(QRect(120, 159, 113, 29));
        aircraftServiceTimeField = new QLineEdit(aircraftGroupBox);
        aircraftServiceTimeField->setObjectName(QString::fromUtf8("aircraftServiceTimeField"));
        aircraftServiceTimeField->setGeometry(QRect(120, 130, 113, 29));
        aircraftServiceTimeField->setMaxLength(32767);
        aircraftBoardingTimeField = new QLineEdit(aircraftGroupBox);
        aircraftBoardingTimeField->setObjectName(QString::fromUtf8("aircraftBoardingTimeField"));
        aircraftBoardingTimeField->setGeometry(QRect(120, 186, 113, 29));
        aircraftOKButton = new QPushButton(aircraftGroupBox);
        aircraftOKButton->setObjectName(QString::fromUtf8("aircraftOKButton"));
        aircraftOKButton->setGeometry(QRect(121, 220, 111, 29));
        aircraftIDLabel = new QLabel(aircraftGroupBox);
        aircraftIDLabel->setObjectName(QString::fromUtf8("aircraftIDLabel"));
        aircraftIDLabel->setGeometry(QRect(34, 50, 101, 19));
        aircraftIDComboBox = new QComboBox(aircraftGroupBox);
        aircraftIDComboBox->setObjectName(QString::fromUtf8("aircraftIDComboBox"));
        aircraftIDComboBox->setGeometry(QRect(120, 47, 111, 27));
        aircraftDeleteButton = new QRadioButton(aircraftGroupBox);
        aircraftDeleteButton->setObjectName(QString::fromUtf8("aircraftDeleteButton"));
        aircraftDeleteButton->setGeometry(QRect(10, 20, 71, 25));
        aircraftUpdateButton = new QRadioButton(aircraftGroupBox);
        aircraftUpdateButton->setObjectName(QString::fromUtf8("aircraftUpdateButton"));
        aircraftUpdateButton->setGeometry(QRect(80, 20, 105, 25));
        aircraftCreateButton = new QRadioButton(aircraftGroupBox);
        aircraftCreateButton->setObjectName(QString::fromUtf8("aircraftCreateButton"));
        aircraftCreateButton->setGeometry(QRect(156, 20, 105, 25));
        PasswordGroup = new QGroupBox(airportManagerGroupBox);
        PasswordGroup->setObjectName(QString::fromUtf8("PasswordGroup"));
        PasswordGroup->setGeometry(QRect(680, 44, 291, 121));
        PasswordGroup->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 0, 0);"));
        passwordOKButton = new QPushButton(PasswordGroup);
        passwordOKButton->setObjectName(QString::fromUtf8("passwordOKButton"));
        passwordOKButton->setGeometry(QRect(150, 84, 101, 29));
        passwordNewField = new QLineEdit(PasswordGroup);
        passwordNewField->setObjectName(QString::fromUtf8("passwordNewField"));
        passwordNewField->setGeometry(QRect(120, 20, 151, 29));
        passwordRetypeField = new QLineEdit(PasswordGroup);
        passwordRetypeField->setObjectName(QString::fromUtf8("passwordRetypeField"));
        passwordRetypeField->setGeometry(QRect(120, 50, 151, 29));
        passwordNewLabel = new QLabel(PasswordGroup);
        passwordNewLabel->setObjectName(QString::fromUtf8("passwordNewLabel"));
        passwordNewLabel->setGeometry(QRect(32, 24, 81, 19));
        passwordRetypeLabel = new QLabel(PasswordGroup);
        passwordRetypeLabel->setObjectName(QString::fromUtf8("passwordRetypeLabel"));
        passwordRetypeLabel->setGeometry(QRect(18, 54, 91, 19));
        airportManagerLOGOUT = new QPushButton(airportManagerGroupBox);
        airportManagerLOGOUT->setObjectName(QString::fromUtf8("airportManagerLOGOUT"));
        airportManagerLOGOUT->setGeometry(QRect(810, 567, 221, 51));
        lb_error = new QLabel(airportManagerGroupBox);
        lb_error->setObjectName(QString::fromUtf8("lb_error"));
        lb_error->setGeometry(QRect(350, 580, 201, 31));
        uiairportmanager->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(uiairportmanager);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        uiairportmanager->setStatusBar(statusbar);

        retranslateUi(uiairportmanager);

        standTab->setCurrentIndex(1);
        accountTab->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(uiairportmanager);
    } // setupUi

    void retranslateUi(QMainWindow *uiairportmanager)
    {
        uiairportmanager->setWindowTitle(QApplication::translate("uiairportmanager", "MainWindow", 0, QApplication::UnicodeUTF8));
        airportManagerGroupBox->setTitle(QApplication::translate("uiairportmanager", "Airport Manager", 0, QApplication::UnicodeUTF8));
        flightRequestLabel->setText(QApplication::translate("uiairportmanager", "Flight Requests", 0, QApplication::UnicodeUTF8));
        standGroupBox->setTitle(QApplication::translate("uiairportmanager", "Stand", 0, QApplication::UnicodeUTF8));
        standCreateAddStandButton->setText(QApplication::translate("uiairportmanager", "Add New Stand", 0, QApplication::UnicodeUTF8));
        standCreateNewTypeLabel->setText(QApplication::translate("uiairportmanager", "New Type:", 0, QApplication::UnicodeUTF8));
        standTab->setTabText(standTab->indexOf(standCreateTab), QApplication::translate("uiairportmanager", "Create", 0, QApplication::UnicodeUTF8));
        standUpdateAddButton->setText(QApplication::translate("uiairportmanager", "ADD>>", 0, QApplication::UnicodeUTF8));
        standUpdateDeleteButton->setText(QApplication::translate("uiairportmanager", "<<DEL", 0, QApplication::UnicodeUTF8));
        standUpdateIDLabel->setText(QApplication::translate("uiairportmanager", "Stand ID:", 0, QApplication::UnicodeUTF8));
        standUpdateTypeLabel_2->setText(QApplication::translate("uiairportmanager", "Aircraft Types Accomodated by Stand:", 0, QApplication::UnicodeUTF8));
        standUpdateTypeLabel_3->setText(QApplication::translate("uiairportmanager", "Aircraft Types Present at Airport:", 0, QApplication::UnicodeUTF8));
        standTab->setTabText(standTab->indexOf(standUpdateTab), QApplication::translate("uiairportmanager", "Update", 0, QApplication::UnicodeUTF8));
        standDeleteButton->setText(QApplication::translate("uiairportmanager", "Delete Stand", 0, QApplication::UnicodeUTF8));
        standDeleteIDLabel->setText(QApplication::translate("uiairportmanager", "ID:", 0, QApplication::UnicodeUTF8));
        standTab->setTabText(standTab->indexOf(standDeleteTab), QApplication::translate("uiairportmanager", "Delete", 0, QApplication::UnicodeUTF8));
        flightRequestDenyButton->setText(QApplication::translate("uiairportmanager", "Deny", 0, QApplication::UnicodeUTF8));
        flightRequestAcceptButton->setText(QApplication::translate("uiairportmanager", "Accept", 0, QApplication::UnicodeUTF8));
        bulkfileGroup->setTitle(QApplication::translate("uiairportmanager", "Bulkfile", 0, QApplication::UnicodeUTF8));
        bulkfileOutput->setText(QApplication::translate("uiairportmanager", "Output Data", 0, QApplication::UnicodeUTF8));
        bulkfileUpload->setText(QApplication::translate("uiairportmanager", "Upload Data", 0, QApplication::UnicodeUTF8));
        bulkfileDataTypeLabel->setText(QApplication::translate("uiairportmanager", "Data Type:", 0, QApplication::UnicodeUTF8));
        bulkfilePrefixLabel->setText(QApplication::translate("uiairportmanager", "Prefix:", 0, QApplication::UnicodeUTF8));
        accountGroupBox->setTitle(QApplication::translate("uiairportmanager", "Account", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        accountTab->setToolTip(QApplication::translate("uiairportmanager", "Employee", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        accountAirlineAddButton->setText(QApplication::translate("uiairportmanager", "Add", 0, QApplication::UnicodeUTF8));
        accountAirlineDeleteButton->setText(QApplication::translate("uiairportmanager", "Delete", 0, QApplication::UnicodeUTF8));
        accountAirlineNameLabel->setText(QApplication::translate("uiairportmanager", "Account Name:", 0, QApplication::UnicodeUTF8));
        accountAirlinePasswordLabel->setText(QApplication::translate("uiairportmanager", "Password:", 0, QApplication::UnicodeUTF8));
        accountAirlineOKButton->setText(QApplication::translate("uiairportmanager", "OK", 0, QApplication::UnicodeUTF8));
        accountTab->setTabText(accountTab->indexOf(AirlineTab), QApplication::translate("uiairportmanager", "Airline", 0, QApplication::UnicodeUTF8));
        accountGTCAddButton->setText(QApplication::translate("uiairportmanager", "Add", 0, QApplication::UnicodeUTF8));
        accountGTCDeleteButton->setText(QApplication::translate("uiairportmanager", "Delete", 0, QApplication::UnicodeUTF8));
        accountGTCPasswordLabel->setText(QApplication::translate("uiairportmanager", "Password:", 0, QApplication::UnicodeUTF8));
        accountGTCOKButton->setText(QApplication::translate("uiairportmanager", "OK", 0, QApplication::UnicodeUTF8));
        accountGTCNameLabel->setText(QApplication::translate("uiairportmanager", "Account Name:", 0, QApplication::UnicodeUTF8));
        accountTab->setTabText(accountTab->indexOf(GTCTab), QApplication::translate("uiairportmanager", "G.T.C", 0, QApplication::UnicodeUTF8));
        aircraftGroupBox->setTitle(QApplication::translate("uiairportmanager", "Aircraft Type", 0, QApplication::UnicodeUTF8));
        aircraftManufacturerLabel->setText(QApplication::translate("uiairportmanager", "Manufacturer:", 0, QApplication::UnicodeUTF8));
        aircraftModelLabel->setText(QApplication::translate("uiairportmanager", "Model:", 0, QApplication::UnicodeUTF8));
        aircraftServiceTimeLabel->setText(QApplication::translate("uiairportmanager", "Service Time:", 0, QApplication::UnicodeUTF8));
        aircraftCapacityLabel->setText(QApplication::translate("uiairportmanager", "Capacity:", 0, QApplication::UnicodeUTF8));
        aircraftBoardingTimeLabel->setText(QApplication::translate("uiairportmanager", "Boarding Time:", 0, QApplication::UnicodeUTF8));
        aircraftCapacityField->setInputMask(QString());
        aircraftServiceTimeField->setInputMask(QString());
        aircraftServiceTimeField->setText(QString());
        aircraftBoardingTimeField->setInputMask(QString());
        aircraftOKButton->setText(QApplication::translate("uiairportmanager", "OK", 0, QApplication::UnicodeUTF8));
        aircraftIDLabel->setText(QApplication::translate("uiairportmanager", "Aircraft \342\200\217ID:", 0, QApplication::UnicodeUTF8));
        aircraftDeleteButton->setText(QApplication::translate("uiairportmanager", "Delete", 0, QApplication::UnicodeUTF8));
        aircraftUpdateButton->setText(QApplication::translate("uiairportmanager", "Update", 0, QApplication::UnicodeUTF8));
        aircraftCreateButton->setText(QApplication::translate("uiairportmanager", "Create", 0, QApplication::UnicodeUTF8));
        PasswordGroup->setTitle(QApplication::translate("uiairportmanager", "Change Password", 0, QApplication::UnicodeUTF8));
        passwordOKButton->setText(QApplication::translate("uiairportmanager", "OK", 0, QApplication::UnicodeUTF8));
        passwordNewLabel->setText(QApplication::translate("uiairportmanager", "New Password:", 0, QApplication::UnicodeUTF8));
        passwordRetypeLabel->setText(QApplication::translate("uiairportmanager", "Retype Password:", 0, QApplication::UnicodeUTF8));
        airportManagerLOGOUT->setText(QApplication::translate("uiairportmanager", "LOGOUT", 0, QApplication::UnicodeUTF8));
        lb_error->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class uiairportmanager: public Ui_uiairportmanager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIAIRPORTMANAGER_H
