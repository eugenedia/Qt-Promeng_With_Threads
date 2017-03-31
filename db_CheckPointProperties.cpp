#include "db_CheckPointProperties.h"

db_CheckPointProperties::db_CheckPointProperties(QSqlDatabase db)
{
    this->db=db;

}





QVector<CheckpointProperties> db_CheckPointProperties::loadCheckPointProperies(int SelectedGuidSignal,int SelectedF_X, int SelectedF_Y)
{
    QSqlQuery query(db);

    //query.exec("SELECT GUID,  GUID_RM_PARAM, GUID_PLAN_TREE,TOP_STATE,LEFT_STATE,DISPLAY_TYPE");
    QString  sqlq;
   // dataTime1 = "2013-02-04 06:41:40";
  //  dataTime2 = "2013-02-04 06:41:50";

    QString GuidSignal = QString::number(SelectedGuidSignal);
    QString F_X = QString::number(SelectedF_X);
    QString F_Y = QString::number(SelectedF_Y);
    //" SELECT fr.ind,fr.F_GUID_SIGNAL,fr.F_X,fr.F_Y, sg.F_GUID_DEVICE," \

    sqlq = " SELECT fr.F_X,fr.F_GUID_SIGNAL,fr.F_X,fr.F_Y, sg.F_GUID_DEVICE," \
            "sg.F_GUID, chk.F_GUID, chk.F_GUID_CHECKPOINT_TYPE, chk.F_GUID_DEVICE, chk.F_GUID_LOCATION," \
            "chk.F_LO_RANGE, chk.F_HI_RANGE, chk.F_THRESHOLD_1, chk.F_THRESHOLD_2, chk.F_DESCRIPTION," \
            "chk.F_UOM, chk.F_SCALE, chk.F_TIMEOUT, chk.F_ARC_INTERVAL, chk.F_ARC_DELTA," \

            "ChkObj.F_GUID, ChkObj.F_NAME, ChkObj.F_DISPLAY_LABEL,ChkObj.F_DESCRIPTION," \

            "dev.F_GUID, dev.F_GUID_DEVICE_TYPE, dev.F_GUID_MODULE, dev.F_GUID_PARENT_DEVICE, dev.F_ADDR," \
            "dev.F_ENABLED, dev.F_PHONE_NUMBER, dev.F_REDIAL_COUNT,dev.F_NEED_PING,dev.F_PORT," \

            "obj.F_GUID, obj.F_NAME, obj.F_DISPLAY_LABEL,obj.F_DESCRIPTION "  \



            "FROM TBL_FRAME_SIGNAL " \
            "as fr LEFT JOIN TBL_SIGNAL AS sg ON " \
            "fr.F_GUID_SIGNAL=sg.F_GUID " \
            "LEFT JOIN TBL_CHECKPOINT as chk ON " \
            "sg.F_GUID_CONTROLED_OBJECT = chk.F_GUID " \
            "LEFT JOIN TBL_OBJECT as ChkObj ON " \
            "chk.F_GUID = ChkObj.F_GUID " \
            "LEFT JOIN TBL_DEVICE as dev ON " \
            "chk.F_GUID_DEVICE = dev.F_GUID " \
            "LEFT JOIN TBL_OBJECT as obj ON " \
            "dev.F_GUID = obj.F_GUID " \
            "where (fr.F_GUID_SIGNAL= " + GuidSignal +") AND  (fr.F_X = " + F_X  + ") AND (fr.F_Y= " + F_Y +  ")";



    //  / query.exec()/


    bool Issql = query.exec( sqlq);

     if(!Issql)  QMessageBox::critical(0,  QObject::tr("Error"),  QObject::tr("Error when access TBL_FRAME_SIGNAL, TBL_SIGNAL,TBL_CHECKPOINT"));



    CheckpointProperties chkProp;

    while(query.next()) {

                            //query.value(0).toInt();
        chkProp.FRAME_F_GUID_SIGNAL=  query.value(1).toInt();
        chkProp.FRAME_F_X= query.value(2).toInt();
        chkProp.FRAME_F_Y= query.value(3).toInt();

        chkProp.CheckPoint_F_GUID=query.value(6).toInt();
        chkProp.CheckPoint_F_GUID_CHECKPOINT_TYPE=query.value(7).toInt();
        chkProp.CheckPoint_F_GUID_DEVICE=query.value(8).toInt();
        chkProp.CheckPoint_F_GUID_LOCATION=query.value(9).toInt();
        chkProp.CheckPoint_F_LO_RANGE=query.value(10).toDouble();
        chkProp.CheckPoint_F_HI_RANGE=query.value(11).toDouble();
        chkProp.CheckPoint_F_THRESHOLD_1=query.value(12).toDouble();
        chkProp.CheckPoint_F_THRESHOLD_2=query.value(13).toDouble();
        chkProp.CheckPoint_F_DESCRIPTION=query.value(14).toString();
        chkProp.CheckPoint_F_UOM=query.value(15).toString();
        chkProp.CheckPoint_F_SCALE=query.value(16).toInt();
        chkProp.CheckPoint_F_TIMEOUT=query.value(17).toInt();
        chkProp.CheckPoint_F_ARC_INTERVAL=query.value(18).toInt();
        chkProp.CheckPoint_F_ARC_DELTA=query.value(19).toDouble();

        chkProp.CheckpointObject_F_GUID=query.value(20).toInt();
        chkProp.CheckpointObject_F_NAME=query.value(21).toString();
        chkProp.CheckpointObject_F_DISPLAY_LABEL=query.value(22).toString();
        chkProp.CheckpointObject_F_DESCRIPTION=query.value(23).toString();


        chkProp.dev_F_GUID=query.value(24).toInt();
        chkProp.dev_F_GUID_DEVICE_TYPE=query.value(25).toInt();
        chkProp.dev_F_GUID_MODULE=query.value(26).toInt();
        chkProp.dev_F_GUID_PARENT_DEVICE=query.value(27).toInt();
        chkProp.dev_F_ADDR=query.value(28).toString();
        chkProp.dev_F_ENABLED= query.value(29).toInt();
        chkProp.dev_F_PHONE_NUMBER=query.value(30).toString();
        chkProp.dev_F_REDIAL_COUNT=query.value(31).toInt();
        chkProp.dev_F_NEED_PING=query.value(32).toInt();
        chkProp.dev_F_PORT=query.value(33).toString();

        chkProp.obj_F_GUID=query.value(34).toInt();
        chkProp.obj_F_NAME=query.value(35).toString();
        chkProp.obj_F_DISPLAY_LABEL=query.value(36).toString();
        chkProp.obj_F_DESCRIPTION=query.value(37).toString();




        vecCheckpointProperties.append(chkProp);

    }

    return vecCheckpointProperties;


}


