
#include <stdio.h>
#include "FilaDinamica.h"

Fila *cria_fila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}

void pushF(Fila *f, char *pais, char *aux_pais){
    nodoF *novo = (nodoF*)malloc(sizeof(nodoF));
    strcpy(novo->vetor1, pais);
    strcpy(novo->vetor2, aux_pais);
    if(f->fim == NULL){
        novo->prox = NULL;
        f->fim = f->inicio = novo;
    }
    else if(f->fim->prox == NULL){
        f->fim->prox = novo;
        novo->prox = NULL;
        f->fim = novo;
    }
}

void popF(Fila *f, char *pais, char *aux_pais){
    nodoF *aux;
    if(f->inicio == NULL){
        f->inicio = f->fim;
        strcpy(pais, f->inicio->vetor1);
        strcpy(aux_pais, f->inicio->vetor2);
    }
    else{
        strcpy(pais, f->inicio->vetor1);
        strcpy(aux_pais, f->inicio->vetor2);
        aux = f->inicio->prox;
        free(f->inicio);
        f->inicio = aux;
    }
}

