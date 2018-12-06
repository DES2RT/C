
// this program is a bike rental company's calculator. it determines the cost of a bike that is
// rented. it asks the user for the time the bike was rented and the time it was returned then calculates how
// long the bike was rented for. then the program calcualtes the cost of the rental. it displays the duration
// of the rental in hours:minutes and the cost of the rental. it uses four functions
/**************************************************************/

#include <stdio.h>

int verify(int);																								// function validates the input by the user
int leapyear(int yearIn, int yearOut);													// determines if year entered is a leapyear
int durout(int yearOut, int monthOut, int dayOut, int hourOut, int minOut, int leapY);	
																																// calculates the date the bike was rented into minutes
int durin(int yearIn, int monthIn, int dayIn, int hourIn, int minIn, int leapY);				
																																// calculates the date the bike was returned into minutes
double cost(int duration);																			// returns the cost of the rental

int main(void)  
{

	/** VARIABLE DECLARATIONS **/
	  // FOR THE INPUT FROM USER
		int yearIn, monthIn, dayIn, hourIn, minIn;  								// variables hold the date of the bike returned;
		int yearOut, monthOut, dayOut, hourOut, minOut;							// variables hold the date of the bike rented

		// FOR THE CALCULATION OF THE DURATION FO THE RENTAL
		int durationIn, durationOut, duration, durationTot;					
		int durationDays, durationHours, durationMins;														
																																
		double totCost;																							// holds the calculation of the cost of the rental

		int leapY;																									// holds the value returned by leapyear()

	/** THIS SECTION PROMPTS THE USER FOR THE DATE AND TIME OF THE  RENTAL OUT  **/
		printf("\nPlease enter the date and time the bike was rented out: \n");
		printf("Year (YYYY): ");    																// PROMPTS FOR YEAR OF RENTAL OUT
		scanf("%d", &yearOut);		
		
		printf("Month (1-12): ");   																// PROMPTS FOR MONTH OF RENTAL OUT
		scanf("%d", &monthOut); 
		while (monthOut <1 || monthOut >12)													// LOOP TO DETERMINE VALID INPUT
		{
			printf("The month must be (0-12). Please try again ");
			scanf("%d", &monthOut);
		}
		
		printf("Day (1-31): ");    																// PROMPTS FOR DAY OF RENTAL OUT
		scanf("%d", &dayOut);
		while (dayOut <1 || dayOut >31)															// LOOP TO DETERMINE VALID INPUT
		{
			printf("The day must be (0-31)/ Please try again. ");
			scanf("%d", &dayOut);
		}
		
		printf("Hour (0-23): ");    																// PROMPTS FOR HOUR OF RENTAL OUT
		scanf("%d", &hourOut);
		while (hourOut >23)																					// LOOP TO DETERMINE VALID INPUT
		{
			printf("Hour must be (0-23). Please try again ");
			scanf("%d", &hourOut);
		}
		
		printf("Minutes (0-59): ");  																// PROMPS FOR MINUTES OF RENTAL OUT
		scanf("%d", &minOut);																				
		while (minOut >59)																					// LOOP TO DETERMINE VALID INPUT
		{
			printf("Minutes must be (0-59). Please try again ");
			scanf("%d", &minOut);
		}

	/** THIS SECTION PROMPT THE USER FOR THE DATE AND TIME OF THE RENTAL RETURNED **/

	  printf("Please enter the date and time the bike rented was returned: \n");
		printf("Year (YYYY): ");    																// PROMPTS FOR YEAR OF RENTAL RETURNEDT
		scanf("%d", &yearIn);
		while (yearIn < yearOut)																		// LOOP TO DETERMINE VALID INPUT AND WHETHER
		{																														// RENTAL RETURNED IN PREVIOUS YEAR TO RENTAL
			printf("The bike can not be returned previous to being rented. Please try again ");
			scanf("%d", &yearIn); 
		}

		printf("Month (1-12): ");   																// PROMPTS FOR MONTH OF RENAL RETURNED
		scanf("%d", &monthIn);
			while (monthIn <1 || monthIn >12)													// LOOP TO DETERMINE VALID INPUT
			{
				printf("Month must be (1-12). Please try again ");
				scanf("%d", &monthIn);
			}
			
			while ((yearIn == yearOut) && (monthIn < monthOut))				// LOOP TO DETERMINE IF MONTH RETURNED IS 
			{																													// PREVIOUS TO MONTH RENTED
				printf("The bike cannot be returned in previous to being rented. Please try again ");
				scanf("%d", &monthIn);
			}
			
		printf("Day (1-31): ");    																// PROMPTS FOR DAY OF RENTAL RETURNED
		scanf("%d", &dayIn);
			while (dayIn <1 || dayIn >31)														// LOOP TO DETERMINE VALID INPUT
			{
				printf("Day must be (1-31). Please try again ");
				scanf("%d", &dayIn);
			}
			
			while ((yearIn == yearOut) && (monthIn == monthOut) && (dayIn < dayOut))	// LOOP TO DETERMINE THE DAY THE
			{																																					// BIKE WAS RETURNED IS VALID
				printf("The bike cannot be returned on previous to being rented. Please try again ");
				scanf("%d", &dayIn);
			}
		
		printf("Hour (0-23): ");    																// PROMPTS FOR HOUR OF RENTAL RETURNED
		scanf("%d", &hourIn);
			while (hourIn >23)																				// LOOP TO DETERMINE VALID INPUT
			{
				printf("Hour must be (0-23). Please try again ");
				scanf("%d", &hourIn);
			}
			
			while ((yearIn == yearOut) && (monthIn == monthOut) && (dayIn == dayOut) && (hourIn < hourOut))			
			{
				printf("The bike cannot be returned previous to being rented. Please try again ");
				scanf("%d", &hourIn);
			}
		
		printf("Minutes (0-59): ");  																// PROMPS FOR MINUTES OF RENTAL RETURNED
		scanf("%d", &minIn);
			while (minIn >59)																					// LOOP TO DETERMINE VALID INPUT
			{
				printf("Minutes must be (0-59). Please try again ");
				scanf("%d", &minIn);
			}
	
			while ((yearIn == yearOut) && (monthIn == monthOut) && (dayIn == dayOut) && (hourIn == hourOut) && (minIn < minOut))
			{
				printf("The bike cannot be returned previous to being rented. Please try again ");
				scanf("%d", &minIn);
			}	

		// function call to determine if year entered is a leap year
		leapY = leapyear(yearIn, yearOut);

		// function call to calculate the time the bike was rented and represented in minutes
		durationOut = durout(yearOut, monthOut, dayOut, hourOut, minOut, leapY);		
		// function call to calculate the time the bike was returned represented in minutes
		durationIn = durin(yearIn, monthIn, dayIn, hourIn, minIn, leapY);
		duration = durationIn - durationOut;												// calculates the total duration of the rental	
		totCost = cost(duration);																		// function call to calculate the cost of
																																// the rental
		
		durationHours = duration / 60;															// calculates the number of hours of
		durationMins = duration % 60;																// calculates the remaining minutes of the
																																// rental by using the modulus operator
		if (durationHours > 23)
		{
				durationDays = durationHours / 24;
				durationHours = durationHours % 24;
		printf("\n\nThe total duration of the rental was: %d days, %d hours and %d minutes, for a total cost of $%.2lf\n\n",	 			durationDays, durationHours, durationMins, totCost); 
		}
		else
			printf("\n\nThe total duration of the rental was: %d hours and %d minutes, for a total cost of $%.2lf\n\n",
			durationHours, durationMins, totCost);
		
		return 0;
}

