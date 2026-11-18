public class Bevanda extends Prodotto {
    private final int volume;

    public Bevanda(String nome, int costo, int volume) {
        super(nome, costo);
        if(volume <= 0) throw new IllegalArgumentException("\nERRORE: Il volume NON può essere negativo.\n");
        this.volume = volume;
    }

    public int getVolume() {
        return volume;
    }

    @Override
    public String toString() {
        return super.toString() + " | Volume: " + volume +" cl";
    }
}