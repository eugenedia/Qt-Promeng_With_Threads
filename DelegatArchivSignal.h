#ifndef DELEGATARCHIVSIGNAL_H
#define DELEGATARCHIVSIGNAL_H

#include <QItemDelegate>

class DelegatArchivSignal : public QItemDelegate
{
    Q_OBJECT
public:
    explicit DelegatArchivSignal(QObject *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const;
    
signals:
    
public slots:
    
};

#endif // DELEGATARCHIVSIGNAL_H
