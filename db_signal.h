#ifndef DB_SIGNAL_H
#define DB_SIGNAL_H
#include <QtGui>
#include <QtSql>
#include <QObject>
#include "AllHeaders.h"
#include "vec_signal.h"

class vec_signal;

class db_Signal : public QThread
{
    Q_OBJECT
public:
    //db_Signal(QSqlDatabase db);
    db_Signal();

    void run();
    void stop();
    ~db_Signal();

signals:
    //void writeToDialog(QVector<Signal> );
        void writeToDialog(vec_signal vSignal);


public slots:

   // bool createConnection();
    QVector<Signal> loadTableSignal(QString dataTime1, QString dataTime2);

    QVector<Signal> loadArchiveTableSignal(QDateTime dataTime1, QDateTime dataTime2, int SelectedGuidSignal, QSqlDatabase sq);
private:

    QVector<Signal> vecSignal;
    QSqlDatabase db;

    bool loadDatabase();

    bool m_stop;


    QDateTime qdt,oldQdt;

    QString timeBegin, timeEnd;

    QString DateTimeToString(QDateTime qt);
    QDateTime DateTimeFromString(QString str1);

    vec_signal *vec_Signal;

    QHash<int, Signal> hash_sig;
};

#endif // DB_SIGNAL_H
