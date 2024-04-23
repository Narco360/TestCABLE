//debut main.cpp
#include "testcable.h"
#include <QApplication>
#include <QDebug>
#include <QCoreApplication>
#include <QtSql>


//#include <iostream> using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestCable w;
    w.show();

    qDebug() << QDir::currentPath()<<QCoreApplication::applicationDirPath();

    return a.exec();
}
