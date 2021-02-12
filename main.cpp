#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qApp->setStyleSheet("QLineEdit { background-color: yellow }");

    w.show();
    return a.exec();
}
