#include "meinString.h"

//vergleicht zwei eingegebene chars nach alphabetischer reihenfolge
int kleiner(char *name1, char *name2)
{

 //initalisiert den z�hler
 int a = 0;

 //geht mit einer schleife buchstabenweise die beiden chars durch zum vegleichen
 while((name1[a]!='\0') && (name2[a])!='\0')
 {
     //gibt 1 zur�ck falls der erste char kleiner ist al der zweite
     if(name1[a]<name2[a])
     {
      return 1;
     }

     //gibt 0 zur�ck fall der erste char gr��er ist als der zweite
     if(name1[a]>name2[a])
     {
     return 0;
     }

     a++;
 }

 //gibt 1 zur�ck falls der erste char k�rzer ist als der zweite
 if(name1[a]!='\0')
 {
  return 1;
 }

 //gibt 0 zur�ck falls der erste char l�nger ist als der zweite
  return 0;
}

//pr�ft zwei gegebene chars auf gleichheit
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

//gibt die L�nge des *str aus
int length(char *str)
{
	if(str == NULL)
	{
		// return fehler -1, falls str == NULL
		return -1;
	}
		
	//z�hle die zeichen bis '\0'
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
	//neuen Pointer zur�ckgeben
	return newString;
}
