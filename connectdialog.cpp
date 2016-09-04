#include "connectdialog.h"
#include "ui_connectdialog.h"
#include <QHostAddress>

ConnectDialog::ConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDialog)
{
    ui->setupUi(this);
}

ConnectDialog::~ConnectDialog()
{
    delete ui;
}

void ConnectDialog::setRequesterIP(QString& hostIP)
{
    for(int i=hostIP.size() - 1; i>0; --i)
    {
        if(hostIP[i] == ':')
            hostIP = hostIP.right((hostIP.size() - i))
    }
    this->ui->lE_IP->setText(hostIP);
}

void ConnectDialog::on_buttonBox_accepted()
{
    this->done(QDialog::Accepted);
}

void ConnectDialog::on_buttonBox_rejected()
{
    this->done(QDialog::Rejected);
}
