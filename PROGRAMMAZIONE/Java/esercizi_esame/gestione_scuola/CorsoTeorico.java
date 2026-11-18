public class CorsoTeorico extends Corso {
    private final int numeroOre;

    public CorsoTeorico(String nome, int numeroPosti, int costoIscrizione, int numeroOre) {
        super(nome, numeroPosti, costoIscrizione);
        this.numeroOre = numeroOre;
    }

    public int getNumeroOre() {
        return numeroOre;
    }

    @Override
    public String toString() {
        return super.toString() + "\nNumero ore: " + numeroOre;
    }
}