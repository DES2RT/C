

// THIS PROGRAM CONVERTS A RANGE OF NUMBERS FROM INTEGERS TO THE CHINESE EQUIVALENT
// IN PINYIN. THE MAIN FUNCTION WILL PROMPT THE USER FOR THE START OF THE RANGE AND
// THE END OF THE RANGE. IT PASSES THOSE NUMBERS AS PARAMETERS TO A FUNCTION
// (getRANGE) THATI DETERMINES ALL THE NUMBERS IN THE RANGE. THAT FUNCTION (getRANGE)
// THEN CALLS A FUNCTION TO PRINT THE TOP PART OF THE TABLE. THE SAME FUNCTION (getRANGE) 
// CALLS ANOTHER FUNCTION PASSING THE NUMBERS IN THE RANGE AS INTEGERS ALONG WITH THE ADDRESSES 
// OF THE VARIOUS CHINESE COUNTING COLUMNS(TEN THOUSANDS, THOUSAND, HUNDREDS, TENS AND ONES) TO 
// ANOTHER FUNCTION THAT WILL DETERMINE THE VALUES IN EACH OF THOSE COLUMNS. THE SAME FUNCTION (getRANGE)
// CALL ANOTHER FUNCTION THAT WILL TRANSLATE THE NUMBERS INTO THE PINYIN EQUIVALENT.
// FINALLY THE NUMBERS AND THE PINYIN EQUIVALENT ARE PRINTED INTO THE TABLE. THE
// PROGRAM REPEATS UNTIL THE USER ENTER 'N'.

#include <stdio.h>
#include <stdlib.h>

// TWO DEFINES THAT DETERMINE THE MIN AND MAX NUMBERS ALLOWED FOR INPUT
#define MIN 0
#define MAX 100000000

//FUNCTION HEADERS
void clear(void);					
int getNum(int min, int max, int num1);         	            // receives the numbers from user and validates input
int lnum(int min, int max, int num1, int num2);                 // function holds logic to make sure num2 is not 
                                                                // less than num1
void getRange(int num1 , int num2);				                // determines the range of numbers from numbers input
                                                                // from user
void getCounts(int num, int *, int *, int *, int *, int *);		// determines the values in each column of
                                                                // numbers (chinese counting)
void getPinyin(int *, int *, int *, int *, int *);			    // gets the pinyin for the numbers in the range
void printTableHead(void);                                      // prints the top of the table
char again(void);                                               // determines if user wants to do another translation

// GLOBAL VARIABLES
int tenThous, thous, hundreds, tens, ones;				    // holds the values for the numbers in the specific
                                                            // column (chinese counting)
