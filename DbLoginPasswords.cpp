#include "DbLoginPasswords.h"

DbLoginPasswords::DbLoginPasswords(QSqlDatabase &db)
{
    this->db=db;
}

LoginPassword DbLoginPasswords::CheckLoginAndPasswords(QString f_login, QString f_password)
{
    QSqlQuery query(db);

    QString  sqlq;



    sqlq = " SELECT F_LOGIN, F_PASSWORD, F_NAME, F_ACCESS_MASK " \
            " FROM TBL_ACCESS WHERE ((F_LOGIN = \'" + f_login +  "\' ) AND ( F_PASSWORD = \'" + f_password +  "\' )) ";










    //  / query.exec()/


    bool Issql = query.exec( sqlq);

     if(!Issql)  QMessageBox::critical(0,  QObject::tr("Error"),  QObject::tr("Error when access TBL_ACCESS"));

    LoginPassword tmploginPassword;



     if(query.next())

      {   tmploginPassword.F_LOGIN = query.value(0).toString();
         tmploginPassword.F_NAME = query.value(1).toString();
         tmploginPassword.F_ACCESS_MASK = query.value(3).toInt();

         return tmploginPassword; }
         //return true;
     else

     {
         tmploginPassword.F_LOGIN = "";
         tmploginPassword.F_NAME = "";
         tmploginPassword.F_ACCESS_MASK = 0; // Если логин и пароль не совпадают, то ACCESS_MASK присваевается значение 0.

         return tmploginPassword;
     }











}

QVector<LoginPassword> DbLoginPasswords::getLoginAndPasswords()
{
    QSqlQuery query(db);

    QString  sqlq;

    vLoginPasswords.clear();

    sqlq = " SELECT F_LOGIN, F_PASSWORD, F_NAME, F_ACCESS_MASK " \
            " FROM TBL_ACCESS  ORDER BY F_LOGIN";


    bool Issql = query.exec(sqlq);

    //qDebug() << Issql;


    LoginPassword tmploginPassword;


    while(query.next()) {





        tmploginPassword.F_LOGIN = query.value(0).toString();
        tmploginPassword.F_PASSWORD = query.value(1).toString();
        tmploginPassword.F_NAME = query.value(2).toString();
        tmploginPassword.F_ACCESS_MASK = query.value(3).toInt();

       // qDebug() << tmpVideoFrame.F_NAME;


         vLoginPasswords.append(tmploginPassword);

    }



    return vLoginPasswords;



}

bool DbLoginPasswords::updateLoginAndPasswords(QVector<LoginPassword> lp,QVector<LoginPassword> vRemovedItems)
{
    QSqlQuery query(db);

    QString  sqlq;

    bool result = true;

    for(int i=0; i<lp.count(); i++)
    {
        if(lp[i].isModified)
        {

           QString login =  lp[i].F_LOGIN;
           QString password = lp[i].F_PASSWORD;
           QString name = lp[i].F_NAME;
           int amask = lp[i].F_ACCESS_MASK;
           QString strAmask = QString::number(amask);
           QString prevLogin = lp[i].prev_F_LOGIN;

            sqlq = "UPDATE TBL_ACCESS " \
                    "  SET " \
                    " F_LOGIN = \'" + login + "\', " \
                    " F_PASSWORD = \'" + password + "\', " \
                    " F_NAME = \'" + name + "\', "  \
                    " F_ACCESS_MASK =  \'"  + strAmask + "\' " \
                    " WHERE F_LOGIN = \'" + prevLogin + "\' ";

            bool Issql = query.exec(sqlq);

            if(!Issql) result = false;



            qDebug() << "Update sql operator " << Issql;

        }

        if(lp[i].isNewRecord)
        {

            QString login =  lp[i].F_LOGIN;
            QString password = lp[i].F_PASSWORD;
            QString name = lp[i].F_NAME;
            int amask = lp[i].F_ACCESS_MASK;
            QString strAmask = QString::number(amask);


            sqlq =  "INSERT INTO TBL_ACCESS " \
            "(F_LOGIN, " \
            "F_PASSWORD, " \
            "F_NAME, " \
            "F_ACCESS_MASK) " \
            "VALUES " \
                    "( \'" + login + "\', " \
                    "\'" + password + "\', " \
                    "\'" + name + "\', "\
                    "\'" + strAmask + "\') ";

            bool Issql = query.exec(sqlq);

            if(!Issql) result = false;



            qDebug() << "Insert sql operator " << Issql;


        }




    }

    if(vRemovedItems.count()>0)
    {
        for(int i=0; i<vRemovedItems.count(); i++)
        {
                QString login =  vRemovedItems[i].F_LOGIN;

                sqlq =  "DELETE FROM TBL_ACCESS " \
                        "WHERE F_LOGIN = \'" + login + "\'";




                bool Issql = query.exec(sqlq);

                if(!Issql) result = false;



                qDebug() << "Delete sql operator " << Issql;


    }
    }
    return result;
}
