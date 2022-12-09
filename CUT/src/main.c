#include <stdio.h>
#include <stdlib.h>
#include <main.h>
#include <unistd.h>
#include <string.h>

#define DATALIMIT 365

int main(int argc, char** argv)
{
	city delhi[DATA_LIMIT];
    	
    	for(int i =0; i < DATA_LIMIT; i++)
        {
        	loadFromFile("../data/employees.csv", &delhi[i]);
        }
        
	return EXIT_SUCCESS;
}
