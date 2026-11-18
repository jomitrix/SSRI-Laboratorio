public abstract class Veicolo implements Comparable<Veicolo> {
    private int id;
    private String marca;
    private String modello;
    private int costoGiornaliero;

    public Veicolo(int id, String marca, String modello, int costoGiornaliero) {
        this.id = id;
        this.marca = marca;
        this.modello = modello;
        this.costoGiornaliero = costoGiornaliero;
    }

    public int getId() {
        return id;
    }

    public String getMarca() {
        return marca;
    }

    public String getModello() {
        return modello;
    }

    public int getCosto() {
        return costoGiornaliero;
    }

    public int compareTo(Veicolo other) {
        return Double.compare(this.costoGiornaliero, other.getCosto());
    }

    public String toString() {
        return id + " | " + marca + " - " + modello + " - Costo: " + costoGiornaliero + " €/d";
    }
}