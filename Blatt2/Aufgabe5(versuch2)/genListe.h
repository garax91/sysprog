#ifndef _genListe
#define _genListe

#include <stdio.h>
#include <stdlib.h>
#include "genString.h"
//#include "genListe.c"
#include "Person.h"

void printListe(void (*func)(void*));
void add(void *object, int (*func)(void*,void*,int),int sort);
void loeschen(void(*func)(void*));

#endif
