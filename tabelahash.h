#ifndef HASH_H
#define HASH_H

#include "lista.h"
//========================================

#define MAX 10000

using std::string;
//========================================
typedef struct TabelaHash{
  Lista tabela[MAX];
}TabelaHash;

void new_hash(TabelaHash *th){
  for(int i=0; i<MAX; i++)
    new_lista(&th->tabela[i]);
}

void print_tabela_hash(TabelaHash *th){

  for(int i=0; i<MAX; i++){
    //printf("%i\t", i);
    print_lista(&th->tabela[i]);
  }
}



int converter(string a){
  
  int soma;
    for ( int i = 0; i < a.length(); i++ ){
        soma = soma+a[i];
    }
  return soma;
}
//funcao hash
int hash(int chave){
  return chave%MAX;
}

void add_hash(TabelaHash *th, Registro dado){

  int pos = hash(converter(dado.reg));
  add(&th->tabela[pos], dado);

}

/*Registro pesquisa_hash(TabelaHash *th, int reg){
  
  int pos = hash(reg);

  return pesquisa_lista(&th->tabela[pos],reg);

}*/

//========================================
#endif
