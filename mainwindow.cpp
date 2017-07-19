#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QTableWidget>
#include<QDebug>
#include<QFile>
#include<QStringList>
#include<QtCharts/QChartView>
#include<QtCharts/QLineSeries>
QT_CHARTS_USE_NAMESPACE
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    tableWidget = new QTableWidget(this);
    ui->tablelayout->addWidget(tableWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_File_triggered()
{
    filename=QFileDialog::getOpenFileName(this, tr("Open File"),"/home",tr("Data Files(*.txt)"));
    ui->lineEdit->setText(filename);
    showdata();

}

void MainWindow::showdata()
{
    ui->status->setText("SHOW DATA");
    getdata();
    tableWidget->setRowCount(rows);
    tableWidget->setColumnCount(columns);
   // qDebug()<<rows<<" "<<columns;
  for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++)
        {
            Status="";
            Status=Status+"["+i+","+j+"]"+data[i].at(j);
          //  qDebug()<<Status;
            ui->status->setText(Status);
             QTableWidgetItem *newItem = new QTableWidgetItem(data[i].at(j));
            tableWidget->setItem(i,j,newItem);
        }
    }
     ui->status->setText("DATA COLLECTED");
}

void MainWindow::getdata()
{
    QString qseparator;
    qseparator=ui->separators->text();
    qseparator.remove(0,1);
    qseparator.remove(qseparator.length()-1,1);
    qseparator.remove(" ");
    separators = qseparator.split("','",QString::SkipEmptyParts);
    ui->status->setText("GET DATA");
    gettabledimens();
    data = new QStringList [rows];
    tableWidget->setRowCount(rows);
    tableWidget->setColumnCount(columns);
    QFile file(filename);
    int rownumber=0;
    if(!file.open(QIODevice::ReadOnly)|QIODevice::Text);
    QTextStream in(&file);
    while(!in.atEnd()){
        QString line = in.readLine();
        line.replace(QString("\t"),QString(" "));
        for(int k=0;k<separators.size();k++)
              line.replace(separators.at(k),QString(" "));
        data[rownumber]=line.split(" ",QString::SkipEmptyParts);
        rownumber++;
    }
    file.close();
}

void MainWindow::gettabledimens()
{
    rows=0;
    columns=0;
    ui->status->setText("GET DATA DIMENSIONS");
    QStringList temp;
    QFile file2(filename);
    if(!file2.open(QIODevice::ReadOnly)|QIODevice::Text);
    QTextStream in(&file2);
    while(!in.atEnd()){
        QString line = in.readLine();
        if(rows==0)
        {
             line.replace(QString("\t"),QString(" "));
            temp =line.split(" ",QString::SkipEmptyParts);
         }
        rows++;
        }
    file2.close();
    columns=temp.size();
    Status="";
    Status=Status+"Rows: "+rows+" Columns: "+columns;
    ui->status->setText(Status);
}

void MainWindow::on_pushButton_2_clicked()
{
    data=NULL;
    showdata();
    ui->status->setText("REFRESH DONE");
}

void MainWindow::showplot()
{
    QLineSeries *series[columns-1];
    for(int j=1;j<columns;j++)
        series[j]= new QLineSeries();
    for(int i=1;i<rows;i++)
    {
        QTableWidgetItem *ItemX;
        ItemX=tableWidget->item(i,0);
        for(int j=1;j<columns;j++)
        {
            QTableWidgetItem *ItemY;
            ItemY=tableWidget->item(i,j);
            //qDebug()<<i<<" "<<j<<" :"<<ItemX->text().toFloat()<<" "<<ItemY->text().toFloat();
            series[j]->append(ItemX->text().toFloat(),ItemY->text().toFloat());
        }
    }
    QChart *chart = new QChart();
    chart->legend()->hide();
    for(int j=1;j<columns;j++)
        chart->addSeries(series[j]);

    chart->createDefaultAxes();
    QString vsplot;
    vsplot=data[0].at(0)+" vs ";
    for(int j=1;j<columns;j++)
        vsplot+=" and "+data[0].at(j);
    chart->setTitle("Graph "+vsplot);
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->plotlayout->addWidget(chartView);

}

void MainWindow::on_pushButton_clicked()
{
    showplot();
    ui->status->setText("DATA PLOTTED");
}

void MainWindow::on_actionSave_Image_triggered()
{
    QString imagePath = QFileDialog::getSaveFileName(this,tr("Save File"),"/home",tr("PNG (*png)"));
    if(!imagePath.endsWith(".png",Qt::CaseInsensitive))
        imagePath+=".png";
    chartView->grab().save(imagePath);

}
