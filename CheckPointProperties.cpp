#include "CheckPointProperties.h"
#include <QString>

CheckpointProperties::CheckpointProperties()
    :
      FRAME_F_GUID_SIGNAL(0),
      FRAME_F_X(0), FRAME_F_Y(0),

      CheckPoint_F_GUID(0),
      CheckPoint_F_GUID_CHECKPOINT_TYPE(0),
      CheckPoint_F_GUID_DEVICE(0),
      CheckPoint_F_GUID_LOCATION(0),
      CheckPoint_F_LO_RANGE(0),
      CheckPoint_F_HI_RANGE(0),
      CheckPoint_F_THRESHOLD_1(0),
      CheckPoint_F_THRESHOLD_2(0),
      CheckPoint_F_DESCRIPTION(" "),
      CheckPoint_F_UOM(" "),
      CheckPoint_F_SCALE(0),
      CheckPoint_F_TIMEOUT(0),
      CheckPoint_F_ARC_INTERVAL(0),
      CheckPoint_F_ARC_DELTA(0),

      CheckpointObject_F_GUID(0),
      CheckpointObject_F_NAME(" "),
      CheckpointObject_F_DISPLAY_LABEL(" "),
      CheckpointObject_F_DESCRIPTION(" "),


      dev_F_GUID(0),
      dev_F_GUID_DEVICE_TYPE(0),
      dev_F_GUID_MODULE(0),
      dev_F_GUID_PARENT_DEVICE(0),
      dev_F_ADDR(" "),
      dev_F_ENABLED(0),
      dev_F_PHONE_NUMBER(" "),
      dev_F_REDIAL_COUNT(0),
      dev_F_NEED_PING(0),
      dev_F_PORT(" "),

      obj_F_GUID(0)
      //obj_F_NAME(" "),
     // obj_F_DISPLAY_LABEL(" "),
      //obj_F_DESCRIPTION(" "),


{

}

void CheckpointProperties::copy(const CheckpointProperties &chkProp)
{
     FRAME_F_GUID_SIGNAL=chkProp.FRAME_F_GUID_SIGNAL;
     FRAME_F_X=chkProp.FRAME_F_X;
     FRAME_F_Y=chkProp.FRAME_F_Y;

     CheckPoint_F_GUID=chkProp.CheckPoint_F_GUID;
     CheckPoint_F_GUID_CHECKPOINT_TYPE=chkProp.CheckPoint_F_GUID_CHECKPOINT_TYPE;
     CheckPoint_F_GUID_DEVICE=chkProp.CheckPoint_F_GUID_DEVICE;
     CheckPoint_F_GUID_LOCATION=chkProp.CheckPoint_F_GUID_LOCATION;
     CheckPoint_F_LO_RANGE=chkProp.CheckPoint_F_LO_RANGE;
     CheckPoint_F_HI_RANGE=chkProp.CheckPoint_F_HI_RANGE;
     CheckPoint_F_THRESHOLD_1=chkProp.CheckPoint_F_THRESHOLD_1;
     CheckPoint_F_THRESHOLD_2=chkProp.CheckPoint_F_THRESHOLD_2;
     CheckPoint_F_DESCRIPTION=chkProp.CheckPoint_F_DESCRIPTION;
     CheckPoint_F_UOM=chkProp.CheckPoint_F_UOM;
     CheckPoint_F_SCALE=chkProp.CheckPoint_F_SCALE;
     CheckPoint_F_TIMEOUT=chkProp.CheckPoint_F_TIMEOUT;
     CheckPoint_F_ARC_INTERVAL=chkProp.CheckPoint_F_ARC_INTERVAL;
     CheckPoint_F_ARC_DELTA=chkProp.CheckPoint_F_ARC_DELTA;

     CheckpointObject_F_GUID=chkProp.CheckpointObject_F_GUID;
     CheckpointObject_F_NAME=chkProp.CheckpointObject_F_NAME;
     CheckpointObject_F_DISPLAY_LABEL=chkProp.CheckpointObject_F_DISPLAY_LABEL;
     CheckpointObject_F_DESCRIPTION=chkProp.CheckpointObject_F_DESCRIPTION;


     dev_F_GUID=chkProp.dev_F_GUID;
     dev_F_GUID_DEVICE_TYPE=chkProp.dev_F_GUID_DEVICE_TYPE;
     dev_F_GUID_MODULE=chkProp.dev_F_GUID_MODULE;
     dev_F_GUID_PARENT_DEVICE=chkProp.dev_F_GUID_PARENT_DEVICE;
     dev_F_ADDR=chkProp.dev_F_ADDR;
     dev_F_ENABLED=chkProp.dev_F_ENABLED;
     dev_F_PHONE_NUMBER=chkProp.dev_F_PHONE_NUMBER;
     dev_F_REDIAL_COUNT=chkProp.dev_F_REDIAL_COUNT;
     dev_F_NEED_PING=chkProp.dev_F_NEED_PING;
     dev_F_PORT=chkProp.dev_F_PORT;

     obj_F_GUID=chkProp.obj_F_GUID;
     obj_F_NAME=chkProp.obj_F_NAME;
     obj_F_DISPLAY_LABEL=chkProp.obj_F_DISPLAY_LABEL;
     obj_F_DESCRIPTION=chkProp.obj_F_DESCRIPTION;


    CheckPoint_F_DESCRIPTION = chkProp.CheckpointObject_F_DESCRIPTION;
    CheckPoint_F_UOM = chkProp.CheckPoint_F_UOM;
    CheckpointObject_F_NAME = chkProp.CheckpointObject_F_NAME;
    CheckpointObject_F_DISPLAY_LABEL = chkProp.CheckpointObject_F_DISPLAY_LABEL;
    CheckpointObject_F_DESCRIPTION = chkProp.CheckpointObject_F_DESCRIPTION;

    dev_F_ADDR = chkProp.dev_F_ADDR;
    dev_F_PHONE_NUMBER = chkProp.dev_F_PHONE_NUMBER;
    dev_F_PORT = chkProp.dev_F_PORT;

    obj_F_NAME = chkProp.obj_F_NAME;
    obj_F_DISPLAY_LABEL = chkProp.obj_F_DISPLAY_LABEL;
    obj_F_DESCRIPTION = chkProp.obj_F_DESCRIPTION;

}



/* CheckpointProperties::CheckpointProperties(const CheckpointProperties& chkProp)
    : QObject(parent)
{
    copy(chkProp);
}

 CheckpointProperties & CheckpointProperties::operator=(const CheckpointProperties& chkProp )
 {
     copy(chkProp);
     return *this;

 }*/