// array for pinyin(chinese) numbers 1 to 9
char onesArray[9][6] = { "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };	
// array for columsn (tens, hundreds, thousands, ten thousands)
char colsArray[4][6] = { "shi", "bai", "qian", "wan" };		

/************************  START OF PROGRAM   ***************************/

int main(void)
{
	int num1=0, num2=0, goodscan;
    char more;

    do
    {
        do							            // this loop prompts the user and calls getNum function to determine 
        {								        // valid input and loops until input is valid
            printf("\nPlease enter the first number in the range: "); 
            num1 = getNum(MIN, MAX, num1);
        } while (!num1);
        
        do								        // this loop does the same as the previous loop
        {								
            printf("Please enter the second number in the range: "); 
            num2 = getNum(MIN, MAX, num1);
            if (num2 < num1)                    // to determine if the second number input is less than the first
            {
                num2 = 0;
                num2 = lnum(MIN, MAX, num1, num2);
            }

        } while (!num2);

        getRange(num1, num2);					// calls function to get all the numbers in the range of numbers
                                                // between two numbers that were input from user
        
        do                                      // loop to ask the user for more translations
        {                           
            printf("\nDo you want to do another translation? (Y/N): ");
            more = again(); 
        } while (!more);
   
        if (more == 'N' || more == 'n')
            return 0;

    } while (more == 'Y' || more == 'y'); 

}   // end of main function
/*****************************************************************************************/

// CLEAR FUNCTION
// this function clears the input from the buffer for proper input

void clear(void)
{
    while (getchar() != '\n')
    ;
}   // end of clear function
/****************************************************************************************/

// GET NUM FUNCTION
// this function receives the number input from user as a parameter. also receives two defined variable for 
// min and max. it determines if the input from the user is valid and if it isnt returns a zero to main and the 
// user is prompted again for the number

int getNum(int min, int max, int num)
{
        int value, goodscan;
        char c;

        goodscan = scanf("%d%c", &value, &c);           // determines proper input
        if (goodscan == 0 || c != '\n')                 // logic to be performed if input is not valid
        {
            printf("\nBad input. Please try again\n");
            clear();
            return 0;
        }
        else if (value <= min || value >= max)
        {
            printf("\nOut of range (1-100000000). Please try again\n");
            //clear();
            return 0;
        }
        else
            return value;

}   // end of getNum function
/********************************************************************************************/

// LNUM FUNCTION
// this function is called if the second number of the range, entered by the user,
// is smaller than the first

int lnum(int min, int max, int num1, int num2)
{
    int value, goodscan;
    char c;

    do
    {
        printf("\nSecond number in range cannot be smaller than the first. ");
        printf("Please try again\n\n");
        printf("Please enter the second number in the range: ");
        goodscan =  scanf("%d%c", &value, &c);
        if (goodscan == 0 || c != '\n')                 // logic to be performed if input is not valid
        {
            printf("\nBad input. Please try again\n");
            clear();
        }
        else if (value <= min || value >= max)
        {
            printf("\nOut of range (1-100000000). Please try again\n\n");
            //clear();
        }
        else if (value >= num1)
            return value;

    } while (value < num1);


}   // end of lnum function
/********************************************************************************************/

// GET RANGE FUNCTION
// this function receives the two numbers input from the user as parameters and determines the number of numbers
// in the range (the size of the array) it then assigns the numbers in the range to an array called range[] .. 
// it calls the function printHead which prints the top of the table .. 
// it uses a for loop to call the getCounts function to get all the values stored in the columns of each number in
// the range array and prints those numbers in the table. finally, within the same for loop, it calls the getPinyin
// function to translate the numbers in the range to pinyin and print those string into the table

void getRange(int num1, int num2)
{
	int a, n=0, x=0;

        for (a=num1; a<num2; a++)				// loop determines the number of numbers in the range and then assigns
        {							            // that number to be the size of the range array ( range[n] )
            n++;
        }
        
        int range[n];						    // declared variable to hold the size of the array

    	for(a=num1; a<=num2; a++)				// this loop puts into the range array all the numbers between the
	    {				    	                // two numbers that were input by the user 
               range[x] = a;
               x++;
	    }
	
	printTableHead();                           // prints the top of the table

	for (a=num1; a<=num2; a++)
    {	
        getCounts(a, &tenThous, &thous, &hundreds, &tens, &ones);   // calls function to get the values in 
                                                                    // the specific columns
	    printf("|%10d | ", a);
	    getPinyin(&tenThous, &thous, &hundreds, &tens, &ones);
	    printf("\n");
	}

}   // end of getRange function
/**********************************************************************************************/

// GET COUNTS FUNCTION
// this function receives the range array and the addresses of the variables holding the numbers of 
// the specific columns. from the range of numbers received it calculates the value in each of the columns 
// and stores those values in the addresses

void getCounts(int num, int *tenThous, int *thous, int *hundreds, int *tens, int *ones)
{
        *ones = num % 10;
        *tens = (num / 10) % 10;
        *hundreds = (num / 100) % 10;
        *thous = (num / 1000) % 10;
        *tenThous = num / 10000;
        
}   // end of getCounts function
/*************************************************************************************************/

// GET PINYIN FUNCTION
// this function takes the address of the specific columns as variables and the
// values that are stored in each address are then translated into pinyin(chines)
// using the character arrays

void getPinyin(int *tenThous, int *thous, int *hundreds, int *tens, int *ones)
{
    int i=0, tthou=*tenThous, strL, temp;
    
    if (*tenThous != 0)
    {    
        while (tthou > 0)                           // this loop determines how many tenthou there are
        {                                           // so we can print the number properly
            tthou /= 10;
            i++;
        }

        if (i > 3)                                  // if #### * 10000
        {
            if(((*tenThous/10)%10) == 1)
            {
                strL = printf("%s %s %s %s %s %s %s ", onesArray[(*tenThous/1000)-1],
                        colsArray[2], onesArray[((*tenThous/100)%10)-1],
                        colsArray[1], colsArray[0], onesArray[(*tenThous%10)-1],
                        colsArray[3]);
                temp = strL;
            }
            else
            {
                strL = printf("%s %s %s %s %s %s %s %s ", onesArray[(*tenThous/1000)-1],
                        colsArray[2], onesArray[((*tenThous/100)%10)-1],
                        colsArray[1], onesArray[((*tenThous/10)%10)-1],
                        colsArray[0], onesArray[(*tenThous%10)-1], colsArray[3]);
                temp += strL;
            }
        }

        else if (i == 3)  							// if ### * 10000 
        {
            if (((*tenThous/10)%10) == 1)           // determine if column value is 11 to print translation properly
            {
                strL = printf("%s %s %s %s %s ", onesArray[(*tenThous/100)-1],
                        colsArray[1], colsArray[0], onesArray[(*tenThous%10)-1],
                        colsArray[3]);
                temp += strL;
            }
            else
            {
                strL = printf("%s %s %s %s %s %s ", onesArray[((*tenThous/100)%10)-1], colsArray[1],
                            onesArray[((*tenThous/10)%10)-1], colsArray[0],
                            onesArray[(*tenThous%10)-1], colsArray[3]);
                temp += strL;
            }
        }
        
        else if (i == 2) 						    // if ## * 10000
        {
            if (((*tenThous/10)%10) == 1)           // determine if column value is 11 to print translation properly
            {
                strL = printf("%s %s %s ", colsArray[0], onesArray[(*tenThous%10)-1],
                            colsArray[3]);
                temp += strL;
            }
            else
            {
                strL = printf("%s %s %s %s ", onesArray[(*tenThous/10)-1], colsArray[0],
                        onesArray[((*tenThous/10)%10)-1], colsArray[3]);
                temp += strL;
            }
        }
        
        else if (i == 1) 						    // if # * 10000
        {
            strL = printf("%s %s ", onesArray[*tenThous - 1], colsArray[3]);
            temp += strL;
        }
    }

    if (*thous != 0)
    {
	    strL = printf("%s %s ", onesArray[*thous - 1], colsArray[2]);
        temp += strL;
    }

    if (*hundreds !=0)
    {
	    strL = printf("%s %s ", onesArray[*hundreds - 1], colsArray[1]);
        temp += strL;
    }
    
    if (*tens != 0)
    {
        if (*tens == 1)
        {
            strL = printf("%s ", colsArray[0]);
            temp += strL;
        }
        else
        {
	        strL = printf("%s %s ", onesArray[*tens - 1], colsArray[0]);
            temp += strL;
        }
    }
        
    if (*ones != 0)
    {
        strL = printf("%s", onesArray[*ones - 1]);
        temp += strL;
    }
   
    printf("%*c", (65-(temp+1)), '|');

} // end of getPinyin function
/*************************************************************************************************/

// PRINT TABLE HEADER FUNCTION
// this function simply prints the top part of the table

void printTableHead(void)
{

    printf("\n\n");
    printf("|  Numbers |                     Chinese Equivalent                          |\n");
    printf("-----------+------------------------------------------------------------------\n");

} // end of printTableHead function
/****************************************************************************************/

// AGAIN FUNCTION
// this function determines whether the user wants to do more translations.
// prompting the user to enter Y or N and testing for the validity or the input and
// following the proper logic depending on the input from the user

char again(void)
{
        int value, goodscan, valid = 1;
        char again, c;

        goodscan = scanf("%c%c", &again, &c);           // determines proper input
        if (goodscan == 0 || c != '\n')                 // logic to be performed if input is not valid
        {
            printf("\nBad input. Please try again\n");
            clear();
            return 0;
        }
        else
            return again;
}   // end of getNum function
/********************************  END OF PROGRAM  **************************/
