//********************************************************************
//********** Диалоговое окно с логотипом проминженеринга, отображает статусы соответствующих модулей.
//**************************************************************
#ifndef PROMENGDIALOG_H
#define PROMENGDIALOG_H

#include <QDialog>
#include "AllHeaders.h"

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class PromengDialog : public QDialog
{
    Q_OBJECT

public:
    PromengDialog(QWidget *parent = 0);
    void timeUpdate();
//signals:
    //void findNext(const QString &str, Qt::CaseSensitivity cs);
   //void findPrevious(const QString &str, Qt::CaseSensitivity cs);

//private slots:
    //void findClicked();
    //void enableFindButton(const QString &text);

protected:
    void paintEvent(QPaintEvent *event);

private:
    //QLabel *label;
    //QLineEdit *lineEdit;
   // QCheckBox *caseCheckBox;
    //QCheckBox *backwardCheckBox;
    //QPushButton *findButton;
   //QPushButton *closeButton;
    QPixmap *PromengLogo;
    QLabel *PromengLogoWid;
    QDateTime dateTime;
    QString dateTimeString;
    QLabel *lblGrp4Time;

};

#endif
