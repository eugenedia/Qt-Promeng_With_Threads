#ifndef db_VisualParam_H
#define db_VisualParam_H
#include <QtGui>
#include <QtSql>
#include "VisualParam.h"
#include "AllHeaders.h"
class VisualParam;
class db_VisualParam
{

public:
    db_VisualParam(QSqlDatabase db);
    bool createConnection();
    QList<VisualParam> loadTableVisualParam(int VideoFrameGuid, QString resolution);
    QVector<VisualParam> loadTableVisualParamForAllFrame();

     bool updateVisualParam(QVector<VisualParam> vVisualParam, QVector<VisualParam> vRemovedChekpoints);
 private:
    QList<VisualParam> listVisualParam;
    QVector<VisualParam> vVisualParam;
    QSqlDatabase db;
};

#endif // db_VisualParam_H
