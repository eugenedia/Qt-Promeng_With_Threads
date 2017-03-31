#ifndef CHECKPOINTMESSAGES_H
#define CHECKPOINTMESSAGES_H
#include "AllHeaders.h"


class CheckpointMessages
{

public:
    CheckpointMessages();
    
    int chk_F_GUID, chk_F_GUID_CHECKPOINT_TYPE, chk_F_GUID_DEVICE;
    int sg_F_GUID_DEVICE;
    int sg_F_GUID;

    int sig_type_F_GUID_MSG_SET;
    int sig_type_F_TYPE;
    int sig_type_F_GUID;


    int tcd_F_VALUE;

    QString obj_F_DISPLAY_LABEL;
    QString obj_F_NAME;
    QString tbo_F_CODE;

    
};

#endif // CHECKPOINTMESSAGES_H

/*SELECT sg.F_GUID_DEVICE, sg.F_GUID,
tcd.F_GUID, tcd.F_VALUE,
tst.F_GUID_MSG_SET, tbo.F_DISPLAY_LABEL, tbo.F_CODE

FROM TBL_SIGNAL
               as sg LEFT JOIN
TBL_CURRENT_DATA_DISCRET as tcd ON
               sg.F_GUID = tcd.F_GUID
LEFT JOIN TBL_SIGNAL_TYPE as tst ON
sg.F_GUID_SIGNAL_TYPE = tst.F_GUID
LEFT JOIN TBL_OBJECT as tbo ON
tst.F_GUID_MSG_SET = tbo.F_GUID




WHERE (tcd.F_VALUE=1)*/
