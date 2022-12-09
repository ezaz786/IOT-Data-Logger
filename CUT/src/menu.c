#include <stdio.h>
#include <stdlib.h>
#include <main.h>
#include <unistd.h>


void menu()
{
	int ch ;
	int returnValue = 0;
	do 
	{
	    	printf("Welcome to Data Logger Processing System\n");	
		printf("1. Temperature\n");
		printf("2. Humidity\n");
		printf("3. PM 2.5\n");
		printf("4. PM 10\n");
		printf("5. NO2\n");
		printf("6. Exit\n");
	
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
