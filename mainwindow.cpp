#include "mainwindow.h"


void MainWindow::checkLogin(bool check)
{
    if (!check)
    {
    loginCount++;
    QString strloginCount = "Number of attempts: ";
    strloginCount += QString::number( loginCount);
    QMessageBox(QMessageBox::NoIcon,QString("Wrong Password"),strloginCount).exec();// show();
    pLoginDialog->exec();

    if (loginCount >=3)
        exit(0);
    }
}

MainWindow::MainWindow(QWidget *parent)
    :  QMainWindow(parent), loginCount(0)
{




    promengDialogWidget = new PromengDialog();

    setWindowTitle(tr("ARSMS Bushehr"));



    setCentralWidget(promengDialogWidget);
    move(300,25);



    if(!db.loadDatabase())
       { QMessageBox::critical(0, tr("Error"), tr("Unable to load database."));
            exit(1);}

    tmpDatabase = db.getDatabase();

     pLoginDialog = new LoginDialog(tmpDatabase);

     //bool check;
     while(loginCount<3)
     {
     //pLoginDialog->setModal(true);
     if(pLoginDialog->exec())
        {
       // check = pLoginDialog->getLoginStatus();
        lp = pLoginDialog->getLoginStatus();




        //if(!check)
         if(lp.F_ACCESS_MASK ==0)
        {
        loginCount++;
        if (loginCount >=3)
             exit(0);
        QString strloginCount = "Error, Enter Login and Password, Number of attempts: ";
        strloginCount += QString::number( loginCount);
        QMessageBox(QMessageBox::NoIcon,QString("Wrong Password"),strloginCount).exec();// show();
        }
        else
            break;

        }

     else
        exit(0);
    }
     loginCount =0;


    pdbVideoFrame  = new db_VideoFrame(tmpDatabase);

    vVideoFrame = pdbVideoFrame->loadVideoFrames();

    for(int i=0; i<vVideoFrame.size(); i++)
    mVideoFrame.insert(vVideoFrame[i].F_GUID,vVideoFrame[i]);

    treeWidget = new QTreeWidget();

    treeWidget->move(25,25);

    treeWidget->setColumnCount(1);

    treeWidget->setHeaderLabel("");
 //pLoginDialog = new LoginDialog()
    //qDebug() << tr("Привет мир");

    QTreeWidgetItem *item1 = new QTreeWidgetItem((QTreeWidget*)0,QStringList(QString("ARSMS Plans")));
    item1->setIcon(0,QIcon(":/resources/images/6.bmp"));
    //item1->setData();
    item1->setExpanded(true);



    for(int i=0; i<vVideoFrame.size(); i++)
    {

        QTreeWidgetItem *item11 = new QTreeWidgetItem((QTreeWidget*)0,QStringList(vVideoFrame[i].F_DISPLAY_LABEL));
        item11->setIcon(0,QIcon(":resources/images/29.bmp"));
 //pLoginDialog = new LoginDialog()
        item11->setData(0,Qt::UserRole,vVideoFrame[i].F_GUID);

       // item11->setData(0,Qt::UserRole,i);


        item1->addChild(item11);

       // vVideoFrame[i].F_DISPLAY_LABEL

    }

   // item1->setExpanded(true);



    QTreeWidgetItem *item2 = new QTreeWidgetItem((QTreeWidget*)0,QStringList(QString("Charts")));
    item2->setIcon(0,QIcon(":/resources/images/3.bmp"));


    QTreeWidgetItem *item3 = new QTreeWidgetItem((QTreeWidget*)0,QStringList(QString("UserFormats")));
    item3->setIcon(0,QIcon(":/resources/images/2.bmp"));

    QTreeWidgetItem *item4 = new QTreeWidgetItem((QTreeWidget*)0,QStringList(QString("Forecasts")));
    item4->setIcon(0,QIcon(":/resources/images/5.bmp"));

    treeWidget->insertTopLevelItem(0, item4);
    treeWidget->insertTopLevelItem(0, item3);
    treeWidget->insertTopLevelItem(0, item2);
    treeWidget->insertTopLevelItem(0, item1);
    treeWidget->show();
    treeWidget->setAlternatingRowColors(true);
    //QModelIndex  index= treeWidget->indexAt( indexFromItem(item1);// currentIndex();
    //treeWidget->expand(index);
    item1->setExpanded(true);
   // treeWidget

     treeWidget->connect(treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*, int )),
                             this,   SLOT(onTreeItemClicked(QTreeWidgetItem*, int )));


    //QDebug
    short short_AccMask = lp.F_ACCESS_MASK;   //lp.F_ACCESS_MASK >> 16;
    bool rights = short_AccMask & 256;

     if(rights)
        {
         createActions();
         createMenus();
        }

   myTimerId1 = startTimer(1000);

   bitmapWorkerWidget = 0;

   //createStatusBar();

   //readSettings();


   modelVisualParam = new ModelVisualParam(this);

   //vBitmapWorker =0;
   db_LoginPasswords=0;
    tblLoginDlg =0;
    tblCheckpointDlg=0;
   db_visualParam=0;







}

