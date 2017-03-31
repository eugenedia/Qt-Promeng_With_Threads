#include "LoginPassword.h"

LoginPassword::LoginPassword():
    F_LOGIN(""),
    F_PASSWORD(""),
    F_NAME(""),
    F_ACCESS_MASK(0),
    isModified(false),
    isNewRecord(false),
    isForRemove(false),
    prev_F_LOGIN("")
{

}





LoginPassword::~LoginPassword()
{
}
