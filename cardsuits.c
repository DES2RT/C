#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear(void);
void cardDraw(int num, char suit, char *suits[10]);

int main(void)
{
    int num;;
    char suit, after, suits[10];
    
    printf("\n\nCard Draw \n");
    printf("==========\n");

    do
    {
        printf("Enter suit: ");
        scanf("%c%c", &suit, &after);
    
        switch (suit)
    {
        case 'S': 
            suits = 'Spades';
            printf("suit is %s\n", suits);
            break;
        case 'H':
            suits = "Hearts";
            break;
        case 'C':
            suits = "Clubs";
            break;
        case 'D':
            suits = "Diamonds";
            break;
        default:
            suits = "Unknown Suit";
    }
        if (after != '\n')
            printf("%c, %c\n", suit, after);

            if (suit != 'S' && suit != 'H' && suit != 'C' && suit != 'D') 
                printf("Invalid input. Please try again \n");

    } while (suit != 'S' && suit != 'H' && suit != 'C' && suit != 'D');

    do
    {
        printf("Enter card number ");
        scanf("%d", &num);
    
            if (num < 1 || num > 13)
                printf("Out of range of card numbers. Please try again. \n");

    } while (num < 1 || num > 13);
   
    
    cardDraw(num, suit, &suits);

    return 0;
}

void cardDraw(int num, char suit, char *suits[10])
{
    int i, m, n, a=1, b=13, x;
    printf("Your card is the %d of %c\n", num, suits);
            

    for (i=0; i<10; i++)
    {
//        srand(time(NULL));
        m = a + rand() % (b+1-a);
 //       n = a + rand() % (b+1-a);
        printf("Result of draw %d : %d\n", i+1, m);
        
        if (m+n == num+suit)
            printf("You got your card in %d draws!\n", i+1);
    }
}
