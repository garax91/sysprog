#ifndef _Person
#define _Person

#include <stdio.h>
#include <stdlib.h>
#include "genString.h"
#include "genListe.h"
#include "Person.c"

void* createPerson(char *vorname, char *nachname, char *datum, char *ort);
int kleinerPerson(void *person1, void *person2, int sort);
void printPerson(void *person);
void deletePerson(void *person);

#endif
