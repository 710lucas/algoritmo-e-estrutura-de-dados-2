#include <iostream>

#include "ArvoreBST.h"
#include "Paciente.h"
#include "TipoAtendimento.h"

void cadastrar(ArvoreBST* arvore);
void consultar(ArvoreBST* arvore);
void remover(ArvoreBST* arvore);
void ver(ArvoreBST* arvore);
void cadastrar_fila(ArvoreBST* ubs, ArvoreBST* fila);

int main() {

    ArvoreBST* ubs = new ArvoreBST();
    ArvoreBST* fila = new ArvoreBST();

    const int CADASTRAR = 1;
    const int CONSULTAR = 2;
    const int REMOVER = 3;
    const int CADASTRAR_FILA = 4;
    const int VER_FILA = 5;
    const int REMOVER_FILA = 6;
    const int SAIR = -1;

    int opcao = 0;
    while (opcao != SAIR) {
        std::cout << "Escolha uma opção:"<<std::endl;
        std::cout << "1. Cadastrar paciente na UBS"<<std::endl;
        std::cout << "2. Consultar paciente na UBS"<<std::endl;
        std::cout << "3. Remover paciente da UBS"<<std::endl;
        std::cout << "4. Cadastrar paciente na fila do dia"<<std::endl;
        std::cout << "5. Ver fila do dia"<<std::endl;
        std::cout << "6. Remover paciente da fila"<<std::endl;
        std::cout << "-1. Sair"<<std::endl;
        std::cout << "> ";
        std::cin >> opcao;

        switch (opcao) {
            case CADASTRAR:
                cadastrar(ubs);
                break;
            case CONSULTAR:
                consultar(ubs);
                break;
            case REMOVER:
                remover(ubs);
                break;
            case CADASTRAR_FILA:
                cadastrar_fila(ubs, fila);
                break;
            case VER_FILA:
                ver(fila);
                break;
            case REMOVER_FILA:
                remover(fila);
                break;
            default:
                break;
        }
    }

}

void cadastrar(ArvoreBST* arvore) {

    long cpf;
    std::string nome;
    std::string cartaoSus;

    std::cout << std::endl;
    std::cout << "Insira o CPF do paciente (somente numeros): ";
    std::cin >> cpf;

    std::cout << std::endl;
    std::cout << "Insira o nome completo do paciente: ";
    std::cin >> nome;

    std::cout << std::endl;
    std::cout << "Insira o cartaoSus do paciente: ";
    std::cin >> cartaoSus;

    arvore->cadastrarPaciente(cpf, nome, cartaoSus, TipoAtendimento::CONSULTA_AGENDADA);
    std::cout << std::endl;
    std::cout << "Paciente cadastrado com sucesso";
    std::cout << std::endl;
}

void consultar(ArvoreBST *arvore) {
    long cpf;
    std::cout << std::endl;
    std::cout << "Insira o CPF do paciente (somente numeros): ";
    std::cin >> cpf;

    Paciente* p = arvore->buscarPaciente(cpf);
    // Paciente::printPaciente(p);
    std::cout << std::endl;
}

void remover(ArvoreBST *arvore) {
    long cpf;
    std::cout << std::endl;
    std::cout << "Insira o CPF do paciente (somente numeros): ";
    std::cin >> cpf;

    arvore->removerNo(cpf);
    std::cout << "Paciente removido com sucesso";
    std::cout << std::endl;
}

void ver(ArvoreBST *arvore) {
    std::vector<Paciente*> fila;
    arvore->buscaEmProfundidade(fila);
}

void cadastrar_fila(ArvoreBST *ubs, ArvoreBST *fila) {
    long cpf;
    std::cout << std::endl;
    std::cout << "Insira o CPF do paciente que você deseja cadastrar na fila (somente numeros): ";
    std::cin >> cpf;

    Paciente* p = ubs->buscarPaciente(cpf);
    if (p == nullptr) {
        std::cerr << "O paciente não foi encontrado" << std::endl;
        return;
    }

    fila->cadastrarPaciente(*p);
}
