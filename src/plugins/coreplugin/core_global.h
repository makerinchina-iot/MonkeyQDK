#ifndef CORE_GLOBAL_H
#define CORE_GLOBAL_H

#include <qglobal.h>

#if defined(CORE_LIBRARY)
#  define CORE_EXPORT Q_DECL_EXPORT
#else
#  define CORE_EXPORT Q_DECL_IMPORT

#endif // CORE_GLOBAL_H
