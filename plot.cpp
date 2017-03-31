#include "plot.h"

/*class Zoomer: public QwtPlotZoomer
{
public:
    Zoomer( QWidget *canvas ):
        QwtPlotZoomer( canvas )
    {
        setRubberBandPen( QColor( Qt::darkGreen ) );
        setTrackerMode( QwtPlotPicker::AlwaysOn );
        setZoomBase();
    }

protected:
    virtual QwtText trackerTextF( const QPointF &pos ) const
    {
        const QDateTime dt = QwtDate::toDateTime( pos.x() );

        QString s;
        s += QwtDate::toString( QwtDate::toDateTime( pos.x() ),
            "MMM dd hh:mm ", QwtDate::FirstThursday );

        QwtText text( s );
        text.setColor( Qt::white );

        QColor c = rubberBandPen().color();
        text.setBorderPen( QPen( c ) );
        text.setBorderRadius( 6 );
        c.setAlpha( 170 );
        text.setBackgroundBrush( c );

        return text;
    }
};



class DateScaleDraw: public QwtDateScaleDraw
{
public:
    DateScaleDraw( Qt::TimeSpec timeSpec ):
        QwtDateScaleDraw( timeSpec )
    {
        // as we have dates from 2010 only we use
        // format strings without the year

        setDateFormat( QwtDate::Millisecond, "hh:mm:ss:zzz\nddd dd MMM" );
        setDateFormat( QwtDate::Second, "hh:mm:ss\nddd dd MMM" );
        setDateFormat( QwtDate::Minute, "hh:mm\nddd dd MMM" );
        setDateFormat( QwtDate::Hour, "hh:mm\nddd dd MMM" );
        setDateFormat( QwtDate::Day, "ddd dd MMM" );
        setDateFormat( QwtDate::Week, "Www" );
        setDateFormat( QwtDate::Month, "MMM" );
    }
};*/


Plot::Plot( QWidget *parent ):
    QwtPlot( parent )
{
    setTitle( "Checkpoint properties" );

    scaleDraw = new DateScaleDraw( Qt::UTC );
    scaleEngine = new QwtDateScaleEngine( Qt::UTC );

    setAxisTitle( QwtPlot::xBottom, QString( "Time" ) );
    setAxisScaleDraw( QwtPlot::xBottom, scaleDraw );
    setAxisScaleEngine( QwtPlot::xBottom, scaleEngine );
    setAxisLabelRotation( QwtPlot::xBottom, -50.0 );
    setAxisLabelAlignment( QwtPlot::xBottom, Qt::AlignLeft | Qt::AlignBottom );
    //setAxisAutoScale(QwtPlot::xBottom,true);

    setAxisTitle( QwtPlot::yLeft, QString( "Value" ) );

/*#if 0
    QwtLegend *legend = new QwtLegend;
    legend->setDefaultItemMode( QwtLegendData::Checkable );
    insertLegend( legend, QwtPlot::RightLegend );
#else
    Legend *legend = new Legend;
    insertLegend( legend, QwtPlot::RightLegend );
#endif*/

 //   populate();

    // LeftButton for the zooming
    // MidButton for the panning
    // RightButton: zoom out by 1
    // Ctrl+RighButton: zoom out to full size

   // Zoomer* zoomer = new Zoomer( canvas() );
   // zoomer->setMousePattern( QwtEventPattern::MouseSelect2,
   //     Qt::RightButton, Qt::ControlModifier );
   // zoomer->setMousePattern( QwtEventPattern::MouseSelect3,
     //   Qt::RightButton );

    panner = new QwtPlotPanner( canvas() );
    panner->setMouseButton( Qt::MidButton );

  //  connect( legend, SIGNAL( checked( QwtPlotItem *, bool, int ) ),
    //     SLOT( showItem( QwtPlotItem *, bool ) ) );
}

Plot::~Plot()
{
   // delete scaleEngine;
    delete panner;
    //delete scaleEngine;
   // delete scaleDraw;
   //
   //
}




Zoomer::~Zoomer()
{

}
