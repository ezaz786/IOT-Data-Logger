#include <stdio.h>
#include <stdlib.h>
#include <main.h>
#include <unistd.h>
#include <string.h>
#include <struct.h>

void avgTemperature(city *head)
{
    for(int i=1;i<13;i++)
    {
        int count = 0, temp = 0;
        float avgTemperature;
        char mon[3];
	mon[2] = 0;
    	city *iter = head;

        while(iter!= NULL)
        {
	    	mon[0] = iter->date[3]; // Copy two character of date including leading zero.
	    	mon[1] = iter->date[4];
            if(atoi(mon) == i)
            {
                temp += iter->temperature;
                count++;
            }
            iter = iter->next;
        }
        
        if(count!=0)
        	avgTemperature = temp/count;
        printf("Average temperature for month %d is %.2f\n", i, avgTemperature);
        
    }
}

void avgHumidity(city *head)
{
    for(int i=1;i<13;i++)
    {
        int count = 0, temp = 0;
        float avgHumidity;
        char mon[3];
	mon[2] = 0;
    	city *iter = head;
        while(iter!= NULL)
        {
	    	mon[0] = iter->date[3]; // Copy two character of date including leading zero.
	    	mon[1] = iter->date[4];
            if(atoi(mon) == i)
            {
                temp += iter->humidity;
                count++;
            }
            iter = iter->next;
        }
        
        if(count!=0)
        	avgHumidity = temp/count;
        printf("Average Humidity for month %d is %.2f\n", i, avgHumidity);
        
    }
}

void avgPM25(city *head)
{   
    for(int i=1;i<13;i++)
    {
        int count = 0, temp = 0;
        float avgPM25;
        char mon[3];
	mon[2] = 0;
    	city *iter = head;
        while(iter!= NULL)
        {
	    	mon[0] = iter->date[3]; // Copy two character of date including leading zero.
	    	mon[1] = iter->date[4];
            if(atoi(mon) == i)
            {
                temp += iter->pm25;
                count++;
            }
            iter = iter->next;
        }
        
        if(count!=0)
        	avgPM25 = temp/count;
        printf("Average PM25 for month %d is %.2f\n", i, avgPM25);
        
    }
}

void avgPM10(city *head)
{   
    for(int i=1;i<13;i++)
    {
        int count = 0, temp = 0;
        float avgPM10;
        char mon[3];
	mon[2] = 0;
    	city *iter = head;
        while(iter!= NULL)
        {
	    	mon[0] = iter->date[3]; // Copy two character of date including leading zero.
	    	mon[1] = iter->date[4];
            if(atoi(mon) == i)
            {
                temp += iter->pm10;
                count++;
            }
            iter = iter->next;
        }
        
        if(count!=0)
        	avgPM10 = temp/count;
        printf("Average PM10 for month %d is %.2f\n", i, avgPM10);
        
    }
}

void avgNO2(city *head)
{   
    for(int i=1;i<13;i++)
    {
        int count = 0, temp = 0;
        float avgNO2;
        char mon[3];
	mon[2] = 0;
    	city *iter = head;
        while(iter!= NULL)
        {
	    	mon[0] = iter->date[3]; // Copy two character of date including leading zero.
	    	mon[1] = iter->date[4];
            if(atoi(mon) == i)
            {
                temp += iter->no2;
                count++;
            }
            iter = iter->next;
        }
        
        if(count!=0)
        	avgNO2 = temp/count;
        printf("Average NO2 for month %d is %.2f\n", i, avgNO2);
        
    }
}
