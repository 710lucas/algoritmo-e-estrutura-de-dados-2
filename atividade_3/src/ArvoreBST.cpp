//
// Created by Lucas Perônico Barbotin on 23/09/26.
//

#include "ArvoreBST.h"

#include <iostream>
#include <ostream>

ArvoreBST::ArvoreBST() {
    this->raiz = nullptr;
}

ArvoreBST::ArvoreBST(Paciente* raiz) {
    this->raiz = raiz;
}

ArvoreBST::ArvoreBST(long cpf, std::string nomeCompleto, std::string cartaoSus, TipoAtendimento tipoAtendimento) {
    this->cadastrarPaciente(cpf, nomeCompleto, cartaoSus, tipoAtendimento);
}

Paciente *ArvoreBST::getPai(Paciente* no, long cpf) {
    if (cpf > no->getCpf()) {
        if (no->getDireita() == nullptr) return no;
        if (no->getDireita()->getCpf() == cpf) return no;
        return this->getPai(no->getDireita(), cpf);
    } else if (cpf < no->getCpf()) {
        if (no->getEsquerda() == nullptr) return no;
        if (no->getEsquerda()->getCpf() == cpf) return no;
        return this->getPai(no->getEsquerda(), cpf);
    } else {
        throw std::runtime_error("Paciente com CPF " + std::to_string(cpf) + " já existe");
        return nullptr;
    }
}

void ArvoreBST::cadastrarPaciente(long cpf, std::string nomeCompleto, std::string cartaoSus, TipoAtendimento tipoAtendimento) {
    try {

        Paciente* p = new Paciente(cpf, nomeCompleto, cartaoSus, tipoAtendimento);
        if (raiz == nullptr) {
            raiz = p;
            return;
        }

        Paciente* pai = this->getPai(raiz, cpf);
        if (cpf > pai->getCpf()) {
            pai->set_direita(p);
        } else {
            pai->set_esquerda(p);
        }

    } catch (const std::runtime_error& e) {
        std::cerr<<e.what()<<'\n';
    }
}

void ArvoreBST::cadastrarPaciente(Paciente paciente) {
    try {

        cadastrarPaciente(
            paciente.getCpf(),
            paciente.getNomeCompleto(),
            paciente.getCartaoSus(),
            paciente.tipo_atendimento()
        );

    } catch (const std::runtime_error& e) {
        std::cerr<<e.what()<<'\n';
    }
}
Paciente *ArvoreBST::getNo(Paciente* no, long cpf, int &altura) {
    if (cpf == no->getCpf()) {
        return no;
    } else if (cpf > no->getCpf() && no->getDireita() != nullptr) {
        altura++;
        return this->getNo(no->getDireita(), cpf, altura);
    } else if (cpf < no->getCpf() && no->getEsquerda() != nullptr) {
        altura++;
        return this->getNo(no->getEsquerda(), cpf, altura);
    } else {
        throw std::runtime_error("O CPF " + std::to_string(cpf) + " não foi encontrado na árvore");
        return nullptr;
    }
}

Paciente *ArvoreBST::buscarPaciente(long cpf) {
    try {

        int altura = 0;
        Paciente* p = getNo(raiz, cpf, altura);
        std::cout<<"Quantidade de pulos para achar o paciente: CPF=" + std::to_string(cpf) + " : " + std::to_string(altura) + '\n';
        Paciente::printPaciente(p);
        std::cout << std::endl;
        return p;
    } catch (std::runtime_error e) {
        std::cerr << e.what() << std::endl;
    }
    return nullptr;
}

Paciente *ArvoreBST::menorValor(Paciente* no) {
    if (no->getEsquerda() != nullptr) {
        return menorValor(no->getEsquerda());
    } return no;
}

Paciente *ArvoreBST::maiorValor(Paciente* no) {
    if (no->getDireita() != nullptr) {
        return maiorValor(no->getDireita());
    } return no;
}

Paciente *ArvoreBST::buscarSucessor(Paciente* no) {
   if (no->getDireita() != nullptr) {
       return menorValor(no->getDireita());
   }

    std::cerr << "Este nó não tem sucessor"<<std::endl;

    return nullptr;
}

