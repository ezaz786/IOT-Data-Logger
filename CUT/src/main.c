#include <stdio.h>
#include <stdlib.h>
#include <main.h>
#include <unistd.h>
#include <string.h>

int removeEmployee(employee** emp, int empId)
{
	return EXIT_SUCCESS;
}


//doAddEmployee

void doAddEmployee(employee** emp)
{
	int empId = 0;
	int salary = 0;
	char firstName[FNAME_LEN] ;
	char lastName[LNAME_LEN] ;

	printf("Enter Employee Id\n");
	if ( 1 != scanf("%d", &empId))
	{
		fflush(stdin);
		printf("Please enter a valid number\n");
		return ;
	}

	printf("Enter first name \n");
	if ( scanf("%s", firstName) != 1 )
	{
		fflush(stdin);
		printf("Please enter a valid name\n");
		return ;
	}

	printf("Enter last name \n");
	if ( scanf("%s", lastName) != 1 )
	{
		fflush(stdin);
		printf("Please enter a valid name\n");
		return ;
	}

	printf("Enter Employee Salary\n");
	if ( 1 != scanf("%d", &salary))
	{
		fflush(stdin);
		printf("Please enter a valid number\n");
		return ;
	}
	
	employee *newEmp = (employee*)malloc(sizeof(employee));
	strcpy(newEmp -> firstName, firstName);
	strcpy(newEmp -> lastName, lastName);
    	strcpy(newEmp -> email, "");
    	strcpy(newEmp -> phone, "");
    	strcpy(newEmp -> jobId, "");
	strcpy(newEmp -> hireDate, "");
	newEmp -> empId = empId ;
	newEmp -> salary = salary ;

    	addEmpToHashTable(emp, newEmp);

}


//doRemoveEmployee

void doRemoveEmployee(employee** emp)
{
	int empId = 0;
	printf("Enter Employee Id\n");
	if ( 1 != scanf("%d", &empId))
	{
		fflush(stdin);
		printf("Please enter a valid number\n");
		return ;
	}

	int retValue =  removeEmployee(emp, empId);
	if ( retValue == EXIT_SUCCESS)
		printf("Employee with Id %d removed from the system successfully.\n", empId);
	else
		printf("Employee not found!\n");
}


//doDisplayEmployeeList

void doDisplayEmployeeList(employee** emp)
{
	visualHashTable(emp); // This needs to be changed later.
}


//doChangeEmployeeDepartment

void doChangeEmployeeDepartment(employee** emp)
{
    int empId = 0;
    printf("Enter Employee Id\n");
    if ( 1 != scanf("%d", &empId))
    {
        fflush(stdin);
        printf("Please enter a valid number\n");
        return ;
    }
	printf("To be implemented\n");
}


//menu

void  menu(employee** emp)
{
	int ch ;
	int returnValue = 0;
	
	do 
	{
		printf("Welcome to Employee Management program \n");	
		printf("1. Add new employee \n");
		printf("2. Remove an employee \n");
		printf("3. Display Employee List \n");
		printf("4. Change employee department \n");
		printf("5. Exit \n");
		
		printf("\nEnter your choice: ");
		returnValue = scanf ("%d", &ch);
		if ( returnValue == 0 || returnValue ==  EOF)
		{
			fflush(stdin);
			printf("Invalid input. Please enter valid input\n");
			continue ; // break;
		}

		switch(ch)
		{
			case 1:
				doAddEmployee(emp);
				break;
			case 2:
				doRemoveEmployee(emp);
				break;
			case 3:
				doDisplayEmployeeList(emp);
				break;
			case 4:
				doChangeEmployeeDepartment(emp);
				break;
			case 5:
				printf("Exiting\n");
				break;
			default:
			    	printf("Invalid operation\n");
				break;
		}

	} while ( ch != 5);

}

//main

int main(int argc, char** argv)
{
	employee* emp[MAXEMP];
    	for(int i =0; i < MAXEMP; i++)
        emp[i] = NULL ;

    	loadFromFile("../data/employees.csv", &emp[0]);
	menu(emp);

	return EXIT_SUCCESS;
}
