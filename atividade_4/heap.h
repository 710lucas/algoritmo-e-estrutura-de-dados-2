//
// Created by Lucas Perônico Barbotin on 28/09/26.
//

#ifndef ALGORITMO_E_ESTRUTURA_DE_DADOS_2_HEAP_H
#define ALGORITMO_E_ESTRUTURA_DE_DADOS_2_HEAP_H
#include <string>

struct Paciente {
    long cpf;
    std::string nome_completo;
    std::string cartao_sus;
    std::string tipo_atendimento;
    int idade;
};

void inserir(Paciente** heap, Paciente elemento, int* cauda, int* tamanho);
Paciente* proximo(Paciente** heap);
Paciente remover(Paciente** heap, int* cauda, int* tamanho);
void printPaciente(Paciente* p);
void printHeap(Paciente** heap, int* cauda);

void heapSort(Paciente** heap, int* cauda);
int quantosFaltam(Paciente** heap, long cpf, int* cauda);


#endif //ALGORITMO_E_ESTRUTURA_DE_DADOS_2_HEAP_H
