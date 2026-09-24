//
// Created by Lucas Perônico Barbotin on 21/09/26.
//

#ifndef ATIVIDADE_3_PACIENTE_H
#define ATIVIDADE_3_PACIENTE_H

#include <string>

#include "TipoAtendimento.h"

class Paciente {

private:
    TipoAtendimento tipoAtendimento;
    long cpf;
    std::string nomeCompleto;
    std::string cartaoSus;
    Paciente* esquerda;
    Paciente* direita;


public:
    Paciente(long cpf, std::string nomeCompleto, std::string cartaoSus, TipoAtendimento tipoAtendimento);
    static void printPaciente(Paciente* p);

    long getCpf() {
        return this->cpf;
    }
    void setCpf(long cpf) {
        this->cpf = cpf;
    }


    TipoAtendimento tipo_atendimento() const {
        return tipoAtendimento;
    }

    void set_tipo_atendimento(TipoAtendimento tipo_atendimento) {
        tipoAtendimento = tipo_atendimento;
    }

    std::string getNomeCompleto() const {
        return nomeCompleto;
    }

    void set_nome_completo(const std::string &nome_completo) {
        nomeCompleto = nome_completo;
    }

    std::string getCartaoSus() const {
        return cartaoSus;
    }

    void set_cartao_sus(const std::string &cartao_sus) {
        cartaoSus = cartao_sus;
    }

    Paciente* getEsquerda() const {
        return this->esquerda;
    }

    void set_esquerda(Paciente* esquerda) {
        this->esquerda = esquerda;
    }

    Paciente* getDireita() const {
        return this->direita;
    }

    void set_direita(Paciente* direita) {
        this->direita = direita;
    }
};


#endif //ATIVIDADE_3_PACIENTE_H
