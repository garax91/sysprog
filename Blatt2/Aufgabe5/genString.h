#ifndef _genString
#define _genString

#include <stdio.h>
#include <stdlib.h>
#include "genListe.h"
#include "genString.c"

//Lese aus der Datei alle Vor- und alle Nachnamen ein
//void einlesen();

/*
int gleichDatum(char *datum1, char *datum2);
int gleichNachname(char *name1, char *name2);
int gleichVorname(char *name1, char *name2);
int gleichOrt(char *ort1, char *ort2);
*/

int kleinerDatum(char *datum1, char *datum2);
int kleinerNachname(char *name1, char* name2);
int kleinerVorname(char *name1, char *name2);
int kleinerOrt(char *ort1, char *ort2);

int gleich(int (*func)(char *, char*),char *name1, char *name2);

int kleiner(int (*func)(char *, char*),char *name1, char *name2);

int length(char *str);

char* copyString(const char *str);

#endif
