#ifndef MODELVISUALPARAM_H
#define MODELVISUALPARAM_H


#include <QAbstractTableModel>
#include "AllHeaders.h"

class VisualParam;

class ModelVisualParam : public QAbstractTableModel
{
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

        QObject *parent;

};







#endif // MODELVISUALPARAM_H
