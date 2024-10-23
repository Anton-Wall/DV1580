#include <stdio.h>

void a1(){
    int i;
    for (i = 1;i < 10; i++) {
        printf("%i",i);
    };
};

void a2(){
    int i;
    int sum;
    for (i = 1;i <10; i++) {
        sum = sum +1;
    };
    printf("%i",sum);
};

void a3(){
    int j;
    int i;
    printf("Type a number: \n");
    scanf("%i",&j);
    int sum;
    for (i = 0;i = j; i++) {
        sum = sum +1;
    };
    printf("%i",sum);
};

void a4(){
    int sum = 0;
    int i;
    int temp;
    for (i = 0; i <10; i++){
        printf("Number %i", i+1);
        scanf("%i", &temp);
        sum = sum + temp;
    };
    printf("%i",sum);
};

void main(){
    a1();
    a2();
    a3();
    return 0;
};