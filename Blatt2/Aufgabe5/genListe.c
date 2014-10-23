#include "genListe.h"

//deffinition des Listenelementes
struct node
{
  struct node *next;
  char *vorname;
  char *nachname;
  char *datum;
  char *ort;
};

//setzt den listenkopf inizial auf NULL
struct node *head = NULL;

//definiert temporäre elemente für listendurchläufe
struct node *temp, *temp2;

//fügt ein element mit gegebene parametern hinzu
void hinzufuegen(char *vorname, char *nachname, char *datum, char *ort, int sort)
{
 //variablen für wahrheitswerte
 int a,b;

 //erstellen einenes neuen listenelemente
 struct node *neu = (struct node*)malloc(sizeof(struct node));
 neu->next = NULL;
 neu->vorname = vorname;
 neu->nachname = nachname;
 neu->datum = datum;
 neu->ort = ort;

 if(head == NULL)
 {
  head = neu;
  return;
 }

 //sortiert nach geburtstadtum
 if(sort == 1)
 {
  //vergleichen ob das aktuell einzufügenede elment kleiner oder größer als der head ist
    a = kleiner(&kleinerDatum, neu->datum,head->datum);
    //b = gleich(&gleichDatum, neu->datum,head->datum);

    //fügt das neue element als head ein falls dieses kleiner ist als der bishheringe head
    if(a==1)
    {
     neu->next = head;
     head = neu;
     return;
    }

    //geht die liste mit hielfe von temp durch um das element zu finden nach dem eingefügt werden muss
    else
    {
     temp = head;

     while(temp->next != NULL)
     {
      a = kleiner(&kleinerDatum, neu->datum,temp->next->datum);
      //b = gleich(&gleichDatum, neu->datum,temp->next->datum);

      //verlässt die schleife falls das nache element größer wäre als das aktuelle nach nachname
      if(a==1)
      {
          break;
      }

      temp = temp->next;
     }

     //nun ist in temp das listenelement gespeichert nach dem neu eingefügt werden muss
     neu->next = temp->next;
     temp->next = neu;
    }
 }

 //sortiert nach nachnamen
 else if(sort == 2)
 {
  //vergleichen ob das aktuell einzufügenede elment kleiner oder größer als der head ist
    a = kleiner(&kleinerNachname, neu->nachname,head->nachname);
    //b = gleich(&gleichNachname, neu->datum,head->nachname);

    //fügt das neue element als head ein falls dieses kleiner ist als der bishheringe head
    if(a==1)
    {
     neu->next = head;
     head = neu;
     return;
    }

    //geht die liste mit hielfe von temp durch um das element zu finden nach dem eingefügt werden muss
    else
    {
     temp = head;

     while(temp->next != NULL)
     {
      a = kleiner(&kleinerNachname, neu->nachname,temp->next->nachname);
      //b = gleich(&gleichNachname, neu->nachname,temp->next->nachname);

      //verlässt die schleife falls das nache element größer wäre als das aktuelle nach nachname
      if(a==1)
      {
          break;
      }

      temp = temp->next;
     }

     //nun ist in temp das listenelement gespeichert nach dem neu eingefügt werden muss
     neu->next = temp->next;
     temp->next = neu;
    }
 }

 //sortiert nach vornamen
 else if(sort == 3)
 {
  //vergleichen ob das aktuell einzufügenede elment kleiner oder größer als der head ist
    a = kleiner(&kleinerVorname, neu->vorname,head->vorname);
    //b = gleich(&gleichVorname, neu->vorname,head->vorname);

    //fügt das neue element als head ein falls dieses kleiner ist als der bishheringe head
    if(a==1)
    {
     neu->next = head;
     head = neu;
     return;
    }

    //geht die liste mit hielfe von temp durch um das element zu finden nach dem eingefügt werden muss
    else
    {
     temp = head;

     while(temp->next != NULL)
     {
      a = kleiner(&kleinerVorname, neu->vorname,temp->next->vorname);
      //b = gleich(&gleichVorname,neu->vorname,temp->next->vorname);

      //verlässt die schleife falls das nache element größer wäre als das aktuelle nach nachname
      if(a==1)
      {
          break;
      }

      temp = temp->next;
     }

     //nun ist in temp das listenelement gespeichert nach dem neu eingefügt werden muss
     neu->next = temp->next;
     temp->next = neu;
    }
 }

 //sortiert nach ort
 else if(sort == 4)
 {
  //vergleichen ob das aktuell einzufügenede elment kleiner oder größer als der head ist
    a = kleiner(&kleinerOrt, neu->ort,head->ort);
    //b = gleich(&gleichOrt, neu->ort,head->ort);

    //fügt das neue element als head ein falls dieses kleiner ist als der bishheringe head
    if(a==1)
    {
     neu->next = head;
     head = neu;
     return;
    }

    //geht die liste mit hielfe von temp durch um das element zu finden nach dem eingefügt werden muss
    else
    {
     temp = head;

     while(temp->next != NULL)
     {
      a = kleiner(&kleinerOrt, neu->ort,temp->next->ort);
      //b = gleich(&gleichOrt, neu->ort,temp->next->ort);

      //verlässt die schleife falls das nache element größer wäre als das aktuelle nach nachname
      if(a==1)
      {
          break;
      }

      temp = temp->next;
     }

     //nun ist in temp das listenelement gespeichert nach dem neu eingefügt werden muss
     neu->next = temp->next;
     temp->next = neu;
    }
 }

 return;
}

void loeschen()
{
 //returnd falls die liste leer ist
 if(head == NULL)
 {
  return;
 }

 //geht die listenelmente sucksesive durch und löscht sie
 temp2 = head;
 temp = head;

 while(temp2 != NULL)
 {
  temp = temp2;
  temp2 = temp->next;

  //löscht die einzelnene chars im listenelement
  free(temp->nachname);
  free(temp->vorname);
  free(temp->datum);
  free(temp->ort);
  //löscht das listenelement selber
  free(temp);
 }

 head = NULL;
 return;
}

void ausgabe()
{
   if(head == NULL)
    {
     printf("die liste ist leer");
     return;
    }

    temp = head;

    //schleife um die liste zu durchlaufen
    while(temp != NULL)
    {
        //gibt den vornamen aus des aktuellen elementes
        printf("%s",temp->vorname);

        printf(" ");

        //gibt den nachnamen des aktuellen elmentes aus
        printf("%s",temp->nachname);

        printf(" ");

        //gibt das datum des aktuellen elemntes aus
        printf("%s",temp->datum);

        printf(" ");

        //gibt den ort des aktuellen elementes aus
        printf("%s",temp->ort);

        printf("\n");

        temp = temp->next;
    }

    return;
}
