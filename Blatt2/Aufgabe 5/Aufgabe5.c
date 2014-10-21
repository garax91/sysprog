#include <stdio.h>
#include <stdlib.h>
#include "genListe.h"
#include "genString.h"

//Lese aus der Datei alle Vor- und alle Nachnamen, sowie geburts- ort und datum ein
void einlesen(int sort)
{

	FILE *datei;

	char text[314+1];
	//öffne das Textdokument (read only)
	datei = fopen ("testdatei.txt", "r");

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

            i++;
			//kopiere nachname
			while(text[i] != ' '){
				nachname[j] = text[i];
				i++;
				j++;
			}
			nachname[j] = '\0';

			i++;
			j=0;
			//kopiert das datum
			for(j=0;j<=10;j++)
			{
			 datum[j] = text[i];
             i++;
			}
			datum[11] = '\0';

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
			char *vornameCopy = copyString(vorname);
			char *nachnameCopy = copyString(nachname);
			char *datumCopy = copyString(datum);
			char *ortCopy = copyString(ort);
			//und füge diesen in die liste ein
			hinzufuegen(vornameCopy, nachnameCopy, datumCopy, ortCopy, sort);

		}

		//schließe die datei wieder
		fclose (datei);
	}
}

int main(int argc, char *argv[])
{

 /*
 sort ist die variable die entscheide nach welchem kriterium sortiert wird.
 1 <= sortieren nach Datum
 2 <= sortieren nach nachnamen;
 3 <= sortieren nach vornamen;
 4 <= sortieren nach ort;
 */
 int sort = 4;

 /*char *datum1, *datum2, *vorname1, *vorname2, *nachname1, *nachname2, *ort1, *ort2;

 datum1 = "28 10 1993";
 vorname1 = "Holger";
 nachname1 = "Neuhaus";
 ort1 = "Bonn";

 datum2 = "27 10 1991";
 vorname2 = "Jens";
 nachname2 = "Harder";
 ort2 = "Koeln";

 hinzufuegen(vorname1,nachname1,datum1,ort1,sort);
 hinzufuegen(vorname2,nachname2,datum2,ort2,sort);
 */

 einlesen(sort);

 //loeschen();

 ausgabe();

 return 0;
}
