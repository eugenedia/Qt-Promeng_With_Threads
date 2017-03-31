#include "VisualParam.h"

VisualParam::VisualParam():
    fr_index(0),F_GUID_SIGNAL(0),F_X(0),F_Y(0),F_GUID_DEVICE(0),FloatValue(0.0),F_GUID_FRAME(0),
    isModified(false),
    isNewRecord(false),
    isForRemove(false)
{
}

void VisualParam::set_fr_index(int fr_index)
{
    this->fr_index = fr_index;
}
int VisualParam::get_fr_index()
{
    return fr_index;
}



void VisualParam::set_F_GUID_SIGNAL(int F_GUID_SIGNAL)
{
    this->F_GUID_SIGNAL = F_GUID_SIGNAL;
}


int VisualParam::get_F_GUID_SIGNAL()
{
    return F_GUID_SIGNAL;
}

QString VisualParam::get_F_RESOLUTION()
{
    return F_RESOLUTION;
}

void VisualParam::set_F_RESOLUTION(QString F_RESOLUTION)
{
    this->F_RESOLUTION = F_RESOLUTION;
}

void VisualParam::set_F_X(int F_X)
{
    this->F_X = F_X;
}
int VisualParam::get_F_X()
{
   return F_X;
}


void VisualParam::set_F_Y(int F_Y)
{
    this->F_Y = F_Y;
}
/*void set_isModified(bool isModified);
bool get_isModified();
void set_isNewRecord(bool isNewRecord);
bool get_isNewRecord();
void set_isForRemove(bool isForRemove);
bool get_isForRemove();*/

int VisualParam::get_F_Y()
{
    return F_Y;
}
void VisualParam::set_F_GUID_DEVICE(int F_GUID_DEVICE)
{
    this->F_GUID_DEVICE = F_GUID_DEVICE;
}
int VisualParam::get_F_GUID_DEVICE()
{
   return F_GUID_DEVICE;
}
void VisualParam::set_FloatValue(float FloatValue)
{
     this->FloatValue = FloatValue;
}
float VisualParam::get_FloatValue()
{
    return FloatValue;
}

void VisualParam::set_F_GUID_FRAME(int F_GUID_FRAME)
{
    this->F_GUID_FRAME = F_GUID_FRAME;
}

int VisualParam::get_F_GUID_FRAME()
{
    return F_GUID_FRAME;
}

void VisualParam::set_isModified(bool isModified)
{
    this->isModified = isModified;
}
bool VisualParam::get_isModified()
{
    return isModified;
}
void VisualParam::set_isNewRecord(bool isNewRecord)
{
    this->isNewRecord = isNewRecord;
}
bool VisualParam::get_isNewRecord()
{
    return isNewRecord;
}
void VisualParam::set_isForRemove(bool isForRemove)
{
    this->isForRemove = isForRemove;
}
bool VisualParam::get_isForRemove()
{
    return isForRemove;
}
