#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "tabelahash.h"

int main(int argc, char *argv[]){
  // A variavel "teste" e usada para debug
  // Comente a linha 12 para rodar seu teste contido no if abaixo
  // Se não cairá no CMD
  int teste = 1;
  //teste=0;
  if (teste == 1){
   /* TabelaHash tabela;
    new_hash(&tabela);
    Registro a;
    a.reg="testestring";
    add_hash(&tabela,a);
    print_tabela_hash(&tabela);
    */
   char str[]= "teste=sim";
    char delim[] = "=";
    char *ptr = strtok(str, delim);
    if(strcmp(str,"teste") == 0){
      printf("%s", str);
    }
  }
  else{
    if (argc == 1 || strcmp(argv[2],"--help") == 0){
        printf("simpledb [cmd]\n"
        "  --insert=<sort-key,value> \n      Insere um objeto no banco de dados.\n"
        "  --remove=<key>\n      Remove do banco de dados o objeto identificado pela chave key.\n"
        "  --search=<key>\n      Busca no banco de dados objeto identificado pela chave key.\n"
        "  --update=<key,sort-key,value>\n      Atualiza o objeto que e identificado pela chave key. \n"
        "  --list=<expr>\n      Lista em ordem crescente todos os objetos que possam uma chave de ordenacao que atenda aos criterios especificados pela expressao 'expr'.\n"
        "  --reverse-list=<expr>\n      Lista em ordem decrescente  todos os objetos que possam uma chave de ordenacao que atenda aos criterios especificados pela expressao 'expr'.\n"
        "  * A expressao 'expr' deve aceitar qualquer operacao logica simples envolvendo a chave:\n"
        "      key>X: objetos que possuem chave de ordenacao maior que X.\n"
        "      key<X: objetos que possuem chave de ordenacao menor que X.\n"
        "      key=X: objetos que possuem chave ordenacao igual a X.\n"
        "      key>=X: objetos que possuem chave de ordenacao maior ou igual que X.\n"
        "      key<=X: objetos que possuem chave de ordenacao menor ou igual que X.\n"
        "  --compress=[huffman|lzw]\n      Compacta os registros do banco de dados usando o algoritmo de Codificacao de Huffman ou o Algoritmo de Compressao LZW. \n"
        "  --decompress=[huffman|lzw]\n      Descompacta os registros do banco de dados usando o algoritmo de Codificacao de Huffman ou o Algoritmo de Compressao LZW. \n"
        "");
    }
    else{
      char arg[];
      strcpy(arg,argv[2]);
      char delim[] = "=";
      char *arg = strtok(str, delim);
      if(strcmp(arg,"--insert") == 0){

      }
      if(strcmp(arg,"--remove") == 0){

      }
      if(strcmp(arg,"--search") == 0){

      }
      if(strcmp(arg,"--update") == 0){

      }
      if(strcmp(arg,"--list") == 0){

      }
      if(strcmp(arg,"--reverse-list") == 0){

      }
      if(strcmp(arg,"--compress") == 0){

      }
      if(strcmp(arg,"--decompress")== 0){

      }
    }
  }
  return 0;
}

