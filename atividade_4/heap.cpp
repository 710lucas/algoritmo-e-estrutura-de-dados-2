//
// Created by Lucas Perônico Barbotin on 28/09/26.
//

#include "heap.h"

#include <cstdlib>
#include <cstring>
#include <iostream>

// static void redimensionar(int** heap, int* tamanho) {
//     int* novo_heap = (int*) malloc(*tamanho * 2 * sizeof(int));
//
//     memcpy(novo_heap, *heap, *tamanho * sizeof(int)); //copia byte a byte do que tava no end. do heap antigo para o novo
//     free(*heap); //já que heap antigo não vai ser mais utilizado, podemos liberar a memória
//
//     //Aponta para novo endereço
//     *heap = novo_heap;// p->p-/->heap; p->p->novo_heap->[]
//     *tamanho = *tamanho*2;
//
// }

// void inserir(int** heap, int elemento, int* cauda, int* tamanho) {
//
//     if (*cauda >= *tamanho) {
//         redimensionar(heap, tamanho);
//     }
//     (*heap)[*cauda] = elemento; //*heap pega o endereço da heap, [*cauda] avança nos bytes
//     //lembrar que array em C é basicamente o indice do primeiro byte da array
//
//     int i = *cauda;
//     int pai = ((*cauda-1)/2);
//
//     while (i > 0 && (*heap)[i] > (*heap)[pai]) {
//         int tmp = (*heap)[i];
//         (*heap)[i] = (*heap)[pai];
//         (*heap)[pai] = tmp;
//         i = pai;
//         pai = ((i-1)/2);
//     }
//     *cauda += 1;
// }
//


//====
//Considerar cauda como pos. do último elemento, entao incrementar e dps adicionar

static void redimensionar(Paciente** heap, int* tamanho, int* cauda) {
    Paciente* novo_heap = (Paciente*) malloc(*tamanho * 2 * sizeof(Paciente));

    // memcpy(novo_heap, *heap, *tamanho * sizeof(Paciente));

    for (int i = 0; i<=*cauda; i++) {
        novo_heap[i] = (*heap)[i];
    }

    free(*heap);

    //Aponta para novo endereço
    *heap = novo_heap;
    *tamanho = *tamanho*2;
}


static bool isFolha(int i, int cauda, int i_pai_cauda) {
    return i > i_pai_cauda && i <= cauda;
}

static bool indiceValido(long i, int cauda) {
    return i >= 0 && i <= cauda;
}

static int getEsquerdaIndice(int indice) {
    int i_esquerda = ((indice + 1) * 2) - 1;
    return i_esquerda;
}

static int getDireitaIndice(int indice) {
    int i_direita = ((indice + 1) * 2);
    return i_direita; }

static int maiorIndice(Paciente** heap, int indice, int cauda) {
    int i_e = getEsquerdaIndice(indice);
    int i_d = getDireitaIndice(indice);

    Paciente p_e = (*heap)[i_e];
    Paciente p_d = (*heap)[i_d];

    if (i_e > cauda) return cauda; //o anterior
    if (i_d > cauda) return i_e; //o anterior

    return p_e.idade > p_d.idade ? i_e  : i_d;

}

static int menorIndice(Paciente** heap, int indice, int cauda) {
    int i_e = getEsquerdaIndice(indice);
    int i_d = getDireitaIndice(indice);


    if (i_e > cauda) return indice; //o anterior
    if (i_d > cauda) return i_e; //o anterior

    Paciente p_e = (*heap)[i_e];
    Paciente p_d = (*heap)[i_d];

    return p_e.idade < p_d.idade ? i_e  : i_d;

}

void inserir(Paciente** heap, Paciente elemento, int* cauda, int* tamanho) {
    std::cout << "[INSERINDO] idade = " << elemento.idade << "\n";

    if (*cauda + 1 >= *tamanho) {
        std::cout << "[REDIMENSIONANDO] tamanho antigo: " << *tamanho << "\n";
        redimensionar(heap, tamanho, cauda);
        std::cout << "[REDIMENSIONANDO] tamanho novo: " << *tamanho << "\n";
    }

    //0. Como cauda é o ultimo elemento, precisamos incrementar
    *cauda += 1;

    //1 Inserir elemento
    (*heap)[*cauda] = elemento;

    int i = *cauda;

    int pai = ((*cauda-1)/2);

    while (i>0 && (*heap)[i].idade > (*heap)[pai].idade) {
        std::cout << "\tAjustando pois paciente com idade: " << (*heap)[i].idade << "tem idade maior que o pai com idade: " << (*heap)[pai].idade << "\n";
        Paciente tmp = (*heap)[i];
        (*heap)[i] = (*heap)[pai];
        (*heap)[pai] = tmp;
        i = pai;
        pai = (i-1)/2;
    }
}

