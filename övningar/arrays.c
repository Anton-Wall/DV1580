#include <stdio.h>

void a1(){
    int arr[10];
    int i;
    for (i = 0; i < 10; i++) {
        printf("Number %i", i+1);
        scanf("%i", &arr[i]);
    };

    for (i = 0; i < 10; i++) {
    printf("%i", arr[i]);
    };
};

void a2(){
    int len;
    int i;
    printf("Input len");
    scanf("%i", &len);
    for (i = 0; i < len; i++){
        printf("Number %i", i+1);
        scanf("%i", & arr[i]);
    };

    for (i = len -1 ; i >= 0; i--) {
    printf("%i", arr[-i]);
    };
};

void a3(){

}

void main(){
    a1();
    return 0;
};