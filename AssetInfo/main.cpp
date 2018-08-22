#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug("Hi Asset Info Test");
    Widget w;
    w.show();

    return a.exec();
}
