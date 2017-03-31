#ifndef MODELLOGINPASSWORD_H
#define MODELLOGINPASSWORD_H

#include <QAbstractTableModel>
#include "AllHeaders.h"

class ModelLoginPassword : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ModelLoginPassword(QObject *parent = 0);

    void setLoginPasswordVec(  QVector<LoginPassword> &vLoginPasswords);
    QVector<LoginPassword> & getLoginPasswordVec();
    QVector <LoginPassword> & getRemovedItems();
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool insertRows(int position, int rows, const QModelIndex &index=QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index=QModelIndex());


private:
        QVector<LoginPassword> vLoginPasswords;
        QVector<LoginPassword> vRemovedItems;
    
};

#endif // MODELLOGINPASSWORD_H


/*void setSignalList(const QList<Signal> &signalList);
int rowCount(const QModelIndex &parent) const;
int columnCount(const QModelIndex &parent) const;
QVariant data(const QModelIndex &index, int role) const;
QVariant headerData(int section, Qt::Orientation orientation,
                    int role) const;
bool setData(const QModelIndex &index, const QVariant &value, int role);*/
