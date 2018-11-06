#include "helper_functions.h"

bool whatBtn(int fromBase, int n) {
    return fromBase >= n;
}

string numToBaseStr(long long n, int base) {
    const string chars = "0123456789ABCDEF";
    string str = "";
    if (n == 0)
        return "0";
    while (n > 0) {
        int digit = n % base;
        str = chars[digit] + str;
        n /= base;
    }
    return str;
}
