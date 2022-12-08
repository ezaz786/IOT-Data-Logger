#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <struct.h>
#include <main.h>

void freeHashTable(employee** emp)
{
	for (int i=0; i < MAXEMP; i++)
	{
		if (emp[i] != NULL)
			freeLinkedList(&emp[i]);
	}
}

//employee* searchEmpNameInHT (employee* headPointer, const char* empFirstName, const char* empLastName)
employee* searchEmpNameInHT (employee* headPointer, int empId)
{
    employee* iter = headPointer;

    while ( iter != NULL )
    {
		//if((strcmp(iter->firstName, empFirstName) == 0) && (strcmp(iter->lastName, empLastName) == 0))
		if(iter->empId ==  empId)
		{
			printf("Empl found!!\n");
			break;
		}
        iter = iter -> next ;
    }
	return iter;

}

employee* getEmployeeFromHashTable(employee** emp, int empId)
//employee* getEmployeeFromHashTable(employee** emp, char* firstName, char* lastName)
{
	int index = HashFunction(empId);
	printf("Hash Function returned %d\n", index);
	employee* e1 =  searchEmpNameInHT(emp[index], empId);
	return e1 ;
}

int HashFunction(int key)
{
	int index = 0;
	index = key % (MAXEMP);
	return index;

}

void addEmpToHashTable(employee** empTable, employee* emp)
{
	//int index = HashFunction(emp->firstName);
	int index = HashFunction(emp->empId);
	append(&empTable[index], emp); 
	
}

void display_employee(employee* emp)
{
    printf("|%d |%-10s %-12s |%10s |%3s |%12s |%11s |%6d|\n",
        emp->empId,
        emp->firstName,
        emp->lastName,
        emp->email,
        emp->hireDate,
        emp->phone,
        emp->jobId,
        emp->salary );
}

void printHashTable(employee** emp)
{
	for(int i =0; i < MAXEMP; i++)
	{
		printLinkedList(emp[i]);
	}
}


void printLinkedListName(employee** emp)
{
	employee *iter = *emp ;
	while (iter != NULL ) 
	{
    	printf("|%d %-10s%-11s| -> ",
		iter -> empId,
        iter->firstName,
        iter->lastName);
		iter = iter -> next;
	}
	//printf("NULL\n");
	printf("\n");
}

void visualHashTable(employee** emp)
{
	for(int i =0; i < MAXEMP; i++)
	{
		printf("%s[%d]:" , "bucket",  i); 
		printLinkedListName(&emp[i]);
	}
}


void printLinkedList(employee *emp)
{
    employee* iter = emp;
    while ( iter != NULL )
    {
        display_employee(iter);
        iter = iter -> next ;
    }

}

int loadFromFile(const char *fileName, employee **headPointer)
{
	char lineBuffer[EMP_LINE_BUFFER];
	const char* seperator = "|" ;
	char* token = NULL ;
	employee *iter = NULL;

	FILE* empFile = fopen (fileName, "r");
	if (empFile == NULL )
    {
		printf("Issue opening the file %s\n", fileName);
		return EXIT_FAILURE ;
	}	

	while ( fgets ( lineBuffer, EMP_LINE_BUFFER, empFile) != 0)
	{
		iter = (employee*) malloc (sizeof(employee));
		if ( iter == NULL )
		{
			printf("Could not allocate memory !\n");
			break;
		}

		token = strtok (lineBuffer, seperator);
		if ( token != NULL)
		{
			iter -> empId = atoi(token);
		}

		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			strncpy(iter -> firstName, token, FNAME_LEN - 1);
		}

		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			strncpy(iter -> lastName, token, LNAME_LEN - 1);
			
		}

		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			strncpy(iter -> email, token, EMAIL_LEN - 1);
		}


		token = strtok (NULL, seperator);
		if ( token != NULL)
		{
			strncpy(iter -> hireDate, token, HIRE_DATE_LEN - 1);
		}
		token = strtok (NULL, seperator);

		if ( token != NULL)
		{
			strncpy(iter -> phone, token, PHONE_LEN - 1);
		}
		token = strtok (NULL, seperator);

		if ( token != NULL)
		{
			strncpy(iter -> jobId, token, JOB_ID_LEN - 1);
		}


		token = strtok (lineBuffer, seperator);
		if ( token != NULL)
		{
			iter -> salary = atoi(token);
		}

		iter -> next = NULL ;

		//prepend ( headPointer, iter );
		addEmpToHashTable(headPointer, iter);
	}

	fclose(empFile);

	return 0;
}

