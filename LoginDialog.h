#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "AllHeaders.h"

class DbLoginPasswords;

class LoginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit LoginDialog(QSqlDatabase & db,QWidget *parent = 0);
    ~LoginDialog();
    
    LoginPassword getLoginStatus();

signals:
    
public slots:
    void onOkClicked();
    void onCancelBtnClicked();

private:
    LoginPassword checkLoginInformation();
    QSqlDatabase db;


    DbLoginPasswords * db_LoginPasswords;

    bool loginSucc;

    QLineEdit *edt_Login;
    QLineEdit *edt_Password;

     LoginPassword *lp;
};

#endif // LOGINDIALOG_H
