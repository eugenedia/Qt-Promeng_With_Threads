#include "vec_signal.h"

vec_signal::vec_signal(QVector<Signal> vSignal)
{

    this->vSignal =  vSignal;
}

vec_signal::~vec_signal()
{
    vSignal.clear();
}

vec_signal::vec_signal()
{


}
