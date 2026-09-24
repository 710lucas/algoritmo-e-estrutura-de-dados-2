//
// Created by Lucas Perônico Barbotin on 21/09/26.
//

#ifndef ATIVIDADE_3_TIPOATENDIMENTO_H
#define ATIVIDADE_3_TIPOATENDIMENTO_H

#include <string>

enum TipoAtendimento {
  TRIAGEM, VACINACAO, CONSULTA_AGENDADA
};

inline std::string to_string(TipoAtendimento tipo) {
  switch (tipo) {
    case TipoAtendimento::TRIAGEM : return "Triagem";
    case TipoAtendimento::CONSULTA_AGENDADA: return "Consulta Agendada";
    case TipoAtendimento::VACINACAO: return "Vacinação";
    default: break;
  }
}

#endif //ATIVIDADE_3_TIPOATENDIMENTO_H
