#include "DelegatArchivSignal.h"
#include <QPainter>
#include "ModelArchivSignal.h"


DelegatArchivSignal::DelegatArchivSignal(QObject *parent) :
    QItemDelegate(parent)
{
}

void DelegatArchivSignal::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.column() ==2)
        {

        QVariant QVcurrValue = index.model()->data(index,Qt::DisplayRole);
       // QVariant
        //double F_THRESHOLD_1, F_THRESHOLD_2;
       // F_THRESHOLD_1 = index.model()->


        //MyCustomStruct c;

        CurrentValue currValue;

        if (QVcurrValue.canConvert<CurrentValue>())
            currValue = QVcurrValue.value<CurrentValue>();


             //const QPixmap *imgGreenStatus = new QPixmap(":/resources/1.0.bmp");

            // painter->drawPixmap(0,0,imgGreenStatus);
            QBrush qb;

            if (currValue.currValue <= currValue.F_THRESHOLD_1)
            {
             qb.setColor(Qt::green);
             qb.setStyle(Qt::SolidPattern);
            }
            else
            if ((currValue.currValue > currValue.F_THRESHOLD_1)&&(currValue.currValue <= currValue.F_THRESHOLD_2))
             {
             qb.setColor(Qt::yellow);
             qb.setStyle(Qt::SolidPattern);
             }
            else
            if (currValue.currValue > currValue.F_THRESHOLD_2)
            {
            qb.setColor(Qt::red);
             qb.setStyle(Qt::SolidPattern);
            }


            painter->setBrush(qb);

             painter->drawRect(option.rect.x()+2,option.rect.y()+2,94,option.rect.height()-3);


           // painter->drawEllipse(option.rect);// drawPixmap(0,0,imgGreenStatus);

           //  QLabel *lblGreenStatusGrp1C1 = new QLabel();

           // lblGreenStatusGrp1C1->setPixmap(*imgGreenStatus);
   //lblGreenStatusGrp1C1->setText("C1");
   //lblGreenStatusGrp1C1->setPixmap(*imgGreenStatusWithTextC1);



            // QPainter *draw = new QPainter(imgGreenStatusWithTextC1);
             //draw->setPen( Qt::black );


        }
    else
    {
        QItemDelegate::paint(painter, option, index);

    }

}

QSize DelegatArchivSignal::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
     if(index.column() ==0)
        {
            return QSize(30,300);
        }
     if(index.column() ==2)
        {
            return QSize(30,120);
        }
}
