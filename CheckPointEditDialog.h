#ifndef CHECKPOINTEDITDIALOG_H
#define CHECKPOINTEDITDIALOG_H


#include "AllHeaders.h"
#include <QtGui>

class ModelVisualParam;

class CheckPointEditDialog : public QDialog
{
public:
   // ModelVisualParam modelVisualParam;

   // QTableView viewVisualParam;

    Q_OBJECT
public:
    explicit CheckPointEditDialog( ModelVisualParam *modelVisualParam, QTableView *viewVisualParam, QWidget *parent = 0);
    ~CheckPointEditDialog();
    bool get_IsCheckPointsChanged();
    void  set_IsCheckPointsChanged(bool IsCheckPointsChanged);

public slots:

    void onCancelBtnClicked();
    void onOkClicked();
    void onInsertBtnClicked();
    void onDeleteBtnClicked();
    void onDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);

private:
    QTableView *viewVisualParam;
    ModelVisualParam *modelVisualParam;
    //ModelLoginPassword *oldmodelLoginPassword;

    QVector<VisualParam> vVisualParam;

    //QVector<LoginPassword> vLoginPasswords;

    QMenu *bdMenu;

   // QAction *openMapAct;
   // QAction *exitAct;
   // QAction *loginManageAct;
    QAction *saveDataAct;
    QAction * addRecordAct;
    QAction * removeRecordAct;

    bool IsCheckPointsChanged;



};








#endif // CHECKPOINTEDITDIALOG_H
