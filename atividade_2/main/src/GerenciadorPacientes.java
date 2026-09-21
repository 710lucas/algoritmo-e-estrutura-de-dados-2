public class GerenciadorPacientes {

    private Paciente raiz = null;

    private int ALTURA_ULTIMA_CONSULTA = 0;

    public GerenciadorPacientes(Paciente raiz) {
        this.raiz = raiz;
    }

    public GerenciadorPacientes(){
        ;
    }

    public Paciente getRaiz() {
        return raiz;
    }

    public void setRaiz(Paciente raiz){
        this.raiz = raiz;
    }


    private Paciente getPai(long cpf, Paciente no) throws Exception{
        if(cpf > no.getCpf()){
            if(no.getDireita() == null) return no;
            return getPai(cpf, no.getDireita());
        } else if(cpf < no.getCpf()){
            if(no.getEsquerda() == null) return no;
            return getPai(cpf, no.getEsquerda());
        } else{
            throw new Exception("Paciente já existe!");
        }
    }

    public void cadastrar_paciente(long cpf, String nome, String cartao_sus, TIPO_ATENDIMENTO tipo_atendimento){
        Paciente p = new Paciente(
                cpf,
                nome,
                cartao_sus,
                tipo_atendimento
        );

        if(raiz == null){
            this.raiz = p;
            return;
        }

        try{
            Paciente pai = getPai(cpf, raiz);
            if(cpf > pai.getCpf())
                pai.setDireita(p);
            else
                pai.setEsquerda(p);
        } catch (Exception e) {
            System.err.println("Não foi possível cadastrar o paciente, pois ele já existe.");
        }

    }

    private Paciente getNo(long cpf, Paciente no, int altura) throws Exception{
        if(cpf == no.getCpf()){
            ALTURA_ULTIMA_CONSULTA = altura;
            return no;
        } else if(cpf > no.getCpf() && no.getDireita() != null){
            altura++;
            return getNo(cpf, no.getDireita(), altura);
        } else if(cpf < no.getCpf() && no.getEsquerda() != null){
            altura++;
            return getNo(cpf, no.getEsquerda(), altura);
        } else{
            throw new Exception("O CPF não foi encontrado na base de dados");
        }
    }

    public Paciente buscar_paciente(long cpf){
        try{
            Paciente p = getNo(cpf, raiz, 0);
            System.out.println("Quantidade de pulos para achar o paciente: " + cpf + ": " + ALTURA_ULTIMA_CONSULTA);
            System.out.println("CPF Do paciente: " + p.getCpf());
            System.out.println("Nome do paciente: " + p.getNome_completo());
            System.out.println("Cartão Sus do paciente " + p.getCartao_sus());
            System.out.println("Tipo Atendimento: " + p.getTipo_atendimento());
            return p;
        } catch (Exception e){
            System.err.println("O paciente com CPF " + cpf + " não foi encontrado na plataforma");
            return null;
        }
    }
}
