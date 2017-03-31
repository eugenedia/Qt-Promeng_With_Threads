#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    promengDialogWidget = new PromengDialog;

    setWindowTitle(tr("ARSMS Bushehr"));



    setCentralWidget(promengDialogWidget);
    move(300,25);



    db.loadDatabase();


    treeWidget = new QTreeWidget();

    treeWidget->move(25,25);

    treeWidget->setColumnCount(1);

    treeWidget->setHeaderLabel("");

    //qDebug() << tr("Привет мир");

    QTreeWidgetItem *item1 = new QTreeWidgetItem((QTreeWidget*)0,QStringList(QString("ARSMS Plans")));
    item1->setIcon(0,QIcon(":/resources/images/6.bmp"));
    //item1->setData();
    item1->setExpanded(true);

    QTreeWidgetItem *item11 = new QTreeWidgetItem((QTreeWidget*)0,QStringList(QString("Ventillation Full")));
    item11->setIcon(0,QIcon(":resources/images/29.bmp"));

    QTreeWidgetItem *item12 = new QTreeWidgetItem((QTreeWidget*)0,QStringList(QString("Ventillation Stack")));
    item12->setIcon(0,QIcon(":resources/images/29.bmp"));

    QTreeWidgetItem *item13 = new QTreeWidgetItem((QTreeWidget*)0,QStringList(QString("Meteo")));
    item13->setIcon(0,QIcon(":resources/images/29.bmp"));

    QTreeWidgetItem *item14 = new QTreeWidgetItem((QTreeWidget*)0,QStringList(QString("NPP Site")));
    item14->setIcon(0,QIcon(":resources/images/29.bmp"));

    QTreeWidgetItem *item15 = new QTreeWidgetItem((QTreeWidget*)0,QStringList(QString("Map Bushehr")));
    item15->setIcon(0,QIcon(":resources/images/29.bmp"));

    item1->addChild(item11);
    item1->addChild(item12);
    item1->addChild(item13);
    item1->addChild(item14);
    item1->addChild(item15);

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
   // item1->setExpanded(true);
   // treeWidget

     treeWidget->connect(treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*, int )),
                             this,   SLOT(onTreeItemClicked(QTreeWidgetItem*, int )));




   createActions();
   createMenus();


   myTimerId1 = startTimer(1000);

   //createStatusBar();

   //readSettings();





}

MainWindow::~MainWindow()
{
    
}
void MainWindow::closeEvent(QCloseEvent *event)
//! [3] //! [4]
{
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
    /*newAct = new QAction(QIcon(":/images/new.png"), tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));*/

    openMapAct = new QAction(tr("Загрузка карты"),this);
    connect(openMapAct, SIGNAL(triggered()), this, SLOT(openMap()));



    /*openAct = new QAction(QIcon(":/images/open.png"), tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));*/


    /*saveAct = new QAction(QIcon(":/images/save.png"), tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));*/

    /*saveAsAct = new QAction(tr("Save &As..."), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Save the document under a new name"));
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));*/


    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);

    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));


    //cutAct = new QAction(QIcon(":/images/cut.png"), tr("Cu&t"), this);

    //cutAct->setShortcuts(QKeySequence::Cut);
    //cutAct->setStatusTip(tr("Cut the current selection's contents to the "
     //                       "clipboard"));
    //connect(cutAct, SIGNAL(triggered()), textEdit, SLOT(cut()));

   /* copyAct = new QAction(QIcon(":/images/copy.png"), tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                             "clipboard"));
    connect(copyAct, SIGNAL(triggered()), textEdit, SLOT(copy()));

    pasteAct = new QAction(QIcon(":/images/paste.png"), tr("&Paste"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"));
    connect(pasteAct, SIGNAL(triggered()), textEdit, SLOT(paste()));*/

    /*aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

//! [22]
    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
//! [22]

//! [23]
    cutAct->setEnabled(false);
//! [23] //! [24]
    copyAct->setEnabled(false);
    connect(textEdit, SIGNAL(copyAvailable(bool)),
            cutAct, SLOT(setEnabled(bool)));
    connect(textEdit, SIGNAL(copyAvailable(bool)),
            copyAct, SLOT(setEnabled(bool)));*/
}

void MainWindow::createMenus()

{
    fileMenu = menuBar()->addMenu(tr("Окна"));

    fileMenu->addAction(openMapAct);


}

void MainWindow::createToolBars()
{
   /* fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAct);
//! [29] //! [31]
    fileToolBar->addAction(openAct);
//! [31]
    fileToolBar->addAction(saveAct);

    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(cutAct);
    editToolBar->addAction(copyAct);
    editToolBar->addAction(pasteAct);*/
}
//! [30]

