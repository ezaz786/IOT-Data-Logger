#ifndef __MAIN_H__
#define __MAIN_H__
#include <struct.h>

extern int freeLinkedList(city** headPointer);
extern void appendLinkedList(city **headPointer, city* data);
extern void display_city(city* ct);
extern void printLinkedList(city *ct);
extern int loadFromFile(const char* fileName, city **);
extern void printHeaderList(const char *fileName);


#endif
