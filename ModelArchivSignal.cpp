#include "ModelArchivSignal.h"

ModelArchivSignal::ModelArchivSignal(QObject *parent) :
    QAbstractTableModel(parent)
{
}

void ModelArchivSignal::setArchivSignalVec(const QVector<Signal> &vSig)
{
    this->vSig = vSig;
    reset();
}

void ModelArchivSignal::setTreholds(double F_THRESHOLD_1, double F_THRESHOLD_2)
{
    this->F_THRESHOLD_1 =  F_THRESHOLD_1;
    this->F_THRESHOLD_2 = F_THRESHOLD_2;
}

double ModelArchivSignal::getTrehold_1()
{
    return F_THRESHOLD_1;
}

double ModelArchivSignal::getTrehold_2()
{
    return F_THRESHOLD_2;
}


int ModelArchivSignal::rowCount(const QModelIndex &parent) const
{
    return vSig.size();
}

int ModelArchivSignal::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant ModelArchivSignal::data(const QModelIndex &index, int role) const
{
     if(!index.isValid())
        return QVariant();


    if (role == Qt::TextAlignmentRole) {
        return int(Qt::AlignRight | Qt::AlignVCenter );
     }
    else if  (role == Qt::DisplayRole)
    {
       //

        int vIndex = index.row();

   Signal curSig  = vSig[vIndex];

        switch(index.column())
        {


            case 0:
            return curSig.get_currentTime().toString();
            break;

            case 1:
            return curSig.get_FloatValue();
            break;

            case 2:
            CurrentValue currValue;
            currValue.currValue = curSig.get_FloatValue();
            currValue.F_THRESHOLD_1 = F_THRESHOLD_1;
            currValue.F_THRESHOLD_2 = F_THRESHOLD_2;

              QVariant qva;//(QVariant::UserType);
              qva.setValue(currValue);
              return qva;
          //  return (QVariant)currValue;
            break;







        }

    }

    return QVariant();
}

QVariant ModelArchivSignal::headerData(int section, Qt::Orientation orientation, int role) const
{
if(role==Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            switch(section)
            {


                case 0:
                return "Date and Time";
                break;

                case 1:
                return "Value";
                break;

                case 2:
                return "Status";
                break;


            }
        }

        if(orientation == Qt::Vertical)
        {
            return section;
        }
//QAbstractTableModel
    }
    return QVariant();

}


Qt::ItemFlags ModelArchivSignal::flags(const QModelIndex &index) const
{
     Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    //flags |=Qt::ItemIsEditable;
    return flags;
}