//! [32]
void MainWindow::createStatusBar()
//! [32] //! [33]
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::onTreeItemClicked(QTreeWidgetItem *item, int col)
{
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
QString itemStr = item->text(0);

   if (itemStr=="Map Bushehr")
            {
       //QString fileName = "/home/eugene/qt/ManyWindows/Map2_new.bmp";
       QString fileName =":/resources/Map2_new.bmp";
                 if (!fileName.isEmpty()) {
                    QImage image(fileName);
                    if (image.isNull())          {
                                        QMessageBox::information(this, tr("Image Viewer"),
                                                          tr("Cannot load %1.").arg(fileName));
                                                         return;
                                                 }
                          QPoint winPos(300,100);

                     bitmapWorkerWidget = new BitmapWorker(fileName, image,winPos,Busher,db);
       //bitmapWorkerWidget->
       //bitmapWorkerWidget->setGeometry(300,100,1300,850);
                bitmapWorkerWidget->move(300,170);
                     bitmapWorkerWidget->show();

                                }
        }

   /*if (itemStr=="Ventillation Full")
        {
       //QString fileName = "/home/eugene/qt/ManyWindows/Map2_new.bmp";
       QString fileName =":/resources/VentFull.bmp";
       if (!fileName.isEmpty()) {
           QImage image(fileName);
           if (image.isNull()) {
               QMessageBox::information(this, tr("Image Viewer"),
                                        tr("Cannot load %1.").arg(fileName));
               return;
           }
           QPoint winPos(300,100);

       bitmapWorkerWidget = new BitmapWorker(fileName, image,winPos,Busher,db);
       //bitmapWorkerWidget->
       //bitmapWorkerWidget->setGeometry(300,100,1300,850);
       bitmapWorkerWidget->move(400,170);
       bitmapWorkerWidget->show();

        }
    }

   if (itemStr=="Ventillation Stack")
        {

       QString fileName =":/resources/Truba.bmp";
       if (!fileName.isEmpty()) {
           QImage image(fileName);
           if (image.isNull()) {
               QMessageBox::information(this, tr("Image Viewer"),
                                        tr("Cannot load %1.").arg(fileName));
               return;
           }
           QPoint winPos(300,100);

       bitmapWorkerWidget = new BitmapWorker(fileName, image,winPos,Busher,db);
       //bitmapWorkerWidget->
       //bitmapWorkerWidget->setGeometry(300,100,1300,850);
       bitmapWorkerWidget->move(500,170);
       bitmapWorkerWidget->show();

        }
    }
   if (itemStr=="Meteo")
        {

       QString fileName =":/resources/MeteoB_NEW.bmp";
       if (!fileName.isEmpty()) {
           QImage image(fileName);
           if (image.isNull()) {
               QMessageBox::information(this, tr("Image Viewer"),
                                        tr("Cannot load %1.").arg(fileName));
               return;
           }
           QPoint winPos(1300,100);

       bitmapWorkerWidget = new BitmapWorker(fileName, image,winPos,Busher,db);
       //bitmapWorkerWidget->
       //bitmapWorkerWidget->setGeometry(300,100,1300,850);
       bitmapWorkerWidget->move(1300,170);
       bitmapWorkerWidget->show();

        }
    }
   if (itemStr=="NPP Site")
        {

       QString fileName =":/resources/Map1_new.bmp";
       if (!fileName.isEmpty()) {
           QImage image(fileName);
           if (image.isNull()) {
               QMessageBox::information(this, tr("Image Viewer"),
                                        tr("Cannot load %1.").arg(fileName));
               return;
           }
           QPoint winPos(300,100);

       bitmapWorkerWidget = new BitmapWorker(fileName, image,winPos,Busher,db);
       //bitmapWorkerWidget->
       //bitmapWorkerWidget->setGeometry(300,100,1300,850);
       bitmapWorkerWidget->move(600,170);
       bitmapWorkerWidget->show();

        }
    }*/


}

void MainWindow::openMap()
{
    /*QString fileName = QFileDialog::getOpenFileName(this,
                                    tr("Open File"), QDir::currentPath());*/

   /* QString fileName = "/home/eugene/qt/ManyWindows/Map2_new.bmp";

    if (!fileName.isEmpty()) {
        QImage image(fileName);
        if (image.isNull()) {
            QMessageBox::information(this, tr("Image Viewer"),
                                     tr("Cannot load %1.").arg(fileName));
            return;
        }
        QPoint winPos(300,100);
        bitmapWorkerWidget = new BitmapWorker(fileName, image,winPos,Busher,db);
        //bitmapWorkerWidget->
        //bitmapWorkerWidget->setGeometry(300,100,1300,850);
        bitmapWorkerWidget->move(300,100);
        bitmapWorkerWidget->show();
}*/}

 void MainWindow::timerEvent(QTimerEvent *event)
 {




 }
