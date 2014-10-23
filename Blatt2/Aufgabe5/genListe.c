#include "genListe.h"

struct node
{
  struct node *next;
  void *object;
};

struct node *head = NULL;
struct node *temp, *temp2;

void printListe(void (*func)(void*))
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
        (*func)(temp->object);
        temp = temp->next;
    }

    return;
}

void loeschen(void(*func)(void*))
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
  (*func)(temp->object);
  //löscht das listenelement selber
  free(temp);
 }

 head = NULL;
 return;
}

void add(void *object, int (*func)(void*,void*,int),int sort)
{
    struct node *neu = (struct node*)malloc(sizeof(struct node));
    neu->next = NULL;
    neu->object = object;

    if(head == NULL)
    {
     head = neu;
     return;
    }

    //Variable für wahrheitswerte
    int a;

 //vergleichen ob das aktuell einzufügenede elment kleiner oder größer als der head ist
    a = (*func)(neu->object,head->object,sort);
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
      a = (*func)(neu->object,temp->next->object,sort);
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


 return;
}
