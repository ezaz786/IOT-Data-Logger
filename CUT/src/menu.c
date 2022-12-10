#include <stdio.h>
#include <stdlib.h>
#include <main.h>
#include <unistd.h>
#include <string.h>
#include <struct.h>

void menu()
{
	int ch ;
	int returnValue = 0;
	do 
	{
	    	printf("\n\n***********************************************\n");
	    	printf("* Welcome to Data Logger Processing System\n");
	    	printf("***********************************************\n");
	    	printf("1. Displays the Dataset.\n");	
		printf("2. Displays the monthly average Temperature.\n");
		printf("3. Displays the monthly average Humidity\n");
		printf("4. Displays the monthly average PM 2.5\n");
		printf("5. Displays the monthly average PM 10\n");
		printf("6. Displays the monthly average NO2\n");
		printf("7. Exit the system.\n");
		printf("***********************************************\n");
	
		printf("Enter a valid choice [1-7]: ");
		returnValue = scanf ("%d", &ch);
		printf("\n");
		if ( returnValue == 0 || returnValue ==  EOF)
		{
			fflush(stdin);
			printf("Invalid input. Please enter valid input\n");
			break;
		}
		
		city *headPointer = NULL;
		loadFromFile("../data/delhi.csv", &headPointer);
		
		switch(ch)
		{
			case 1:
				printLinkedList(headPointer);
				break;
				
			case 2:
				printf("Month-wise comparsion of Temperature\n");
				avgTemperature(headPointer);
				break;
				
			case 3:
				printf("Month-wise comparsion of Humidity\n");
				avgHumidity(headPointer);
				break;
				
			case 4:
				printf("Month-wise comparsion of PM 2.5\n");
				avgPM25(headPointer);
				break;
				
			case 5:
				printf("Month-wise comparsion of PM 10\n");
				avgPM10(headPointer);
				break;
				
			case 6:
				printf("Month-wise comparsion of NO2\n");
				avgNO2(headPointer);
				break;
				
			case 7:
				freeLinkedList(&headPointer);
				printf("Exiting\n");
				exit(0);
			default:
			    	printf("Invalid Choice.\nKindly enter valid number as per menu.\n");
				break;
		}

	} while ( ch != 7);

}
