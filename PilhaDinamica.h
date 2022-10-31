#ifndef PILHADINAMICA_H_INCLUDED
#define PILHADINAMICA_H_INCLUDED

typedef struct NodoP{
    char vetor[31];
    struct NodoP *prox;
}nodoP;


typedef struct Pilha{
    nodoP *topo;
}Pilha;

Pilha *cria_pilha();

void pushP(Pilha *p, char pais[31]);

char *popP(Pilha *p);

#endif // PILHADINAMICA_H_INCLUDED

