#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _city
{
	int id;
	char cityName[50];
	int areaCode;
	char date[50];
	int temperature;
	int humidity;
	float pm25;
	float pm10;
	float no2;
	struct city *next;
}city;


int main(int argc, char** argv)
{
	char line[100], line2[100], token = NULL;
	char delim = ',';
	FILE *fp = fopen("./delhi.csv","r");
	
	city *delhi;
	delhi = (struct _city)malloc(sizeof(struct _city));
	
	if(fp == NULL)
	{
		printf("File could not be opened.");
	}
	
	fgets(line, 100, fp);
	printf("%s", line);
	
	fgets(line2, 100, fp);
	printf("%s", line2);
	
	token = strtok(line2,',');
	delhi->id = atoi(token);
	
	token = strtok(NULL,',');
	delhi->cityName = token;
	
	printf("%d", delhi->id);
	printf("%s", delhi->cityName);
		
	/*for(int i=0;i<365;i++)
	{
		fgets(line, 100, fp);
		printf("%s", line);
	}*/
	
	fclose(fp);

	return EXIT_SUCCESS;
}