MainWindow::~MainWindow()
{
    db_sig.stop();

    db_sig.wait();

    delete pdbVideoFrame;

    delete pLoginDialog;

    vLoginPasswords.clear();

    if(tblLoginDlg)
        delete tblLoginDlg;


    if(tblCheckpointDlg)
        delete tblCheckpointDlg;

     delete promengDialogWidget;

     treeWidget->close();
     delete treeWidget;

     for(int i=0; i<vBitmapWorker.size(); i++)   // vBitmapWorker
                 delete vBitmapWorker[i];
     //delete [] vBitmapWorker;

     if(db_LoginPasswords)
     delete db_LoginPasswords;



     if(db_visualParam)
     delete db_visualParam;
     vRemovedItems.clear();


    // }
}
void MainWindow::closeEvent(QCloseEvent *event)

{
    Q_UNUSED(event);
    //if (maybeSave()) {
     //   writeSettings();
     //   event->accept();
   // } else {
     //   event->ignore();
   // }
   // if(bitmapWorkerWidget!=0)
   // delete bitmapWorkerWidget;
}
void MainWindow::createActions()

{


   // openMapAct = new QAction(tr("Загрузка карты"),this);
   // connect(openMapAct, SIGNAL(triggered()), this, SLOT(openMap()));

    loginManageAct = new QAction(tr("Управление пользователями"),this);
    connect(loginManageAct, SIGNAL(triggered()), this, SLOT(openLoginManage()));


    saveDataAct = new QAction(tr("Сохранить данные в базу"),this);
    connect(saveDataAct, SIGNAL(triggered()), this, SLOT(saveToDatabase()));

    saveDataAct->setDisabled(true);


    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);

    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));




    checkPointManageAct = new QAction(tr("Управление Чекпойнтами"),this);
    connect(checkPointManageAct, SIGNAL(triggered()), this, SLOT(openCheckPointManage()));

    saveCheckPointAct = new QAction(tr("Сохранить данные в базу"),this);
    connect(saveCheckPointAct, SIGNAL(triggered()), this, SLOT(saveCheckPointToDatabase()));

    saveCheckPointAct->setDisabled(true);



}

void MainWindow::createMenus()

{
    usersMenu = menuBar()->addMenu(tr("Пользователи"));

    usersMenu->addAction(loginManageAct);

    usersMenu->addAction(saveDataAct);


    CheckPointsMenu = menuBar()->addMenu(tr("Чекпойнты"));

    CheckPointsMenu->addAction(checkPointManageAct);

    CheckPointsMenu->addAction(saveCheckPointAct);


}

void MainWindow::createToolBars()
{

}

void MainWindow::createStatusBar()