Paciente *ArvoreBST::buscarPredecessor(Paciente* no) {
    if (no->getEsquerda() != nullptr) {
        return maiorValor(no->getEsquerda());
    }

    std::cerr << "Este nó não tem predecessor"<<std::endl;

    return nullptr;
}

Paciente *ArvoreBST::buscarPredecessor() {
    return this->buscarPredecessor(raiz);
}

Paciente *ArvoreBST::buscarSucessor() {
    return this->buscarSucessor(raiz);
}

int getQuantidadeFilhos(Paciente* no) {
    int quantidade = 0;
    if (no->getDireita() != nullptr) quantidade++;
    if (no->getEsquerda() != nullptr) quantidade++;
    return quantidade;
}

void ArvoreBST::removerFolha(long cpf) {
    try {

        if (cpf == raiz->getCpf()) {
            raiz = nullptr;
            return;
        }

        Paciente* pai = getPai(raiz, cpf);
        if (pai->getEsquerda() != nullptr && pai->getEsquerda()->getCpf() == cpf) {
            pai->set_esquerda(nullptr);
        } else {
            pai->set_direita(nullptr);
        }

    } catch (std::runtime_error e) {
        std::cerr << e.what() << std::endl;
    }
}

void ArvoreBST::removerUmFilho(Paciente* no) {
    try {

        int altura = 0;
        Paciente* filho = no->getEsquerda() != nullptr ? no->getEsquerda() : no->getDireita();
        if (no->getCpf() == raiz->getCpf()) {
            raiz = filho;
            return;
        }

        long cpf = no->getCpf();
        Paciente* pai = getPai(raiz, cpf);


        if (pai->getDireita() != nullptr && pai->getDireita()->getCpf() == cpf) {
            pai->set_direita(filho);
        } else {
            pai->set_esquerda(filho);
        }

    } catch (std::runtime_error e) {
        std::cerr << e.what() << std::endl;
    }
}

void ArvoreBST::removerDoisFilhos(Paciente *no) {
    try {

        //1. Pegar o sucessor
        Paciente* sucessor = buscarSucessor(no);
        long cpfSucessor = sucessor->getCpf();
        std::string nomeCompleto = sucessor->getNomeCompleto();
        std::string cartaoSus = sucessor->getCartaoSus();
        TipoAtendimento tipo = sucessor->tipo_atendimento();

        //3. remover no
        removerNo(cpfSucessor);

        //3. copiar info do sucessor pro no
        no->setCpf(cpfSucessor);
        no->set_nome_completo(nomeCompleto);
        no->set_cartao_sus(cartaoSus);
        no->set_tipo_atendimento(tipo);


    } catch (std::runtime_error e) {
        std::cerr << e.what() << std::endl;
    }
}

void ArvoreBST::removerNo(long cpf) {
    try {

        int altura = 0;
        Paciente* p_remover = getNo(raiz, cpf, altura);

        int qtdFilhos = getQuantidadeFilhos(p_remover);

        if (qtdFilhos == 0) {
            removerFolha(cpf);
        } else if (qtdFilhos == 1){
            removerUmFilho(p_remover);
        } else if (qtdFilhos == 2) {
            removerDoisFilhos(p_remover);
        }


    } catch (std::runtime_error e) {
        std::cerr << e.what() << std::endl;
    }
}

void ArvoreBST::buscaEmProfundidade(std::vector<Paciente*> fila) {

    if (raiz == nullptr) {
        std::cerr << "A fila está vazia"<<std::endl;
        return;
    }

    std::queue<long> filaCpfs;
    filaCpfs.push(raiz->getCpf());

    while (!filaCpfs.empty()) {
        long atualCpf = filaCpfs.front();
        filaCpfs.pop();

        int altura = 0;

        Paciente* atual = getNo(raiz, atualCpf, altura);
        fila.push_back(atual);

        std::cout << ((atualCpf == raiz->getCpf()) ? "" : ", ") << atualCpf <<  " - " << atual->getNomeCompleto();

        if (atual->getEsquerda() != nullptr) filaCpfs.push(atual->getEsquerda()->getCpf());
        if (atual->getDireita() != nullptr) filaCpfs.push(atual->getDireita()->getCpf());
    }

    std::cout << std::endl;
}