Paciente* proximo(Paciente** heap) {
    return &(*heap)[0];
}

static void heapify(Paciente** heap, int indice, int cauda) {
    int pai = ((cauda-1)/2);
    if (isFolha(indice, cauda, pai) || !indiceValido(indice, cauda)) {
        return;
    }

    int indice_max = maiorIndice(heap, indice, cauda);


    if ((*heap)[indice_max].idade > (*heap)[indice].idade) {
        //swap
        Paciente tmp = (*heap)[indice_max];
        (*heap)[indice_max] = (*heap)[indice];
        (*heap)[indice] = tmp;
        heapify(heap, indice_max, cauda);
    }
}

static void heapifyDecrescente(Paciente** heap, int indice, int cauda) {
    int pai = ((cauda-1)/2);
    if (isFolha(indice, cauda, pai) || !indiceValido(indice, cauda)) {
        return;
    }

    int indice_min = menorIndice(heap, indice, cauda);


    if ((*heap)[indice_min].idade < (*heap)[indice].idade) {
        //swap
        Paciente tmp = (*heap)[indice_min];
        (*heap)[indice_min] = (*heap)[indice];
        (*heap)[indice] = tmp;
        heapifyDecrescente(heap, indice_min, cauda);
    }
}

Paciente remover(Paciente** heap, int* cauda, int* tamanho) {
    Paciente p_raiz = *proximo(heap);

    Paciente p_cauda = (*heap)[*cauda];
    (*heap)[0] = p_cauda;
    // (*heap)[*cauda] = nullptr;

    *cauda -= 1;

    int i_inicio = 0;

    heapify(heap, i_inicio, *cauda);

    return p_raiz;
}

void printPaciente(Paciente* p) {
    std::cout << "Paciente " << p->nome_completo << "\n";
    std::cout << "\tCPF: " << p->cpf << "\n";
    std::cout << "\tCartão do SUS: " << p->cartao_sus << "\n";
    std::cout << "\tTipo do atendimento" << p->tipo_atendimento << "\n";
    std::cout << "\tIdade" << p->idade << "\n";
    std::cout << "\n";
}

void printHeap(Paciente **heap, int *cauda) {
    std::cout << "[";
    for (int i = 0; i<=*cauda; i++) {
        const Paciente p = (*heap)[i];
        std::cout << p.idade << (i == (*cauda) ? "" : ", ");
    }
    std::cout << "]\n";
}

void heapSort(Paciente **heap, int *cauda_) {
    int cauda = *cauda_;

    // Construir min-heap
    for (int i = cauda / 2; i >= 0; i--) {
        heapifyDecrescente(heap, i, cauda);
    }

    for (int i = cauda; i>0; i--) {
        // std::cout << "[heapsort] Começando do i = " << i << std::endl;
        // std::cout << "[heapsort] Element: " << (*heap)[i].idade <<std::endl;
        //
        // std::cout << "[heapsort]";
        // printHeap(heap, &cauda);

        Paciente tmp = (*heap)[i];
        (*heap)[i] = (*heap)[0];
        (*heap)[0] = tmp;

        // std::cout << "[heapsort]";
        // printHeap(heap, &cauda);



        heapifyDecrescente(heap, 0, i-1);
        // std::cout << "[heapsort]";
        // printHeap(heap, &cauda);
        // std::cout << std::endl;
    }
}

int quantosFaltam(Paciente **heap, long cpf, int* cauda) {
    for (int i = 0; i<=*cauda; i++) {
        // std::cout << "[quantosFaltam] analisando: " << (*heap)[i].nome_completo << std::endl;
        if ( (*heap)[i].cpf == cpf) {
            return i;
        }
    }
    return -1;
}
