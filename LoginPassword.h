#ifndef LOGIN_PASSWORD_H
#define LOGIN_PASSWORD_H
#include "AllHeaders.h"

class LoginPassword
{
public:
    LoginPassword();
    ~LoginPassword();

    QString F_LOGIN;
    QString F_PASSWORD;
    QString F_NAME;
    int F_ACCESS_MASK;
    bool isModified;
    bool isNewRecord;
    bool isForRemove;
    QString prev_F_LOGIN; //если произошел апдейт F_LOGIN
};

#endif // LOGIN_PASSWORD_H