QVector<CheckpointMessages> db_CheckPointProperties::loadCheckPointMessages(const int &F_GUID)
{

    QSqlQuery query(db);


    QString  sqlq;


    QString strF_GUID = QString::number(F_GUID);

     // Получаем gid чекпойнта.

    /* sqlq = "SELECT sg.F_GUID_DEVICE, sg.F_GUID, " \
            "tcd.F_GUID, tcd.F_VALUE, " \
            "tst.F_GUID_MSG_SET, tbo.F_DISPLAY_LABEL, tbo.F_CODE " \

            "FROM TBL_SIGNAL as sg LEFT JOIN " \
            "TBL_CURRENT_DATA_DISCRET as tcd ON sg.F_GUID = tcd.F_GUID " \
            "LEFT JOIN TBL_SIGNAL_TYPE as tst ON " \
            "sg.F_GUID_SIGNAL_TYPE = tst.F_GUID " \
            "LEFT JOIN TBL_OBJECT as tbo ON " \
            "tst.F_GUID_MSG_SET = tbo.F_GUID " \
            "WHERE (tcd.F_VALUE=1) AND (sg.F_GUID=" + strF_GUID + ")" ; */


            sqlq = "SELECT  chk.F_GUID, chk.F_GUID_CHECKPOINT_TYPE, chk.F_GUID_DEVICE, sg.F_GUID_DEVICE, sg.F_GUID, " \

                    "sig_type.F_GUID_MSG_SET, sig_type.F_TYPE, sig_type.F_GUID, " \

                    " tcd.F_VALUE, " \

                    "obj.F_DISPLAY_LABEL, obj.F_NAME, obj.F_CODE " \



                    "FROM   TBL_CHECKPOINT as chk LEFT JOIN " \

                    "TBL_SIGNAL as sg ON chk.F_GUID = sg.F_GUID_CONTROLED_OBJECT " \

                    "LEFT JOIN TBL_SIGNAL_TYPE as sig_type ON sg.F_GUID_SIGNAL_TYPE =  sig_type.f_GUID " \


                    "LEFT JOIN TBL_CURRENT_DATA_DISCRET as tcd ON sg.F_GUID = tcd.F_GUID " \

                    "LEFT JOIN TBL_OBJECT as obj ON  sig_type.F_GUID_MSG_SET = obj.F_GUID " \

                    "WHERE  (sg.F_GUID_CONTROLED_OBJECT= "+ strF_GUID + ") AND(tcd.F_VALUE=1) AND ((sig_type.F_TYPE=4)OR(sig_type.F_TYPE=2))";

                    //AND ((sig_type.F_TYPE=4)OR(sig_type.F_TYPE=2))AND(tcd.F_VALUE=1))";






         /*   SELECT  chk.F_GUID, chk.F_GUID_CHECKPOINT_TYPE, chk.F_GUID_DEVICE, sg.F_GUID_DEVICE, sg.F_GUID,
            sig_type.F_GUID_MSG_SET, sig_type.F_TYPE, sig_type.F_GUID,  tcd.F_VALUE, obj.F_DISPLAY_LABEL,
            obj.F_NAME, obj.F_CODE FROM
               TBL_CHECKPOINT as chk LEFT JOIN TBL_SIGNAL as sg ON chk.F_GUID = sg.F_GUID_CONTROLED_OBJECT
                LEFT JOIN TBL_SIGNAL_TYPE as sig_type ON sg.F_GUID_SIGNAL_TYPE =  sig_type.f_GUID
                 LEFT JOIN TBL_CURRENT_DATA_DISCRET as tcd ON sg.F_GUID = tcd.F_GUID
                  LEFT JOIN TBL_OBJECT as obj ON  sig_type.F_GUID_MSG_SET = obj.F_GUID WHERE   (sg.F_GUID_CONTROLED_OBJECT= 37) AND ((sig_type.F_TYPE=4)OR(sig_type.F_TYPE=2))AND(tcd.F_VALUE=1)*/















    //  / query.exec()/


    bool Issql = query.exec( sqlq);

    CheckpointMessages chkMsgs;

    while(query.next()) {


      chkMsgs.chk_F_GUID = query.value(0).toInt();
      chkMsgs.chk_F_GUID_CHECKPOINT_TYPE = query.value(1).toInt();
      chkMsgs.chk_F_GUID_DEVICE = query.value(2).toInt();


      chkMsgs.sg_F_GUID_DEVICE  = query.value(3).toInt();
      chkMsgs.sg_F_GUID =  query.value(4).toInt();

       chkMsgs.sig_type_F_GUID_MSG_SET = query.value(5).toInt();
       chkMsgs.sig_type_F_TYPE = query.value(6).toInt();
       chkMsgs.sig_type_F_GUID = query.value(7).toInt();

       chkMsgs.tcd_F_VALUE = query.value(8).toInt();;

       chkMsgs.obj_F_DISPLAY_LABEL = query.value(9).toString();
       chkMsgs.obj_F_NAME = query.value(10).toString();
       chkMsgs.tbo_F_CODE = query.value(11).toString();





       vecCheckpointMessages.append(chkMsgs);

    }

    return vecCheckpointMessages;

}
