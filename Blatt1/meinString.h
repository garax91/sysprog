#ifndef Mein_String
#define Mein_String

#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "meinString.c"

//vergleicht zwei eingegebene chars nach alphabetischer reihenfolge
int kleiner(char *name1, char *name2);

//pr�ft zwei gegebene chars auf gleichheit
int gleich(char *name1, char *name2);

//kopiert einen string (neuer speicherplatz)
char* copyString(const char *str);

//gibt die l�nge des strings zur�ck
int length(char *str);

#endif
