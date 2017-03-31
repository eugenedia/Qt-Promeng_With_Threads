#ifndef CHECKPOINTPROPERTIES_H
#define CHECKPOINTPROPERTIES_H

#include <QObject>
#include "AllHeaders.h"

class CheckpointProperties
{


public:
    explicit CheckpointProperties();
    // CheckpointProperties(const CheckpointProperties&);
    // CheckpointProperties & operator=(const CheckpointProperties& chkProp );





public:
   // Signal();
   // void set_fr_index(int fr_index);
   // int get_fr_index();
    void copy(const CheckpointProperties & chkProp);




public:

    int FRAME_F_GUID_SIGNAL;
    int FRAME_F_X, FRAME_F_Y;

    int CheckPoint_F_GUID;
    int CheckPoint_F_GUID_CHECKPOINT_TYPE;
    int CheckPoint_F_GUID_DEVICE;
    int CheckPoint_F_GUID_LOCATION;
    double CheckPoint_F_LO_RANGE;
    double CheckPoint_F_HI_RANGE;
    double CheckPoint_F_THRESHOLD_1;
    double CheckPoint_F_THRESHOLD_2;
    QString CheckPoint_F_DESCRIPTION;
    QString CheckPoint_F_UOM;
    int CheckPoint_F_SCALE;
    int CheckPoint_F_TIMEOUT;
    int CheckPoint_F_ARC_INTERVAL;
    double CheckPoint_F_ARC_DELTA;

    int CheckpointObject_F_GUID;
    QString CheckpointObject_F_NAME;
    QString CheckpointObject_F_DISPLAY_LABEL;
    QString CheckpointObject_F_DESCRIPTION;


    int dev_F_GUID;
    int dev_F_GUID_DEVICE_TYPE;
    int dev_F_GUID_MODULE;
    int dev_F_GUID_PARENT_DEVICE;
    QString dev_F_ADDR;
    int dev_F_ENABLED;
    QString dev_F_PHONE_NUMBER;
    int dev_F_REDIAL_COUNT;
    int dev_F_NEED_PING;
    QString dev_F_PORT;

    int obj_F_GUID;
    QString obj_F_NAME;
    QString obj_F_DISPLAY_LABEL;
    QString obj_F_DESCRIPTION;







};

#endif // CHECKPOINTPROPERTIES_H





/*SELECT fr.ind,fr.F_GUID_SIGNAL,fr.F_X,fr.F_Y,

sg.F_GUID_DEVICE, sg.F_GUID,

chk.F_GUID, chk.F_GUID_CHECKPOINT_TYPE, chk.F_GUID_DEVICE, chk.F_GUID_LOCATION, chk.F_LO_RANGE,
chk.F_HI_RANGE, chk.F_THRESHOLD_1, chk.F_THRESHOLD_2, chk.F_DESCRIPTION,
chk.F_UOM, chk.F_SCALE, chk.F_TIMEOUT, chk.F_ARC_INTERVAL, chk.F_ARC_DELTA,

ChkObj.F_GUID, ChkObj.F_NAME, ChkObj.F_DISPLAY_LABEL,ChkObj.F_DESCRIPTION,

dev.F_GUID, dev.F_GUID_DEVICE_TYPE, dev.F_GUID_MODULE,
dev.F_GUID_PARENT_DEVICE, dev.F_ADDR, dev.F_ENABLED,
dev.F_PHONE_NUMBER, dev.F_REDIAL_COUNT,dev.F_NEED_PING,
dev.F_PORT,

obj.F_GUID, obj.F_NAME, obj.F_DISPLAY_LABEL,obj.F_DESCRIPTION



FROM TBL_FRAME_SIGNAL
               as fr LEFT JOIN TBL_SIGNAL AS sg ON
               fr.F_GUID_SIGNAL=sg.F_GUID
                LEFT JOIN TBL_CHECKPOINT as chk ON
                sg.F_GUID_CONTROLED_OBJECT = chk.F_GUID
                LEFT JOIN TBL_OBJECT as ChkObj ON
                chk.F_GUID = ChkObj.F_GUID
                LEFT JOIN TBL_DEVICE as dev ON
                chk.F_GUID_DEVICE = dev.F_GUID
                LEFT JOIN TBL_OBJECT as obj ON
                dev.F_GUID = obj.F_GUID
*/
