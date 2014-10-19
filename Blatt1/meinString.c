#include "meinString.h"

//vergleicht zwei eingegebene chars nach alphabetischer reihenfolge
int kleiner(char *name1, char *name2)
{

 //initalisiert den zähler
 int a = 0;

 //geht mit einer schleife buchstabenweise die beiden chars durch zum vegleichen
 while((name1[a]!='\0') && (name2[a])!='\0')
 {
     //gibt 1 zurück falls der erste char kleiner ist al der zweite
     if(name1[a]<name2[a])
     {
      return 1;
     }

     //gibt 0 zurück fall der erste char größer ist als der zweite
     if(name1[a]>name2[a])
     {
     return 0;
     }

     a++;
 }

 //gibt 1 zurück falls der erste char kürzer ist als der zweite
 if(name1[a]!='\0')
 {
  return 1;
 }

 //gibt 0 zurück falls der erste char länger ist als der zweite
  return 0;
}

//prüft zwei gegebene chars auf gleichheit
int gleich(char *name1, char *name2)
{
 int a = 0;
 do
 {
 if(name1[a] != name2[a])
    {
     return 0;
    }
    a++;
 }
 while((name1[a] != '\0') && (name2[a] != '\0'));

 return 1;
}

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
	char *newString = malloc (100 + 1); 
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
