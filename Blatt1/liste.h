#ifndef _Liste
#define _Liste

#include <stdio.h>
#include <stdlib.h>
#include "meinString.h"
#include "liste.c"

//bekommt einen nach und einen vornamen übergeben um eine neues element sortiert in die lieste einzufügen
void hinzufuegen(char *vorname, char *nachname);

//gibt jeden allocierten speicher wider frei
void loeschen();

//gibt die namen in der liste nacheinader aus
void ausgabe();

#endif
