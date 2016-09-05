#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>
#include <QHostAddress>

namespace Ui {
class ConnectDialog;
}


/**
 * @brief The ConnectDialog class - This is the window which is shown when connection request is received
 */
class ConnectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDialog(QWidget *parent = 0);
    ~ConnectDialog();

    /**
     * @brief setRequesterIP - This function sets the requesterr IP, which is used to display it in the window
     * @param hostIP[in]
     */
    void setRequesterIP(QString &hostIP);
private slots:

    /**
     * @brief on_buttonBox_accepted - service call for connection accept
     */
    void on_buttonBox_accepted();

    /**
     * @brief on_buttonBox_rejected - service of the connection rejection
     */
    void on_buttonBox_rejected();

private:
    Ui::ConnectDialog *ui;
};

#endif // CONNECTDIALOG_H
