#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>
#include <QHostAddress>

namespace Ui {
class ConnectDialog;
}

class ConnectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDialog(QWidget *parent = 0);
    ~ConnectDialog();
    void setRequesterIP(QString &hostIP);
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ConnectDialog *ui;
};

#endif // CONNECTDIALOG_H
