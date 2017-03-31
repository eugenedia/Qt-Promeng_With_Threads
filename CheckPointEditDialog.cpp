#include "CheckPointEditDialog.h"




CheckPointEditDialog::CheckPointEditDialog(ModelVisualParam *modelVisualParam, QTableView *viewVisualParam, QWidget *parent)
{
    //this->db = db;
    //this->SelectedGuidSignal = SelectedGuidSignal;

    this->viewVisualParam = viewVisualParam;
    this->modelVisualParam = modelVisualParam;
    vVisualParam = modelVisualParam->getVisualParamVec(); // ->getLoginPasswordVec();

    //oldmodelLoginPassword = new ModelLoginPassword();
    //*oldmodelLoginPassword = *tableModel;

   // QGridLayout *leftGrid = new QGridLayout ;

    QVBoxLayout *vLayout = new QVBoxLayout(this);


   // QGroupBox *grpCheckPoint =new QGroupBox("Enter Login and Password:");







    QPushButton *InsertBtn = new QPushButton(this );
    InsertBtn->setText(tr("INSERT"));

    QPushButton *DeleteBtn = new QPushButton(this);
    DeleteBtn->setText(tr("DELETE"));

    QPushButton *okBtn = new QPushButton(this);
    okBtn->setText(tr("OK"));


    QPushButton *cancelBtn = new QPushButton(this);
    cancelBtn->setText(tr("CANCEL"));


    connect(InsertBtn,SIGNAL(clicked()),this, SLOT(onInsertBtnClicked()));
    connect(DeleteBtn,SIGNAL(clicked()),this, SLOT(onDeleteBtnClicked()));

    connect(okBtn,SIGNAL(clicked()),this, SLOT(onOkClicked()));
    connect(cancelBtn,SIGNAL(clicked()),this, SLOT(onCancelBtnClicked()));
    bdMenu = new QMenu(this);

    //leftGrid->setMenuBar(bdMenu);

    // leftGrid->addWidget(bdMenu,0,0);

    //leftGrid->addWidget(tableView,1,0,4,3);
    vLayout->addWidget(viewVisualParam);

    //добавить LeftLayout, а дальше меню.

    QHBoxLayout *hLayout = new QHBoxLayout(this);

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
    setWindowTitle(tr("Edit Checkpoints"));
    //setWindowTitle(tr("ARSMS Bushehr."));
    setFixedHeight(sizeHint().height());

    IsCheckPointsChanged = false;

   // connect(modelVisualParam,SIGNAL(dataChanged ( const QModelIndex & topLeft, const QModelIndex & bottomRight )),this, SLOT(onDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight)));



}

CheckPointEditDialog::~CheckPointEditDialog()
{
   delete viewVisualParam;
   delete modelVisualParam;
   vVisualParam.clear();
}

bool CheckPointEditDialog::get_IsCheckPointsChanged()
{
return IsCheckPointsChanged;
}















void CheckPointEditDialog::onCancelBtnClicked()
{
    ///tableModel->setLoginPasswordVec(vLoginPasswords);viewVisualParam

      modelVisualParam->setVisualParamVec( vVisualParam );
            // getVisualParamVec();
}

void CheckPointEditDialog::onOkClicked()
{
    this->close();
}



void CheckPointEditDialog::onInsertBtnClicked()
{
    //tableView.insertAction();
    int rowCount = modelVisualParam->rowCount(QModelIndex());
    modelVisualParam->insertRows(rowCount, 1, QModelIndex());

    QModelIndex index = modelVisualParam->index(rowCount,0,QModelIndex());
    //createIndex(rowCount,1);
    viewVisualParam->setCurrentIndex(index);

   // viewVisualParam->set

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

void CheckPointEditDialog::onDeleteBtnClicked()
{

            //QItemSelectionModel *selectionModel = tableView->selectionModel();


            //QModelIndexList indexes = selectionModel->selectedRows();
            QModelIndex index = viewVisualParam->currentIndex();

           // foreach (index, indexes) {
                //int row = proxy->mapToSource(index).row();
                int row = index.row();
                modelVisualParam->removeRows(row, 1, QModelIndex());
                // }
}

void CheckPointEditDialog::onDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight)
{
     IsCheckPointsChanged = true;
}







void CheckPointEditDialog::set_IsCheckPointsChanged(bool IsCheckPointsChanged)
{
    this->IsCheckPointsChanged = IsCheckPointsChanged;
}
