#ifndef TABLEEDITDIALOG_H
#define TABLEEDITDIALOG_H

#include "AllHeaders.h"
#include <QtGui>

class ModelLoginPassword;

class TableEditDialog : public QDialog
{
public:


    Q_OBJECT
public:
    explicit TableEditDialog(ModelLoginPassword *tableModel, QTableView *tableView, QWidget *parent = 0);

public slots:
    void saveData();
    void addRecord();
    void removeRecord();
    void onCancelBtnClicked();
    void onOkClicked();
    void onInsertBtnClicked();
    void onDeleteBtnClicked();

private:
    QTableView *tableView;
    ModelLoginPassword *tableModel;
    //ModelLoginPassword *oldmodelLoginPassword;

    QVector<LoginPassword> vLoginPasswords;

    QMenu *bdMenu;

   // QAction *openMapAct;
   // QAction *exitAct;
   // QAction *loginManageAct;
    QAction *saveDataAct;
    QAction * addRecordAct;
    QAction * removeRecordAct;


    void createActions();
    void createMenus();
};

#endif // TABLEEDITDIALOG_H
