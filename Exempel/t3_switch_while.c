#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int a = 4;

    switch (a)
    {
    case 0:
        printf("a is 0\n");
        break;
    case 1:
        printf("a is 1\n");
        break;
    case 2:
        printf("a is 2\n");
        break;
    case 7:
        printf("a is 7\n");
        break;
    case 4:
        printf("a is 4\n");
        break;
    case -123:
        printf("a is -123\n");
        break;
    default:
        printf("a is not 0, 1, 2, 7, or -123\n");
    }

    bool var = false;
    while (var)
    {
        printf("This will never be printed\n");
    }

    // do
    // {
    //     printf("This will be printed once\n");
    // } while (var);

    for (int i = 0; i < 5; ++i)
    {
        printf("i: %d\n", i);
    }

    return 0;
}