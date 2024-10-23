#include <stdio.h>
#include <string.h>

int main(){
    printf("vad heter du?\n");
    char name[100];
    char lastname[100];

    int age;

    scanf("%s", name); //tar inte in efter mellanslag. 
    scanf("%s", lastname);

    fgets(name,100,stdin); //kan hantera mellanslag men tar in 100 element av de givna
    fgets(name,5,stdin); // tar in 5 element istället

    scanf("%i",&age)
    
    printf("Hello, %s\n", name, lastname);

    return 0;
}
