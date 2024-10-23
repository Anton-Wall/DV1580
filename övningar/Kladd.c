#include <stdio.h>
#include <stdlib.h>
char text[] = "Hello";
text[5] = '!';
void main(int argc, char *argv[]){

    printf("%s\n", text);
};