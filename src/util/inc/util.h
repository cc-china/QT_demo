#ifndef UTIL_H
#define UTIL_H

#include <QDebug>
#include "util_global.h"

#define hlogd  qDebug
#define hlogi  qInfo
#define hlogw  qWarning
#define hlogc  qCritical
#define hlogf  qFatal

UTIL_EXPORT void hlog_init();

class UTIL_EXPORT Util
{
public:
    Util();
};

#endif // UTIL_H
