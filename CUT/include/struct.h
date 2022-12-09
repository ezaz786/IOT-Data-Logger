#ifndef _STRUCT_H_
#define _STRUCT_H_


#define CITY_LEN 100
#define DATE_LEN 20
#define DATA_LIMIT 365
#define CITY_LINE_BUFFER 200

typedef struct _city_
{
	char *city[CITY_LEN];
	int code;
	char *date[DATE_LEN];
	int temperature;
	int humidity;
	float pm25;
	float pm10;
	float no2;
	struct _employee_ *next;
} city;

#endif
