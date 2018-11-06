#ifndef HELPER_FUNCTIONS_GLOBAL_H
#define HELPER_FUNCTIONS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HELPER_FUNCTIONS_LIBRARY)
#  define HELPER_FUNCTIONSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define HELPER_FUNCTIONSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // HELPER_FUNCTIONS_GLOBAL_H
