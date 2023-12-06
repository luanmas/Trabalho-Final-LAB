/*Aluno: Mikaelle Costa dos Santos
Matricula: 20221045050311
Aluno: Ana Flávia Torres do Carmo
Matricula: 20221045050427
Aluno: Isabelly Pinheiro da Costa
Matricula: 20221045050460
Aluno: Larissa do Nascimento Vieira
Matricula: 20202045050412
Avaliação 04: Trabalho Final
04.505.23 - 2022.2 - Prof. Daniel Ferreira
Compilador: gcc Versão: version 6.3.0 (MinGW.org GCC-6.3.0-1)
*/

#include "library.h"

int menu()
{
  int op;

  puts("\nQuantizar imagens em:\n");
  puts("\t(1) 8 níveis");
  puts("\t(2) 16 níveis");
  printf("\nOpção: ");
  scanf("%d", &op);
  puts("");

  switch (op)
  {
  case 1:
    return 8;
    break;
  case 2:
    return 16;
    break;
  default:
    puts("Opção Inválida!");
    exit(1);
  }
}