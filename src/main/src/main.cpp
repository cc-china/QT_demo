#include "mainwindow.h"
#include <QApplication>
#include "util.h"

int main(int argc, char *argv[])
{
//    hlog_init();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