// end of main function

/**********************************************************************************************************************/
// function leapyear receives the yearIn and yearOut parameters from main and determines whether either of the
// years is a leap year and returns that to main

int leapyear(int yearIn, int yearOut)
{
		int leapyear;
		
		if (yearIn % 400 == 0)
				leapyear = 1;
		else if (yearIn % 100 == 0)
				leapyear = 0;
		else if (yearIn % 4 == 0)
				leapyear = 1;
		else
				leapyear = 0;

		if (yearOut % 400 == 0)
				leapyear = 1;
		else if (yearOut % 100 == 0)
				leapyear = 0;
		else if (yearOut % 4 == 0)
				leapyear = 1;
		else
				leapyear = 0;

		return leapyear;
	
}
// end of leapyear function

/*********************************************************************************************************************/
// function durout receives 5 parameters from main and calculates the number of minutes in the date provided.
// it returns that value back to main

int durout(int year, int month, int day, int hour, int min, int leapY)
{
		long long hourYear, durOutTot, durOutTotMins;
		int hourMonth, hourMonthTot=0, hourDay, hourHour, mins;

		hourYear = (year-1)*365*24; 												// the year minus one * no. of day in year * no. of hours in day

		while (month != 0)																	// loop to calculate the number of hours in the months
		{																										// previous to the rental month
				month -= 1;
				// if statement dtermines whatyy month was entered and determines the number of hours in that month
				if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month ==12)
	  			{																							
							hourMonth	= 31*24;								 				
					}			 																				
				else if (month == 4 || month == 6 || month == 9 || month == 11)
					{
							hourMonth = 30*24;
					}
				else if (leapY && (month == 2))									// this if statement says if it is a leapyear and the
					{																							// month is february, the month has 29 days
							hourMonth = 29*24;											
					}
				else if (month == 2)
					{
							hourMonth = 28*24;
					}
				else
							hourMonth = 0;
				
				hourMonthTot = hourMonthTot + hourMonth; 				// accumulates the total hours in the months previous
																												// the rental month

		}																										// end loop

		hourDay = (day - 1) * 24;														// calculate the number of hours in the days previous
																												// to the rental
		hourHour = hour;
		mins = min;
		

		durOutTotMins = (hourYear + hourMonthTot + hourDay + hourHour) * 60;
		durOutTot = durOutTotMins + mins;									// calculates total rental time in minutes

		return durOutTot;

}
//end of durout function

