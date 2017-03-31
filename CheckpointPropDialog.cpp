#include "CheckpointPropDialog.h"
#include <QSizePolicy>

//class Zoomer;

CheckpointPropDialog::CheckpointPropDialog(int SelectedGuidSignal, int SelectedF_X, int SelectedF_Y, DBConn db, QWidget *parent) :
    QDialog(parent)
{
    points =0;
    db_signal = new db_Signal();

     QHBoxLayout * tabLayout = new QHBoxLayout();

    mainTab = new QTabWidget(this);
  //  tb2 = new QTabWidget(this);



   // *wDialog,*wGraphArch,*wGraph,*wArch;

    wDialog = new QWidget(this);
    wGraphArch = new QWidget(this);
    wGraph = new QWidget(this);
    wArch = new QWidget(this);


    mainTab->addTab(wDialog,"Dialog");
    //tb1->addTab(wGraph, "Graphics");
    mainTab->addTab(wGraphArch, "Graphics and Archives");
    tabLayout->addWidget(mainTab);
    setLayout(tabLayout);


    this->db = db;
    this->SelectedGuidSignal = SelectedGuidSignal;
    this->SelectedF_X = SelectedF_X;
    this->SelectedF_Y = SelectedF_Y;

    d_zoomer =0;
    curve=0;
    plot=0;


      fillDialogTab();
      fillGraphicAndArchives();
    //
    fillChartTab();
    fillArchives();

    connect(dataBegin,SIGNAL(editingFinished()),this, SLOT(manualUpdateData()));
    connect(dataEnd,SIGNAL(editingFinished()),this, SLOT(manualUpdateData()));
    connect(timeBegin,SIGNAL(editingFinished()),this, SLOT(manualUpdateData()));
    connect(timeEnd,SIGNAL(editingFinished()),this, SLOT(manualUpdateData()));

    connect(r30Min,SIGNAL(toggled ( bool )),this, SLOT(r30Min_toogled(bool )));
    connect(r1h,SIGNAL(toggled ( bool  )),this, SLOT(r1h_toogled(bool )));
    connect(r8h,SIGNAL(toggled ( bool  )),this, SLOT(r8h_toogled(bool )));
    connect(r24h,SIGNAL(toggled ( bool  )),this, SLOT(r24h_toogled(bool )));
    connect(rManual,SIGNAL(toggled ( bool  )),this, SLOT(rManual_toogled(bool )));

   /*     QRadioButton *r30Min = new QRadioButton(tr("30 мин"));
    QRadioButton *r1h = new QRadioButton(tr("1 час"));
    QRadioButton *r8h= new QRadioButton(tr("8 часов"));
    QRadioButton *r24h= new QRadioButton(tr("24 часа"));
    QRadioButton *rManual= new QRadioButton(tr("вручную"));*/

     this->setFixedWidth(1500);
    this->setFixedHeight(1000);




    //std::unique_ptr<int*> p1(new int);

    //this->

}

CheckpointPropDialog::~CheckpointPropDialog()
{
   vecCheckpointProperties.clear();
    vecCheckpointMessages.clear();
    vSig.clear();

    delete db_signal;
    delete d_zoomer;
    delete curve;
}

