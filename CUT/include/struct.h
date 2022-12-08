#ifndef _STRUCT_H_
#define _STRUCT_H_

#define FNAME_LEN 40
#define LNAME_LEN 40
#define EMAIL_LEN 30
#define PHONE_LEN 20
#define DEPT_LEN  32
#define HIRE_DATE_LEN 16
#define JOB_ID_LEN 12

#define EMP_LINE_BUFFER 256

#define EMPLOYEE_NOTFOUND -1
#define OPERATION_FAIL -2
#define OPERATION_SUCCESS 0 

#define MAXEMP 20


#define FAILURE -1

typedef struct _employee_
{
    int empId ;
    char firstName[FNAME_LEN];
    char lastName[LNAME_LEN];
    char email[EMAIL_LEN];
    char phone[PHONE_LEN];
    char hireDate[HIRE_DATE_LEN];
    char jobId[JOB_ID_LEN];
    int  salary;

    struct _employee_ *next;
} employee;

#endif

