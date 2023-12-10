#include <dirent.h>
#include "library.h"

#define FOLDER "./oncotex_pgm"
 
int main(int argc, char *argv[]){
  int numFilter;
	clock_t begin, end;
	double time_per_img, time_total=0;

  if(argc != 2) {
    puts("Use: ./<nomeDoArquivo> <filtro>\n");
    exit(1);
  }
  numFilter = atoi(argv[1]);
  printf("numFilter: %d\n" , numFilter);
  
  DIR *d;
  struct dirent *dir;
  d = opendir(FOLDER);

  FILE *fp;

  //Abre um arquivo pra ordem dos arquivos lidos
  if (!(fp = fopen("matrixOrder.txt","a+"))){
		perror("Erro.");
		exit(2);
	}

  if (d){

    //Menu quantização
    int level = menu();
    printf("Nivel: %d\n\n", level);
    
    
    while (((dir = readdir(d)) != NULL)){

      // Ignorar os diretórios "." e ".."
      if (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name,"..")){
        continue;
      }

      if(strstr(dir->d_name,"mean")){
        continue;
      }

      // Iniciar medição do tempo.
      begin = clock();

      struct pgm img1, img2;

      // Leitura da Imagem -PGM
      readPGMImage(&img1,FOLDER,dir->d_name);
      
      // Quantização da Imagem -PGM
      quantize(&img1,level);
      
      // dir = readdir(d); // Próximo arquivo


      for(int i=0;i<strlen(dir->d_name);i++){
        if(dir->d_name[i] == '.') {
          dir->d_name[i]='\0';
          fprintf(fp, "%s\n", dir->d_name);
        }
      }

      strcat(dir->d_name,"_mean.pgm");
      
      // Leitura da Imagem suavizada -PGM
      readPGMImage(&img2,FOLDER,dir->d_name);
      
      // Quantização da Imagem suavizada -PGM
      quantize(&img2,level);

      // Filtrar a imagem 
      filterMatriz(&img2, numFilter);
      
      // Saida - Salvar matriz vetorizada no arquivo de características com o rotulo no final
      SCM(&img1, &img2, dir->d_name, level);
      

      // Finalizar medição do tempo.
      end = clock();

      // Acumular tempo
      time_per_img = (double)(end - begin) / CLOCKS_PER_SEC;
		  time_total += time_per_img;
    }
    fclose(fp);
    closedir(d);
    
    // Mostrar tempo de execução
    printf("Tempo Total: %lf\n",time_total);
  }

  return(0);
}
