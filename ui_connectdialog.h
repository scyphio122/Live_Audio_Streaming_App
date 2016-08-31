/********************************************************************************
** Form generated from reading UI file 'connectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTDIALOG_H
#define UI_CONNECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ConnectDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *lE_IP;
    QLabel *label_3;

    void setupUi(QDialog *ConnectDialog)
    {
        if (ConnectDialog->objectName().isEmpty())
            ConnectDialog->setObjectName(QStringLiteral("ConnectDialog"));
        ConnectDialog->resize(500, 100);
        ConnectDialog->setMinimumSize(QSize(500, 100));
        ConnectDialog->setMaximumSize(QSize(500, 100));
        ConnectDialog->setStyleSheet(QLatin1String("QDialog{\n"
"background-color: rgb(49, 49, 49);\n"
"}\n"
""));
        buttonBox = new QDialogButtonBox(ConnectDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(370, 30, 81, 241));
        buttonBox->setStyleSheet(QLatin1String("QPushButton:enabled\n"
"{\n"
"    color:orange;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1,y2:1, stop: 1 rgba(60, 60, 60, 100), stop: 0 rgba(80, 80, 80, 100));\n"
"    border-color: rgba(70,70,70,200);\n"
"    border-width: 1px;\n"
"    border-style: outset;\n"
"	border-radius:3;\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"    color:gray;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1,y2:1, stop: 1 rgba(60, 60, 60, 100), stop: 0 rgba(80, 80, 80, 100));\n"
"    border-color: rgba(70,70,70,200);\n"
"    border-width: 1px;\n"
"    border-style: inset;\n"
"	border-radius:3;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"    color:orange;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1,y2:1, stop: 1 rgba(60, 60, 60, 100), stop: 0 rgba(80, 80, 80, 100));\n"
"    border-color: rgba(70,70,70,200);\n"
"    border-width: 1px;\n"
"    border-style: inset;\n"
"	border-radius:3;\n"
"}"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);
        label = new QLabel(ConnectDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 261, 16));
        label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	color:rgb(255,127,39);\n"
"}"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lE_IP = new QLabel(ConnectDialog);
        lE_IP->setObjectName(QStringLiteral("lE_IP"));
        lE_IP->setGeometry(QRect(280, 27, 121, 20));
        lE_IP->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	color:orange;\n"
"}"));
        label_3 = new QLabel(ConnectDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 50, 51, 16));
        label_3->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	color:rgb(255,127,39);\n"
"}"));

        retranslateUi(ConnectDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConnectDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConnectDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectDialog)
    {
        ConnectDialog->setWindowTitle(QApplication::translate("ConnectDialog", "Connection Request", 0));
        label->setText(QApplication::translate("ConnectDialog", "Otrzymano pro\305\233b\304\231 na po\305\202\304\205czenie od urz\304\205dzenia o IP:", 0));
        lE_IP->setText(QString());
        label_3->setText(QApplication::translate("ConnectDialog", "Zezwoli\304\207?", 0));
    } // retranslateUi

};

namespace Ui {
    class ConnectDialog: public Ui_ConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDIALOG_H
