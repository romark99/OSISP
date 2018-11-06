#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include "helper_functions_global.h"
#include <string>

using namespace std;

extern "C" {
HELPER_FUNCTIONSSHARED_EXPORT bool whatBtn(int, int);
HELPER_FUNCTIONSSHARED_EXPORT string numToBaseStr(long long, int);
}

#endif // HELPER_FUNCTIONS_H
