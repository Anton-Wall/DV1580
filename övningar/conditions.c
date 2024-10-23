#include <stdio.h>

/*1 Write a C program to accept two integers and check whether they are equal or not.
Test Data : 15 15*/

void a1() {
    printf("Type a number: \n");
    int data1;
    scanf("%d", &data1);
    printf("Type a number: \n");
    int data2;
    scanf("%d", &data2);

    if (data1 == data2) {
        printf("True");
    }
    else {
        printf("False");
    }
};

void a2(){
    printf("Type a number: \n");
    int data1;
    scanf("%d", &data1);

    if  (data1 % 2 == 1) {
        printf("odd");
}  else  {
        printf("Even");
    };
};

void a3(){
    printf("Type a number: \n");
    int data1;
    scanf("%d", &data1);
    if (data1 > 0) {
        printf("Positive");
} else {
    printf("Negative");
    };
};

void a4(){
    printf("Type a year: \n");
    int data1;
    scanf("%d")
    if (data1 %4 == 0) {
        printf("Leap year");
    } else{
        printf("no")
    }
};

void main(){
    a1();
    a2();

    return 0;
};