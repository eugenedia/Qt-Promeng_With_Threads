#include "Signal.h"



Signal::Signal(): fr_index(0),F_GUID_SIGNAL(0),F_ID(0), FloatValue(0.0)
{
}

void Signal::set_fr_index(int fr_index)
{
    this->fr_index = fr_index;
}
int Signal::get_fr_index()
{
    return fr_index;
}
void Signal::set_F_GUID_SIGNAL(int F_GUID_SIGNAL)
{
    this->F_GUID_SIGNAL = F_GUID_SIGNAL;
}
int Signal::get_F_GUID_SIGNAL()
{
    return F_GUID_SIGNAL;
}
void Signal::set_F_ID(int F_ID)
{
    this->F_ID = F_ID;
}

int Signal::get_F_ID()
{
    return F_ID;
}
void Signal::set_FloatValue(float FloatValue)
{
    this->FloatValue = FloatValue;
}
float Signal::get_FloatValue() const
{
    return FloatValue;
}

void Signal::set_currentTime(QDateTime &currentTime)
{
    this->currentTime = currentTime;
}

void Signal::set_dt()
{
    int i=0;
    i++;
}

QDateTime Signal::get_currentTime() const
{
    return currentTime;
}

Signal::~Signal()
{
}
