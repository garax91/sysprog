#include "genString.h"

//gibt die Länge des *str aus
int length(char *str)
{
	if(str == NULL)
	{
		// return fehler -1, falls str == NULL
		return -1;
	}

	//zähle die zeichen bis '\0'
	int length;
		for (length = 0; *str != '\0'; str++)
		{
			length++;
		}
	return(length);
}

// reserviere neuen Speicherplatz und kopiere den String dort hin
char* copyString(const char *str)
{
	//neuer Speicherplatz reserviert
	char *newString = (char*) malloc (100 + 1);
	int i = 0;
	//String kopieren
	while(str[i] != '\0'){
		newString[i] = str[i];
		i++;
	}
	newString[i] = '\0';
	//neuen Pointer zurückgeben
	return newString;
}


//Lese aus der Datei alle Vor- und alle Nachnamen, sowie geburts- ort und datum ein
/*void einlesen(int sort)
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
			i++;
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


int gleichDatum(char *datum1, char *datum2)
{

}

int gleichNachname(char *name1, char *name2)
{

}
int gleichVorname(char *name1, char *name2)
{

}
int gleichOrt(char *ort1, char *ort2)
{

}


int kleinerDatum(char *datum1, char *datum2)
{
 //zählervariable zum durchgehen der chars;
 int x;

 //vergleicht das jahr
 for(x=6;x<10;x++)
 {
  if(datum1[x]>datum2[x])
  {
    return 0;
  }

  if(datum1[x]<datum2[x])
  {
   return 1;
  }
 }

 //vergleicht den monat
 for(x=3;x<5;x++)
 {
  if(datum1[x]>datum2[x])
  {
    return 0;
  }

  if(datum1[x]<datum2[x])
  {
   return 1;
  }
 }

 //vergleicht den tag
 for(x=0;x<2;x++)
 {
  if(datum1[x]>datum2[x])
  {
    return 0;
  }

  if(datum1[x]<datum2[x])
  {
   return 1;
  }
 }

 //gibt 0 zurück da datum1<datum2 nicht gilt
 return 0;
}

int kleinerNachname(char *name1, char* name2)
{
 //zählervariable zum durchlaufen er chars
 int x = 0;

 //vergleicht die beiden namen
 while((name1[x]!='\0') && (name2[x]!='\0'))
 {
  if(name1[x]>name2[x])
  {
   return 0;
  }
  else if(name1[x]<name2[x])
  {
   return 1;
  }
  x++;
 }

 //gibt 1 zurück falls name2 länger ist als name1
 if(name2[x]!='\0')
 {
  return 1;
 }

 //gibt null zurück da name1<name2 nicht gilt
 return 0;
}

int kleinerVorname(char *name1, char *name2)
{
 //zählervariable zum durchlaufen er chars
 int x = 0;

 //vergleicht die beiden namen
 while((name1[x]!='\0') && (name2[x]!='\0'))
 {
  if(name1[x]>name2[x])
  {
   return 0;
  }
  else if(name1[x]<name2[x])
  {
   return 1;
  }
  x++;
 }

 //gibt 1 zurück falls name2 länger ist als name1
 if(name2[x]!='\0')
 {
  return 1;
 }

 //gibt null zurück da name1<name2 nicht gilt
 return 0;
}

int kleinerOrt(char *ort1, char *ort2)
{
 //zählervariable zum durchlaufen er chars
 int x = 0;

 //vergleicht die beiden orte
 while((ort1[x]!='\0') && (ort2[x]!='\0'))
 {
  if(ort1[x]>ort2[x])
  {
   return 0;
  }

  else if(ort1[x]<ort2[x])
  {
   return 1;
  }
  x++;
 }

 //gibt 1 zurück falls ort2 länger ist als ort1
 if(ort2[x]!='\0')
 {
  return 1;
 }

 //gibt null zurück da ort1<ort2 nicht gilt
 return 0;
}

int gleich(int (*func1)(char* , char*),char *name1, char *name2)
{
 int result = (*func1)(name1,name2);
 return result;
}

int kleiner(int (*func2)(char *, char*),char *name1, char *name2)
{
 int result = (*func2)(name1,name2);
 return result;
}
*/

