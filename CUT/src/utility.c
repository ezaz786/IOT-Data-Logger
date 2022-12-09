#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <struct.h>
#include <main.h>

/*void printLinkedList(employee *emp)
{
    employee* iter = emp;
    while ( iter != NULL )
    {
        display_employee(iter);
        iter = iter -> next ;
    }

}*/

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
			strncpy(iter -> city, token, CITY_LEN - 1);
		}

		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			iter -> code = atoi(token);
		}

		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			strncpy(iter -> date, token, DATE_LEN - 1);
			
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

		printf("%s", lineBuffer);
	}

	fclose(cityFile);
}

