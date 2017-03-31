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
    int get_F_GUID_FRAME();
    void set_F_GUID_FRAME(int F_GUID_FRAME);
    void set_F_GUID_SIGNAL(int F_GUID_SIGNAL);
    int get_F_GUID_SIGNAL();
    QString get_F_RESOLUTION();
    void set_F_RESOLUTION(QString F_RESOLUTION);
    void set_F_ID(int F_ID);
    int get_F_ID();
    void set_FloatValue(float FloatValue);
    float get_FloatValue() const;
     void set_currentTime(QDateTime & currentTime);

    QDateTime get_currentTime() const;
    ~Signal();
private:
    int fr_index;
    int F_GUID_FRAME;
    int F_GUID_SIGNAL;
    QString F_RESOLUTION;
    int F_ID;
    float FloatValue;
    QDateTime currentTime;


};

//Q_DECLARE_METATYPE(Signal);

#endif // SIGNAL_H
