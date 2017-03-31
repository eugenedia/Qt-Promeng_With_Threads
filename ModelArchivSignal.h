#ifndef MODELARCHIVSIGNAL_H
#define MODELARCHIVSIGNAL_H

#include <QAbstractTableModel>
#include "AllHeaders.h"

class ModelArchivSignal : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ModelArchivSignal(QObject *parent = 0);

     void setArchivSignalVec(  const QVector<Signal> &vSig);
     void setTreholds(double F_THRESHOLD_1,double F_THRESHOLD_2);
      double getTrehold_1();
      double getTrehold_2();
   // QVector<VisualParam> & getVisualParamVec();
   // QVector <VisualParam> & getRemovedItems();
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
   // bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    //bool insertRows(int position, int rows, const QModelIndex &index=QModelIndex());
   // bool removeRows(int position, int rows, const QModelIndex &index=QModelIndex());
    
signals:
    
public slots:

private:

     QVector<Signal> vSig;
     double F_THRESHOLD_1, F_THRESHOLD_2;
    
};

struct CurrentValue
{
double currValue;
double F_THRESHOLD_1, F_THRESHOLD_2;
};

Q_DECLARE_METATYPE(CurrentValue)

#endif // MODELARCHIVSIGNAL_H


/*

    Q_OBJECT
public:
    explicit ModelVisualParam(QObject *parent = 0);

    void setVisualParamVec(  QVector<VisualParam> &vVisualParam);
    QVector<VisualParam> & getVisualParamVec();
    QVector <VisualParam> & getRemovedItems();
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool insertRows(int position, int rows, const QModelIndex &index=QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index=QModelIndex());

signals:
//void checkPointDataChanged ( const QModelIndex & topLeft, const QModelIndex & bottomRight );
void checkPointDataChanged ( const QModelIndex & topLeft, const QModelIndex & bottomRight );

private:
        QVector<VisualParam> vVisualParam;
        QVector<VisualParam> vRemovedChekpoints;

        QObject *parent;*/
