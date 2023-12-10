//Realiza a quantização da imagem

#include "library.h"

void quantize(struct pgm *img, int level){
  
  int quant = (img->mv+1) / level; // 8 ou 16
  int start, end, count=0; // começa em 0 e termina em level-1
  int inter = quant;
  
   puts("Quantizando Imagem PGM");
   while (inter <= img->mv+1){
     start = inter - quant; // 0
     end = inter-1; // 255
     
  // Compara os dados e transforma os que entram no intervalo dos níveis
    for (int k=0; k < (img->r * img->c); k++){
      if ((*(img->pData+k) >= start) && (*(img->pData+k) <= end)){
        *(img->pData+k) = count; // +1
	    }
    } 

    count++;
    inter += quant;
  }

}
