#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int num, i, a=1, b=6, n, m;

    printf("\n\nDice Game \n");
    printf("==========\n");

    do
    {
        printf("Please enter the total sought: ");
        scanf("%d", &num);
        if (num<2 || num>12)
            printf("Invalid input. Please try again. \n");
    } while (num < 2 || num > 12);

    for (i=0; ; i++)
    {
//        srand(time(NULL));
        n = a + rand() % (b+1-a);
        m = a + rand() % (b+1-a);
        printf("Result of throw %d : %d + %d\n", i+1, m, n);
    
        if (m+n == num)
        {   
            printf("You got your total in %d throws!\n", i+1);
            return 0;
        }
    }
}
