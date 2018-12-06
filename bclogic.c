// Program Name: bclogic.c

// BarCode logic program to determine if a valid barcode has been entered. the program first prompts user for
// a UPC and then verifies if the correct number of digits has been entered. if the correct number has been
// entered the program then checks for the checkdigit (the last one) and finally uses an algorithm to
// determine if the UPC entered is valid or not. the user can quit the program by pressing 0.

#include <stdio.h>

int countdigits(int upc);									// function prototype for checking proper number of digits entered for UPC
int checkdigit(int upc);									// function prototype for obtainning the checkdigit for the UPC
int validation(int upc);									// function prototype to validate the UPC

int main(void)	{
		
		int upc;																// variable to hold the UPC entered
		int count;															// count determines if the UPC entry has the proper amount of digits
		int chdigit;														// holds the number for the checkdigit
		int valid;															// variable to determine if the UPC is valid

		printf("\n\nUPC Validator\n");
		printf("=============\n");

		do	{																		// start of do/while to have program continue until the user
																						// presses 0 
			do	{																	// start of do/while that prompts the user for a valid UPC that
																						// includes 12 digits
				printf("UPC (0 to quit): ");				// prompts the user to enter UPC or 0 to quit
				scanf("%d", &upc);								// accepts input and stores it in variable upc
				if (upc == 0)	{											// determines what logic to proceed with if user enters 0
					printf("Have a nice day!\n\n\n");	// prints if user presses 0
					return 0;													// returns control to operating system if user presses 0
				} else
						count = countdigits(upc);				// if user enters valid UPC a function call is made to
																						// countdigits, passing upc as a parameter the number of digits
																						// counted is then passed back and stored in count
			printf("count is %d\n", count);
			if (count == 11)
				count++;

			printf("second count is %d\n", count);
				if (count != 12)										// if user has not entered correct number of digits for UPC the
																						// following is printed
					printf("UPC must contain 12 digits. Please try again\n");

			} while (count != 12);								// end of do/while to prompt the user for a valid UPC, that
																						// includes 12 digits

			chdigit = checkdigit(upc);						// function call to checkdigit passing upc as a parameter.
																						// receiving back the checkdigit and placing it in variable chdigit

			valid = validation(upc);							// function call to validation passing upc as a parameter to
																						// validate the UPC, the value is passed back and stored in the variable valid

			if (valid == 0)	{												// logic determines if valid is equal to zero and prints the
																						// appropriate message to the user
				printf("This is a valid UPC\n");
			} else	{
				printf("This is not a valid UPC\n");
			}
		
		} while (upc != 0);											// end of do/while that allows the user to enter UPC's into the
																						// program until 0 is pressed
	
		return 0;																// return control back to the operating systme

}																						// end of main function

/*******************************************************************************************************/
// function countdigits accepts the UPC from main and with it obtains the number of digits entered by counting
// the number of times the numbers of the UPC can be divided by 10 and returns that number (count) to main

int countdigits(int upc)	{

		int count=0;
		int a;

		while (upc)	{
			upc /= 10;
			++count;
		}

		return count;
	
}																						// end of countdigits function

/*******************************************************************************************************/
// function checkdigits accepts the UPC from main and uses the modulus operator to find the remainder (the
// remaining number after grouping the other 11) and returns that number to the main function

int checkdigit(int upc)	{

	int chdigit;

	chdigit = upc % 10;

	return chdigit;

}																						// end of checkdigit function

/******************************************************************************************************/
// function validation accepts the UPC from main and uses an algorithm to determine if the UPC entered is
// valid

int validation(int upc)	{

	int chdigit, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;	// the digits entered for UPC seperated
	int sum1;																	// the sum of all the odd placed numbers (1, 3, 5, etc) multiplied
																						// by 3
	int sum2;																	// the sum of all the evenly placed numbers (2, 4, 6, etc)
	int total;																// the sum of adding sum1 + sum2
	int chdigtotal;														// the chdigtotal is the sum of adding total to the checkdigit
	int valid;																// valid holds the answer from the final step of validation

	chdigit = upc % 10;												// again .. there has to be a better way of seperating the digits
	d11 = (upc / 10) % 10;											// of the UPC into individual digits. what i did was use division
	d10 = (upc / 100) % 10;											// and the modulus operator to get the remaining number after the 
	d9 = (upc / 1000) % 10;											// division was done
	d8 = (upc / 10000) % 10;
	d7 = (upc / 100000) % 10;
	d6 = (upc / 1000000) % 10;
	d5 = (upc / 10000000) % 10;
	d4 = (upc / 100000000) % 10;
	d3 = (upc / 1000000000) % 10;
	d2 = (upc / 10000000000) % 10;
	d1 = (upc / 100000000000) % 10;
	printf("last six digits are %d %d %d %d %d %d\n", d7, d8, d9, d10, d11, chdigit);
	sum1 = (d1 + d3 + d5 + d7 + d9 + d11) * 3;// the first step in the validation process is to add all the odd
																						// placed number (position 1, 3, 5, etc) and multiply that sum by 3
	sum2 = d2 + d4 + d6 + d8 + d10;	// the second step in the validation process is to add all the
																						// even placed numbers (position 2, 4, 6, etc), excluding the 12th
																						// placed number which is the checkdigit
	total = sum1 + sum2;											// the third step in the validation process is to add the two
																						// previous sums together
	chdigtotal = total + chdigit;							// the fourth step in the validation process is to add the
																						// checkdigit to the weighted total
	valid = chdigtotal % 10;									// the final step in the validation process is to divide the
																						// chdigtotal by 10 to produce a remainder that should equal zero

	return valid;															// returns valid back to main

}																						// end of function validation

// end of program
/******************************************************************************************************/


