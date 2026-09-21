void main() {

    GerenciadorPacientes g = new GerenciadorPacientes();

    g.cadastrar_paciente(
            0000000004,
            "Paciente 4",
            "444.444",
            TIPO_ATENDIMENTO.CONSULTA_AGENDADA
    );

    g.cadastrar_paciente(
            0000000001,
            "Paciente 1",
            "111.111",
            TIPO_ATENDIMENTO.TRIAGEM
    );

    g.cadastrar_paciente(
            0000000003,
            "Paciente 3",
            "333.333",
            TIPO_ATENDIMENTO.VACINACAO
    );

    g.cadastrar_paciente(
            0000000005,
            "Paciente 5",
            "555.555",
            TIPO_ATENDIMENTO.VACINACAO
    );


    g.cadastrar_paciente(
            0000000002,
            "Paciente 2",
            "222.222",
            TIPO_ATENDIMENTO.CONSULTA_AGENDADA
    );

    g.cadastrar_paciente(
            0000000006,
            "Paciente 6",
            "666.666",
            TIPO_ATENDIMENTO.TRIAGEM
    );

    g.cadastrar_paciente(
            0000000006,
            "Paciente 6",
            "666.666",
            TIPO_ATENDIMENTO.TRIAGEM
    );

    for (int i = 0; i <= 6; i++) {
        g.buscar_paciente(i);
        System.out.println();
    }
}