void CheckpointPropDialog::fillGraphicAndArchives()
{
    //tb1->addTab(wGraphArch, "Graphics and Archives");
    childTab = new QTabWidget(this);


     QVBoxLayout * tabLayoutSecond = new QVBoxLayout();
     QHBoxLayout * tabLayout1 = new QHBoxLayout();
     QHBoxLayout * tabLayout2 = new QHBoxLayout();
      QHBoxLayout * optionsLayout = new QHBoxLayout();
     tabLayoutSecond->addLayout(optionsLayout);
     tabLayoutSecond->addWidget(childTab);
    wGraphArch->setLayout(tabLayoutSecond);

    childTab->addTab(wGraph, "Graphics");
    childTab->addTab(wArch, "Archives");


    QVBoxLayout * datasTimeLayout = new QVBoxLayout();
    QHBoxLayout * dataTimeLayout1 = new QHBoxLayout();
    QHBoxLayout * dataTimeLayout2 = new QHBoxLayout();
    QHBoxLayout * timeListLayout = new QHBoxLayout();
    r30Min = new QRadioButton(tr("30 мин"),this);
    r1h = new QRadioButton(tr("1 час"),this);
    r8h= new QRadioButton(tr("8 часов"),this);
    r24h= new QRadioButton(tr("24 часа"),this);
    rManual= new QRadioButton(tr("вручную"),this);




   // wGraph = new QWidget();
   // wArch = new QWidget();

     QLabel *labelFrom, *labelTo;

    labelFrom = new QLabel(this);
    labelTo = new QLabel(this);

    labelFrom->setText(tr("От: "));
    labelFrom->adjustSize();
    labelFrom->setAlignment( Qt::AlignRight);
    labelTo->setText(tr("До: "));
    labelTo->adjustSize();
    labelTo->setAlignment( Qt::AlignRight);


    dataBegin = new QDateEdit(this);
   //QSizePolicy s1 =  new QSizePolicy::Policy()
    //dataBegin->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Preferred);
    dataBegin->setFixedSize(100,20);
    //dataBegin->set
    dataBegin->setCalendarPopup(true);
    dataEnd = new QDateEdit(this);

    dataEnd->setFixedSize(100,20);
    dataEnd->setCalendarPopup(true);


    timeBegin = new QTimeEdit(this);
    timeBegin->setDisplayFormat("HH-mm-ss");
    timeBegin->setFixedSize(100,20);
    timeEnd = new QTimeEdit(this);
    timeEnd->setDisplayFormat("HH-mm-ss");
    timeEnd->setFixedSize(100,20);
     QDate data1,data2;
     data1 = QDate::currentDate();
     data2 = QDate::currentDate();
     dataBegin->setDate(data1);
     dataEnd->setDate(data2);
     QTime qtimeBegin = QTime::currentTime();
     QTime qtimeEnd = QTime::currentTime();
     timeBegin->setTime(qtimeBegin);
     timeEnd->setTime(qtimeEnd);




    timeListLayout->addWidget(r30Min);
    timeListLayout->addWidget(r1h);
    timeListLayout->addWidget(r8h);
    timeListLayout->addWidget(r24h);
    timeListLayout->addWidget(rManual);

    dataTimeLayout1->addWidget(labelFrom);
    dataTimeLayout1->addWidget(dataBegin);
    dataTimeLayout1->addWidget(timeBegin);
    dataTimeLayout2->addWidget(labelTo);
    dataTimeLayout2->addWidget(dataEnd);
    dataTimeLayout2->addWidget(timeEnd);

    datasTimeLayout->addLayout(dataTimeLayout1);
    datasTimeLayout->addLayout(dataTimeLayout2);


    optionsLayout->addLayout(timeListLayout);
     optionsLayout->addSpacing(100);
    optionsLayout->addLayout(datasTimeLayout);
    optionsLayout->addStretch();
    // tabLayout1->addWidget(labelFrom);
    //tabLayout2->addWidget(labelTo);

    // wGraph->setLayout(tabLayout1);
  //  wArch->setLayout(tabLayout2);



}





