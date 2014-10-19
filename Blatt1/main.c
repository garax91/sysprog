#include <stdio.h>
#include "liste.h"
#include "meinString.h"

//Lese aus der Datei alle Vor- und alle Nachnamen ein
void einlesen()
{
	
	FILE *datei;

	char text[200+1];
	//öffne das Textdokument (read only)
	datei = fopen ("testdatei.txt", "r");
	
	if (datei != NULL){
		
		//bekomme die Textzeile
		while(fgets(text, 200, datei)){
			
			//temp char[] um vorname und nachname auszulesen
			char vorname[100+1] = "";
			char nachname[100+1] = "";
	
			int i = 0;
			int j = 0;
			//kopiere vorname
			while(text[i] != ' '){
				vorname[i] = text[i];
				i++;
			}
			vorname[i] = '\0';
			//kopiere nachname
			while(text[i] != '\n'){
				nachname[j] = text[i];
				i++;
				j++;
			}
			nachname[j] = '\0';
				
			//reserviere durch copyString neuen Speicherplatz
			char* vornameCopy = copyString(vorname);
			char* nachnameCopy = copyString(nachname);
			//und füge diesen in die liste ein
			hinzufuegen(vornameCopy, nachnameCopy);
			
		}
		
		//schließe die datei wieder
		fclose (datei);
	}
}

int main()
{

	einlesen();
		
	ausgabe();
	
	printf("#######\n");
	loeschen();
	ausgabe();
	
    return 0;

}
