#include "ModelVisualParam.h"



ModelVisualParam::ModelVisualParam(QObject *parent)
{
    this->parent = parent;

    //connect(this,SIGNAL(checkPointDataChanged ( const QModelIndex & topLeft, const QModelIndex & bottomRight )),this->parent, SLOT(onCheckPointDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight)));
   // connect(this,SIGNAL(checkPointDataChanged ( const QModelIndex & , const QModelIndex & )),this->parent, SLOT(onCheckPointDataChanged(const QModelIndex & , const QModelIndex & )));

    connect(this,SIGNAL(dataChanged ( const QModelIndex & , const QModelIndex & )),this->parent, SLOT(onCheckPointDataChanged(const QModelIndex & , const QModelIndex & )));
}


int ModelVisualParam::rowCount(const QModelIndex &parent) const
{
    return vVisualParam.size();
}


int ModelVisualParam::columnCount(const QModelIndex &parent) const
{
    return 6;
}

void ModelVisualParam::setVisualParamVec(QVector<VisualParam> &vVisualParam)
{
    this->vVisualParam = vVisualParam;
    reset();
}

QVector<VisualParam> &ModelVisualParam::getVisualParamVec()
{
    return vVisualParam;
}


QVector<VisualParam> &ModelVisualParam::getRemovedItems()
{
    return vRemovedChekpoints;
}


QVariant ModelVisualParam::data(const QModelIndex &index, int role) const
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

        VisualParam vp = vVisualParam[vIndex];

        switch(index.column())
        {
            case 0:
            //int F_GUID_FRAME =
            return vp.get_F_GUID_FRAME();
            break;

            case 1:
            return vp.get_F_GUID_SIGNAL();
            break;

            case 2:
            return vp.get_F_RESOLUTION();
            break;

            case 3:
            return vp.get_F_X();
            break;

            case 4:
            return vp.get_F_Y();
            break;

            case 5:
            return vp.get_F_GUID_DEVICE();
            break;




            /*
    int fr_index;
    int F_GUID_SIGNAL;
    int F_X;
    int F_Y;case 0:

            vVisualParam[row].set_F_GUID_FRAME(value.toString()); //
            break;

        case 1:

        vVisualParam[row].set_F_GUID_SIGNAL(value.toString()); //
        break;

        case 2:

        vVisualParam[row].set_F_X((value.toString()); //
        break;

        case 3:

        vVisualParam[row].set_F_Y((value.toString()); //
        break;

        case 4:

        vVisualParam[row].set_F_GUID_DEVICE(value.toString()); //
        break;

    int F_GUID_DEVICE;F_GUID_SIGNAL
    float FloatValue;
    int F_GUID_FRAME;

            */
        }

    }

    return QVariant();

}


QVariant ModelVisualParam::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role==Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            switch(section)
            {
                case 0:
                return "F_GUID_FRAME";
                break;

                case 1:
                return "F_GUID_SIGNAL";
                break;

                case 2:
                return "F_RESOLUTION";
                break;

                case 3:
                return "F_X";
                break;

                case 4:
                return "F_Y";
                break;

                case 5:
                return "F_GUID_DEVICE";
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


bool ModelVisualParam::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole)
    {
        int row = index.row();

        vVisualParam[row].set_isModified(true);

        switch(index.column())
        {
        case 0:

            vVisualParam[row].set_F_GUID_FRAME( value.toInt()); //
            break;

        case 1:

            vVisualParam[row].set_F_GUID_SIGNAL(value.toInt()); //
            break;

        case 2:

            vVisualParam[row].set_F_RESOLUTION(value.toString()); //
                    break;

        case 3:

            vVisualParam[row].set_F_X(value.toInt()); //
                    break;

        case 4:

            vVisualParam[row].set_F_Y(value.toInt()); //
                    break;

        case 5:

            vVisualParam[row].set_F_GUID_DEVICE(value.toInt()); //
            break;


        }

        emit dataChanged(index,index);
        return true;
    }


    return false;
}


Qt::ItemFlags ModelVisualParam::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    flags |=Qt::ItemIsEditable;
    return flags;
}


bool ModelVisualParam::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position+rows-1);

    for (int row=0; row < rows; row++) {

        VisualParam visualParam;
        //LoginPassword loginPassword;

        visualParam.set_isNewRecord(true);
        visualParam.set_isModified(false);


        vVisualParam.append(visualParam);


    }

    endInsertRows();
    return true;
}


bool ModelVisualParam::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position+rows-1);

    for (int row=0; row < rows; ++row) {

        VisualParam visualParam = vVisualParam[position];
        vRemovedChekpoints.append(visualParam);

        vVisualParam.remove(position);

    }

    endRemoveRows();
    return true;

}












