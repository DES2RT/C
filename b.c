#include <stdio.h>
#include <stdlib.h>

#define ISBN 100
#define PRICE 100
#define QUANT 100

int display(int isbn[], double price[], int quantity[], int i);

main(void)
{
    int i, a, end, isbn[ISBN], quantity[QUANT];
    double price[PRICE];


    printf("\nBook Store Inventory\n");
    printf("=======================\n");

        for(i=0; i<ISBN; i++)
        {
                printf("ISBN number (0 to quit) : ");
                scanf("%d", &isbn[i]);
                if (isbn[i] == 0)
                    end = display(isbn, price, quantity, i);
                if (end == 0)
                    return 0;
            do
            {
                printf("Price of item           : $ ");
                scanf("%lf", &price[i]);
                if (price[i] < 0)
                    printf("Price cannot be less than zero. Please enter a valid price  \n");

            } while (price[i] < 0);

            do
            {
                printf("Quantity in stock       : ");
                scanf("%d", &quantity[i]);
                if (quantity[i] < 0)
                    printf("Quantity cannot be less than zero. Please try again \n");
                
            } while (quantity[i] < 0);
    
         }
        
}

int display(int b[], double p[], int q[], int i)
{
   int x;
    double total=0, value[i];
    
   printf("\n%25s\n", "Goods In Stock");
   printf("%25s\n\n", "==============");
   printf("%-10s %10s %10s %10s\n", "ISBN", "Price", "Quantity", "Value");
   printf("---------------------------------------------\n");

    for (x=0; x<i; x++)
    {
        value[x] = (p[x]*q[x]);
        printf("%-10d %10.2lf %10d %10.2lf\n", b[x], p[x], q[x], value[x]);
    }
    
    printf("%45s\n", "--------\n");
    printf("Total value of books in stock");
    for (x=0; x<i; x++)
    {
        total += value[x];
    }
    
    printf("%15.2lf\n\n", total);  
    
    return 0;
}
