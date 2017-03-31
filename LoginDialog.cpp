#include "LoginDialog.h"

LoginDialog::LoginDialog(QSqlDatabase &db, QWidget *parent) :
    QDialog(parent)
{

    this->db = db;
    //this->SelectedGuidSignal = SelectedGuidSignal;
    QGridLayout *leftGrid = new QGridLayout ;


    QGroupBox *grpCheckPoint =new QGroupBox("Enter Login and Password:");





    QLabel *lbl_Login =new QLabel();
    lbl_Login->setText(tr("Login: "));
    edt_Login = new QLineEdit();
    edt_Login->setText("Operator");
    ///edt_Login->setReadOnly(true);


    QPalette palette = edt_Login->palette();
    palette.setColor(QPalette::Base, QColor(210,210,210));
    edt_Login->setPalette(palette);


    QLabel *lbl_Password =new QLabel();
    lbl_Password->setText(tr("Password"));
    edt_Password = new QLineEdit();
    edt_Password->setText("askro");
    edt_Password->setEchoMode(QLineEdit::Password);
    //edt_Password->setReadOnly(true);

    QPushButton *okBtn = new QPushButton();
    okBtn->setText(tr("OK"));
    //okBtn->set

    QPushButton *cancelBtn = new QPushButton();
    cancelBtn->setText(tr("CANCEL"));

    connect(okBtn,SIGNAL(clicked()),this, SLOT(onOkClicked()));
    connect(cancelBtn,SIGNAL(clicked()),this, SLOT(onCancelBtnClicked()));

    leftGrid->addWidget(lbl_Login,0,0);
    leftGrid->addWidget(edt_Login,0,1);
    leftGrid->addWidget(lbl_Password,1,0);
    leftGrid->addWidget(edt_Password,1,1);
    leftGrid->addWidget(okBtn,3,0);
    leftGrid->addWidget(cancelBtn,3,1);


    grpCheckPoint->setLayout(leftGrid);



    QHBoxLayout * leftLayout = new QHBoxLayout;
    leftLayout->addWidget(grpCheckPoint);



    setLayout(leftLayout);
    setWindowTitle(tr("Login And Passwords"));
    //setWindowTitle(tr("ARSMS Bushehr."));
    setFixedHeight(sizeHint().height());




    db_LoginPasswords = new DbLoginPasswords(db);

    loginSucc = false;

     lp = new LoginPassword ;





}

LoginDialog::~LoginDialog()
{
    delete db_LoginPasswords;
    delete lp;
}

LoginPassword LoginDialog::getLoginStatus()
{
   // return loginSucc;
    return *lp;
}

void LoginDialog::onOkClicked()
{
    //bool check = checkLoginInformation();
    checkLoginInformation();
    this->accept();
   /* if (check){ loginSucc = true; this->accept();}
    else
    {loginSucc = false; this->accept();}*/
        //QMessageBox(QMessageBox::NoIcon,QString("Wrong Password"), QString("Wrong Password")).show();
}

void LoginDialog::onCancelBtnClicked()
{
    this->reject();
}

LoginPassword LoginDialog::checkLoginInformation()
{
  //bool check =  db_LoginPasswords->CheckLoginAndPasswords(edt_Login->text(), edt_Password->text());
    *lp = db_LoginPasswords->CheckLoginAndPasswords(edt_Login->text(), edt_Password->text());
  //return check;
    return *lp;

}

