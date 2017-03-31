#ifndef DBLOGINPASSWORDS_H
#define DBLOGINPASSWORDS_H

#include "AllHeaders.h"
class LoginPassword;
class DbLoginPasswords
{
public:
    DbLoginPasswords(QSqlDatabase & db);

    LoginPassword CheckLoginAndPasswords(QString f_login, QString f_password);

    QVector<LoginPassword> getLoginAndPasswords();

   bool updateLoginAndPasswords(QVector<LoginPassword> lp, QVector<LoginPassword> removedItems);

private:
    QSqlDatabase db;
    QVector<LoginPassword> vLoginPasswords;


};

#endif // DBLOGINPASSWORDS_H