/********************************************************************************************************************/
// function durin receives 5 parameters from main and calculates the number of minutes in the date provided.
// it returns that value back to main

int durin(int year, int month, int day, int hour, int min, int leapY)
{
		long long hourYear, durInTot, durInTotMins;
	
		int hourMonth, hourMonthTot=0, hourDay, hourHour, mins;
		
		hourYear = (year-1)*365*24; 												// the year minus one * no. of day in year * no. of hours in day

		while (month != 0)																	// loop to accumulate the
		{
				month -= 1;
						
						// if statement dtermines whatyy month was entered and determines the number of hours in that month
						if (month == 1 || month ==  3 || month ==  5 || month ==  7 || month ==  8 || month ==  10 ||
																							month ==  12)			
	  				{																							
								hourMonth	= 31*24;								 		
						}			 																		
						else if (month == 4 || month == 6 || month == 9 || month == 11)
						{
								hourMonth = 30*24;
						}
						else if (leapY && (month == 2))								// this if statement says if it is a leapyear and the
						{																							// month is february, the month has 29 days
								hourMonth = 29*24;									
						}
						else if (month == 2)
						{
								hourMonth = 28*24;
						}
						else
								hourMonth = 0;

				hourMonthTot = hourMonthTot + hourMonth; 					// accumulates the total hours in the months
																													// previous to the rental month
		}																											// end loop	

		hourDay = (day-1)*24;																	// calculate the number of hours in the days
																													// previous to rental
		hourHour = hour;
		mins = min;
		
		durInTotMins = (hourYear + hourMonthTot + hourDay + hourHour) * 60;
		durInTot = durInTotMins + mins;												// calculates total rental time in minutes

		return durInTot;

}
// end of durin function

/**********************************************************************************************************************/
// function cost takes the duration of the rental parameter from main and calculates the total for the rental

double cost(int duration)
{
		double rentCost;
		int durHours, durMins;
		
		durHours = duration / 60;
		durMins = duration % 60;

		if ((durHours == 0) && (durMins == 0))
				rentCost = 0;
		else if (durHours <= 5)
				rentCost = 5;
		else if (durHours <= 24)
				rentCost = 12;
		else if(durHours > 24)
				rentCost = 12 + ((durHours - 24) * .5);

		return rentCost;

}
// end of program

/***************************************************************************************************************/
