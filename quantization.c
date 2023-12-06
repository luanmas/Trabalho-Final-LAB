/*Aluno: Luan Silva Mascarenhas
Matricula: 00000000000
Aluno: Isaac Nycolas
Matricula: 00000000000
Aluno: Breno Pinheiro
Matricula: 00000000000
Avaliação 04: Trabalho Final
Compilador: gcc Versão: version 6.3.0 (MinGW.org GCC-6.3.0-1)
*/

// Realiza a quantização da imagem

#include "library.h"

void quantize(struct pgm *img, int level)
{

  int quant = (img->mv + 1) / level;
  int start, end, count = 0; // começa em 0 e termina em level-1
  int inter = quant;

  puts("Quantizando Imagem PGM");
  while (inter <= img->mv + 1)
  {
    start = inter - quant;
    end = inter - 1;

    // Compara os dados e transforma os que entram no intervalo dos níveis
    for (int k = 0; k < (img->r * img->c); k++)
    {
      if ((*(img->pData + k) >= start) && (*(img->pData + k) <= end))
      {
        *(img->pData + k) = count;
      }
    }
    count++;
    inter += quant;
  }
}
