#include "liste.h"

//definition des listenelementes
struct node
{
  struct node *next;
  char *vorname;
  char *nachname;
};

//setzt den listenanfang auf NULL, damit die liste am anfang leer ist
struct node *head = NULL;

//temporäres listenelement zum durchlaufen der liste
struct node *temp, *temp2;

//bekommt einen nach und einen vornamen übergeben um eine neues element sortiert in die lieste einzufügen
void hinzufuegen(char *vorname, char *nachname)
{
    //variablen um wahrheitswerte zu speichern
    int a,b;

    //erstellen eines neuen listenelementes
    struct node *neu = (struct node*)malloc(sizeof(struct node));
    neu->next = NULL;
    neu->vorname = vorname;
    neu->nachname = nachname;

    //überprüfung ob die liste leer ist und gegebene falls erstellen
    if(head == NULL)
    {
     head = neu;
     return;
    }

    //vergleichen ob das aktuell einzufügenede elment kleiner oder größer als der head ist
    a = kleiner(neu->nachname,head->nachname);
    b = gleich(neu->nachname,head->nachname);

    //fügt das neue element als head ein falls dieses kleiner ist als der bishheringe head
    if(a==1)
    {
     neu->next = head;
     head = neu;
     return;
    }

    //bearbeitet weiter falls die nachnamen gleich sind
    else if((b == 1) && (kleiner(neu->vorname,head->vorname) == 1))
    {
      neu->next = head;
      head = neu;
      return;
    }

    //geht die liste mit hielfe von temp durch um das element zu finden nach dem iengefügt werden muss
    else
    {
     temp = head;

     while(temp->next != NULL)
     {
      a = kleiner(neu->nachname,temp->next->nachname);
      b = gleich(neu->nachname,temp->next->nachname);

      //verlässt die schleife falls das nache element größer wäre als das aktuelle nach nachname
      if(a==1)
      {
          break;
      }

      //prüft ob die überprüften nachnamen gleich sind udn verfährt sonst mit vornamen
      else if(b==1)
      {
       a = kleiner(neu->vorname,temp->next->vorname);

       //verlässt die schleife falls nach vorname das nächste element größer wäre
       if(a==1)
       {
        break;
       }
      }

      temp = temp->next;
     }

     //nun ist in temp das listenelement gespeichert nach dem neu eingefügt werden muss
     neu->next = temp->next;
     temp->next = neu;
    }

 return;
}

//gibt jeden allocierten speicher wider frei
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

  free(temp->nachname);
  free(temp->vorname);
  free(temp);
 }

 head = NULL;
 return;
}

//gibt die namen in der liste nacheinader aus
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

        printf("\n");

        temp = temp->next;
    }

    return;
}