bool CheckpointPropDialog::fillDialogTab()
{
      QGridLayout *leftGrid = new QGridLayout();


    QGroupBox *grpCheckPoint =new QGroupBox(tr("Checkpoint Display Label"),wDialog);


    QGridLayout *rightGrid = new QGridLayout(); //!
    QGroupBox *grpDevice =new QGroupBox(tr("Device Properties"),wDialog);



    QLabel *lbl_F_LO_RANGE =new QLabel(wDialog);
    lbl_F_LO_RANGE->setText(tr("lbl_F_LO_RANGE"));
    QLineEdit *edt_F_LO_RANGE = new QLineEdit(wDialog);
    edt_F_LO_RANGE->setText("");
    edt_F_LO_RANGE->setReadOnly(true);


    QPalette palette = edt_F_LO_RANGE->palette();
    palette.setColor(QPalette::Base, QColor(210,210,210));
    edt_F_LO_RANGE->setPalette(palette);


    QLabel *lbl_F_HI_RANGE =new QLabel(wDialog);
    lbl_F_HI_RANGE->setText(tr("lbl_F_HI_RANGE"));
    QLineEdit *edt_F_HI_RANGE = new QLineEdit(wDialog);
    edt_F_HI_RANGE->setText("");
    edt_F_HI_RANGE->setReadOnly(true);


    QLabel *lbl_F_THRESHOLD_1 = new QLabel(wDialog);
    lbl_F_THRESHOLD_1->setText(tr("lbl_F_THRESHOLD_1"));
    QLineEdit *edt_F_THRESHOLD_1 = new QLineEdit(wDialog);
    edt_F_THRESHOLD_1->setText("");
    //edt_F_THRESHOLD_1->setReadOnly(true);

    QLabel *lbl_F_THRESHOLD_2 =new QLabel(wDialog);
    lbl_F_THRESHOLD_2->setText(tr("lbl_F_THRESHOLD_2"));
    QLineEdit *edt_F_THRESHOLD_2 = new QLineEdit(wDialog);
    edt_F_THRESHOLD_2->setText("");
    //edt_F_THRESHOLD_2->setReadOnly(true);

    QLabel *lbl_F_DESCRIPTION =new QLabel(wDialog);
    lbl_F_DESCRIPTION->setText(tr("lbl_F_DESCRIPTION"));
    QLineEdit *edt_F_DESCRIPTION = new QLineEdit(wDialog);
    edt_F_DESCRIPTION->setText("");
    edt_F_DESCRIPTION->setReadOnly(true);

    QLabel *lbl_F_UOM =new QLabel(wDialog);
    lbl_F_UOM->setText(tr("lbl_F_UOM"));
    QLineEdit *edt_F_UOM = new QLineEdit(wDialog);
    edt_F_UOM->setText("");
    edt_F_UOM->setReadOnly(true);

    QLabel *lbl_F_SCALE =new QLabel(wDialog);
    lbl_F_SCALE->setText(tr("lbl_F_SCALE"));
    QLineEdit *edt_F_SCALE = new QLineEdit(wDialog);
    edt_F_SCALE->setText("");
    edt_F_SCALE->setReadOnly(true);

    QLabel *lbl_F_TIMEOUT =new QLabel(wDialog);
    lbl_F_TIMEOUT->setText(tr("lbl_F_TIMEOUT"));
    QLineEdit *edt_F_TIMEOUT = new QLineEdit(wDialog);
    edt_F_TIMEOUT->setText("");
    edt_F_TIMEOUT->setReadOnly(true);


    QLabel *lbl_F_ARC_INTERVAL =new QLabel(wDialog);
    lbl_F_ARC_INTERVAL->setText(tr("lbl_F_ARC_INTERVAL"));
    QLineEdit *edt_F_ARC_INTERVAL = new QLineEdit(wDialog);
    edt_F_ARC_INTERVAL->setText("");
    edt_F_ARC_INTERVAL->setReadOnly(true);

    QLabel *lbl_F_ARC_DELTA =new QLabel(wDialog);
    lbl_F_ARC_DELTA->setText(tr("lbl_F_ARC_DELTA"));
    QLineEdit *edt_F_ARC_DELTA = new QLineEdit(wDialog);
    edt_F_ARC_DELTA->setText("");
    edt_F_ARC_DELTA->setReadOnly(true);

    QPixmap *CheckPointImag = new QPixmap("./resources/CheckPointImages/BOP_1M.jpg");
    QLabel *CheckPointLbl = new QLabel(wDialog);
    CheckPointLbl->setPixmap(*CheckPointImag);
    delete CheckPointImag;


    QLabel *lbl_F_NAME =new QLabel(wDialog);
    lbl_F_NAME->setText(tr("lbl_F_NAME"));
    QLineEdit *edt_F_NAME = new QLineEdit(wDialog);
    edt_F_NAME->setText("");
    edt_F_NAME->setReadOnly(true);


    QLabel *lblMessages =new QLabel(wDialog);
    //lblMessages->setText("lbl_F_ARC_DELTA");

    // Device name

    QLabel *lbl_obj_F_NAME =new QLabel(wDialog);
    lbl_obj_F_NAME->setText(tr("obj_F_NAME"));
    QLineEdit *edt_obj_F_NAME = new QLineEdit(wDialog);

    edt_obj_F_NAME->setText("");
    edt_obj_F_NAME->setReadOnly(true);

    QLabel *lbl_obj_F_DISPLAY_LABEL =new QLabel(wDialog);
    lbl_obj_F_DISPLAY_LABEL->setText(tr("obj_F_DISPLAY_LABEL"));
    QLineEdit *edt_obj_F_DISPLAY_LABEL = new QLineEdit(wDialog);
    edt_obj_F_DISPLAY_LABEL->setText("");
    edt_obj_F_DISPLAY_LABEL->setReadOnly(true);//CheckPoint Properties


    QLabel *lbl_obj_F_DESCRIPTION =new QLabel(wDialog);
    lbl_obj_F_DESCRIPTION->setText(tr("obj_F_DESCRIPTION"));
    QLineEdit *edt_obj_F_DESCRIPTION = new QLineEdit(wDialog);
    edt_obj_F_DESCRIPTION->setText("");//CheckPoint Properties
    edt_obj_F_DESCRIPTION->setReadOnly(true);

    leftGrid->addWidget(lbl_F_LO_RANGE,0,0);
    leftGrid->addWidget(edt_F_LO_RANGE,0,1);
    leftGrid->addWidget(lbl_F_HI_RANGE,1,0);
    leftGrid->addWidget(edt_F_HI_RANGE,1,1);
    leftGrid->addWidget(lbl_F_THRESHOLD_1,2,0);
    leftGrid->addWidget(edt_F_THRESHOLD_1,2,1);
    leftGrid->addWidget(lbl_F_THRESHOLD_2,3,0);
    leftGrid->addWidget(edt_F_THRESHOLD_2,3,1);
    leftGrid->addWidget(lbl_F_DESCRIPTION,4,0);
    leftGrid->addWidget(edt_F_DESCRIPTION,4,1);
    leftGrid->addWidget(lbl_F_UOM,5,0);
    leftGrid->addWidget(edt_F_UOM,5,1);
    leftGrid->addWidget(lbl_F_SCALE,6,0);
    leftGrid->addWidget(edt_F_SCALE,6,1);
    leftGrid->addWidget(lbl_F_TIMEOUT,7,0);
    leftGrid->addWidget(edt_F_TIMEOUT,7,1);
    leftGrid->addWidget(lbl_F_ARC_INTERVAL,8,0);
    leftGrid->addWidget(edt_F_ARC_INTERVAL,8,1);
    leftGrid->addWidget(lbl_F_ARC_DELTA,9,0);
    leftGrid->addWidget(edt_F_ARC_DELTA,9,1);
    leftGrid->addWidget(lbl_F_NAME,10,0);
    leftGrid->addWidget(edt_F_NAME,10,1);


    leftGrid->addWidget(CheckPointLbl,11,0,1,2);




    rightGrid->addWidget(lbl_obj_F_NAME,0,0);
    rightGrid->addWidget(edt_obj_F_NAME,0,1,1,2);
    rightGrid->addWidget(lbl_obj_F_DISPLAY_LABEL,1,0);
    rightGrid->addWidget(edt_obj_F_DISPLAY_LABEL,1,1,1,2);
    rightGrid->addWidget(lbl_obj_F_DESCRIPTION,2,0);
    rightGrid->addWidget(edt_obj_F_DESCRIPTION,2,1,1,2);


    rightGrid->addWidget(lblMessages,9,0,1,2);

    grpCheckPoint->setLayout(leftGrid);

    grpDevice->setLayout(rightGrid);

    QVBoxLayout * mainLayout = new QVBoxLayout();



    QHBoxLayout * leftLayout = new QHBoxLayout();
    leftLayout->addWidget(grpCheckPoint);

    leftLayout->addWidget(grpDevice);

    leftLayout->addStretch();

    mainLayout->addLayout(leftLayout);
    mainLayout->addStretch(500);

   // setLayout(leftLayout);
    wDialog->setLayout(mainLayout);
    setWindowTitle(tr("CheckPoint Properties"));
    //setWindowTitle(tr("ARSMS Bushehr."));
    setFixedHeight(sizeHint().height());

    //"./resources/CheckPointImages/BOP_1M.jpg";
            // выполняем запрос для получения свойств checkpoint точки.

    db_CheckPointProperties * db_CheckPointParameter = new db_CheckPointProperties(db.getDatabase());
     vecCheckpointProperties = db_CheckPointParameter->loadCheckPointProperies(SelectedGuidSignal, SelectedF_X, SelectedF_Y);
            for(int j=0; j<vecCheckpointProperties.size();j++)
                {
                   // qDebug() << vecCheckpointProperties[j].CheckpointObject_F_GUID;
                   // qDebug() << vecCheckpointProperties[j].CheckPoint_F_UOM;

                    //QString str_F_DISPLAY_LABEL = vecCheckpointProperties[j].CheckpointObject_F_DISPLAY_LABEL; // CheckPoint_F_LO_RANGE);
                    grpCheckPoint->setTitle(vecCheckpointProperties[j].CheckpointObject_F_DISPLAY_LABEL);

                   QString str_F_LO_RANGE = QString::number(vecCheckpointProperties[j].CheckPoint_F_LO_RANGE);
                   edt_F_LO_RANGE->setText(str_F_LO_RANGE);
                   edt_F_LO_RANGE->setMinimumWidth(150);

                   QString str_F_HI_RANGE = QString::number(vecCheckpointProperties[j].CheckPoint_F_HI_RANGE);
                   edt_F_HI_RANGE->setText(str_F_HI_RANGE);

                   QString str_F_THRESHOLD_1 = QString::number(vecCheckpointProperties[j].CheckPoint_F_THRESHOLD_1);
                   edt_F_THRESHOLD_1->setText(str_F_THRESHOLD_1);
                   F_THRESHOLD_1 = vecCheckpointProperties[j].CheckPoint_F_THRESHOLD_1;

                   QString str_F_THRESHOLD_2 = QString::number(vecCheckpointProperties[j].CheckPoint_F_THRESHOLD_2);
                   edt_F_THRESHOLD_2->setText(str_F_THRESHOLD_2);
                   F_THRESHOLD_2 = vecCheckpointProperties[j].CheckPoint_F_THRESHOLD_2;

                   edt_F_DESCRIPTION->setText(vecCheckpointProperties[j].CheckpointObject_F_DESCRIPTION);

                   edt_F_UOM->setText(vecCheckpointProperties[j].CheckPoint_F_UOM);


                   QString str_F_SCALE = QString::number(vecCheckpointProperties[j].CheckPoint_F_SCALE);
                   edt_F_SCALE->setText(str_F_SCALE);

                   QString str_CheckPoint_F_TIMEOUT = QString::number(vecCheckpointProperties[j].CheckPoint_F_TIMEOUT);
                   edt_F_TIMEOUT->setText(str_CheckPoint_F_TIMEOUT);

                   QString str_CheckPoint_F_ARC_INTERVAL = QString::number(vecCheckpointProperties[j].CheckPoint_F_ARC_INTERVAL);
                   edt_F_ARC_INTERVAL->setText(str_CheckPoint_F_ARC_INTERVAL);

                   QString str_CheckPoint_F_ARC_DELTA = QString::number(vecCheckpointProperties[j].CheckPoint_F_ARC_DELTA);
                   edt_F_ARC_DELTA->setText(str_CheckPoint_F_ARC_DELTA);




                   QString str_F_NAME = vecCheckpointProperties[j].CheckpointObject_F_NAME;

                   QString imgFullPath =    "./resources/CheckPointImages/" + str_F_NAME +    ".jpg";

                   //QDebug << imgFullPath;

                   CheckPointImag = new QPixmap(imgFullPath);
                   //QRect rsize = CheckPointImag->rect();


                   //QLabel *CheckPointLbl = new QLabel();
                   CheckPointLbl->setPixmap(*CheckPointImag);
                   CheckPointLbl->setScaledContents(false);
                   delete CheckPointImag;

                   edt_obj_F_NAME->setText(vecCheckpointProperties[j].obj_F_NAME);
                   edt_obj_F_NAME->setMinimumWidth(200);

                   edt_obj_F_DISPLAY_LABEL->setText(vecCheckpointProperties[j].obj_F_DISPLAY_LABEL);
                   edt_obj_F_DISPLAY_LABEL->setMinimumWidth(200);

                   edt_obj_F_DESCRIPTION->setText(vecCheckpointProperties[j].obj_F_DESCRIPTION);
                   edt_obj_F_DESCRIPTION->setMinimumWidth(200);


                }

            if(vecCheckpointProperties.size()>=1)
            {
            int p_F_GUID = vecCheckpointProperties[0].CheckPoint_F_GUID; // tbl_checkpoint -> F_GUID;


            vecCheckpointMessages = db_CheckPointParameter->loadCheckPointMessages(p_F_GUID);

            //qDebug() << p_F_GUID;

            QString qMsg = "";
            QString qCode = "*";

            for(int j=0; j<vecCheckpointMessages.size();j++)
                {


                qMsg =qMsg + "*" + vecCheckpointMessages[j].obj_F_DISPLAY_LABEL  + "\n";
                qCode =qCode +  vecCheckpointMessages[j].obj_F_NAME + "\n";

                //edt_F_LO_RANGE->setText(str_F_LO_RANGE);



                }
             lblMessages->setText(qMsg);
            }

}

