public class CorsoPratico extends Corso {
    private final String attrezzaturaNecessaria;

    public CorsoPratico(String nome, int numeroPosti, int costoIscrizione, String attrezzaturaNecessaria) {
        super(nome, numeroPosti, costoIscrizione);
        this.attrezzaturaNecessaria = attrezzaturaNecessaria;
    }

    public String getInfo() {
        return attrezzaturaNecessaria;
    }

    @Override
    public String toString() {
        return super.toString() + "\nAttrezzatura Necessaria: " + attrezzaturaNecessaria;
    }
}