#include <stdio.h>
int main(void)
{
    int choice, i; 
    double price;

    for (i = 1; i <= 5; i++)
    {
        printf("[1] Select crisps \n");
        printf("[2] Select popcorn \n");
        printf("[3] Select chocolate \n");
        printf("[4]Select cola \n");
        printf("[0] exit \n");

        printf("Enter choice:");
        scanf("%d", &choice);

        if (choice == 0)
            break;

        switch (choice)
        {
        case 1:
            price = 3.0;
            break;
        case 2:
            price = 2.5;
            break;
        case 3:
            price = 4.0;
            break;
        case 4:
            price = 3.5;
            break;

        default:
            price = 0.0;
            break;
        }
        printf("price=%0.1f\n", price);
    }
    printf("Thanks！ \n");

    return 0;
}