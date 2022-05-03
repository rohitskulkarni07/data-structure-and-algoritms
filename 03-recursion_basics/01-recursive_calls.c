#include <stdio.h>
#include <stdlib.h>

void f();

int main (void) {

    f();
}

void f() {
    static int i = 0;
    printf("i = %d\n", ++i);
    f();
}