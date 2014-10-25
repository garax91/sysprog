#include "mymatrix.h"


struct matrix* add(struct matrix *matrixA, struct matrix *matrixB)
{
	if(matrixA->sizeN != matrixB->sizeN
		|| matrixA->sizeM != matrixB->sizeM)
	{
		printf("Matrixen nicht kompatiebel");
		return NULL;
	}

	int n = matrixA->sizeN;
	int m = matrixA->sizeM;

	
	struct matrix *matrixResult = allocMatrix(n, m);

	int i = 0;
	int j = 0;

	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			matrixResult->felder[i][j] = matrixA->felder[i][j] + matrixB->felder[i][j];
			j++;
		}
		i++;
	}

	return matrixResult;	
}

void generateMatrix(struct matrix *matrixGenerate, int randomArea)
{
	int i = 0;
	int j = 0;
	srand(time(NULL));

	while (i < matrixGenerate->sizeN)
	{
		j = 0;
		while (j < matrixGenerate->sizeM)
		{
			matrixGenerate->felder[i][j] = (rand() % randomArea) - randomArea/2;
			j++;
		}
		i++;
	}
}

void printLineSeperator(int m)
{
	//newLine
	int j = 0;
	while (j < m)
	{
		printf("----");
		j++;
	}
	printf("-\n");
}

void printMatrix(struct matrix *matrixPrint)
{
	int i = 0;
	int j = 0;
	while (i < matrixPrint->sizeN)
	{
		printLineSeperator(matrixPrint->sizeM);
		j = 0;
		while (j < matrixPrint->sizeM)
		{
			printf("|%3i", matrixPrint->felder[i][j]);
			j++;
		}
		printf("|\n");
		i++;
	}
	printLineSeperator(matrixPrint->sizeM);
}

struct matrix* allocMatrix(int n, int m)
{
	struct matrix *newMatrix = (struct matrix*) malloc (sizeof(struct matrix));	

	newMatrix->felder = (int**) malloc (n*sizeof(int*));
	int i = 0;
	while (i < n)
	{
		newMatrix->felder[i] = (int*) malloc(m*sizeof(int));
		i++;
	}

	newMatrix->sizeN = n;
	newMatrix->sizeM = m;
	return newMatrix;
}

void freeMatrix(struct matrix *matrixDelete)
{
	//free speicher
	int i = 0;
	while(i < matrixDelete->sizeN)
	{
		free(matrixDelete->felder[i]);
		i++;
	}
	free(matrixDelete->felder);
	free(matrixDelete);
}
