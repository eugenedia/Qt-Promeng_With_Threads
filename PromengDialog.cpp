#include <QtGui>

#include "PromengDialog.h"

PromengDialog::PromengDialog(QWidget *parent)
    : QDialog(parent)
{


  QHBoxLayout *topLeftLayout = new QHBoxLayout;
   PromengLogo = new QPixmap(":/resources/AsrkroLogoPanel.bmp");
   //PromengLogo->
  PromengLogoWid = new QLabel();



  PromengLogoWid->setPixmap(*PromengLogo);



   topLeftLayout->addWidget(PromengLogoWid);
   topLeftLayout->addSpacing(100);

   QGroupBox *grp1 =new QGroupBox("Software status");
   //grp1->setTitle("Олололололо");

   QPixmap *imgGreenStatus = new QPixmap(":/resources/1.0.bmp");

   QPixmap *imgGreenStatusWithTextC1 = new QPixmap(":/resources/1.0.bmp");
   QPixmap *imgGreenStatusWithTextC2 = new QPixmap(":/resources/1.0.bmp");
   QPixmap *imgGreenStatusWithTextC3 = new QPixmap(":/resources/1.0.bmp");
   QPixmap *imgGreenStatusWithTextC4 = new QPixmap(":/resources/1.0.bmp");


   QPainter *draw = new QPainter(imgGreenStatusWithTextC1);
   draw->setPen( Qt::black );
   //draw->set
   //QTextOption *txtOpt = new QTextOption(Qt::AlignCenter);
   //QTextOption txtOpt(Qt::AlignVCenter);// = new QTextOption(Qt::AlignCenter);

   draw->drawText( imgGreenStatusWithTextC1->rect(),Qt::AlignCenter,"C1" );

   draw = new QPainter(imgGreenStatusWithTextC2);
   draw->setPen( Qt::black );
   draw->drawText( imgGreenStatusWithTextC2->rect(),Qt::AlignCenter,"C2" );

   draw = new QPainter(imgGreenStatusWithTextC3);
   draw->setPen( Qt::black );
   draw->drawText( imgGreenStatusWithTextC3->rect(),Qt::AlignCenter,"C3" );
http://egor-tokmakov.livejournal.com/1487.html#cutid1
   draw = new QPainter(imgGreenStatusWithTextC4);
   draw->setPen( Qt::black );
   draw->drawText( imgGreenStatusWithTextC3->rect(),Qt::AlignCenter,"C4" );



  // pmDestination->setPixmap( *pm );

   QLabel *lblGreenStatusGrp1C1 = new QLabel();
   QLabel *lblGreenStatusGrp1C2 = new QLabel();
   QLabel *lblGreenStatusGrp1C3 = new QLabel();
   QLabel *lblGreenStatusGrp1DB = new QLabel();

   //lblGreenStatusGrp1C1->setPixmap(*imgGreenStatus);
   //lblGreenStatusGrp1C1->setText("C1");
   lblGreenStatusGrp1C1->setPixmap(*imgGreenStatusWithTextC1);

   lblGreenStatusGrp1C2->setPixmap(*imgGreenStatusWithTextC2);
   lblGreenStatusGrp1C3->setPixmap(*imgGreenStatusWithTextC3);
   lblGreenStatusGrp1DB->setPixmap(*imgGreenStatusWithTextC4);


   QHBoxLayout *firstStatusLayot =  new QHBoxLayout;
   firstStatusLayot->addWidget(lblGreenStatusGrp1C1);
   firstStatusLayot->addSpacing(5);
   firstStatusLayot->addWidget(lblGreenStatusGrp1C2);
   firstStatusLayot->addSpacing(5);
   firstStatusLayot->addWidget(lblGreenStatusGrp1C3);
   firstStatusLayot->addSpacing(5);
   firstStatusLayot->addWidget(lblGreenStatusGrp1DB);


   grp1->setLayout(firstStatusLayot);


   QGroupBox *grp2 =new QGroupBox("Equipment status");

  // QPixmap *imgGreenStatus = new QPixmap(":/resources/1.0.bmp");

   QLabel *lblGreenStatusGrp2C1 = new QLabel();
   QLabel *lblGreenStatusGrp2C2 = new QLabel();
   QLabel *lblGreenStatusGrp2C3 = new QLabel();

   QPixmap *imgGreenStatusWithTextE1 = new QPixmap(":/resources/1.0.bmp");
   QPixmap *imgGreenStatusWithTextE2 = new QPixmap(":/resources/1.0.bmp");
   QPixmap *imgGreenStatusWithTextE3 = new QPixmap(":/resources/1.0.bmp");
   QPixmap *imgGreenStatusWithTextE4 = new QPixmap(":/resources/1.0.bmp");

    draw = new QPainter(imgGreenStatusWithTextE1);
   draw->setPen( Qt::black );
   draw->drawText( imgGreenStatusWithTextE1->rect(),Qt::AlignCenter,"E1" );

    draw = new QPainter(imgGreenStatusWithTextE2);
   draw->setPen( Qt::black );
   draw->drawText( imgGreenStatusWithTextE2->rect(),Qt::AlignCenter,"E2" );

    draw = new QPainter(imgGreenStatusWithTextE3);
   draw->setPen( Qt::black );
   draw->drawText( imgGreenStatusWithTextE3->rect(),Qt::AlignCenter,"E3" );


   lblGreenStatusGrp2C1->setPixmap(*imgGreenStatusWithTextE1);
   lblGreenStatusGrp2C2->setPixmap(*imgGreenStatusWithTextE2);
   lblGreenStatusGrp2C3->setPixmap(*imgGreenStatusWithTextE3);



   QHBoxLayout *secondStatusLayot =  new QHBoxLayout;
   secondStatusLayot->addWidget( lblGreenStatusGrp2C1);
   secondStatusLayot->addSpacing(5);
   secondStatusLayot->addWidget(lblGreenStatusGrp2C2);
   secondStatusLayot->addSpacing(5);
   secondStatusLayot->addWidget(lblGreenStatusGrp2C3);
   secondStatusLayot->addSpacing(5);
   grp2->setLayout(secondStatusLayot);


   QGroupBox *grp3 =new QGroupBox("Alarm Status");
   QLabel *lblGreenStatusGrp3C1 = new QLabel();
   QLabel *lblGreenStatusGrp3C2 = new QLabel();
   QLabel *lblGreenStatusGrp3C3 = new QLabel();
   QLabel *lblGreenStatusGrp3C4 = new QLabel();
   QLabel *lblGreenStatusGrp3C5 = new QLabel();


   QPixmap *imgGreenStatusWithTextA1 = new QPixmap(":/resources/1.0.bmp");
   QPixmap *imgGreenStatusWithTextA2 = new QPixmap(":/resources/1.0.bmp");
   QPixmap *imgGreenStatusWithTextA3 = new QPixmap(":/resources/1.0.bmp");
   QPixmap *imgGreenStatusWithTextA4 = new QPixmap(":/resources/1.0.bmp");
   QPixmap *imgGreenStatusWithTextA5 = new QPixmap(":/resources/1.0.bmp");

    draw = new QPainter(imgGreenStatusWithTextA1);
   draw->setPen( Qt::black );
   draw->drawText( imgGreenStatusWithTextA1->rect(),Qt::AlignCenter,"A1" );

    draw = new QPainter(imgGreenStatusWithTextA2);
   draw->setPen( Qt::black );
   draw->drawText( imgGreenStatusWithTextA2->rect(),Qt::AlignCenter,"A2" );

    draw = new QPainter(imgGreenStatusWithTextA3);
   draw->setPen( Qt::black );
   draw->drawText( imgGreenStatusWithTextA3->rect(),Qt::AlignCenter,"A3" );

    draw = new QPainter(imgGreenStatusWithTextA4);
   draw->setPen( Qt::black );
   draw->drawText( imgGreenStatusWithTextA4->rect(),Qt::AlignCenter,"A4" );

    draw = new QPainter(imgGreenStatusWithTextA5);
   draw->setPen( Qt::black );
   draw->drawText( imgGreenStatusWithTextA5->rect(),Qt::AlignCenter,"A5" );


   lblGreenStatusGrp3C1->setPixmap(*imgGreenStatusWithTextA1);
   lblGreenStatusGrp3C2->setPixmap(*imgGreenStatusWithTextA2);
   lblGreenStatusGrp3C3->setPixmap(*imgGreenStatusWithTextA3);
   lblGreenStatusGrp3C4->setPixmap(*imgGreenStatusWithTextA4);
   lblGreenStatusGrp3C5->setPixmap(*imgGreenStatusWithTextA5);


   QHBoxLayout *thirdStatusLayot =  new QHBoxLayout;
   thirdStatusLayot->addWidget( lblGreenStatusGrp3C1);
   thirdStatusLayot->addSpacing(5);
   thirdStatusLayot->addWidget(lblGreenStatusGrp3C2);
   thirdStatusLayot->addSpacing(5);
   thirdStatusLayot->addWidget(lblGreenStatusGrp3C3);
   thirdStatusLayot->addSpacing(5);
   thirdStatusLayot->addWidget(lblGreenStatusGrp3C4);
   thirdStatusLayot->addSpacing(5);
   thirdStatusLayot->addWidget(lblGreenStatusGrp3C5);
   thirdStatusLayot->addSpacing(5);
   grp3->setLayout(thirdStatusLayot);


   QGroupBox *grp4 =new QGroupBox("Date/Time");

   lblGrp4Time = new QLabel();
   //lblGrp4Time->setText("26.03.2013 / 16:30:40");
     //lblGrp4Time->setText(dateTimeString);
     dateTimeString = "26.03.2013 / 16:30:40";

   QHBoxLayout *fourthStatusLayot =  new QHBoxLayout;
   fourthStatusLayot->addWidget( lblGrp4Time);
   grp4->setLayout(fourthStatusLayot);


   topLeftLayout->addWidget(grp1);
   topLeftLayout->addSpacing(10);
   topLeftLayout->addWidget(grp2);
   topLeftLayout->addSpacing(10);
   topLeftLayout->addWidget(grp3);
   topLeftLayout->addSpacing(10);
   topLeftLayout->addWidget(grp4);
   topLeftLayout->addSpacing(10);
   setLayout(topLeftLayout);
   //this->setWindowTitle(tr("ARSMS Bushehr."));
   //setWindowTitle(tr("ARSMS Bushehr."));
   setFixedHeight(sizeHint().height());

    /*label = new QLabel(tr("Find &what:"));
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    caseCheckBox = new QCheckBox(tr("Match &case"));
    backwardCheckBox = new QCheckBox(tr("Search &backward"));

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("Close"));

    connect(lineEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(enableFindButton(const QString &)));
    connect(findButton, SIGNAL(clicked()),
            this, SLOT(findClicked()));
    connect(closeButton, SIGNAL(clicked()),
            this, SLOT(close()));

    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();*/

   /* QHBoxLayout *mainLayout = new QHBoxLayout;
    //mainLayout->addLayout(leftLayout);
    //mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());*/
}

void PromengDialog::timeUpdate()
{
    dateTime = QDateTime::currentDateTime();
         dateTimeString = dateTime.toString();
         update();
}

void PromengDialog::paintEvent(QPaintEvent *event)
{
    lblGrp4Time->setText(dateTimeString);
}

/*void FindDialog::findClicked()
{
    QString text = lineEdit->text();
    Qt::CaseSensitivity cs =
            caseCheckBox->isChecked() ? Qt::CaseSensitive
                                      : Qt::CaseInsensitive;
    if (backwardCheckBox->isChecked()) {
        emit findPrevious(text, cs);
    } else {
        emit findNext(text, cs);
    }
}

void FindDialog::enableFindButton(const QString &text)
{
    findButton->setEnabled(!text.isEmpty());
}
*/
