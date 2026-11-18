public class Carta {
    Semi seme;
    Valori valore;

    public Carta(Semi seme, Valori valore) {
        this.seme = seme;
        this.valore = valore;
    }

    @Override
    public String toString() {
        return valore.name() + " di " + seme.name();
    }
}