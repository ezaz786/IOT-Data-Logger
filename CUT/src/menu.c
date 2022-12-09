#include <stdio.h>
#include <stdlib.h>
#include <main.h>
#include <unistd.h>

void avgTemperature()
{
	printf("avgTemperature\n");
}

void avgHumidity()
{
	printf("avgHumidity\n");
}

void avgPM25()
{
	printf("avgPM25\n");
}

void avgPM10()
{
	printf("avgPM10\n");
}

void avgNO2()
{
	printf("avgNO2\n");
}


void menu()
{
	int ch ;
	int returnValue = 0;
	do 
	{
	    	printf("Welcome to Data Logger Processing System\n\n");	
		printf("\t1. Temperature\n");
		printf("\t2. Humidity\n");
		printf("\t3. PM 2.5\n");
		printf("\t4. PM 10\n");
		printf("\t5. NO2\n");
		printf("\t6. Exit\n");
	
		printf("Enter a valid choice [1-6]: \n");
		returnValue = scanf ("%d", &ch);
		if ( returnValue == 0 || returnValue ==  EOF)
		{
			fflush(stdin);
			printf("Invalid input. Please enter valid input\n");
			break;
		}

		switch(ch)
		{
			case 1:
				avgTemperature();
				break;
			case 2:
				avgHumidity();
				break;
			case 3:
				avgPM25();
				break;
			case 4:
				avgPM10();
				break;
			case 5:
				avgNO2();
				break;
			case 6:
				printf("Exiting\n");
				break;
			default:
			    	printf("Invalid Choice\n");
				break;
		}

	} while ( ch != 6);

}
