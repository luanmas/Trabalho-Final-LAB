#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct pgm{
	int tipo; // 8 ou 16
	int c;
	int r;
	int mv;
	unsigned char *pData;
};

int menu();
void filterMatriz(struct pgm *, int);
void generateMatrix(int *, struct pgm *, struct pgm *, int);
void readPGMImage(struct pgm *, char *, char *);
void quantize(struct pgm *, int);
void SCM(struct pgm *, struct pgm *, char *, int);
