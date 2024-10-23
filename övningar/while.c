#include <stdio.h>

void a1(){
    int i = 0;
    while (i < 10)
    {
        printf("%i", i);
        i++;
    };
};

void a2(){
    int i;
    int temp;
    while (temp != 0)
    {
        scanf("%i",temp);
        i = i + temp;
    };
    printf("%i", i);
};

void a3(){
    int i = 1;
    int sum = 1;
    while (i<5)
    {
        sum = sum*i;
        i++1;
    };
    printf("%i", sum);
};

void a4(){
    int nums[];
    int i = 0;
    int in;
    bool runing = true;
    while(runing) {
        scanf("%i", in);
        i++;
        while (i != in)
        {
            if  (nums[i] == in){
                runing = false;
            };
        };
        nums[i] = in;
        
    };
};

void main(){
    a1();
    return 0;
}