bool CheckpointPropDialog::fillChartTab()
{


    QVBoxLayout * graphLayout = new QVBoxLayout();

 //
    plot = new Plot(this);

     d_zoomer = new Zoomer( plot->canvas() );
     d_zoomer->setAxis(QwtPlot::xBottom, QwtPlot::yLeft);

    d_zoomer->setMousePattern( QwtEventPattern::MouseSelect2,
        Qt::RightButton, Qt::ControlModifier );
    d_zoomer->setMousePattern( QwtEventPattern::MouseSelect3,
        Qt::RightButton );
       graphLayout->addWidget(plot);
      wGraph->setLayout(graphLayout);


          plot->setCanvasBackground( Qt::white );
  //  plot->setAxisScale( QwtPlot::yLeft, 0.0, 10.0 );
  //  plot->insertLegend( new QwtLegend() );

   // QwtPlotGrid *grid = new QwtPlotGrid();
   // grid->attach( plot );

    //for

    curve = new QwtPlotCurve();
    curve->setTitle( "Some Points" );
    curve->setPen( Qt::green, 4 ),
    curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );

          QDateTime qdt, oldQdt;
      oldQdt.setDate(QDate(2013,02,04));
                oldQdt.setTime(QTime(06,41,40));


   // qDebug() << oldQdt;
            //(QDate(2013,02,04),QTime(16,21,00)),

    //oldQdt =qdt;

        qdt =   oldQdt.addSecs(3000);

    //getArchivedData(oldQdt, qdt, SelectedGuidSignal);


}



