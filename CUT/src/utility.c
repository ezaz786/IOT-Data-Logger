#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <struct.h>
#include <main.h>

int freeLinkedList(city** headPointer)
{
    city* iter = *headPointer;
    int recordsFreed = 0;
    // Following code block frees the dynamically memory allocated 
    while ( iter != NULL )
    {
        city* temp = iter ;
        iter = iter -> next ;
        if ( temp != NULL)
		{
            		free (temp);
			recordsFreed++;
		}
    }
    return recordsFreed;

}

void appendLinkedList(city **headPointer, city* data)
{
    city* iter = *headPointer ;

    if ( *headPointer == NULL ) //No  element in the linkedlist 
        *headPointer = data ;
    else
    {
        while ( iter -> next != NULL)
            iter = iter -> next;
        iter -> next = data ;
    }
    data -> next = NULL ;
}

void display_city(city* ct)
{
    printf("| %s | %d | %s | %d | %d | %.2f | %.2f | %.2f |\n",
        ct -> city,
        ct -> code,
        ct -> date,
        ct -> temperature,
        ct -> humidity,
        ct -> pm25,
        ct -> pm10,
        ct -> no2 );
}

void printLinkedList(city *ct)
{
    city* iter = ct;
    while ( iter != NULL )
    {
        display_city(iter);
        iter = iter -> next ;
    }

}

int loadFromFile(const char *fileName, city **headPointer)
{
	char lineBuffer[CITY_LINE_BUFFER];
	const char* seperator = "," ;
	char* token = NULL ;

	FILE* cityFile = fopen (fileName, "r");
	if (cityFile == NULL )
    	{
		printf("Issue opening the file %s\n", fileName);
		return EXIT_FAILURE ;
	}
	
	fgets ( lineBuffer, CITY_LINE_BUFFER, cityFile);
	for(int i=0; i<strlen(lineBuffer); i++)
    	{
	    	if(lineBuffer[i]==',')
		{
			lineBuffer[i]='|';
		}
	}
	
	while ( fgets ( lineBuffer, CITY_LINE_BUFFER, cityFile) != 0)
	{
		city *iter = (city*)malloc(sizeof(struct _city));
		if ( iter == NULL )
		{
			printf("Could not allocate memory !\n");
			break;
		}

		token = strtok (lineBuffer, seperator);
		if ( token != NULL)
		{
			strcpy(iter -> city, token);
		}

		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> code = atoi(token);
		}

		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			strcpy(iter -> date, token);
			
		}

		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> temperature = atoi(token);
		}


		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> humidity = atoi(token);
		}
		
		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> pm25 = atof(token);
		}
		
		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> pm10 = atof(token);
		}

		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> no2 = atof(token);
		}

		appendLinkedList(headPointer, iter);
	}

	fclose(cityFile);
	return 0;
}

