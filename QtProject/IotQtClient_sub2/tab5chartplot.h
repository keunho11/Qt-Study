#ifndef TAB5CHARTPLOT_H
#define TAB5CHARTPLOT_H

#include <QWidget>
#include <QChartView>
#include <QSplineSeries>
#include <QDateTimeAxis> // 시간을 축으로 이용하기 위한 라이브러리
#include <QDateTime>
#include <QDate>
#include <QTime>
#include <QDebug>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>


QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Tab5ChartPlot;
}

class Tab5ChartPlot : public QWidget
{
    Q_OBJECT

public:
    explicit Tab5ChartPlot(QWidget *parent = nullptr);
    ~Tab5ChartPlot();

private:
    Ui::Tab5ChartPlot *ui;
    QLineSeries* pIlluLine;
    QLineSeries* pTempLine;
    QLineSeries* pHumiLine;


    QChart* chart;

    QChartView *chartView;
    QDateTimeAxis *axisX;
    QDateTime firstDate;
    QDateTime lastDate;

private slots:
    void chartPlotClear();
    void chartPlotAdd();
    void slotTab5RecvData(QString);
};

#endif // TAB5CHARTPLOT_H
