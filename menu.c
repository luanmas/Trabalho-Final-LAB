#include "library.h"

int menu(){
  int op;
  
  puts("\nQuantizar imagens em:\n");
  puts("\t(1) 8 níveis");
  puts("\t(2) 16 níveis");
  printf("\nOpção: ");
  scanf("%d",&op);
  puts("");

  switch(op){
    case 1:
      return 8;
    case 2:
      return 16;
    default:
      puts("Opção Inválida!");
      exit(1);
  }
}
