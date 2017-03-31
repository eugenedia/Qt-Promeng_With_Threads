#include "bitmapworker.h"
#include <QCursor>

//BitmapWorker::BitmapWorker(QString fileName, QImage image, QPoint winPos, Maps eMaps, DBConn db, QWidget *parent) :
    //QWidget(parent),SelectedGuidSignal(0), SelectedF_X(0), SelectedF_Y(0),numberOfPoints(0)

BitmapWorker::BitmapWorker(QString fileName, DBConn db, int VideoFrameGuid,ModelVisualParam *modelVisualParam, QWidget *parent )
{
    this->fileName=fileName;
    //this->image = image;
    this->db = db;



    if (!fileName.isEmpty()) {
                          image.load(this->fileName);

                        if (image.isNull())          {
                                            QMessageBox::information(this, tr("Image Viewer"),
                                                             tr("Cannot load %1.").arg(fileName));
                                                             return;
                                                    }
                            }





    //this->winPos = winPos;
    pointFileName = "resources/4.4.bmp";
   setMouseTracking(true);
    numberOfPoints = 0;

   // if (eMaps==Busher)
    //    {
     //   this->eMaps =Busher;


        dbVisParametr = new db_VisualParam(db.getDatabase());
        listVisParametr = dbVisParametr->loadTableVisualParam(VideoFrameGuid,"1280x1024");


        QListIterator<VisualParam> i(listVisParametr);
            while(i.hasNext()) {
               VisualParam vp =  i.next();

               numberOfPoints++;

            }


            pVisualParam = new VisualParam[numberOfPoints];



            int j=0;

            i.toFront();

            mapVP.clear();

            while(i.hasNext()) {
               VisualParam vp =  i.next();


               pVisualParam[j]=vp;

                j++;


            // mapVP.insert(vp.get_fr_index(),vp);
            mapVP.insert(vp.get_F_GUID_SIGNAL(),vp);
           // qDebug() << vp.get_F_GUID_SIGNAL();

             //qDebug() << vp.get_F_X() << vp.get_F_Y();




        }










    //oldQdt.setDate(QDate(2013,02,04));
     //           oldQdt.setTime(QTime(06,41,40));


   // qdt =   oldQdt.addSecs(300);


   // timeBegin, timeEnd;




   // timeBegin = DateTimeToString(oldQdt);

  //  timeEnd = DateTimeToString(qdt);




     createActions();
     createMenu();

     Is_mouse_move = false;
     Is_mouse_stop = false;

    //connect(InsertBtn,SIGNAL(clicked()),this, SLOT(onInsertBtnClicked()));

    videoFrameGuid = VideoFrameGuid;

    beginDragAndDrop = false;

    //selected_fr_index = 0;
    selected_checkPoint = 0;

    this->modelVisualParam = modelVisualParam;

    //checkPointUpdate();

    hideToolTip = false;

    setFocusPolicy(Qt::StrongFocus);

}

BitmapWorker::~BitmapWorker()
{
    delete dbVisParametr;
    listVisParametr.clear();

    delete [] pVisualParam;

    mapVP.clear();

}

void BitmapWorker::draw(QPainter *painter)
{
   QRect rect = painter->viewport();
    QSize size =  image.size();
    size.scale(rect.size(), Qt::KeepAspectRatio);


    painter->setWindow(0,0,size.width(), size.height());






    StationPoint.load(pointFileName);


    int j=0;




   painter->drawImage ( 0,0, image);

 /*!!!  for(j=0; j<numberOfPoints; j++)
           {

       painter->drawImage ( pVisualParam[j].get_F_X() ,pVisualParam[j].get_F_Y(), StationPoint);
       QBrush qb(Qt::gray,Qt::SolidPattern);
       painter->setBrush(qb);

        painter->drawRect(pVisualParam[j].get_F_X()+30,pVisualParam[j].get_F_Y()+5,65,20);

        painter->drawText(pVisualParam[j].get_F_X()+40 ,pVisualParam[j].get_F_Y()+20,QString::number(pVisualParam[j].get_FloatValue(),'g',5));


       float t;

           } !!!*/

   QMapIterator<int,VisualParam> it(mapVP);
   VisualParam vp;

   while(it.hasNext()) {
    it.next();
    qDebug() << it.key() << "coordinate";
    vp = it.value();

    qDebug() << vp.get_F_X() << vp.get_F_Y();

    painter->drawImage ( vp.get_F_X() ,vp.get_F_Y(), StationPoint);
    QBrush qb(Qt::gray,Qt::SolidPattern);
    painter->setBrush(qb);

    painter->drawRect( vp.get_F_X()+30, vp.get_F_Y()+5,65,20);

    painter->drawText( vp.get_F_X()+40 , vp.get_F_Y()+20,QString::number( vp.get_FloatValue(),'g',5));



   }
  // mapVP

}

