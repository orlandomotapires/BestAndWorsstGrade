// Código feito por Antonio Horácio e Orlando Mota
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  FILE *arq;
  float maiorMedia=0, menorMedia = 10, media, notas;
  int  qntNotas=3, i, j=0, vetBytes[50];
  char nomeArq[50], registro[500], nomeMaior[500], nomeMenor[500], nome[500];
    printf("Digite o nome do arquivo : ");
    scanf(" %s", nomeArq);
    arq = fopen(nomeArq, "r+");
    while(fgets(registro, sizeof(registro), arq)){
      vetBytes[j++] = ftell(arq);
    } //Pular cabeçalho

     fseek(arq, vetBytes[5], SEEK_SET);
      while(!feof(arq)){ //Calculando as medias
        media = 0;
        fscanf(arq," %s", nome);
        for(i=0;i<qntNotas;i++){
          fscanf(arq," %f", &notas);
          media += notas;
        }
        media /= qntNotas;
        if(media > maiorMedia){
          maiorMedia = media;
          strcpy(nomeMaior,nome);
        }
        if(media < menorMedia){
          menorMedia = media;
          strcpy(nomeMenor,nome);
        }
      }

    fseek(arq, vetBytes[1], SEEK_SET);  //Substituir as frases adequadas
    sprintf(registro, "O aluno que apresenta o maior desempenho eh: %s com media igual a: %.1f\n", nomeMaior, maiorMedia);
    fputs(registro, arq);
    sprintf(registro, "O aluno que apresenta o menor desempenho eh: %s com media igual a: %.1f", nomeMenor, menorMedia);
    fputs(registro, arq);

    rewind(arq);
    while(fgets(registro, sizeof(registro), arq)){ //Printar tudo em tela
      printf("%s", registro);
    }

  fclose(arq);
  return 0;
}