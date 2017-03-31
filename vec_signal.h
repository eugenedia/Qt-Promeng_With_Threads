//#include "AllHeaders.h"
#include "Signal.h"
#ifndef VEC_SIGNAL_H
#define VEC_SIGNAL_H

#include <QMetaType>
class Signal;

class vec_signal
{
public:
   vec_signal();
    vec_signal(QVector<Signal> vSignal);
     ~vec_signal();

    QVector<Signal> vSignal;
};

Q_DECLARE_METATYPE(vec_signal)

#endif // VEC_SIGNAL_H
