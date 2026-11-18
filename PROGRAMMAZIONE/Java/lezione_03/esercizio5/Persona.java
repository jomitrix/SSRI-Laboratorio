abstract class Persona {
    private final String nome;
    private final String cognome;
    private final int giornoNascita;
    private final int meseNascita;
    private final int annoNascita;

    public Persona(String nome, String cognome, int giornoNascita, int meseNascita, int annoNascita) {
        this.nome = nome;
        this.cognome = cognome;
        this.giornoNascita = giornoNascita;
        this.meseNascita = meseNascita;
        this.annoNascita = annoNascita;
    }

    public String getNome() {
        return nome;
    }

    public String getCognome() {
        return cognome;
    }

    public int getGiornoNascita() {
        return giornoNascita;
    }
    public int getMeseNascita() {
        return meseNascita;
    }
    public int getAnnoNascita() {
        return annoNascita;
    }

    @Override
    public String toString() {
        return nome + " " + cognome + ", nato il " + giornoNascita
                + "/" + meseNascita + "/" + annoNascita;
    }

}