void CheckpointPropDialog::getArchivedData(QDateTime dataTime1, QDateTime dataTime2, int SelectedGuidSignal)
{

   // db_Signal * db_signal = new db_Signal();

    vSig =  db_signal->loadArchiveTableSignal(dataTime1, dataTime2,SelectedGuidSignal, db.getDatabase());

   //
}



void CheckpointPropDialog::manualUpdateData()
{

    if ( rManual->isChecked())
    {
      QDateTime qdt, oldQdt;
      double x,y,minX,maxX;
      minX = 0;
      maxX = 0;
      oldQdt.setDate(dataBegin->date());
      oldQdt.setTime(timeBegin->time() );

      qdt.setDate(dataEnd->date());
      qdt.setTime(timeEnd->time() );

      getArchivedData(oldQdt, qdt, SelectedGuidSignal);

      if (vSig.size()>0)
     {

       if(points!=0)
       points->clear();

       points = new QPolygonF();

      for(int i=0; i < vSig.size(); i++)  //vSig Содержит данные
      {
        x = QwtDate::toDouble(vSig.at(i).get_currentTime());
        //if(x<minX) minX=x;
        //if(x>maxX) maxX=x;
        y = vSig.at(i).get_FloatValue();
        qDebug()<< x << " " << y << " ";
        (*points) << QPointF( x, y );



      //qDebug() << vSig.at(i).get_FloatValue()<< " "<< vSig.at(i).get_currentTime().toString("yyyy-MM-dd hh:mm:ss");
        }
         //plot->setAxisScale(QwtPlot::xBottom,minX,maxX);
        curve->detach();
        curve->setSamples( *points );
        //curve->setSymbol();
        //plot->
        curve->attach( plot );
        //curve->
        //plot->setAxisAutoScale(QwtPlot::yRight ,true);
        //plot->show();
       // plot->

        plot->replot();

        d_zoomer->setZoomBase(false);
        }

       if(vSig.size()>0)
        modelSignal->setArchivSignalVec(vSig);

        //tab

        //tableView->resizeColumnsToContents();// resizeColumnToContents();
        tableView->setColumnWidth(0,240);
    }
}

