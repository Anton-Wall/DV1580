#include <stdio.h>

enum CHOICES
{
    ADD,
    SUB,
    MUL,
    DIV
};

void func(int choices)
{
    switch (choices)
    {
    case 1:
        printf("You picked addition\n");
        break;
    case 2:
        printf("You picked subtraction\n");
        break;
    case 3:
        printf("You picked multiplication\n");
        break;
    case 4:
        printf("You picked division\n");
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
}

void func2(enum CHOICES choice)
{
    switch (choice)
    {
    case ADD:
        printf("You picked addition\n");
        break;
    case SUB:
        printf("You picked subtraction\n");
        break;
    case MUL:
        printf("You picked multiplication\n");
        break;
    case DIV:
        printf("You picked division\n");
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
}

int main(void)
{
    int choice = 0;

    while (1)
    {
        printf("Enter a choice: ");
        scanf("%d", &choice);
        if (choice == -1)
        {
            printf("Exiting...\n");
            break;
        }
        func(choice);
    }

    return 0;
}