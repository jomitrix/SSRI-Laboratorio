public abstract class Corso {
    private final String nome;
    private int numeroPosti;
    private final int costoIscrizione;

    public Corso(String nome, int numeroPosti, int costoIscrizione) {
        this.nome = nome;
        this.numeroPosti = numeroPosti;
        this.costoIscrizione = costoIscrizione;
    }

    public boolean iscrivi() {
        if (numeroPosti > 0) {
            numeroPosti--;
            return true;
        }
        return false;
    }

    public String getNome() {
        return nome;
    }

    public int getNumeroPosti() {
        return numeroPosti;
    }

    public int getCostoIscrizione() {
        return costoIscrizione;
    }

    @Override
    public String toString() {
        return "Corso " + nome + ": " + numeroPosti + " posti. Costo: € " + costoIscrizione;
    }
}