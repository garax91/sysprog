#ifndef _Brett
#define _Brett

#include <stdlib.h>
#include <stdio.h>


struct t_brett {

	int **felder;
	int curPosX;
	int curPosY;
	int moveCounter;
	int size;
};


int neuer_sprung(struct t_brett *b, int x, int y);

int entferne_sprung(struct t_brett *b, int x, int y);

int frei(struct t_brett *b, int x, int y);

int besuchte_felder(struct t_brett *b);

void print(struct t_brett *b);

int init_brett(struct t_brett *b, int n, int x, int y);

void loesche_brett(struct t_brett *b);

#endif
