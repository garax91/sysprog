#include <stdio.h>
#include <stdlib.h>
#include "genString.h"
#include "genListe.h"
#include "Person.h"

//Lese aus der Datei alle Vor- und alle Nachnamen, sowie geburts- ort und datum ein
void einlesen(int (*func)(void*,void*,int), int sort, char dateiName[])
{

	FILE *datei;

	char text[314+1];
	//�ffne das Textdokument (read only)
	datei = fopen (dateiName, "r");

	if (datei != NULL){

		//bekomme die Textzeile
		while(fgets(text, 314, datei)){

			//temp char[] um vorname und nachname auszulesen
			char vorname[100+1] = "";
			char nachname[100+1] = "";
			char datum[11] = "";
			char ort [100+1] = "";
			int i = 0;
			int j = 0;
			//kopiere vorname
			while(text[i] != ' '){
				vorname[i] = text[i];
				i++;
			}

			vorname[i] = '\0';
			//reserviere durch copyString neuen Speicherplatz
			char *vornameCopy = copyString(vorname);

            		i++;
			//kopiere nachname
			while(text[i] != ' '){
				nachname[j] = text[i];
				i++;
				j++;
			}
			nachname[j] = '\0';
			//reserviere durch copyString neuen Speicherplatz
			char *nachnameCopy = copyString(nachname);

			i++;
			j=0;
			//kopiert das datum
			for(j=0;j<=10;j++)
			{
			 datum[j] = text[i];
             		i++;
			}
			datum[11] = '\0';
			//reserviere durch copyString neuen Speicherplatz
			char *datumCopy = copyString(datum);

			j=0;
			//i++;
            		//kopiere ort
			while(text[i] != '\n'){
				ort[j] = text[i];
				i++;
				j++;
			}
			ort[j] = '\0';
			//reserviere durch copyString neuen Speicherplatz
			char *ortCopy = copyString(ort);

			void *object;
			object = createPerson(vornameCopy, nachnameCopy, datumCopy, ortCopy);

			//und f�ge diesen in die liste ein
			add(object, &(*func),sort);

		}

		//schlie�e die datei wieder
		fclose (datei);
	}
}

int main()
{
 //variablen f�r dateinname und sortierkriterium
 /*
 sortierkriterien:
 1=geburtsdatum
 2=vorname
 3=nachname
 4=ort
 */
 int x = 1;
 char datei[100];

 printf("Geben sie ien Sortierkriterium an:\n1=datum\n2=vorname\n3=nachname\n4=ort\n");
 scanf("%d",&x);

 printf("Geben sie die Datei an aus der ausgelesen erden soll.\n");
 scanf("%s",datei);

 //datei = "testdatei.txt";
 einlesen(&kleinerPerson, x, datei);

 printListe(&printPerson);

 loeschen(&deletePerson);

 printListe(&printPerson);
 return 1;
}
