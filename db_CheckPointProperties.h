#ifndef DB_CHECKPOINTPROPERTIES_H
#define DB_CHECKPOINTPROPERTIES_H
#include <QtGui>
#include <QtSql>
#include "CheckPointProperties.h"
#include "AllHeaders.h"

class CheckpointProperties;
class CheckpointMessages;

class db_CheckPointProperties
{

public:
    db_CheckPointProperties(QSqlDatabase db);

    bool createConnection();
    QVector<CheckpointProperties> loadCheckPointProperies(int SelectedGuidSignal, int SelectedF_X, int SelectedF_Y);
    QVector<CheckpointMessages> loadCheckPointMessages(const int& F_GUID);
private:
    QVector<CheckpointProperties> vecCheckpointProperties;

    QSqlDatabase db;

    QVector<CheckpointMessages> vecCheckpointMessages;


    
};

#endif // DB_CHECKPOINTPROPERTIES_H
