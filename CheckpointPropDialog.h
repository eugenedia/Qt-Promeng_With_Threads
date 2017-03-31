#ifndef CHECKPOINTPROPDIALOG_H
#define CHECKPOINTPROPDIALOG_H

#include <QDialog>
#include <qwt_plot_zoomer.h>

#include "AllHeaders.h"
#include "plot.h"

class CheckpointProperties;
class CheckpointMessages;
class QwtPlotCurve;
class Plot;
class db_Signal;
class ModelArchivSignal;
class DelegatArchivSignal;
//class std::unique_ptr;

class Zoomer;

class CheckpointPropDialog : public QDialog
{
    Q_OBJECT
public:
    explicit CheckpointPropDialog(int SelectedGuidSignal,int SelectedF_X, int SelectedF_Y,DBConn db, QWidget *parent = 0);
    ~CheckpointPropDialog();

signals:
    
public slots:

   // void paintEvent(QPaintEvent *event);
    void manualUpdateData();
    void r30Min_toogled(bool checked);
    void r1h_toogled(bool checked);
    void r8h_toogled(bool checked);
    void r24h_toogled(bool checked);
    void rManual_toogled(bool checked);

protected:
    bool fillDialogTab();
    bool fillChartTab();
    void fillGraphicAndArchives();
    void fillArchives();
    void getArchivedData(QDateTime dataTime1, QDateTime dataTime2, int SelectedGuidSignal);
    void recalculateGraphic(uint numberOfSeconds); // передаем число секунд, которое вычитаем из текущего времени, формируя диапазон для построения графика.
private:
   int SelectedGuidSignal;
   DBConn db;
   QVector<CheckpointProperties> vecCheckpointProperties;
    QVector<CheckpointMessages> vecCheckpointMessages;

    QTabWidget *mainTab, *childTab;
    QWidget *wDialog,*wGraphArch,*wGraph,*wArch;
     int SelectedF_X, SelectedF_Y;
    QVector<Signal> vSig;
    QDateEdit *dataBegin, *dataEnd;
    QTimeEdit *timeBegin, *timeEnd;

    QwtPlotCurve *curve;
    Plot *plot;
     QPolygonF *points;
    // std::unique_ptr<int>pQPolygon;
     //std::unique_ptr<QPolygonF> p1;
    // QwtPlotZoomer *d_zoomer;
    Zoomer *d_zoomer;

    QRadioButton *r30Min;
    QRadioButton *r1h;
    QRadioButton *r8h;
    QRadioButton *r24h;
    QRadioButton *rManual;
    db_Signal * db_signal;

    ModelArchivSignal *modelSignal;
    QTableView *tableView;
    DelegatArchivSignal * delArchSig;

    double F_THRESHOLD_1;
    double F_THRESHOLD_2;


};

#endif // CHECKPOINTPROPDIALOG_H
