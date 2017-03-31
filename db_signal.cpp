#include "db_signal.h"

db_Signal::db_Signal(): QThread()
{
    m_stop = false;


    //oldQdt.setDate(QDate(2013,02,04));
             //   oldQdt.setTime(QTime(06,41,40));
   // qDebug() << oldQdt;
            //(QDate(2013,02,04),QTime(16,21,00)),

    //oldQdt =qdt;

 //   qdt =   oldQdt.addSecs(300);

   // qDebug() << qdt;
    timeBegin, timeEnd;


    //timeBegin = oldQdt.toString(Qt::SystemLocaleShortDate);
    //timeEnd = qdt.toString(Qt::SystemLocaleShortDate);

    timeBegin = DateTimeToString(oldQdt);

    timeEnd = DateTimeToString(qdt);

     vec_Signal = new vec_signal(vecSignal);



}

void db_Signal::run()
{
    while(!m_stop)
    {


        oldQdt = qdt;

        qdt = oldQdt.addSecs(300);

        timeBegin = DateTimeToString(oldQdt);

        timeEnd = DateTimeToString(qdt);



        loadTableSignal(timeBegin, timeEnd);

       //vSignal->vSignal.clear();

        //emit(writeToDialog(*vec_Signal));

        emit(writeToDialog(vecSignal));

        sleep(1);


    }

}


bool db_Signal::loadDatabase()
{
   /* db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("arsmssv2");
    db.setUserName("root");
    db.setPassword("password"); */


    db.setHostName(HOST);
    db.setDatabaseName(DB_NAME);
    db.setUserName(USERNAME);
    db.setPassword(PASSWORD);

    if(!db.open()){
        db.lastError().text();
        //cerr << qPrintable("error");
      //  qDebug() << "error";



        return false;

        }
    return true;
}

QVector<Signal> db_Signal::loadTableSignal(QString dataTime1, QString dataTime2)
{
    QSqlQuery query(db);

    //query.exec("SELECT GUID,  GUID_RM_PARAM, GUID_PLAN_TREE,TOP_STATE,LEFT_STATE,DISPLAY_TYPE");
    QString  sqlq;
   // dataTime1 = "2013-02-04 06:41:40";
  //  dataTime2 = "2013-02-04 06:41:50";

    //sqlq ="SELECT fr.ind,fr.F_GUID_SIGNAL,ta.F_ID, ta.F_VALUE FROM TBL_FRAME_SIGNAL as fr LEFT OUTER JOIN TBL_ARCHIVE_DATA AS ta ON fr.F_GUID_SIGNAL=ta.F_ID WHERE (F_DATETIME >\'" + dataTime1+"\')&&(F_DATETIME<\'" + dataTime2 + "\')";
    sqlq ="SELECT fr.F_GUID_FRAME, fr.F_GUID_SIGNAL,fr.F_RESOLUTION, ta.F_GUID, ta.F_VALUE FROM TBL_FRAME_SIGNAL as fr LEFT OUTER JOIN TBL_CURRENT_DATA_ANALOG AS ta ON fr.F_GUID_SIGNAL=ta.F_GUID ";
    //  / query.exec()/


    bool Issql = query.exec( sqlq);

                //            SELECT fr.ind,fr.F_GUID_SIGNAL,ta.F_ID, ta.F_VALUE FROM TBL_FRAME_SIGNAL\
                //   as fr LEFT OUTER JOIN `TBL_ARCHIVE_DATA` AS ta ON \
                //   fr.F_GUID_SIGNAL=ta.F_ID \
           // WHERE (F_DATETIME >" + dataTime1+"')&&(F_DATETIME<'" + dataTime2 + "'");

                   //'2013-02-04 06:41:40')&&(F_DATETIME<'2013-02-04 06:41:50'");





                   //qDebug() <<"Signal Query" <<Issql;

          //  QList<VisualParam> listVisualParam;

    Signal tmpSignal;

    int fr_index,F_GUID_SIGNAL,F_ID,F_GUID_FRAME;
    fr_index =0;
    F_GUID_SIGNAL=0;
    F_ID =0;
    F_GUID_FRAME =0;
    float F_VALUE=0;
    QString F_RESOLUTION="";

    //int guid,  guid_rm_param, guid_plan_tree,top_state,left_state,display_type;
   // QVector<Signal> tmpvecSignal;
    vecSignal.clear();

    while(query.next()) {



         //fr_index = query.value(0).toInt();
         F_GUID_FRAME = query.value(0).toInt();

         F_GUID_SIGNAL = query.value(1).toInt();
         F_RESOLUTION = query.value(2).toString();
         F_ID = query.value(3).toInt();
         F_VALUE = query.value(4).toFloat();
         //F_GUID_DEVICE = query.value(4).toInt();
         //FloatValue = query.value(5).toInt();





        // tmpSignal.set_fr_index(fr_index);
         tmpSignal.set_F_GUID_FRAME(F_GUID_FRAME);
         tmpSignal.set_F_GUID_SIGNAL(F_GUID_SIGNAL);
         tmpSignal.set_F_RESOLUTION(F_RESOLUTION);
         tmpSignal.set_F_ID(F_ID);
         tmpSignal.set_FloatValue(F_VALUE);


         vecSignal.append(tmpSignal);

        // tmpvecSignal.append(tmpSignal);

    }

    int i=0;
    i++;

    return vecSignal;


}

