#ifndef _myMatrix
#define _myMatrix

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct matrix {

	int **felder;
	int sizeN;
	int sizeM;
};

struct matrix* add(struct matrix *matrixA, struct matrix *matrixB);
struct matrix* allocMatrix(int n, int m);
void freeMatrix(struct matrix *matrixDelete);
void generateMatrix(struct matrix *matrixGenerate, int randomArea);
void printMatrix(struct matrix *matrixPrint);

#endif
