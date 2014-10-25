#include <stdio.h>
#include <stdlib.h>

#include "mymatrix.h"


struct matrix *matrixA;
struct matrix *matrixB;
struct matrix *matrixResult;



int writeFile(struct matrix *matrixWrite)
{
	FILE *datei;

	//öffne das Textdokument (write only)
	datei = fopen ("zahlen.txt", "w");

	if(datei == NULL)
	{
		printf("file error");
		return 1;
	}

	int i = 0;
	int j = 0;
	while (i < matrixWrite->sizeN)
	{
		j = 0;
		while (j < matrixWrite->sizeM)
		{
			fprintf(datei, "%i ", matrixWrite->felder[i][j]);
			j++;
		}
		i++;
		fprintf(datei, "\n");
	}
	fclose(datei);
	return 0;
}

int main(int argc, char* argv[])
{
/*	int i = 0;
	while(i < argc)
	{
		printf("Argument %d:  %s\n", i, argv[i]);
		i++;
	}
	printf("argc : %d\n", argc);
*/
/*

	int n = 4;
	int m = 5;

	if(argc >= 3)
	{
		n = atoi(argv[1]);
		m = atoi(argv[2]);
	}
	else
	{
		printf("no arguments.... default : n  = %d, m = %d\n", n, m);
	}


printf("n : %d\n", n);
printf("m : %d\n", m);

printf("starting alloc\n");
	allocMatrix(n, m);
printf("starting generate\n");
	generateMatrix(n, m, 100);
printf("starting print\n");
	printMatrix(n, m);
printf("starting fileWriting\n");
	writeFile(n, m);
printf("starting free\n");
	freeMatrix(n, m);
*/

matrixA = allocMatrix(7, 4);
matrixB = allocMatrix(5, 3);

generateMatrix(matrixA, 10);
generateMatrix(matrixB, 10);

printf("Matrix A:\n");
printMatrix(matrixA);
printf("Matrix B:\n");
printMatrix(matrixB);
printf("Matrix RESULT (addition) :\n");
struct matrix *matrixResultAdd= add(matrixA, matrixB);
printMatrix(matrixResultAdd);
printf("Matrix RESULT (multiplikation) :\n");
struct matrix *matrixResultMult= mult(matrixA, matrixB);
printMatrix(matrixResultMult);

//riteFile(matrixResult);

freeMatrix(matrixA);
freeMatrix(matrixB);
freeMatrix(matrixResultAdd);
freeMatrix(matrixResultMult);

return 0;
}