void CheckpointPropDialog::r30Min_toogled(bool checked)
{
    if(checked)
    {
        recalculateGraphic(30*60);

    }
}

void CheckpointPropDialog::r1h_toogled(bool checked)
{
    if(checked)
    {
        recalculateGraphic(60*60);

    }
}

void CheckpointPropDialog::r8h_toogled(bool checked)
{
    if(checked)
    {
        recalculateGraphic(8*60*60);

    }
}

void CheckpointPropDialog::r24h_toogled(bool checked)
{
    if(checked)
    {
        recalculateGraphic(24*60*60);

    }
}

void CheckpointPropDialog::rManual_toogled(bool checked)
{
    if(checked)
    manualUpdateData();
}



void CheckpointPropDialog::recalculateGraphic(uint numberOfSeconds)
{
     //QDateTime qdt, oldQdt;
      double x,y,minX,maxX;
      minX = 0;
      maxX = 0;

       QDate data1,data2;
     data1 = QDate::currentDate();

     dataEnd->setDate(data1);

     QTime qtimeEnd = QTime::currentTime();

     timeEnd->setTime(qtimeEnd);


      QDateTime rightBorderOfRange, leftBorderOfRange;
      rightBorderOfRange.setDate(QDate::currentDate());
      rightBorderOfRange.setTime(QTime::currentTime());



        uint numberOfSecondRightBorderOfRange =  rightBorderOfRange.toTime_t();

        uint numberOfSecondLeftBorderOfRange = numberOfSecondRightBorderOfRange - numberOfSeconds;

        leftBorderOfRange.setTime_t(numberOfSecondLeftBorderOfRange);



      getArchivedData(leftBorderOfRange, rightBorderOfRange, SelectedGuidSignal);

      if (vSig.size()>0)
     {

       if(points!=0)
        points->clear();

       points = new QPolygonF();

      for(int i=0; i < vSig.size(); i++)  //vSig Содержит данные
      {
        x = QwtDate::toDouble(vSig.at(i).get_currentTime());

        y = vSig.at(i).get_FloatValue();
        qDebug()<< x << " " << y << " ";
        (*points) << QPointF( x, y );




        }

        curve->setSamples( *points );


        curve->attach( plot );


        plot->replot();

        d_zoomer->setZoomBase(false);

        //if(vSig.size()>0)
        modelSignal->setArchivSignalVec(vSig);

         tableView->setColumnWidth(0,240);

         }

        //tableView->resizeColumnsToContents();
}


