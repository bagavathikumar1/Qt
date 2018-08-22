#include <QApplication>
#include <QPointer>
#include <QDebug>
#include "logbrowser.h"

QPointer<LogBrowser> logBrowser;

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
void myMessageOutput(QtMsgType type, const QMessageLogContext &, const QString & str)
{
    const char * msg = str.toStdString().c_str();
#else
void myMessageOutput(QtMsgType type, const char *msg)
{
#endif
    if(logBrowser)
        logBrowser->outputMessage( type, msg );
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    logBrowser = new LogBrowser;
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    qInstallMessageHandler(myMessageOutput);
#else
    qInstallMsgHandler(myMessageOutput);
#endif

    qDebug() << "test for debug";
    int result = a.exec();
    qDebug() << "application exec return result =" << result;

    delete logBrowser;
    return result;
}
