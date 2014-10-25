#include "brett.h"

int neuer_sprung(struct t_brett *b, int x, int y)
{
	//increase moveCounter
	b->moveCounter++;

	//update the current position
	b->curPosX = b->curPosX + x;
	b->curPosY = b->curPosY + y;
	
	//write moveCounter in field
	b->felder[b->curPosX][b->curPosY] = b->moveCounter;
	
	return 0;
}

int entferne_sprung(struct t_brett *b, int x, int y)
{
	//reset moveCoutner
	b->moveCounter--;

	//reset field
	b->felder[b->curPosX][b->curPosY] = 0;

	//update the current position
	b->curPosX = b->curPosX - x;
	b->curPosY = b->curPosY - y;

	return 0;
}

int frei(struct t_brett *b, int x, int y)
{
	//berechne wohin der springer springen möchte
	int newX = b->curPosX + x;
	int newY = b->curPosY + y;

	//coordinaten sind außerhalb des feldes
	if(newX < 0 || newX > b->size -1)
	{
		return 0;
	}
	if(newY < 0 || newY > b->size -1)
	{
		return 0;
	}

	//check ob feld schon besucht wurden ist
	if(b->felder[newX][newY] == 0)
	{
		return 1;
	}

	return 0;

}

int besuchte_felder(struct t_brett *b)
{
	//return moveCounter
	return b->moveCounter;
}

void printLineSeperator(struct t_brett *b)
{
	//newLine
	int j;
	for(j = 0; j < b->size; j++)
	{
		printf("+---");
	}
	printf("+\n");
}

void print(struct t_brett *b)
{
	int i, j;
	for(i = 0; i < b->size; i++)
	{
		printLineSeperator(b);
		for(j = 0; j < b->size; j++)
		{
			printf("+%3i", b->felder[i][j]);
		}
		printf("+\n");
	}
	printLineSeperator(b);
}

int init_brett(struct t_brett *b, int n, int x, int y)
{
	//malloc genug speicher
	int i, j;
	b->felder = (int**) malloc (n*sizeof(int*));
	for(i = 0; i < n; i++)
	{
		b->felder[i] = (int*) malloc(n*sizeof(int));
	}

	//setze alle felder auf 0
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			b->felder[i][j] = 0;
		}
	}

	//setze startposition
	b->curPosX = x-1;
	b->curPosY = y-1;
 	b->size = n;
	b->moveCounter = 1;
	b->felder[b->curPosX][b->curPosY] = b->moveCounter;
	
	return 0;
}

void loesche_brett(struct t_brett *b)
{
	//free speicher
	int i;
	for(i = 0; i < b->size; i++)
	{
		free(b->felder[i]);
	}
	free(b->felder);
}
