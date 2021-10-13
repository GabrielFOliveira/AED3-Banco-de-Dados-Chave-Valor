#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <tabelahash.h>

int main(){

TabelaHash tabela;

new_hash(&tabela);

string a[] = "oioioioi";

add_hash(&tabela,a);

print_tabela_hash(&tabela);

return 0;
}

