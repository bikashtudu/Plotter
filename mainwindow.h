#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include<QChartView>
#include <QLineSeries>
namespace Ui {
class MainWindow;
}
QT_CHARTS_USE_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_File_triggered();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_actionSave_Image_triggered();

private:
    Ui::MainWindow *ui;
    QString filename;
    void plot();
    void showdata();
    void getdata();
    void gettabledimens();
    QTableWidget *tableWidget;
    int rows;
    int columns;
    QStringList *data;
    QString Status;
    QStringList separators;
    void showplot();
    QChartView *chartView;
};

#endif // MAINWINDOW_H
