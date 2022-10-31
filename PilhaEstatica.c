/*
#include "PilhaEstatica.h"

Pilha *cria_pilha(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}

void pushP(Pilha *p, char pais[31]){
    p->topo++;
    strcpy(p->vetor[p->topo], pais);
}

char *popP(Pilha *p){
    char *aux = (char*)malloc(sizeof(char));
    strcpy(aux, p->vetor[p->topo]);
    p->topo--;
    return aux;
}

void imprimeP(Pilha *p){
    int i;
    for(i = p->topo; i > -1; i--)
        printf("|  %s  |\n", p->vetor[i]);
    printf("\n");
}
*/
