public class Moto extends Veicolo {
    private int cilindrata;

    public Moto(int id, String marca, String modello, int costoGiornaliero, int cilindrata) {
        super(id, marca, modello, costoGiornaliero);
        this.cilindrata = cilindrata;
    }

    public int getCilindrata() {
        return cilindrata;
    }

    public String toString() {
        return super.toString() + " - Cilindrata: " + cilindrata;
    }
}