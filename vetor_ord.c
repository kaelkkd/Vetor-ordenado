#include <stdio.h>
#include <stdlib.h>
#include "vetor_ord.h"

VETORORD* VETORD_create(int vetTam, COMP * compara) {
    VETORORD* vetor_novo = malloc(sizeof(VETORORD));
    vetor_novo -> tam = vetTam;
    vetor_novo -> numElems = 0;
    vetor_novo -> comparador = compara;   //setando a função de comparação
    vetor_novo -> elems = malloc(sizeof(void*) * vetTam);    //alocando memória o suficiente de acordo com o tamanho passado
    
    for (int i = 0; i < vetor_novo->tam; i++) {
        vetor_novo->elems[i] = NULL;    //apontando todos os elementos para NULL
    }

    return vetor_novo;
}

void VETORD_add(VETORORD* vetor, void* newelem) {
    if (vetor-> numElems < vetor-> tam) {   //prosseguirá caso ainda haja espaço no vetor     
        int aux = (vetor -> numElems) - 1;  //variavel auxiliar para o processo de caminhada
        
        if (vetor -> numElems == 0) {   //caso o vetor esteja vazio, o novo elemento ocupará a primeira posição  
            vetor -> elems[0] = newelem;
        }

        else if (vetor -> comparador(newelem, vetor -> elems[vetor -> numElems - 1]) == 0 || vetor -> comparador(newelem, vetor -> elems[vetor -> numElems - 1]) == -1) {
            vetor -> elems[vetor -> numElems] = newelem;    
        }   //verifica se o elemento a ser adicionado é maior que o último elemento do vetor ou menor que o primeiro elemento
        
        else {  //caminhada por todo o vetor até encontrar a posição correta para o elemento a ser adicionado
            while (vetor -> comparador(newelem, (vetor -> elems[aux])) == 1) {
                vetor -> elems[aux + 1] = vetor -> elems[aux];
                vetor -> elems[aux] = newelem;
                aux--;
            }
        }
        vetor-> numElems++;
    }    

    else {
        printf("Não é possível adicionar, o vetor está lotado.\n");
    }
}

void* VETORD_remove(VETORORD* vetor) {
    if (vetor->numElems > 1) {  //caso haja elementos no vetor  
        void* elem_removido = vetor -> elems[0];
        for (int i = 0; i <= vetor -> numElems; i++) {
            vetor -> elems[i] = vetor -> elems[i + 1];  //reorganizando os elementos do vetor apos a remocao 
        }
    
        vetor -> numElems--;

        return elem_removido;
    }
} 