void BitmapWorker::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);



    draw(&painter);


}

 QSize	BitmapWorker::sizeHint () const
 {
    QSize size = image.size();
    return size;

 }

 void BitmapWorker::timeUpdate()
 {
   //  if (eMaps==Busher)
     //{

          this->update();





         if(Is_mouse_stop&&(!hideToolTip)&&(this->isActiveWindow()))
             display_tooltip();

         Is_mouse_stop = true;



//QPixmap *imgGreenStatus = new QPixmap(":/resources/1.0.bmp");


   ///  }


 }

 void BitmapWorker::display_tooltip()
 {



   // qDebug()<< mousePoint.x() <<mousePoint.y();

     int selectedPoint=0;




     QRect stationRect = StationPoint.rect();


     QMapIterator<int,VisualParam> it(mapVP);
     VisualParam vp;

    while(it.hasNext()) {
    it.next();

    vp = it.value();

    stationRect.setRect(vp.get_F_X() ,vp.get_F_Y(),26,26);
    stationSelect = false;

        if(stationRect.contains(mousePoint))
        {
            stationSelect = true;

            tooltipPoint.setX(vp.get_F_X()+x()+30);
            tooltipPoint.setY(vp.get_F_Y()+y());


            QString strGuid_Device = "Guid_Device: " + QString::number(vp.get_F_GUID_DEVICE());

             QToolTip::showText(tooltipPoint,strGuid_Device );

        }



        }








 }

 void BitmapWorker::checkPointUpdate()
 {
  //this->modelVisualParam = modelVisualParam;
  QVector<VisualParam> vVisualParam =  modelVisualParam->getVisualParamVec();
  //modelVisualParam->
  mapVP.clear();
  for(int i=0; i<vVisualParam.size(); i++)
  {
    if( vVisualParam[i].get_F_GUID_FRAME()==videoFrameGuid)
    mapVP.insert(vVisualParam[i].get_F_GUID_SIGNAL(),vVisualParam[i]);
  }

 }

 bool BitmapWorker::updateModel()
 {
    QVector<VisualParam> vVisualParam =  modelVisualParam->getVisualParamVec();

     for(int i=0; i<vVisualParam.size(); i++)
  {
    int selected_checkPoint = vVisualParam[i].get_F_GUID_SIGNAL();// F_GUID_SIGNAL;
    if (mapVP.contains(selected_checkPoint))
    {

     vVisualParam[i] = mapVP.value(selected_checkPoint);

    }

    }

    modelVisualParam->setVisualParamVec(vVisualParam);

 }

 void BitmapWorker::deviceProperties()
 {
     //QToolTip::hideText();
     chkPropDialog = new CheckpointPropDialog(SelectedGuidSignal,SelectedF_X, SelectedF_Y,db, this);

   // chkPropDialog->

     chkPropDialog->show();



 }

 void BitmapWorker::writeSignal(vec_signal vecSignal )
 {

     for(int j=0; j<vecSignal.vSignal.size();j++)
                                 {


                                int tmpInd2 = vecSignal.vSignal[j].get_F_GUID_SIGNAL();

                                if (mapVP.contains(tmpInd2))
                                 mapVP[tmpInd2].set_FloatValue(vecSignal.vSignal[j].get_FloatValue());
                                //mapVP.value(tmpInd2).set_FloatValue(vecSignal.vSignal[j].get_FloatValue());

                                 //if( tmpInd1==tmpInd2)
                                           //  pVisualParam[k].set_FloatValue( vecSignal.vSignal[j].get_FloatValue());




                                 }










        /*!!!      for(int k=0; k<numberOfPoints;k++)
                     {

                             for(int j=0; j<vecSignal.vSignal.size();j++)
                                 {

                                int tmpInd1 = pVisualParam[k]. get_fr_index();
                                int tmpInd2 = vecSignal.vSignal[j].get_fr_index();


                                 if( tmpInd1==tmpInd2)
                                             pVisualParam[k].set_FloatValue( vecSignal.vSignal[j].get_FloatValue());




                                 }
                     }
    !!!*/
 }




 void BitmapWorker::mouseMoveEvent ( QMouseEvent * event )
 {
     Is_mouse_stop = false;
      mousePoint.setX(event->x());
      mousePoint.setY(event->y());
              //(event->x(),event->y());

      QToolTip::hideText();
 }

 void BitmapWorker::mouseDoubleClickEvent(QMouseEvent *event)
 {
        QRect stationRect = StationPoint.rect();
        QMapIterator<int,VisualParam> it(mapVP);
        VisualParam vp;


         if( beginDragAndDrop == true)

                                {
                                    if (mapVP.contains(selected_checkPoint))
                                    {
                                     mapVP[selected_checkPoint].set_F_X(event->x()-15);
                                     mapVP[selected_checkPoint].set_F_Y(event->y()-15);
                                     mapVP[selected_checkPoint].set_isModified(true);
                                       }

                                   // vp = mapVP.value( selected_fr_index);
                                    beginDragAndDrop = false;

                                    //vp.set_F_X(event->x());
                                    //vp.set_F_Y(event->y());

                                   // mapVP.value( selected_fr_index) = vp;

                                    this->setCursor( Qt::ArrowCursor);
                                    updateModel();
                                }



       // QMapIterator<int,VisualParam> it(mapVP);
       // VisualParam vp;

    while(it.hasNext()) {
    it.next();

    vp = it.value();

    stationRect.setRect(vp.get_F_X() ,vp.get_F_Y(),26,26);


             if(stationRect.contains( event->pos()))
                    if( beginDragAndDrop == false)
                                {
                                 QPixmap *checkPoint = new QPixmap(pointFileName);

                                 QCursor qCur(*checkPoint);


                                beginDragAndDrop = true;

                                // vp.set_F_X(-10);
                                 //vp.set_F_Y(-10);




                                 this->setCursor(qCur);
                                 delete checkPoint;

                                selected_checkPoint = it.key();

                                 if (mapVP.contains(selected_checkPoint))
                                   {  mapVP[selected_checkPoint].set_F_X(-50);
                                     mapVP[selected_checkPoint].set_F_Y(-50);
                                     this->update();
                                     }

                                 }



    }
 }

 void BitmapWorker::focusInEvent(QFocusEvent *event)
 {
   // bool bFocus =	event->gotFocus ();

  //  isActiveWindow
  //  if(bFocus)

    if(this->isActiveWindow())
    hideToolTip =false;
    else
    hideToolTip =true;
 }

 /*void BitmapWorker::focusOutEvent(QFocusEvent *event)
 {
    // QToolTip::hideText();
 }*/


 QString BitmapWorker::DateTimeToString(QDateTime qt)
 {
 QDate oldDate = qt.date();
QTime oldTime = qt.time();

  QString dt = oldDate.toString("yyyy-MM-dd");
  QString tm = oldTime.toString("hh:mm:ss");
  dt = dt +" "+ tm;
 return dt;
 }


 void BitmapWorker::mousePressEvent(QMouseEvent *event)
 {
    if(event->button()==Qt::RightButton)
    {
       QRect stationRect = StationPoint.rect();



     QMapIterator<int,VisualParam> it(mapVP);
     VisualParam vp;

   while(it.hasNext()) {
    it.next();

    vp = it.value();

    stationRect.setRect(vp.get_F_X() ,vp.get_F_Y(),26,26);


             if(stationRect.contains( event->pos()))
            {

                  SelectedGuidSignal =vp.get_F_GUID_SIGNAL();
                  SelectedF_X = vp.get_F_X();
                  SelectedF_Y = vp.get_F_Y();

                 QPoint qp(vp.get_F_X()+x()+35 ,vp.get_F_Y()+y()+20);

                  QToolTip::hideText();

                  hideToolTip = true;

                 rightClickMenu->exec(qp);





            }


   }




 }

 }

 void BitmapWorker::createMenu()
 {

rightClickMenu = new QMenu(this);

     rightClickMenu->addAction ("Add to chart");

     rightClickMenu->addAction("Add to format");

     rightClickMenu->addSeparator();

     rightClickMenu->addAction("Lock Param");

     rightClickMenu->addSeparator();
     rightClickMenu->addAction(propertiesAct);

    // menuBar()->addMenu(tr("Окна"));

    // fileMenu->addAction(openMapAct);
 }
 void BitmapWorker::createActions()

 {


     propertiesAct = new QAction(tr("Properties"),this);
     connect(propertiesAct, SIGNAL(triggered()), this, SLOT(deviceProperties()));


 }
