#include "db_VisualParam.h"
#include <iostream>
#include <QtDebug>
#include "AllHeaders.h"


//using namespace std;

db_VisualParam::db_VisualParam(QSqlDatabase db)

{

this->db=db;

}

bool db_VisualParam::createConnection()
{

}




QList<VisualParam> db_VisualParam::loadTableVisualParam(int VideoFrameGuid,QString resolution)
{
    QSqlQuery query(db);

    QString strVideoFrameGuid = QString::number(VideoFrameGuid);

    //query.exec("SELECT GUID,  GUID_RM_PARAM, GUID_PLAN_TREE,TOP_STATE,LEFT_STATE,DISPLAY_TYPE");

    QString sqlq;

   // sqlq =  "SELECT fr.ind,fr.F_GUID_SIGNAL,fr.F_X,fr.F_Y,sg.F_GUID_DEVICE, sg.F_GUID, fr.F_GUID_FRAME FROM TBL_FRAME_SIGNAL " \
    //        "as fr LEFT OUTER JOIN TBL_SIGNAL AS sg ON " \
    //        "fr.F_GUID_SIGNAL=sg.F_GUID WHERE (fr.F_GUID_FRAME= " + strVideoFrameGuid + ")";

     sqlq =  "SELECT fr.F_GUID_FRAME, fr.F_GUID_SIGNAL,fr.F_RESOLUTION,fr.F_X,fr.F_Y,sg.F_GUID_DEVICE, sg.F_GUID FROM TBL_FRAME_SIGNAL " \
            "as fr LEFT OUTER JOIN TBL_SIGNAL AS sg ON " \
            "fr.F_GUID_SIGNAL=sg.F_GUID WHERE (fr.F_GUID_FRAME= " + strVideoFrameGuid + ") AND (fr.F_RESOLUTION= \"" + resolution + "\")";

    bool Issql = query.exec(sqlq);

    qDebug() <<"Load Table Visual Param" <<  Issql;

    // if(!Issql)  QMessageBox::critical(0, tr("Error"), tr("Error when access TBL_FRAME_SIGNAL and TBL_SIGNAL"));

     if(!Issql)  QMessageBox::critical(0,  QObject::tr("Error"),  QObject::tr("Error when access Visual Param"));


    VisualParam tmpVisualParam;

    int fr_index,F_GUID_SIGNAL,F_X,F_Y,F_GUID_DEVICE,F_GUID_FRAME;
    F_GUID_SIGNAL=0;
    F_X=0;
    F_Y=0;
    F_GUID_DEVICE =0;
    F_GUID_FRAME =0;

    QString F_RESOLUTION="";

    float FloatValue = 0.0;

    //int guid,  guid_rm_param, guid_plan_tree,top_state,left_state,display_type;

    while(query.next()) {



         //fr_index = query.value(0).toInt();
         F_GUID_FRAME = query.value(0).toInt();
         F_GUID_SIGNAL = query.value(1).toInt();
         F_RESOLUTION = query.value(2).toString();
         F_X = query.value(3).toInt();
         F_Y = query.value(4).toInt();
         F_GUID_DEVICE = query.value(5).toInt();
         //F_GUID_FRAME = query.value(6).toInt();
         //FloatValue = query.value(5).toInt();

//sql operator



         //tmpVisualParam.set_fr_index(fr_index);

         tmpVisualParam.set_F_GUID_FRAME(F_GUID_FRAME);
         tmpVisualParam.set_F_GUID_SIGNAL(F_GUID_SIGNAL);
          tmpVisualParam.set_F_RESOLUTION(F_RESOLUTION);
         tmpVisualParam.set_F_X(F_X);
         tmpVisualParam.set_F_Y(F_Y);
         tmpVisualParam.set_F_GUID_DEVICE(F_GUID_DEVICE);
         tmpVisualParam.set_FloatValue(FloatValue);


         listVisualParam.append(tmpVisualParam);

    }

    int i=0;
    i++;

    return listVisualParam;

}


