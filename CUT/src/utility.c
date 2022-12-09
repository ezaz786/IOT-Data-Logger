#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <struct.h>
#include <main.h>

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

void loadFromFile(const char *fileName, city **headPointer)
{
	char lineBuffer[CITY_LINE_BUFFER];
	const char* seperator = "," ;
	char* token = NULL ;
	city *iter = NULL;

	FILE* cityFile = fopen (fileName, "r");
	if (cityFile == NULL )
    	{
		printf("Issue opening the file %s\n", fileName);
		return EXIT_FAILURE ;
	}	
	
	while ( fgets ( lineBuffer, CITY_LINE_BUFFER, cityFile) != 0)
	{
		iter = (city*) malloc (sizeof(city));
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


		token = strtok (lineBuffer, seperator);
		if ( token != NULL)
		{
			iter -> no2 = atof(token);
		}

		iter -> next = NULL ;
	}

	fclose(cityFile);
}

