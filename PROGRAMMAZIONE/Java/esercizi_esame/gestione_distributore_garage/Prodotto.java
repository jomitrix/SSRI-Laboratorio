public abstract class Prodotto implements Comparable<Prodotto> {
    private final String nome;
    private final int costo;

    public Prodotto(String nome, int costo) {
        if (costo < 0) throw new IllegalArgumentException("\nERRORE: Il costo NON può essere negativo.\n");

        this.nome = nome;
        this.costo = costo;
    }

    public String getNome() {
        return nome;
    }

    public int getCosto() {
        return costo;
    }

    @Override
    public int compareTo(Prodotto other) {
        return Integer.compare(this.costo, other.getCosto());
    }

    @Override
    public String toString() {
        return nome + ": € " + costo;
    }
}