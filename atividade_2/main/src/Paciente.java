public class Paciente {
    private long cpf;
    private String nome_completo;
    private String cartao_sus;
    private TIPO_ATENDIMENTO tipo_atendimento;

    private Paciente esquerda;
    private Paciente direita;

    public Paciente(long cpf, String nome_completo, String cartao_sus, TIPO_ATENDIMENTO tipo_atendimento) {
        this.cpf = cpf;
        this.nome_completo = nome_completo;
        this.cartao_sus = cartao_sus;
        this.tipo_atendimento = tipo_atendimento;
    }

    public long getCpf() {
        return cpf;
    }

    public void setCpf(long cpf) {
        this.cpf = cpf;
    }

    public String getNome_completo() {
        return nome_completo;
    }

    public void setNome_completo(String nome_completo) {
        this.nome_completo = nome_completo;
    }

    public String getCartao_sus() {
        return cartao_sus;
    }

    public void setCartao_sus(String cartao_sus) {
        this.cartao_sus = cartao_sus;
    }

    public TIPO_ATENDIMENTO getTipo_atendimento() {
        return tipo_atendimento;
    }

    public void setTipo_atendimento(TIPO_ATENDIMENTO tipo_atendimento) {
        this.tipo_atendimento = tipo_atendimento;
    }

    public Paciente getEsquerda() {
        return esquerda;
    }

    public void setEsquerda(Paciente esquerda) {
        this.esquerda = esquerda;
    }

    public Paciente getDireita() {
        return direita;
    }

    public void setDireita(Paciente direita) {
        this.direita = direita;
    }
}
