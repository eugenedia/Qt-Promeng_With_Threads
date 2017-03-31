#ifndef BITMAPWORKER_H
#define BITMAPWORKER_H

#include <QWidget>
//#include <QPainter>
#include <QtGui>
#include "AllHeaders.h"


enum Maps {Busher, Vent };

// *** Создает виджет с заданной картинкой.

class BitmapWorker : public QWidget
{
    Q_OBJECT
public:
   // explicit BitmapWorker(QString fileName,QImage image,QPoint winPos,Maps eMaps,DBConn db, QWidget *parent = 0);

    BitmapWorker(QString fileName, DBConn db, int VideoFrameGuid, ModelVisualParam *modelVisualParam, QWidget *parent = 0);
    ~BitmapWorker();

    //void setDuration(int secs);
    //int duration() const;
    void draw(QPainter *painter);

     QSize	sizeHint () const;

     void timeUpdate();

     void display_tooltip();

    void checkPointUpdate();

    bool updateModel();


private slots:
     void deviceProperties();

     void writeSignal(vec_signal vecSignal );

signals:
    //void timeout();

protected:
   void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent ( QMouseEvent * event );
  void mouseDoubleClickEvent ( QMouseEvent * event );
  //void focusOutEvent ( QFocusEvent * event );
  //bool event(QEvent *event);
  void focusInEvent ( QFocusEvent * event );


private:
   // QDateTime finishTime;
    DBConn db;

   QString fileName;
   QString pointFileName;
   QImage image;
   bool stationSelect;
   QImage StationPoint;
   QPoint tooltipPoint;
   QPoint winPos;

   db_VisualParam *dbVisParametr;
   QList<VisualParam> listVisParametr;

   db_Signal *dbSignal;
   //QVector<Signal> vecSignal;



   int numberOfPoints;
   QPoint* pPointers;
   //QString fileName;
   VisualParam *pVisualParam;

   QPoint OldmousePoint;

   bool isSelectedPoint;
   int selectedPoint;

   Maps eMaps;

   QDateTime qdt,oldQdt;

   QString timeBegin, timeEnd;

   QString DateTimeToString(QDateTime qt);

   void createMenu();

   QMenu *rightClickMenu;

   void createActions();

   QAction *propertiesAct;



   CheckpointPropDialog *chkPropDialog;

   int SelectedGuidSignal;

   int SelectedF_X;
   int SelectedF_Y;


   bool Is_mouse_move, Is_mouse_stop;

   bool hideToolTip; // if true hide tooltip.


   QPoint mousePoint;


   int videoFrameGuid;

    QMap<int,VisualParam> mapVP;


    bool beginDragAndDrop;

    //int selected_fr_index;
    int selected_checkPoint;

    ModelVisualParam *modelVisualParam;




    
};



#endif // BITMAPWORKER_H
