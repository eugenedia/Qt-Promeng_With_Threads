//*****************************************
//********* главное окно - создает и управляет дочернми виджетами.
//************************************************************************
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "PromengDialog.h"
#include "bitmapworker.h"
#include "AllHeaders.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void checkLogin(bool check);
protected:
    void closeEvent(QCloseEvent *event);
    void timerEvent(QTimerEvent *event);

private slots:
    void onTreeItemClicked(QTreeWidgetItem*, int );
    void openMap();
    void openLoginManage();
    void saveToDatabase();
    void openCheckPointManage();
    void saveCheckPointToDatabase();
    void onCheckPointDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
private:
    QPlainTextEdit *textEdit;
    QTreeWidget *treeWidget;
    BitmapWorker *bitmapWorkerWidget;
    PromengDialog  *promengDialogWidget;

    QString curFile;

    QMenu *usersMenu;
    QMenu *CheckPointsMenu;

    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();

    QAction *openMapAct;
    QAction *exitAct;
    QAction *loginManageAct;
    QAction *saveDataAct;
    QAction *checkPointManageAct;
    QAction *saveCheckPointAct;

    DBConn db;

    int myTimerId1;

    db_Signal db_sig;


    db_VideoFrame * pdbVideoFrame;

    QVector<VideoFrame> vVideoFrame;

    QVector<BitmapWorker*> vBitmapWorker;

    QMap<int, VideoFrame> mVideoFrame;

    QSqlDatabase tmpDatabase;


    LoginDialog * pLoginDialog;
    int loginCount;

     LoginPassword lp;

     QVector<LoginPassword> vLoginPasswords;

     QVector<LoginPassword> vRemovedItems;

     QVector<VisualParam> vVisualParam;
     QVector<VisualParam> vRemovedChekpoints;


     DbLoginPasswords * db_LoginPasswords;
     db_VisualParam * db_visualParam;

     ModelLoginPassword modelLoginPassword;

     QTableView tableView;

     ModelVisualParam *modelVisualParam;

     QTableView viewVisualParam;

     TableEditDialog *tblLoginDlg;
     CheckPointEditDialog *tblCheckpointDlg;

};



#endif // MAINWINDOW_H
