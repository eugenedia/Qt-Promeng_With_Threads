#ifndef VISUALPARAM_H
#define VISUALPARAM_H

#include "AllHeaders.h"



class VisualParam
{
public:
    VisualParam();

    void set_fr_index(int fr_index);
    int get_fr_index();
    int get_F_GUID_FRAME();
    void set_F_GUID_FRAME(int F_GUID_FRAME);
    void set_F_GUID_SIGNAL(int F_GUID_SIGNAL);
    int get_F_GUID_SIGNAL();
    QString get_F_RESOLUTION();
    void set_F_RESOLUTION(QString F_RESOLUTION);
    void set_F_X(int F_X);
    int get_F_X();
    void set_F_Y(int F_Y);
    int get_F_Y();
    void set_F_GUID_DEVICE(int F_GUID_DEVICE);
    int get_F_GUID_DEVICE();
    void set_FloatValue(float FloatValue);
    float get_FloatValue();
    //void set_F_GUID_FRAME(int F_GUID_FRAME);
    //int get_F_GUID_FRAME();
    void set_isModified(bool isModified);
    bool get_isModified();
    void set_isNewRecord(bool isNewRecord);
    bool get_isNewRecord();
    void set_isForRemove(bool isForRemove);
    bool get_isForRemove();

private:

    int fr_index;
    int F_GUID_FRAME;
    int F_GUID_SIGNAL;
    QString F_RESOLUTION;
    int F_X;
    int F_Y;
    int F_GUID_DEVICE;
    float FloatValue;
    //int F_GUID_FRAME;
    bool isModified;
    bool isNewRecord;
    bool isForRemove;

  /*  int guid;
    int guid_rm_param;
    int guid_plan_tree;
    int top_state;
    int left_state;
    int display_type;


    fr.ind,fr.F_GUID_SIGNAL,fr.F_X,fr.F_Y,sg.F_GUID_DEVICE, sg.F_GUID FROM TBL_FRAME_SIGNAL \
                   as fr LEFT OUTER JOIN TBL_SIGNAL AS sg ON \
                   fr.F_GUID_SIGNAL=sg.F_GUID*/

};

#endif // VISUALPARAM_H
