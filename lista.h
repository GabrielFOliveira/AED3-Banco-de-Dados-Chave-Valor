#ifndef  LISTA_H
#define  LISTA_H
//========================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//========================================
typedef struct Registro{
  std::string reg;
};

void print_registro(Registro c){
  printf("\nMunicipio: %s \n",
         c.reg);
}
//========================================
typedef struct Celula{
  Registro dado;
  struct Celula *prox;
}Celula;

Celula *new_celula(Registro dado){
  Celula *tmp = (Celula*)malloc(sizeof(Celula));
  tmp->dado = dado;
  tmp->prox = NULL;

  return tmp;
}

//========================================
typedef struct Lista{
  Celula *inicio;
  Celula *fim;
  int tam;
}Lista;
//========================================
void new_lista(Lista *l){

  Celula *tmp = (Celula*)malloc(sizeof(Celula));
  tmp->prox = NULL;

  l->inicio = l->fim = tmp;
  l->tam = 0;
}
//========================================
void add(Lista *l, Registro dado){

  Celula *tmp = new_celula(dado);

  l->fim->prox = tmp;
  l->fim = tmp;
  l->tam++;
}
//========================================

void print_lista(Lista *l){

  Celula *tmp = l->inicio->prox;

  //printf("[%d] ", l->tam);

  while(tmp != NULL){
    print_registro(tmp->dado);
    tmp = tmp->prox;
  }

  printf("\n");
}


Registro pesquisa_lista(Lista *l, char *reg ){

    Celula *tmp = l->inicio->prox;

    while(tmp != NULL){
      if(tmp->dado.reg == reg)
        return tmp->dado;

      tmp = tmp->prox;
    }



    //return a;
}


//========================================
#endif
