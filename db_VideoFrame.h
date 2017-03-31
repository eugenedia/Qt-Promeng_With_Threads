#ifndef DB_VIDEOFRAME_H
#define DB_VIDEOFRAME_H
#include "AllHeaders.h"

class VideoFrame;

class db_VideoFrame
{
public:
    db_VideoFrame(QSqlDatabase & db);

    QVector<VideoFrame> loadVideoFrames();



private:
    QSqlDatabase db;
};




#endif // DB_VIDEOFRAME_H
