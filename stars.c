#include <stdio.h>

#include <stdlib.h>




int main(void)  
{


	int x, strL;
    
	char *foo = "hello world";

    
    char array[8][8] = { "this ", "string ", "has ", "too ", "many ", "words ", "in ", "it " };


/*
    
printf("%s%s%s%s\n", array[1], array[6], array[0], array[4]);
    
strL = strlen(array[1])+strlen(array[6])+strlen(array[0])+strlen(array[4]);
    
printf("string length is %d\n", strL);


    
printf("%s%s%s%s\n", array[3], array[7], array[6], array[0]);
    
strL = strlen(array[3])+strlen(array[7])+strlen(array[6])+strlen(array[0]);
    
printf("string length is %d\n", strL);

*/
    
strL = (printf("%s%s%s%s\n", array[3], array[7], array[6], array[0])-1);
    
printf("string length is %d\n", strL);

}
