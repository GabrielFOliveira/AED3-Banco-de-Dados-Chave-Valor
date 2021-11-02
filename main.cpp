#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Bucket.h"
#include "Directory.h"


int main(int argc, char *argv[]){
  // A variavel "teste" e usada para debug

  // Comente a linha 11 para rodar seu teste contido no if abaixo
  // Se n�o cair� no CMD
  int teste = 1;
  teste=0;
  if (teste == 1){



  }
  else{
    int counter;
    //printf("Program Name Is: %s",argv[0]);

    if(argc>=2)
    {
        printf("\nNumber Of Arguments Passed: %d",argc);
        printf("\n----Following Are The Command Line Arguments Passed----");
        for(counter=0;counter<argc;counter++)
            printf("\nargv[%d]: %s",counter,argv[counter]);
    }



    char *str;
    if (argc == 1 || strcmp(argv[1],"--help") == 0){
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
        "  --decompress=[huffman|lzw]\n      Descompacta os registros do banco de dados usando o algoritmo de Codificacao de Huffman ou o Algoritmo de Compressao LZW. \n");
    }
    else{
      char delim[] = "=";
      char *arg = strtok(argv[1], delim); // arg recebe a string do comando at� o =
      if(strcmp(arg,"--insert") == 0){
        arg = strtok(NULL, delim); // arg recebe a string do comando ap�s o =
        char *valores = strtok(arg,","); // valores recebe o sort-key
        int sortkey = (int)valores[0];
        valores = strtok(NULL,",");  // valores recebe o value
        //insert(sortkey,valores);
        printf("O metodo insert ainda nao foi implementado hehe\nSortkey: %d\nValue: %s\n", sortkey, valores);
      }
      else if(strcmp(arg,"--remove") == 0){
        arg = strtok(NULL, delim); // arg recebe a string do comando ap�s o =
        //remove(arg);
        printf("O metodo remove ainda nao foi implementado hehe\nKey: %s\n",arg);
      }
      else if(strcmp(arg,"--search") == 0){
        arg = strtok(NULL, delim); // arg recebe a string do comando ap�s o =
        //search(arg);
        printf("O metodo search ainda nao foi implementado hehe\nKey: %s\n",arg);
      }
      else if(strcmp(arg,"--update") == 0){
        arg = strtok(NULL, delim); // arg recebe a string do comando ap�s o =
        char *valores = strtok(arg,","); // valores recebe a key
        char *key, value;
        int sortkey;
        strcpy(key,valores);
        valores = strtok(NULL,",");  // valores recebe a sort-key
        sortkey= (int)valores[0];
        valores = strtok(NULL,",");  // valores recebe o value
        //update(key,sort-key,valores)
        printf("O metodo update ainda nao foi implementado hehe\nKey: %s\nSortKey: %d\nValue:%s\n",key,sortkey,valores);

      }
      else if(strcmp(arg,"--list") == 0){
        arg = strtok(NULL, delim); // arg recebe a string do comando ap�s o primeiro = e at� o 2o
        // a fazer
        printf("O metodo list ainda nao foi implementado hehe\nKey: %s\n",arg);
      }
      else if(strcmp(arg,"--reverse-list") == 0){
        arg = strtok(NULL, delim); // arg recebe a string do comando ap�s o primeiro = e at� o 2o
        // a fazer
        printf("O metodo resvese-list ainda nao foi implementado hehe\nKey: %s\n",arg);
      }
      else if(strcmp(arg,"--compress") == 0){
        arg = strtok(NULL, delim); // arg recebe a string do comando ap�s o =
        if(strcmp(arg,"lzw") == 0){
          //compresslzw();
          printf("O metodo compresslzw ainda nao foi implementado hehe\n");
        }
        else if(strcmp(arg,"huffman") == 0){
          //compresshuffman();
          printf("O metodo compresshuffman ainda nao foi implementado hehe\n");
        }
      }
      else if(strcmp(arg,"--decompress")== 0){
        arg = strtok(NULL, delim); // arg recebe a string do comando ap�s o =
        if(strcmp(arg,"lzw") == 0){
          //decompresslzw();
          printf("O metodo decompresslzw ainda nao foi implementado hehe\n");
        }
        else if(strcmp(arg,"huffman") == 0){
          //decompresshuffman();
          printf("O metodo decompresshuffman ainda nao foi implementado hehe\n");
        }
      }
    }
  }
  return 0;
}

