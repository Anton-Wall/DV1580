#include <float.h>
#include <stdio.h>

int main(void)
{
    // float f = FLT_MAX;

    // printf("f = %f\n", f);

    // printf("f * 100000.0f = %f\n", f * 100000.0f); // inf
    // printf("f * 1.000001f = %f\n", f * 1.000001f); // inf

    // printf("f * 10000.0 = %f\n", f * 10000.0); // Perfectly fine, f is promoted to double

    // int si = -2;
    // unsigned short us = 1;

    // printf("si + us = %d\n", si + us); // us is promoted to signed int (because signed int can represent all the values of unsigned short), so this becomes int + int

    // long sl = -2;
    // printf("sl + us = %ld \n", sl + us); // us is promoted to signed long, so this becomes long + long

    unsigned int ui = 1;
    short ss = -5;
    printf("ss + ui = %u\n", ss + ui); // ss is promoted to int, then converted to unsigned int, so we have data loss here.

    if (ss <= ui)
    {
        printf("ss <= ui\n");
    }
    else
    {
        printf("ss > ui\n");
    }

    return 0;
}
