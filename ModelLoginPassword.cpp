#include "ModelLoginPassword.h"

ModelLoginPassword::ModelLoginPassword(QObject *parent) :
    QAbstractTableModel(parent)
{
}

void ModelLoginPassword::setLoginPasswordVec(QVector<LoginPassword> &vLoginPasswords)
{
    this->vLoginPasswords = vLoginPasswords;
    reset();
}

QVector<LoginPassword> &ModelLoginPassword::getLoginPasswordVec()
{
    return vLoginPasswords;
}

QVector<LoginPassword> &ModelLoginPassword::getRemovedItems()
{
    return vRemovedItems;
}

int ModelLoginPassword::rowCount(const QModelIndex &parent) const
{
    return vLoginPasswords.size();
}

int ModelLoginPassword::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant ModelLoginPassword::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();


    if (role == Qt::TextAlignmentRole) {
        return int(Qt::AlignRight | Qt::AlignVCenter );
     }
    else if  (role == Qt::DisplayRole)
    {
       // LoginPassword loginPassword;

        int vIndex = index.row();

        switch(index.column())
        {
            case 0:
            return vLoginPasswords[vIndex].F_LOGIN;
            break;

            case 1:
            return vLoginPasswords[vIndex].F_PASSWORD;
            break;

            case 2:
            return vLoginPasswords[vIndex].F_NAME;
            break;

            case 3:
            return vLoginPasswords[vIndex].F_ACCESS_MASK;
            break;

        }

    }

    return QVariant();

}

QVariant ModelLoginPassword::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role==Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            switch(section)
            {
                case 0:
                return "Login";
                break;

                case 1:
                return "Password";
                break;

                case 2:
                return "Name";
                break;

                case 3:
                return "Access_mask";
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

bool ModelLoginPassword::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole)
    {
        int row = index.row();

        vLoginPasswords[row].isModified = true;
//vLoginPasswords
        switch(index.column())
        {
            case 0:
            vLoginPasswords[row].prev_F_LOGIN = vLoginPasswords[row].F_LOGIN;
            vLoginPasswords[row].F_LOGIN = value.toString();
            break;

            case 1:
            vLoginPasswords[row].F_PASSWORD = value.toString();
            vLoginPasswords[row].prev_F_LOGIN = vLoginPasswords[row].F_LOGIN;
            break;

            case 2:
            vLoginPasswords[row].F_NAME = value.toString();
            vLoginPasswords[row].prev_F_LOGIN = vLoginPasswords[row].F_LOGIN;
            break;

            case 3:
            vLoginPasswords[row].F_ACCESS_MASK = value.toInt(); // toString();
            vLoginPasswords[row].prev_F_LOGIN = vLoginPasswords[row].F_LOGIN;
            break;
        }//QAbstractTableModel

        emit dataChanged(index,index);
        return true;
    }


    return false;
}

Qt::ItemFlags ModelLoginPassword::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    flags |=Qt::ItemIsEditable;
    return flags;
}

bool ModelLoginPassword::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position+rows-1);

    for (int row=0; row < rows; row++) {

        LoginPassword loginPassword;

        loginPassword.isNewRecord = true;


        vLoginPasswords.append(loginPassword);

      //  QPair<QString, QString> pair(" ", " ");
      //  listOfPairs.insert(position, pair);
    }

    endInsertRows();
    return true;
}

bool ModelLoginPassword::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position+rows-1);

    for (int row=0; row < rows; ++row) {

        LoginPassword loginPassword = vLoginPasswords[position];
        vRemovedItems.append(loginPassword);

        vLoginPasswords.remove(position);

    }

    endRemoveRows();
    return true;
}

/*bool ModelLoginPassword::insertRows(int row, const QModelIndex &parent)
{
     beginInsertRows();
    LoginPassword tmpLog;
    tmpLog.F_LOGIN ="";
    tmpLog.F_PASSWORD="";
    tmpLog.F_NAME = "";
    tmpLog.F_ACCESS_MASK=0;

    QModelIndex tempIndex= createIndex(0,vLoginPasswords.count());
    QModelIndex tempIndex4= createIndex(4,vLoginPasswords.count());

     emit dataChanged(tempIndex,tempIndex4);

    vLoginPasswords.append(tmpLog);
    // endInsertRows();
}*/