QVector<VisualParam> db_VisualParam::loadTableVisualParamForAllFrame()
{
    QSqlQuery query(db);

    //QString strVideoFrameGuid = QString::number(VideoFrameGuid);

    //query.exec("SELECT GUID,  GUID_RM_PARAM, GUID_PLAN_TREE,TOP_STATE,LEFT_STATE,DISPLAY_TYPE");

    QString sqlq;

   /* sqlq =  "SELECT fr.ind,fr.F_GUID_SIGNAL,fr.F_X,fr.F_Y,sg.F_GUID_DEVICE, sg.F_GUID, fr.F_GUID_FRAME FROM TBL_FRAME_SIGNAL " \
            "as fr LEFT OUTER JOIN TBL_SIGNAL AS sg ON " \
            "fr.F_GUID_SIGNAL=sg.F_GUID";*/

      sqlq =  "SELECT fr.F_GUID_FRAME, fr.F_GUID_SIGNAL,fr.F_RESOLUTION,fr.F_X,fr.F_Y,sg.F_GUID_DEVICE, sg.F_GUID FROM TBL_FRAME_SIGNAL " \
            "as fr LEFT OUTER JOIN TBL_SIGNAL AS sg ON " \
            "fr.F_GUID_SIGNAL=sg.F_GUID";


    bool Issql = query.exec(sqlq);

    qDebug() << "loadTableVisualParamForAllFrame()" << Issql;



    VisualParam tmpVisualParam;

    int fr_index,F_GUID_SIGNAL,F_X,F_Y,F_GUID_DEVICE,F_GUID_FRAME;
    F_GUID_SIGNAL=0;
    F_X=0;
    F_Y=0;
    F_GUID_DEVICE =0;
    F_GUID_FRAME =0;

    QString F_RESOLUTION="";




    float FloatValue = 0.0;

    //int guid,  guid_rm_param, guid_plan_tree,top_state,left_state,display_type;

    while(query.next()) {


         F_GUID_FRAME = query.value(0).toInt();
         F_GUID_SIGNAL = query.value(1).toInt();
         F_RESOLUTION = query.value(2).toString();
         F_X = query.value(3).toInt();
         F_Y = query.value(4).toInt();
         F_GUID_DEVICE = query.value(5).toInt();



         /*fr_index = query.value(0).toInt();
         F_GUID_SIGNAL = query.value(1).toInt();
         F_X = query.value(2).toInt();
         F_Y = query.value(3).toInt();
         F_GUID_DEVICE = query.value(4).toInt();
         F_GUID_FRAME = query.value(6).toInt();*/
         //FloatValue = query.value(5).toInt();




         tmpVisualParam.set_F_GUID_FRAME(F_GUID_FRAME);
         tmpVisualParam.set_F_GUID_SIGNAL(F_GUID_SIGNAL);
          tmpVisualParam.set_F_RESOLUTION(F_RESOLUTION);
         tmpVisualParam.set_F_X(F_X);
         tmpVisualParam.set_F_Y(F_Y);
         tmpVisualParam.set_F_GUID_DEVICE(F_GUID_DEVICE);
         tmpVisualParam.set_FloatValue(FloatValue);

         //tmpVisualParam.set_fr_index(fr_index);
         /*tmpVisualParam.set_F_GUID_SIGNAL(F_GUID_SIGNAL);
         tmpVisualParam.set_F_X(F_X);
         tmpVisualParam.set_F_Y(F_Y);
         tmpVisualParam.set_F_GUID_DEVICE(F_GUID_DEVICE);
         tmpVisualParam.set_FloatValue(FloatValue);
         tmpVisualParam.set_F_GUID_FRAME(F_GUID_FRAME);*/

         vVisualParam.append(tmpVisualParam);

    }

    int i=0;
    i++;

    return vVisualParam;

}

