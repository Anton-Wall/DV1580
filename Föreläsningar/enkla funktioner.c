#include <stdio.h>

void main()
{
    int tal1 = 1;
    if (var++ == 5)
    {
    printf("Tal 1 är mindre än 5");
    }
    else
    {
        printf("Tal1 är större än 5")
    }

    int a = 4;
//#####################################################
    switch (a)
    {
    case 7:
        break;
    
    case 5:
        printf("gog")
    default:
        printf("innget av ovanstående stämmer")
        break;
    }
//########################################################
    bool var = false
    while(var)
    {
        printf("kommer ite bli utskrivet")
    }
    do
    {
        printf("Detta kommer göras tills var är klart")
    } while (var);
//#####################################################
    for(int i=0; i<5; ++i) //när i är mindre än 5 öka i
    {
        printf("gog");
    };

    return 0;
}

int arry[10]; //array med 10 platser och inget innehåll
int arry2[10] = {1,2}; //samma som ovan men de två första är 1,2
int other[] = {1,2}; //ingen spesific storlek men elementen 1,2 är i den.
int gog[] = {[1] = 2, [2]= 14}; //dessa två positioner är nu deffinierade. 