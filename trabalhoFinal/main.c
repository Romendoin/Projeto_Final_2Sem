#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funcoes.h"

///Daniel Januário e Rodrigo Martins///TRABALHO FINAL///PROGRAMAÇÃO ESTRUTURADA////

const int cp = 1252;

int main(){
     for (int i = 0; i < 21; i++){
        folha[i].mesFat.mes=0;
    }
    for (int i = 0; i < 16; i++){
        carg[i].valor = 0;
    }
    for(int i = 0; i < 11; i++){
        pessoa[i].cont=0;
    }

    for(int i = 0; i<21; i++){
        folha[i].situacao=0;
    }


    for(int i = 0; i<21; i++){
        folha[i].itemFolha[i].tipoLan=0;
    }
    SetConsoleCP(cp);
    SetConsoleOutputCP(cp);

    menu();


    return 0;
}
