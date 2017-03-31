#ifndef SIGNAL_H
#define SIGNAL_H
//#include <QMetaType>
#include "AllHeaders.h"

class Signal
{
public:
    Signal();
    void set_fr_index(int fr_index);
    int get_fr_index();
    void set_F_GUID_SIGNAL(int F_GUID_SIGNAL);
    int get_F_GUID_SIGNAL();
    void set_F_ID(int F_ID);
    int get_F_ID();
    void set_FloatValue(float FloatValue);
    float get_FloatValue() const;
     void set_currentTime(QDateTime & currentTime);
     void set_dt();
    QDateTime get_currentTime() const;
    ~Signal();
private:
    int fr_index;
    int F_GUID_SIGNAL;
    int F_ID;
    float FloatValue;
    QDateTime currentTime;


};

//Q_DECLARE_METATYPE(Signal);

#endif // SIGNAL_H
