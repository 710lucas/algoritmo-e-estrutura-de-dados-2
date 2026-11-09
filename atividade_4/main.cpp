//
// Created by Lucas Perônico Barbotin on 01/10/26.
//

#include <iostream>

#include "heap.h"

int main(int argc, char *argv[]) {

    Paciente p = {
        1,
        "Ana",
        "10-001",
        "VACINA",
        25
    };

    Paciente p_2 = {
        2,
        "Bob",
        "20-002",
        "TRIAGEM",
        32
    };

    Paciente p_3 = {
        3,
        "Carla",
        "30-003",
        "TRIAGEM",
        28
    };

    Paciente p_4 = {
        4,
        "Danilo",
        "40-004",
        "CONSULTA AGENDADA",
        50
    };

    Paciente p_5 = {
        5,
        "Elisangela",
        "50-005",
        "CONSULTA AGENDADA",
        48
    };

    int cauda = -1;
    int tamanho = 1;

    Paciente* heap = (Paciente*) malloc(tamanho * sizeof(Paciente));


    inserir(&heap, p, &cauda, &tamanho);
    printHeap(&heap, &cauda);

    std::cout << "\n";

    inserir(&heap, p_2, &cauda, &tamanho);
    printHeap(&heap, &cauda);

    std::cout << "\n";

    inserir(&heap, p_3, &cauda, &tamanho);
    printHeap(&heap, &cauda);

    std::cout << "\n";

    inserir(&heap, p_4, &cauda, &tamanho);
    printHeap(&heap, &cauda);

    std::cout << "\n";

    inserir(&heap, p_5, &cauda, &tamanho);
    printHeap(&heap, &cauda);

    std::cout << "\nConsultando próximo paciente...\n";
    Paciente* prox = proximo(&heap);
    printPaciente(prox);
    std::cout << "\n";

    std::cout << "\nRemovendo paciente...\n";
    remover(&heap, &cauda, &tamanho);
    printHeap(&heap, &cauda);
    std::cout << "\n";

    std::cout << "\nOrdenando Fila\n";
    heapSort(&heap, &cauda);
    printHeap(&heap, &cauda);
    std::cout << "\n";

    std::cout << "\nQuantos faltam para Carla?\n";
    printHeap(&heap, &cauda);
    int quantos_faltam = quantosFaltam(&heap, p_3.cpf, &cauda);
    std::cout << ((quantos_faltam == -1) ? "Paciente não foi encontrado na fila" : "Faltam " + std::to_string(quantos_faltam) + " pacientes para Carla ser atendida") ;
    std::cout << "\n";

}
