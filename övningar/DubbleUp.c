#include <stdio.h>

int doubleUp (int number){
    return  number * 2;
}

int main(void){
    char text[] = "Hello";
    text[5] = '!';
    printf("%s\n", text);
}