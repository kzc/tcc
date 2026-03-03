#include "lib.h"
#include <stdio.h>
int main() {
    int ok = func_one() == 1
        && func_to() == 2
        && func_three() == 3
        && func_four() == 4;
    printf("%s %s %s\n", NAME("main"), lib_name(), ok ? "OK" : "FAIL");
    return ok ? 0 : 1;
}