void CheckpointPropDialog::fillArchives()
{


 QVBoxLayout * archLayout = new QVBoxLayout();

 modelSignal = new ModelArchivSignal();
 modelSignal->setArchivSignalVec(vSig);
 modelSignal->setTreholds(F_THRESHOLD_1,F_THRESHOLD_2);

 tableView = new QTableView;
 //delArchSig = new DelegatArchivSignal();
 tableView->setItemDelegate(new DelegatArchivSignal());
 tableView->setModel(modelSignal);
 //tableView->setColumnWidth(2,120);

  archLayout->addWidget(tableView);


  wArch->setLayout(archLayout);

}

/*

 QHBoxLayout * optionsLayout = new QHBoxLayout;

   /*! QVBoxLayout * datasTimeLayout = new QVBoxLayout;
    QHBoxLayout * dataTimeLayout1 = new QHBoxLayout;
    QHBoxLayout * dataTimeLayout2 = new QHBoxLayout;
    QHBoxLayout * timeListLayout = new QHBoxLayout;
    QRadioButton *r30Min = new QRadioButton(tr("30 мин"));
    QRadioButton *r1h = new QRadioButton(tr("1 час"));
    QRadioButton *r8h= new QRadioButton(tr("8 часов"));
    QRadioButton *r24h= new QRadioButton(tr("24 часа"));
    QRadioButton *rManual= new QRadioButton(tr("вручную"));

    QLabel *labelFrom, *labelTo;

    labelFrom = new QLabel();
    labelTo = new QLabel();

    labelFrom->setText(tr("От: "));
    labelFrom->adjustSize();
    labelFrom->setAlignment( Qt::AlignRight);
    labelTo->setText(tr("До: "));
    labelTo->adjustSize();
    labelTo->setAlignment( Qt::AlignRight);*/
    //QwtPlot *plot = new QwtPlot();


     //timeListLayout->addStretch();

   // r30Min.
    //, r1h, r8h, r24h, rManual;

      //oldQdt.setDate(QDate(2013,02,04));
     //           oldQdt.setTime(QTime(06,41,40));


   // qdt =   oldQdt.addSecs(300);


   // timeBegin, timeEnd;




   // timeBegin = DateTimeToString(oldQdt);

  //  timeEnd = DateTimeToString(qdt);


 /*!dataBegin = new QDateEdit();
   //QSizePolicy s1 =  new QSizePolicy::Policy()
    //dataBegin->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Preferred);
    dataBegin->setFixedSize(100,20);
    //dataBegin->set
    dataBegin->setCalendarPopup(true);
    dataEnd = new QDateEdit();QTableView *

    dataEnd->setFixedSize(100,20);
    dataEnd->setCalendarPopup(true);


    timeBegin = new QTimeEdit();
    timeBegin->setDisplayFormat("HH-mm-ss");
    timeBegin->setFixedSize(100,20);
    timeEnd = new QTimeEdit();
    timeEnd->setDisplayFormat("HH-mm-ss");
    timeEnd->setFixedSize(100,20);
     QDate data1,data2;
     data1 = QDate::currentDate();
     data2 = QDate::currentDate();
     dataBegin->setDate(data1);
     dataEnd->setDate(data2);
     QTime qtimeBegin = QTime::currentTime();
     QTime qtimeEnd = QTime::currenQTableView *tTime();
     timeBegin->setTime(qtimeBegin);
     timeEnd->setTime(qtimeEnd);


      QDateTime qdt, oldQdt;
      oldQdt.setDate(QDate(2013,02,04));
                oldQdt.setTime(QTime(06,41,40));


   // qDebug() << oldQdt;
            //(QDate(2013,02,04),QTime(16,21,00)),

    //oldQdt =qdt;

        qdt =   oldQdt.addSecs(3000);

    getArchivedData(oldQdt, qdt, SelectedGuidSignal);

    timeListLayout->addWidget(r30Min);
    timeListLayout->addWidget(r1h);
    timeListLayout->addWidget(r8h);
    timeListLayout->addWidget(r24h);
    timeListLayout->addWidget(rManual);

   // r30Min.
    //, r1h, r8h, r24h, rManual;

      //oldQdt.setDate(QDate(2013,02,04));
     //           oldQdt.setTime(QTime(06,41,40));


   // qdt =   oldQdt.addSecs(300);


   // timeBegin, timeEnd;




   // timeBegin = DateTimeToString(oldQdt);

  //  timeEnd = DateTimeToString(qdt);

    dataTimeLayout1->addWidget(labelFrom);
    dataTimeLayout1->addWidget(dataBegin);
    dataTimeLayout1->addWidget(timeBegin);
    dataTimeLayout2->addWidget(labelTo);
    dataTimeLayout2->addWidget(dataEnd);
    dataTimeLayout2->addWidget(timeEnd);
  graphLayout->addWidget(plot);
      wGraph->setLayout(graphLayout);
    datasTimeLayout->addLayout(dataTimeLayout1);
    datasTimeLayout->addLayout(dataTimeLayout2);

    optionsLayout->addLayout(timeListLayout);
    optionsLayout->addLayout(datasTimeLayout); !/*
    graphLayout->addLayout(optionsLayout);
     graphLayout->addWidget(plot);
      wGraph->setLayout(graphLayout);

   // plot->setTitle( "Plot Demo" );



    plot->setCanvasBackground( Qt::white );
  //  plot->setAxisScale( QwtPlot::yLeft, 0.0, 10.0 );
  //  plot->insertLegend( new QwtLegend() );

   // QwtPlotGrid *grid = new QwtPlotGrid();
   // grid->attach( plot );

    //for

    curve = new QwtPlotCurve();
    curve->setTitle( "Some Points" );
    curve->setPen( Qt::green, 4 ),
    curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );

   // QwtSymbol *symbol = new QwtSymbol( QwtSymbol::DTriangle,
     //   QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 8, 8 ) );
   // curve->setSymbol( symbol );

    /*QPolygonF points;
    points << QPointF( 0.0, 0.2 ) << QPointF( 1.0, 3.0 )
        << QPointF( 2.0, 4.5 ) << QPointF( 3.0, 6.8 )
        << QPointF( 4.0, 7.9 ) << QPointF( 5.0, 17.1 );*/
    //curve->setSamples( points );

   // curve->attach( plot );

    //plot->resize( 1200, 800 );
    // plot->show();










