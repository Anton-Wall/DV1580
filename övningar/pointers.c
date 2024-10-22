#include <stdio.h>

int m = 10;
int *x = &m;

void main() {
    printf("Value of m: %i\n", m);
    printf("Address of m (using pointer): %p\n", x);
    printf("Value at address stored in x: %i\n", *x);
    printf("Address of m (using &m): %p\n", &m);
    return 0;
}