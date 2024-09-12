#include <stdio.h>
#include <string.h>

int main(void)
{

    printf("What is your age?\n");
    char name[100];
    char lastname[100];

    int age;
    // fgets(name, 6, stdin); // https://en.cppreference.com/w/c/io/fgets
    // fgets(lastname, 6, stdin);
    scanf("%i", &age); // https://en.cppreference.com/w/c/io/fscanf
    // scanf("%s", lastname); // https://en.cppreference.com/w/c/io/fscanf
    printf("Age, %i!\n", age);

    return 0;
}