/*Aluno: Luan Silva Mascarenhas
Matricula: 00000000000
Aluno: Isaac Nycolas
Matricula: 00000000000
Aluno: Breno Pinheiro
Matricula: 00000000000
Avaliação 04: Trabalho Final
Compilador: gcc Versão: version 6.3.0 (MinGW.org GCC-6.3.0-1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct pgm
{
	int tipo;
	int c;
	int r;
	int mv;
	unsigned char *pData;
};

int menu();
void readPGMImage(struct pgm *, char *, char *);
void quantize(struct pgm *, int);
void SCM(struct pgm *, struct pgm *, char *, int);