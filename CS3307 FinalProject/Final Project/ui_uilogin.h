/********************************************************************************
** Form generated from reading UI file 'uilogin.ui'
**
** Created: Mon Mar 28 20:19:34 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UILOGIN_H
#define UI_UILOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_uilogin
{
public:
    QWidget *centralwidget;
    QPushButton *btnOk;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lb_UserName;
    QLineEdit *lineEdit_2;
    QPushButton *btnCancel;
    QLabel *errorLabel;

    void setupUi(QMainWindow *uilogin)
    {
        if (uilogin->objectName().isEmpty())
            uilogin->setObjectName(QString::fromUtf8("uilogin"));
        uilogin->resize(401, 113);
        centralwidget = new QWidget(uilogin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btnOk = new QPushButton(centralwidget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));
        btnOk->setGeometry(QRect(280, 10, 98, 27));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(15, 15, 100, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(14, 52, 91, 19));
        lb_UserName = new QLineEdit(centralwidget);
        lb_UserName->setObjectName(QString::fromUtf8("lb_UserName"));
        lb_UserName->setGeometry(QRect(90, 10, 181, 29));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(90, 46, 181, 29));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        btnCancel = new QPushButton(centralwidget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(280, 40, 98, 30));
        errorLabel = new QLabel(centralwidget);
        errorLabel->setObjectName(QString::fromUtf8("errorLabel"));
        errorLabel->setGeometry(QRect(30, 80, 261, 17));
        uilogin->setCentralWidget(centralwidget);

        retranslateUi(uilogin);

        QMetaObject::connectSlotsByName(uilogin);
    } // setupUi

    void retranslateUi(QMainWindow *uilogin)
    {
        uilogin->setWindowTitle(QApplication::translate("uilogin", "AMS Groupe 10", 0, QApplication::UnicodeUTF8));
        btnOk->setText(QApplication::translate("uilogin", "Sign In", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("uilogin", "Username:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("uilogin", "Password:", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("uilogin", "Cancel", 0, QApplication::UnicodeUTF8));
        errorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class uilogin: public Ui_uilogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UILOGIN_H
