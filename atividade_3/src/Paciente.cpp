//
// Created by Lucas Perônico Barbotin on 21/09/26.
//

#include "Paciente.h"

#include <iostream>
#include <stdexcept>

Paciente::Paciente(long cpf, std::string nomeCompleto, std::string cartaoSus, TipoAtendimento tipoAtendimento) {
    setCpf(cpf);
    set_nome_completo(nomeCompleto);
    set_cartao_sus(cartaoSus);
    set_tipo_atendimento(tipoAtendimento);
    set_esquerda(nullptr);
    set_direita(nullptr);
}

void Paciente::printPaciente(Paciente* p) {
    std::cout << "CPF Do paciente: " + std::to_string(p->getCpf()) << std::endl;
    std::cout << "Nome do paciente: " + p->getNomeCompleto() << std::endl;
    std::cout << "Cartão do Sus: " + p->getCartaoSus() << std::endl;
    std::cout << "Tipo atendimento: "<< to_string(p->tipo_atendimento()) << std::endl;
    std::cout << std::endl;
}
