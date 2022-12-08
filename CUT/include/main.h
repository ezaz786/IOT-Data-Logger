#ifndef __MAIN_H__
#define __MAIN_H__
#include <struct.h>
extern employee*  searchEmpId (employee* headPointer, int empId);
extern employee* searchEmpName (employee* headPointer, const char* empfirstName);
extern int  loadFromFile(const char* fileName, employee **);
extern void display_employee(employee* );
extern void printLinkedList(employee *);
extern int  freeLinkedList(employee **);
extern void append(employee **headPointer, employee* data);
extern void prepend(employee **headPointer, employee* data);

extern int  insertAfter(int empId, employee** headP, employee* newEmp);
extern employee* getEmployeeFromHashTable(employee** emp, int);
//extern employee* getEmployeeFromHashTable(employee** emp, char*, char*);
extern void addEmpToHashTable(employee** empTable, employee* emp);
extern int HashFunction(int key);
extern void visualHashTable(employee** );
extern void freeHashTable(employee** emp);

#endif
