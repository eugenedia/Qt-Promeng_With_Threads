#ifndef DBCONN_H
#define DBCONN_H
#include <QtSql>

class DBConn
{
public:
    DBConn();
   QSqlDatabase getDatabase();
   bool loadDatabase();
private:
    QSqlDatabase db;

};

#endif // DBCONN_H
