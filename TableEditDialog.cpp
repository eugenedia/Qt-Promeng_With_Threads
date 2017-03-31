#include "TableEditDialog.h"




TableEditDialog::TableEditDialog(ModelLoginPassword *tableModel, QTableView *tableView, QWidget *parent):
    QDialog(parent)
{
    //this->db = db;
    //this->SelectedGuidSignal = SelectedGuidSignal;

    this->tableView = tableView;
    this->tableModel = tableModel;
    vLoginPasswords = tableModel->getLoginPasswordVec();

    //oldmodelLoginPassword = new ModelLoginPassword();
    //*oldmodelLoginPassword = *tableModel;

   // QGridLayout *leftGrid = new QGridLayout ;

    QVBoxLayout *vLayout = new QVBoxLayout;


   // QGroupBox *grpCheckPoint =new QGroupBox("Enter Login and Password:");







    QPushButton *InsertBtn = new QPushButton();
    InsertBtn->setText(tr("INSERT"));

    QPushButton *DeleteBtn = new QPushButton();
    DeleteBtn->setText(tr("DELETE"));

    QPushButton *okBtn = new QPushButton();
    okBtn->setText(tr("OK"));


    QPushButton *cancelBtn = new QPushButton();
    cancelBtn->setText(tr("CANCEL"));


    connect(InsertBtn,SIGNAL(clicked()),this, SLOT(onInsertBtnClicked()));
    connect(DeleteBtn,SIGNAL(clicked()),this, SLOT(onDeleteBtnClicked()));

    connect(okBtn,SIGNAL(clicked()),this, SLOT(onOkClicked()));
    connect(cancelBtn,SIGNAL(clicked()),this, SLOT(onCancelBtnClicked()));
    bdMenu = new QMenu();

    //leftGrid->setMenuBar(bdMenu);

    // leftGrid->addWidget(bdMenu,0,0);

    //leftGrid->addWidget(tableView,1,0,4,3);
    vLayout->addWidget(tableView);

    //добавить LeftLayout, а дальше меню.

    QHBoxLayout *hLayout = new QHBoxLayout;

    //hLayout-

    hLayout->addWidget(InsertBtn);
    hLayout->addWidget(DeleteBtn);
    hLayout->addWidget(okBtn);
    hLayout->addWidget(cancelBtn);

    vLayout->addLayout(hLayout);

    //grpCheckPoint->setLayout(leftGrid);



    //QHBoxLayout * leftLayout = new QHBoxLayout;
    //leftLayout->addLaytableModelout(leftGrid);

    //leftLayout->addWidget(leftGrid);


    setLayout(vLayout);
    setWindowTitle(tr("Edit login and passwords"));
    //setWindowTitle(tr("ARSMS Bushehr."));
    setFixedHeight(sizeHint().height());









}

void TableEditDialog::saveData()
{
}

void TableEditDialog::addRecord()
{
}

void TableEditDialog::removeRecord()
{
}

void TableEditDialog::onCancelBtnClicked()
{
    tableModel->setLoginPasswordVec(vLoginPasswords);
}

void TableEditDialog::onOkClicked()
{
    this->close();
}



void TableEditDialog::onInsertBtnClicked()
{
    //tableView.insertAction();
    int rowCount = tableModel->rowCount(QModelIndex());
    tableModel->insertRows(rowCount, 1, QModelIndex());

    /*QModelIndex index = tableModel->index(rowCount, 0, QModelIndex());
    tableModel->setData(index, "", Qt::EditRole);

     index = tableModel->index(rowCount, 1, QModelIndex());
    tableModel->setData(index, "", Qt::EditRole);

    index = tableModel->index(rowCount,2, QModelIndex());
    tableModel->setData(index, "", Qt::EditRole);

    index = tableModel->index(rowCount, 3, QModelIndex());
   tableModel->setData(index, 0, Qt::EditRole);*/


    //tableModel->insertRow(0);

}

void TableEditDialog::onDeleteBtnClicked()
{

            //QItemSelectionModel *selectionModel = tableView->selectionModel();


            //QModelIndexList indexes = selectionModel->selectedRows();
            QModelIndex index = tableView->currentIndex();

           // foreach (index, indexes) {
                //int row = proxy->mapToSource(index).row();
                int row = index.row();
                tableModel->removeRows(row, 1, QModelIndex());
           // }
}

void TableEditDialog::createActions()

{


   // openMapAct = new QAction(tr("Загрузка карты"),this);
   // connect(openMapAct, SIGNAL(triggered()), this, SLOT(openMap()));

      saveDataAct = new QAction(tr("Сохранить данные в базу"),this);
      connect(saveDataAct, SIGNAL(triggered()), this, SLOT(saveData()));


      addRecordAct = new QAction(tr("Добавить запись "),this);
      connect(addRecordAct, SIGNAL(triggered()), this, SLOT(addRecord()));

      removeRecordAct = new QAction(tr("Удалить запись "),this);
      connect(removeRecordAct, SIGNAL(triggered()), this, SLOT(removeRecord()));








}

void TableEditDialog::createMenus()

{
    bdMenu->addMenu(tr("Управление записями"));

    bdMenu->addAction(saveDataAct);

    bdMenu->addAction(addRecordAct);

    bdMenu->addAction(removeRecordAct);


}
