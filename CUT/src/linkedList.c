#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <struct.h>
#include <main.h>

/*********************************************************************
 *  freeLinkedList: Function takes address of the head node pointer
 *                  Itertates through the linked list and free 
 *                  allocated memory to each node.
 *  return value  : Returns the number of records freed.
 *********************************************************************/
int freeLinkedList(employee** emp)
{
    employee* iter = *emp;
    int recordsFreed = 0;
    // Following code block frees the dynamically memory allocated 
    while ( iter != NULL )
    {
        employee* temp = iter ;
        iter = iter -> next ;
        if ( temp != NULL)
		{
            		free (temp);
			recordsFreed++;
		}
    }
    return recordsFreed;

}

/*********************************************************************
 *  append: Function takes address of the head node pointer
 *          and new empoyee structure address and adds the 
 *          node to the end of the linked list
 *********************************************************************/
void append(employee **headPointer, employee* data)
{
    employee* iter = *headPointer ;

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

/*********************************************************************
 *  prepend: Function takes address of the head node pointer
 *          and new empoyee structure address and adds the 
 *          node to the start of the linked list
 *********************************************************************/
void prepend (employee **headPointer, employee* data)
{
    employee* temp = *headPointer ;
    *headPointer = data ;
    data -> next = temp;
//(*headPointer) -> next = temp;
}

/*********************************************************************
 *  insertAfter: Function takes address of the head node pointer
 *               and new empoyee structure address and employee Id
 *               and adds the node after the node of empId in 
 *               the linked list
 *********************************************************************/
int  insertAfter(int empId, employee** headP, employee* newEmp)
{
    int insert = 0;

    if ( newEmp == NULL)
        return OPERATION_FAIL ;

    if (*headP == NULL )
        append(headP, newEmp);

    employee* iter = *headP;

    while ( iter != NULL)   // Iterate through the list
    {
        if ( iter -> empId == empId )
        {
            // Insert after the current iter
            employee *temp = iter -> next;
            iter -> next = newEmp ;
            newEmp -> next = temp ;
            insert =  1;
            break;
        }
        iter = iter -> next;
    }
    if (insert == 1)
        return OPERATION_SUCCESS;
    else
        return EMPLOYEE_NOTFOUND ;

}

/*************************************************************
 * serchEmpId : searcheds the linked list by empId 
 * return value : Returns the found structure pointer or NULL
 *
 ************************************************************/
employee* searchEmpId (employee* headPointer, int empId)
{
	if (headPointer == NULL || empId <= 0) 
		return NULL ;

	employee *iter = headPointer ;
	while ( iter != NULL )
	{
		if ( iter-> empId == empId )
		{
			return iter;
		}
		iter = iter -> next ;
	}
	return NULL ;
}

/*************************************************************
 * searchEmpFirstName : searcheds the linked list by emp first name 
 * return value : Returns the found structure pointer or NULL
 *
 ************************************************************/
employee* searchEmpName (employee* headPointer, const char* empfirstName)
{
	if (headPointer == NULL || empfirstName == 0 || strlen(empfirstName) == 0)
        return NULL ;

	employee *returnList = NULL ;

	employee *iter = headPointer ;
	while ( iter != NULL )
	{
		if ( strcmp (iter-> firstName ,  empfirstName ) == 0)
		{
			employee* temp = (employee*)malloc(sizeof(employee));
			*temp = *iter ;
//  or memcpy ( temp, iter, sizeof(employee);  OR
//       temp -> empId = iter -> empId ;
//       strcpy ( temp -> firstName , iter->firstName);
//         ....
//       temp -> salary = iter -> salary;
//       temp -> next = NULL ;

			append(&returnList, temp);
			//return iter;
		}
		iter = iter -> next ;
	}
	return returnList ;
}

