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

 //geht die listenelmente sucksesive durch und l�scht sie
 temp2 = head;
 temp = head;

 while(temp2 != NULL)
 {
  temp = temp2;
  temp2 = temp->next;

  //l�scht die einzelnene chars im listenelement
  (*func)(temp->object);
  //l�scht das listenelement selber
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

    //Variable f�r wahrheitswerte
    int a;

 //vergleichen ob das aktuell einzuf�genede elment kleiner oder gr��er als der head ist
    a = (*func)(neu->object,head->object,sort);
    //b = gleich(&gleichOrt, neu->ort,head->ort);

    //f�gt das neue element als head ein falls dieses kleiner ist als der bishheringe head
    if(a==1)
    {
     neu->next = head;
     head = neu;
     return;
    }

    //geht die liste mit hielfe von temp durch um das element zu finden nach dem eingef�gt werden muss
    else
    {
     temp = head;

     while(temp->next != NULL)
     {
      a = (*func)(neu->object,temp->next->object,sort);
      //b = gleich(&gleichOrt, neu->ort,temp->next->ort);

      //verl�sst die schleife falls das nache element gr��er w�re als das aktuelle nach nachname
      if(a==1)
      {
          break;
      }

      temp = temp->next;
     }

     //nun ist in temp das listenelement gespeichert nach dem neu eingef�gt werden muss
     neu->next = temp->next;
     temp->next = neu;
    }


 return;
}
