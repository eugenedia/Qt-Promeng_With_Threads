#include "dbconn.h"
#include "AllHeaders.h"

DBConn::DBConn()
{





}

QSqlDatabase DBConn::getDatabase()
{
    return db;
}

bool DBConn::loadDatabase()
{
   /* db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("arsmssv2");
    db.setUserName("root");
    db.setPassword("password");*/



    db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName(HOST);
        db.setDatabaseName(DB_NAME);
        db.setUserName(USERNAME);
        db.setPassword(PASSWORD);


    if(!db.open()){
        db.lastError().text();
        //cerr << qPrintable("error");
        qDebug() << "error";



        return false;

        }
    return true;
}
