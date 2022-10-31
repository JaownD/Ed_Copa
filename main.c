#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "PilhaDinamica.h"
#include "FilaDinamica.h"
#define MAX 31

int main(){
///Variaveis
    int quant_time, quant_pote, i, j, k, aux_pote, tam_def, aux_tam, tam_menor, aux, placar, aux_placar;
    char pais[MAX], aux_pais[MAX], pais_passou[MAX];
    char *retirado;
    char *aux_retirado;
    Fila *f = cria_fila();
    Fila *f_pos = cria_fila();
    Pilha *p_ranking = cria_pilha();

///Leitura
    scanf("%d %d", &quant_time, &quant_pote);

    Pilha **potes = (Pilha**)malloc(quant_pote*sizeof(Pilha*));

    for(i = 0; i < quant_pote; i++)
        potes[i] = cria_pilha();

    j = tam_def = 0;
    tam_menor = MAX;
    for(i = 0; i < quant_time; i++){
        if(j == quant_pote)
            j = 0;
        scanf("%s", pais);
        pushP(potes[j], pais);
        aux_tam = strlen(pais);
        if(aux_tam > tam_def)
            tam_def = aux_tam;
        if(aux_tam < tam_menor)
            tam_menor = aux_tam;
        j++;
    }

///Passando para a fila
    k = 0;
    for(i = 0; i < quant_time/2; i++){
        j = k + 1;
        if(j == quant_pote)
            j = 0;
        retirado = popP(potes[k]);
        aux_retirado = popP(potes[j]);
        k = j + 1;
        if(k == quant_pote)
            k = 0;
        pushF(f, retirado, aux_retirado);
        free(retirado);
        free(aux_retirado);
        retirado = aux_retirado = NULL;
    }

///Fila inicial
    retirado = malloc(31*sizeof(char));
    aux_retirado = malloc(31*sizeof(char));
    printf("\nFila inicial:\n");
    for(i = 0; i < quant_time/2; i++){
        popF(f, retirado, aux_retirado);
        pushF(f_pos, retirado, aux_retirado);
        aux_tam = strlen(retirado);
        aux = tam_menor + tam_def;
        while(aux != aux_tam){
            printf(" ");
            aux--;
        }
        printf("%s x %s\n", retirado, aux_retirado);
    }
    free(retirado);
    free(aux_retirado);

///Disputas
    srand(time(0));
    for(i = 0; i < quant_time/2; i++){
        if(i == ((quant_time/2) - 1))
            printf("\nGrande final: \n");
        else
            printf("\nDia %d: \n", i + 1);
        for(j = 0; j < 2; j++){
            popF(f_pos, retirado, aux_retirado);

            placar = rand() %8;
            aux_placar = rand() %8;
            while(placar == aux_placar){
                placar = rand() %8;
                aux_placar = rand() %8;
            }
            aux_tam = strlen(retirado);
            aux = tam_def;
            aux = tam_menor + tam_def;
            while(aux != aux_tam){
                printf(" ");
                aux--;
            }
            printf("%s %d x %d %s\n", retirado, placar, aux_placar, aux_retirado);
            strcpy(pais, retirado);
            strcpy(aux_pais, aux_retirado);
            if(i == ((quant_time/2) - 1)){
                if(placar > aux_placar){
                    pushP(p_ranking, aux_pais);
                    pushP(p_ranking, pais);
                }
                else{
                    pushP(p_ranking, pais);
                    pushP(p_ranking, aux_pais);
                }
                break;
            }
            else if(j == 0){
                if(placar > aux_placar){
                    pushP(p_ranking, aux_pais);
                    strcpy(pais_passou, retirado);
                }
                else{
                    pushP(p_ranking, pais);
                    strcpy(pais_passou, aux_pais);
                }
            }
            else{
                if(placar > aux_placar){
                    pushP(p_ranking, aux_pais);
                    pushF(f_pos, pais_passou, pais);
                }
                else{
                    pushP(p_ranking, pais);
                    pushF(f_pos, pais_passou, aux_pais);
                }
            }
        //free(retirado);
        }
    }

///Ranking
    printf("\n");
    for(i = 0; i < quant_time; i++){
        retirado = popP(p_ranking);
        if(i == 0){
            for(j = 0; j < 2; j++)
                printf(" ");
            printf("Campeao: %s\n", retirado);
        }
        else if(i == 1){
            for(j = 0; j < 5; j++)
                printf(" ");
            printf("Vice: %s\n", retirado);
        }
        else if(i < 9)
            printf(" %do lugar: %s\n", i + 1, retirado);
        else
            printf("%do lugar: %s\n", i + 1, retirado);
        //free(retirado);
    }

///Desalocando memoria
    for(i = 0; i < quant_pote; i++)
        free(potes[i]);
    free(potes);
    free(f);
    free(f_pos);
    free(p_ranking);

    free(retirado);
    free(aux_retirado);

    return 0;
}