QVector<Signal> db_Signal::loadArchiveTableSignal(QDateTime dataTime1, QDateTime dataTime2,int SelectedGuidSignal, QSqlDatabase sq)
{
     QSqlQuery query(sq);


    QString  sqlq,sdataTime1,sdataTime2, sSelectedGuidSignal;
    sdataTime1 = DateTimeToString(dataTime1);
    sdataTime2 = DateTimeToString(dataTime2);
    sSelectedGuidSignal = QString::number(SelectedGuidSignal);

    //query.prepare("SELECT F_ID, F_VALUE FROM  TBL_ARCHIVE_DATA   WHERE ((F_ID = :bf_id ) AND (F_DATETIME > :bdataTime1 ) AND (F_DATETIME<  :bdataTime2  ))");
    query.prepare("SELECT F_ID, F_VALUE, F_DATETIME FROM  TBL_ARCHIVE_DATA   WHERE ((F_ID = ? ) AND (F_DATETIME > ? ) AND (F_DATETIME<  ? ))");

   // query.prepare("SELECT F_ID, F_VALUE FROM  TBL_ARCHIVE_DATA   WHERE ( (F_DATETIME >\' ? \') AND (F_DATETIME< \' ? \' ))");

   //query.prepare("SELECT F_ID, F_VALUE FROM  TBL_ARCHIVE_DATA   WHERE ( (F_DATETIME > ? ) AND (F_DATETIME<  ?  ))");

    query.bindValue(0, SelectedGuidSignal);
    query.bindValue(1, sdataTime1);
    query.bindValue(2, sdataTime2);

    bool Issql = query.exec( );

    QString lastquerry =query.executedQuery();
    lastquerry = query.lastQuery();

   // QSqlQuery query;






                  // qDebug() <<"Signal Query" <<Issql;

          //  QList<VisualParam> listVisualParam;

    Signal tmpSignal;

    int fr_index,F_GUID_SIGNAL,F_ID;
    float F_VALUE=0;
    QString strCurrentDataTime;
    QDateTime qCurrentDataTime;

    //int guid,  guid_rm_param, guid_plan_tree,top_state,left_state,display_type;
   // QVector<Signal> tmpvecSignal;
    vecSignal.clear();

    while(query.next()) {



        // fr_index = query.value(0).toInt();
        // F_GUID_SIGNAL = query.value(1).toInt();
         F_ID = query.value(0).toInt();
         F_VALUE = query.value(1).toFloat();
         strCurrentDataTime = query.value(2).toString();
       //  qDebug() << strCurrentDataTime;
         qCurrentDataTime = DateTimeFromString(strCurrentDataTime);
         //F_GUID_DEVICE = query.value(4).toInt();
         //FloatValue = query.value(5).toInt();





         tmpSignal.set_fr_index(0);
         tmpSignal.set_F_GUID_SIGNAL(0);
         tmpSignal.set_F_ID(F_ID);
         tmpSignal.set_FloatValue(F_VALUE);
         //tmpSignal.set_currentTime(qCurrentDataTime);
         //tmpSignal.set_currentTime(qCurrentDataTime);
         tmpSignal.set_currentTime(qCurrentDataTime);
         vecSignal.append(tmpSignal);
         //hash_sig.

        // tmpvecSignal.append(tmpSignal);

    }

    int i=0;
    i++;

    return vecSignal;
}


void db_Signal::stop()
{
    m_stop = true;
}

db_Signal::~db_Signal()
{
    delete vec_Signal;
}

QString db_Signal::DateTimeToString(QDateTime qt)
{
QDate oldDate = qt.date();
QTime oldTime = qt.time();

 QString dt = oldDate.toString("yyyy-MM-dd");
 QString tm = oldTime.toString("hh:mm:ss");
 dt = dt +" "+ tm;
 return dt;
}

QDateTime db_Signal::DateTimeFromString(QString strDateTime)
{
 return QDateTime::fromString ( strDateTime, "yyyy-MM-ddThh:mm:ss" );

}


