#include "library.h"

void generateMatrix(int *matrix, struct pgm *img1, struct pgm *img2, int level);


void filterMatriz(struct pgm *img, int numfilter) {
    int sum = 0;
    int average = 0;
    int *filteredData = malloc(img->r * img->c * sizeof(int));

    if (filteredData == NULL) {
        // Tratar erro de alocação de memória, se necessário
        exit(1);
    }

    for (int i = 0; i < img->r; i++) {
        for (int j = 0; j < img->c; j++) {
            // Aplicar o filtro apropriado, dependendo do valor de numfilter
            // Por exemplo, se numfilter for 1, pode ser uma média simples dos pixels ao redor
            // Se numfilter for 2, pode ser outro tipo de filtro, etc.

            // Aqui, por exemplo, apenas uma média simples dos pixels vizinhos
            sum = 0;
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < img->r && y >= 0 && y < img->c) {
                        sum += img->pData[x * img->c + y];
                    }
                }
            }
            average = sum / (numfilter * numfilter);// Para um filtro 3x3, onde 9 é o número total de pixels na vizinhança

            // Armazenar o resultado na matriz filtrada
            filteredData[i * img->c + j] = average;
        }
    }

    // Atualizar os dados da imagem com os dados filtrados
    free(img->pData);
    img->pData = filteredData;
}


// Criação do arquivo SCM
void SCM(struct pgm *img1, struct pgm *img2, char *filename, int level){
  int *matrix=NULL;
  
  if(!(matrix = calloc(level*level,sizeof(int)))){
    puts("Memória Insuficiente");
    exit(3);
  }

  generateMatrix(matrix, img1, img2, level);

  FILE *fp;

  char archiveName[20];
  sprintf(archiveName, "SCM_%d.txt", level);

  fp = fopen(archiveName,"a+");

  if(fp==NULL){
    puts("Erro ao abrir o arquivo");
    exit(1);
  }

  for(int i=0; i<level*level; i++){
    fprintf(fp, "%d, ", *(matrix+i));
  }
  
  fprintf(fp,"%c", *filename);
  fputc('\n', fp);

  fclose(fp);
  
}

// Calculo do SCM
void generateMatrix(int *matrix, struct pgm *img1, struct pgm *img2, int level){
  int elem=0;
  
  for(int i=0; i<(img1->c*img1->r); i++){
    elem = (int)(*(img1->pData+i)*level + *(img2->pData+i));
    *(matrix+elem)+=1;
  }
  // img1 3
  // img2 4
  // level = 8

  puts("Matriz computada!\n");
}
