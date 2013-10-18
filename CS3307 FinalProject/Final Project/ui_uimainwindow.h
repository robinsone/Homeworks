/********************************************************************************
** Form generated from reading UI file 'uimainwindow.ui'
**
** Created: Tue Mar 29 05:15:35 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIMAINWINDOW_H
#define UI_UIMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_uiMainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btnLogin;
    QPlainTextEdit *txtArrival;
    QPlainTextEdit *txtDeparture;
    QDateTimeEdit *dateTime;
    QLabel *label;
    QLabel *label_2;
    QLabel *lblTitle;
    QPushButton *btnClose;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *uiMainWindow)
    {
        if (uiMainWindow->objectName().isEmpty())
            uiMainWindow->setObjectName(QString::fromUtf8("uiMainWindow"));
        uiMainWindow->resize(954, 702);
        centralWidget = new QWidget(uiMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btnLogin = new QPushButton(centralWidget);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(10, 10, 121, 29));
        txtArrival = new QPlainTextEdit(centralWidget);
        txtArrival->setObjectName(QString::fromUtf8("txtArrival"));
        txtArrival->setGeometry(QRect(20, 90, 921, 271));
        QFont font;
        font.setFamily(QString::fromUtf8("Monospace"));
        font.setPointSize(8);
        txtArrival->setFont(font);
        txtArrival->setReadOnly(true);
        txtDeparture = new QPlainTextEdit(centralWidget);
        txtDeparture->setObjectName(QString::fromUtf8("txtDeparture"));
        txtDeparture->setGeometry(QRect(20, 410, 921, 271));
        txtDeparture->setFont(font);
        txtDeparture->setReadOnly(true);
        dateTime = new QDateTimeEdit(centralWidget);
        dateTime->setObjectName(QString::fromUtf8("dateTime"));
        dateTime->setGeometry(QRect(750, 20, 194, 22));
        dateTime->setReadOnly(true);
        dateTime->setButtonSymbols(QAbstractSpinBox::NoButtons);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(25, 67, 60, 13));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(27, 383, 131, 16));
        label_2->setFont(font1);
        lblTitle = new QLabel(centralWidget);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));
        lblTitle->setGeometry(QRect(350, 30, 231, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        lblTitle->setFont(font2);
        btnClose = new QPushButton(centralWidget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(140, 10, 121, 31));
        uiMainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(uiMainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        uiMainWindow->setStatusBar(statusBar);

        retranslateUi(uiMainWindow);

        QMetaObject::connectSlotsByName(uiMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *uiMainWindow)
    {
        uiMainWindow->setWindowTitle(QApplication::translate("uiMainWindow", "uiMainWindow", 0, QApplication::UnicodeUTF8));
        btnLogin->setText(QApplication::translate("uiMainWindow", "Login", 0, QApplication::UnicodeUTF8));
        dateTime->setDisplayFormat(QApplication::translate("uiMainWindow", "dd/MM/yyyy h:mm:ss", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("uiMainWindow", "Arrival", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("uiMainWindow", "Departure", 0, QApplication::UnicodeUTF8));
        lblTitle->setText(QApplication::translate("uiMainWindow", "Public View", 0, QApplication::UnicodeUTF8));
        btnClose->setText(QApplication::translate("uiMainWindow", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class uiMainWindow: public Ui_uiMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIMAINWINDOW_H
