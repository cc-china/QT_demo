#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QMutex>

#include "util.h"

static void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    (void)context;
    static QMutex mutex;
    QString tagText;
    QString contextInfo;

    mutex.lock();
    switch (type) {
    case QtDebugMsg:
        tagText = QString("D:");
        break;
    case QtWarningMsg:
        tagText = QString("W:");
        break;
    case QtInfoMsg:
        tagText = QString("I:");
        break;
    case QtCriticalMsg:
        tagText = QString("C:");
        contextInfo = QString(" File:(%1) Line:(%2)").arg(QString(__FILE__)).arg(__LINE__);
        break;
    case QtFatalMsg:
        tagText = QString("F:");
        contextInfo = QString(" File:(%1) Line:(%2)").arg(QString(__FILE__)).arg(__LINE__);
        //abort();
    default:
        break;
    }

    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString currentDate = QString("%1").arg(current_date_time);
    QString message = QString("%1 %2 %3 %4").arg(currentDate).arg(tagText).arg(msg).arg(contextInfo);

    QFile file("log.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream textStream(&file);

    textStream << message << "\r\n";
    file.flush();
    file.close();

    mutex.unlock();
}
void hlog_init()
{
    qInstallMessageHandler(outputMessage);
}
