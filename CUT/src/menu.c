#include <stdio.h>
#include <stdlib.h>
#include <main.h>
#include <unistd.h>

void avgTemperature()
{
    for(int i=1;i<13;i++){
        char mon[3];
        sprintf(mon,"%2d",k)
        while(iter!= NULL){
            if(strncmp(date[3],mon,2)==0){
                temp+= temperature->temp;
                iter=iter->next;
                count++;
            }
        }
        avgTemperature = temp/count;
        printf("Average temprature for month %d is %d\n",mon,avgTemperature);
    }
    
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
	    	printf("\n\n***********************************************\n");
	    	printf("* Welcome to Data Logger Processing System\n");
	    	printf("***********************************************\n");
	    	printf("1. Displays the Dataset.\n");	
		printf("2. Displays the monthly average Temperature.\n");
		printf("3. Displays the monthly average Humidity\n");
		printf("4. Displays the monthly average PM 2.5\n");
		printf("5. Displays the monthly average PM 10 by\n");
		printf("6. Displays the monthly average NO2\n");
		printf("7. Exit the system.\n");
	
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
				freeLinkedList(headPointer);
				break;
				
			case 2:
				avgTemperature();
				break;
				
			case 3:
				avgHumidity();
				break;
				
			case 4:
				avgPM25();
				break;
				
			case 5:
				avgPM10();
				break;
				
			case 6:
				avgNO2();
				break;
				
			case 7:
				printf("Exiting\n");
				exit(0);
			default:
			    	printf("Invalid Choice\n");
				break;
		}

	} while ( ch != 7);

}
