#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QIcon icon("/home/enco/Plot/PlotterIcon.ico");
    w.setWindowTitle("Plotter");
    w.setWindowIcon(icon);
    return a.exec();
}
