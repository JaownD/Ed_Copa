#include <stdio.h>
#include "PilhaDinamica.h"


Pilha *cria_pilha(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void pushP(Pilha *p, char pais[31]){
    nodoP *novo = (nodoP*)malloc(sizeof(nodoP));
    strcpy(novo->vetor, pais);
    if(p->topo == NULL){
        novo->prox = NULL;
    }
    else{
        novo->prox = p->topo;
    }
    p->topo = novo;
}

char *popP(Pilha *p){
    nodoP *aux;
    char *aux_string = (char*)malloc(sizeof(char));
    if(p->topo == NULL){
        return;
    }
    else{
        strcpy(aux_string, p->topo->vetor);
        aux = p->topo->prox;
        free(p->topo);
        p->topo = aux;
        return aux_string;
    }
}

