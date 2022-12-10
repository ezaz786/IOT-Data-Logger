#ifndef __MAIN_H__
#define __MAIN_H__
#include <struct.h>
#include <menu.h>

extern void menu();

extern void avgTemperature(city *head);
extern void avgHumidity(city *head);
extern void avgPM25(city *head);
extern void avgPM10(city *head);
extern void avgNO2(city *head);

extern int freeLinkedList(city** headPointer);
extern void appendLinkedList(city **headPointer, city* data);
extern void display_city(city* ct);
extern void printLinkedList(city *ct);
extern int loadFromFile(const char* fileName, city **);
extern void printHeaderList(const char *fileName);


#endif
