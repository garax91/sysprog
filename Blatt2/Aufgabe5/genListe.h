#ifndef _genListe
#define _genListe

#include <stdio.h>
#include <stdlib.h>
#include "genString.h"
#include "genListe.c"

//fügt ein element mit gegebene parametern hinzu
void hinzufuegen(char *vorname, char *nachname, char *datum, char *ort, int sort);

void loeschen();

void ausgabe();

#endif
