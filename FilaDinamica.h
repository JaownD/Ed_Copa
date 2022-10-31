
#ifndef FILADINAMICA_H_INCLUDED
#define FILADINAMICA_H_INCLUDED

typedef struct NodoF{
    char vetor1[31];
    char vetor2[31];
    struct NodoF *prox;
}nodoF;

typedef struct Fila{
    nodoF* inicio;
    nodoF* fim;
}Fila;

Fila *cria_fila();

void pushF(Fila *f, char *pais, char *aux_pais);

void popF(Fila *f, char *pais, char *aux_pais);

#endif // FILADINAMICA_H_INCLUDED

