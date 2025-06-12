#ifndef TASK4LIB_GLOBAL_H
#define TASK4LIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TASK4LIB_LIBRARY)
#define TASK4LIB_EXPORT Q_DECL_EXPORT
#else
#define TASK4LIB_EXPORT Q_DECL_IMPORT
#endif

#endif // TASK4LIB_GLOBAL_H
