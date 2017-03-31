#include <QApplication>
#include "mainwindow.h"
#include "PromengDialog.h"
#include "dbconn.h"
#include "db_VisualParam.h"

//class shared_ptr * myptr1;

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);

    QApplication a(argc, argv);
    QApplication::setStyle(new QPlastiqueStyle);
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    QTextCodec::setCodecForTr(codec);

    //qRegisterMetaType<Signal>("Signal");
    //qRegisterMetaType<QVector<Signal> >("QVector<Signal>");
    qRegisterMetaType<vec_signal>("vec_signal");

    MainWindow w;
    //PromengDialog* promengDialogWidget = new PromengDialog;
    //promengDialogWidget->show();

    w.show();
    
    return a.exec();
}