bool db_VisualParam::updateVisualParam(QVector<VisualParam> vp, QVector<VisualParam> vRemovedChekpoints)
{
    QSqlQuery query(db);

    QString  sqlq;

    bool result = true;
    bool isitNotNewRecord =true;

    for(int i=0; i<vp.count(); i++)
    {
        isitNotNewRecord = !(vp[i].get_isNewRecord());
        if(vp[i].get_isModified()&& isitNotNewRecord)
        {

           QString lF_GUID_FRAME = QString::number(vp[i].get_F_GUID_FRAME());
           QString lF_GUID_SIGNAL = QString::number(vp[i].get_F_GUID_SIGNAL());
           QString lF_RESOLUTION = vp[i].get_F_RESOLUTION();
           //QString lfr_index = QString::number(vp[i].get_fr_index());
           QString lF_GUID_DEVICE = QString::number( vp[i].get_F_GUID_DEVICE());

           QString lF_X =QString::number(vp[i].get_F_X());
           QString lF_Y =QString::number(vp[i].get_F_Y());

         /*  QString login =  lp[i].F_LOGIN;
           QString password = lp[i].F_PASSWORD;
           QString name = lp[i].F_NAME;
           int amask = lp[i].F_ACCESS_MASK;
           QString strAmask = QString::number(amask);
           QString prevLogin = lp[i].prev_F_LOGIN;*/

           sqlq = " UPDATE TBL_FRAME_SIGNAL "\
           "SET "\
           "F_X = \'"  + lF_X + "\', "\
           "F_Y = \'"  + lF_Y + "\' "
           "WHERE (F_GUID_FRAME = \'" + lF_GUID_FRAME + "\' )AND (F_GUID_SIGNAL =\'"+lF_GUID_SIGNAL+ "\' ) AND (F_RESOLUTION=\'" +lF_RESOLUTION + "\')" ;

           //"ind =\'" + lfr_index + "\', "  \
             //"F_GUID_FRAME = \'"  + lF_GUID_FRAME + "\', "\
           //"F_GUID_SIGNAL = \'"  + lF_GUID_SIGNAL + "\', "\
           //"F_RESOLUTION = \'" + lF_RESOLUTION + "\', "\
            //"WHERE ind = \'" + lfr_index + "\' ";

           bool Issql = query.exec(sqlq);

           if(!Issql) result = false;

           qDebug() << "Update TBL_FRAME_SIGNAL operator " << Issql;

          // TBL_SIGNAL

          sqlq = " UPDATE TBL_SIGNAL "
           " SET "\
          " F_GUID_DEVICE =\'" +lF_GUID_DEVICE +  "\' " \
           "WHERE F_GUID = \'" + lF_GUID_SIGNAL + "\' ";

           //" F_GUID =\'" +lF_GUID_SIGNAL +  "\', " \

          Issql = query.exec(sqlq);

          if(!Issql) result = false;

          qDebug() << "Update TBL_SIGNAL operator " << Issql;







        }

        if(vp[i].get_isNewRecord())
        {

            QString lF_GUID_FRAME = QString::number(vp[i].get_F_GUID_FRAME());
            //QString lfr_index = QString::number(vp[i].get_fr_index());
            QString lF_GUID_DEVICE = QString::number( vp[i].get_F_GUID_DEVICE());
            QString lF_RESOLUTION = vp[i].get_F_RESOLUTION();
            QString lF_GUID_SIGNAL = QString::number(vp[i].get_F_GUID_SIGNAL());
            QString lF_X =QString::number(vp[i].get_F_X());
            QString lF_Y =QString::number(vp[i].get_F_Y());

          /*  QString login =  lp[i].F_LOGIN;
            QString password = lp[i].F_PASSWORD;
            QString name = lp[i].F_NAME;
            int amask = lp[i].F_ACCESS_MASK;
            QString strAmask = QString::number(amask);
            QString prevLogin = lp[i].prev_F_LOGIN;*/

            sqlq = " INSERT INTO TBL_FRAME_SIGNAL "\
            "(F_GUID_FRAME,F_GUID_SIGNAL,F_RESOLUTION, F_X, F_Y) VALUES"\
            "(\'" +  lF_GUID_FRAME + "\', "\
            "\'" +  lF_GUID_SIGNAL + "\', "\
            "\'" +  lF_RESOLUTION + "\', "\
            "\'" +  lF_X + "\', "\
            "\'" +  lF_Y + "\' "\
            "        ) ";



            bool Issql = query.exec(sqlq);

            if(!Issql) result = false;

            qDebug() << "Insert TBL_FRAME_SIGNAL operator " << Issql;



             sqlq = " INSERT INTO TBL_SIGNAL "\
             "(F_GUID, F_GUID_DEVICE) VALUES "\
             "(\'" +  lF_GUID_SIGNAL + "\', "\
            "\'" +  lF_GUID_DEVICE + "\'"\
            " ) ";



          Issql = query.exec(sqlq);
// "WHERE ind = \'" + lfr_index + "\' ";
          if(!Issql) result = false;

          qDebug() << "Insert TBL_SIGNAL operator " << Issql;















            /*QString login =  lp[i].F_LOGIN;
            QString password = lp[i].F_PASSWORD;
            QString name = lp[i].F_NAME;
            int amask = lp[i].F_ACCESS_MASK;
            QString strAmask = QString::number(amask);


            sqlq =  "INSERT INTO TBL_ACCESS " \
            "(F_LOGIN, " \
            "F_PASSWORD, " \
            "F_NAME, " \
            "FQString lF_GUID_FRAME = QString::number(vp[i].get_F_GUID_FRAME());
            //QString lfr_index = QString::number(vp[i].get_fr_index());
            QString lF_GUID_DEVICE = QString::number( vp[i].get_F_GUID_DEVICE());
            QString lF_RESOLUTION = vp[i].get_F_RESOLUTION();_ACCESS_MASK) " \
            "VALUES " \
                    "( \'" + login + "\', " \
                    "\'" + password + "\', " \
                    "\'" + name + "\', "\
                    "\'" + strAmask + "\') ";

            bool Issql = query.exec(sqlq);

            if(!Issql) result = false;



            qDebug() << "Insert sql operator " << Issql;*/


        }




    }

    if(vRemovedChekpoints.count()>0)
    {
        for(int i=0; i<vRemovedChekpoints.count(); i++)
        {
                //QString login =  vRemovedItems[i].F_LOGIN;

                //QString lfr_index = QString::number(vp[i].get_fr_index());
                QString lF_GUID_FRAME = QString::number(vp[i].get_F_GUID_FRAME());
            //QString lfr_index = QString::number(vp[i].get_fr_index());
               // QString lF_GUID_DEVICE = QString::number( vp[i].get_F_GUID_DEVICE());
                QString lF_GUID_SIGNAL = QString::number(vp[i].get_F_GUID_SIGNAL());
                QString lF_RESOLUTION = vp[i].get_F_RESOLUTION();

                 sqlq = " DELETE FROM TBL_FRAME_SIGNAL "\
                 "WHERE (F_GUID_FRAME = \'" + lF_GUID_FRAME + "\' )AND (F_GUID_SIGNAL =\'"+lF_GUID_SIGNAL+ "\' ) AND (F_RESOLUTION=\'" +lF_RESOLUTION + "\')" ;
                //"WHERE ind = \'" + lfr_index + "\' ";

                //sqlq =  "DELETE FROM TBL_ACCESS " \
                 //       "WHERE F_LOGIN = \'" + login + "\'";




                bool Issql = query.exec(sqlq);

                if(!Issql) result = false;



                qDebug() << "Delete FROM TBL_FRAME_SIGNAL " << Issql;


    } //*/
    }

    return result;
}