{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::onTreeItemClicked(QTreeWidgetItem *item, int col)
{
     Q_UNUSED(col);
    /*switch(item->text(1))
    {
            case "Map Bushehr":

            bitmapWorkerWidget = new BitmapWorker(fileName, image,winPos);
            //bitmapWorkerWidget->
            //bitmapWorkerWidget->setGeometry(300,100,1300,850);
            bitmapWorkerWidget->move(300,100);
            bitmapWorkerWidget->show();
            break;


            default:
            break;

    }*/
//if (col > 0) return;



//int vIndex = item->data(0,Qt::UserRole).toInt();

int F_GUID = item->data(0,Qt::UserRole).toInt();

//QString itemStr = item->text(0);

//QString str_F_NAME = vVideoFrame[vIndex].F_NAME;

QString str_F_NAME = mVideoFrame[F_GUID].F_NAME;


//int VideoFrameGuid = vVideoFrame[vIndex].F_GUID;
int VideoFrameGuid = mVideoFrame[F_GUID].F_GUID;

//QString VideoFrameTitle = vVideoFrame[vIndex].F_DISPLAY_LABEL;
QString VideoFrameTitle = mVideoFrame[F_GUID].F_DISPLAY_LABEL;

//QString str_F_NAME = vecCheckpointProperties[j].CheckpointObject_F_NAME;

QString imgFullPath =    "./resources/" + str_F_NAME +    ".bmp";

//AQP::



       //QString fileName = "/home/eugene/qt/ManyWindows/Map2_new.bmp";
      // QString fileName =":/resources/Map2_new.bmp";
                // if (!fileName.isEmpty()) {
                  //  QImage image(fileName);
                  //  if (image.isNull())          {
                   //                     QMessageBox::information(this, tr("Image Viewer"),
                      //                                    tr("Cannot load %1.").arg(fileName));
                     //                                    return;
                      //                           }
                          QPoint winPos(300,100);

                    // bitmapWorkerWidget = new BitmapWorker(fileName, image,winPos,Busher,db);
                       bitmapWorkerWidget = new BitmapWorker(imgFullPath,db,VideoFrameGuid,modelVisualParam, this);
                       bitmapWorkerWidget->setWindowTitle(VideoFrameTitle);
                       vBitmapWorker.append(bitmapWorkerWidget);

                     //QObject::connect(&db_sig,SIGNAL(writeToDialog(QVector<Signal> )),bitmapWorkerWidget,SLOT(writeSignal(QVector<Signal> )));
                     QObject::connect(&db_sig,SIGNAL(writeToDialog(vec_signal )),bitmapWorkerWidget,SLOT(writeSignal(vec_signal  )));

                     db_sig.start();

       //bitmapWorkerWidget->
       //bitmapWorkerWidget->setGeometry(300,100,1300,850);
                bitmapWorkerWidget->move(300,170);
                     bitmapWorkerWidget->show();

                               // }





}

void MainWindow::openMap()
{
}

void MainWindow::openLoginManage()
{
    //ModelLoginPassword modelLoginPassword;


     db_LoginPasswords = new DbLoginPasswords(tmpDatabase);

    vLoginPasswords = db_LoginPasswords->getLoginAndPasswords();

    modelLoginPassword.setLoginPasswordVec(vLoginPasswords);



    tableView.setModel(&modelLoginPassword);

    tableView.setWindowTitle(QObject::tr("Login and Passwords"));

   // setBaseSize(500,500);

    tableView.resizeColumnsToContents();



     //tableView.setFixedSize(500,500);

     tableView.setFixedSize(tableView.horizontalHeader()->length() + 60, tableView.verticalHeader()->length() + 100);

     tblLoginDlg = new TableEditDialog( &modelLoginPassword, &tableView);
     tblLoginDlg ->show();


     saveDataAct->setEnabled(true);

    //tableView.show();

}

void MainWindow::saveToDatabase()
{
   vLoginPasswords = modelLoginPassword.getLoginPasswordVec();

   vRemovedItems =modelLoginPassword.getRemovedItems();
  //
   db_LoginPasswords->updateLoginAndPasswords(vLoginPasswords,vRemovedItems);
}

void MainWindow::openCheckPointManage()
{
    //ModelLoginPassword modelLoginPassword;


     db_visualParam = new db_VisualParam(tmpDatabase);

    vVisualParam = db_visualParam->loadTableVisualParamForAllFrame();

    modelVisualParam->setVisualParamVec(vVisualParam);







     viewVisualParam.setModel(modelVisualParam);

    //tableView.setWindowTitle(QObject::tr("Login and Passwords"));

   // setBaseSize(500,500);

     viewVisualParam.resizeColumnsToContents();



     //tableView.setFixedSize(500,500);

      viewVisualParam.setFixedSize( viewVisualParam.horizontalHeader()->length() + 60,  350);

     tblCheckpointDlg = new CheckPointEditDialog( modelVisualParam, &viewVisualParam);
     tblCheckpointDlg->show();


      saveCheckPointAct->setEnabled(true);

      //connect(&modelVisualParam,SIGNAL(dataChanged ( const QModelIndex & topLeft, const QModelIndex & bottomRight )),this, SLOT(onCheckPointDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight)));

    //tableView.show();
}

void MainWindow::saveCheckPointToDatabase()
{
    vVisualParam = modelVisualParam->getVisualParamVec();

    vRemovedChekpoints =modelVisualParam->getRemovedItems(); //  modelLoginPassword.getRemovedItems();
   //


    db_visualParam->updateVisualParam(vVisualParam,vRemovedChekpoints);

    //db_LoginPasswords->updateLoginAndPasswords(vLoginPasswords,vRemovedItems);
}

void MainWindow::onCheckPointDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight)
{
      qDebug() << "CheckPointDataChanged";
       for(int i=0; i<vBitmapWorker.size(); i++)   // vBitmapWorker
                // vBitmapWorker[i]->timeUpdate();
      vBitmapWorker[i]->checkPointUpdate();
}

 void MainWindow::timerEvent(QTimerEvent *event)
 {

     if(event->timerId()== myTimerId1){

            promengDialogWidget->timeUpdate();


            for(int i=0; i<vBitmapWorker.size(); i++)   // vBitmapWorker
                 vBitmapWorker[i]->timeUpdate(); //if(bitmapWorkerWidget!=0)

            }
     else
     {
        QWidget::timerEvent(event);

     }



 }
