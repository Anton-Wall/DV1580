#include <stdio.h>

int main(void)
{
    int var = 5;

    // if (var == 5)
    if (++var == 5) // post-increment
    // if (++var == 5) // pre-increment
    {
        printf("var is 5\n");
    }
    else
    {
        printf("var is not 5\n");
    }

    printf("var after if branch: %d\n", var);
    return 0;
}