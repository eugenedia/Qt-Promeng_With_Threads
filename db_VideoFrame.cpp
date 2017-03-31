#include "db_VideoFrame.h"

db_VideoFrame::db_VideoFrame(QSqlDatabase &db)
{
    this->db=db;
}

QVector<VideoFrame> db_VideoFrame::loadVideoFrames()
{

    QSqlQuery query(db);



    bool Issql = query.exec("SELECT F_GUID, F_NAME, F_DISPLAY_LABEL, F_SHORT_NAME " \
                             "FROM TBL_FRAME");






     //qDebug() << Issql;

     if(!Issql)  QMessageBox::critical(0,  QObject::tr("Error"),  QObject::tr("Error when access TBL_FRAME"));

    QVector<VideoFrame> vfr;

    VideoFrame tmpVideoFrame;



    //float FloatValue = 0.0;

    //int guid,  guid_rm_param, guid_plan_tree,top_state,left_state,display_type;

    while(query.next()) {





        tmpVideoFrame.F_GUID = query.value(0).toInt();
        tmpVideoFrame.F_NAME  =  query.value(1).toString();
        tmpVideoFrame.F_DISPLAY_LABEL = query.value(2).toString();
        tmpVideoFrame.F_SHORT_NAME = query.value(3).toString();

        //qDebug() << tmpVideoFrame.F_NAME;


         vfr.append(tmpVideoFrame);

    }



    return vfr;





}
