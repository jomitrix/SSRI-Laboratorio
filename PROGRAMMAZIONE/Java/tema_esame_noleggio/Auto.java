public class Auto extends Veicolo {
    private int numeroPorte;

    public Auto(int id, String marca, String modello, int costoGiornaliero, int numeroPorte) {
        super(id, marca, modello, costoGiornaliero);
        this.numeroPorte = numeroPorte;
    }

    public int getNumeroPorte() {
        return numeroPorte;
    }

    public String toString() {
        return super.toString() + " - Porte: " + numeroPorte;
    }
}