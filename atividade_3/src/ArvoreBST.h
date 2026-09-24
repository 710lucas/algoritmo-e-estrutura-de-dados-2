//
// Created by Lucas Perônico Barbotin on 23/09/26.
//

#ifndef ATIVIDADE_3_ARVOREBST_H
#define ATIVIDADE_3_ARVOREBST_H
#include "Paciente.h"
#include <iostream>


class ArvoreBST {

    Paciente* raiz;

public:
    ArvoreBST();
    ArvoreBST(Paciente* raiz);
    ArvoreBST(long cpf, std::string nomeCompleto, std::string cartaoSus, TipoAtendimento tipoAtendimento);

    Paciente* getPai(Paciente* no, long cpf);
    void cadastrarPaciente(long cpf, std::string nomeCompleto, std::string cartaoSus, TipoAtendimento tipoAtendimento);
    void cadastrarPaciente(Paciente p);

    Paciente* getNo(Paciente* no, long cpf, int& altura);
    Paciente* buscarPaciente(long cpf);

    Paciente* menorValor(Paciente* no);
    Paciente* maiorValor(Paciente* no);


    Paciente* buscarSucessor();
    Paciente* buscarPredecessor();

    Paciente* buscarSucessor(Paciente* no);
    Paciente* buscarPredecessor(Paciente* no);

    void removerNo(long cpf);
    void removerFolha(long cpf);
    void removerUmFilho(Paciente* no);
    void removerDoisFilhos(Paciente* no);

    void buscaEmProfundidade(std::vector<Paciente*> fila);

    Paciente* getRaiz() {
        return raiz;
    }

};


#endif //ATIVIDADE_3_ARVOREBST_H
