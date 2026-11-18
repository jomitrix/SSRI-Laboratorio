public class Rettangolo extends Figura {
    double base;
    double altezza;

    public Rettangolo(double base, double altezza) throws Exception {
        if (base < 0 || altezza < 0) { throw new IllegalArgumentException("ERRORE: Valori NON validi."); }
        this.base = base;
        this.altezza = altezza;
    }

    public double getBase() {
        return base;
    }

    public double getAltezza() {
        return altezza;
    }

    public void setBase(double base) {
        this.base = base;
    }

    public void setAltezza(double altezza) {
        this.altezza = altezza;
    }

    @Override
    public double getPerimetro() {
        return 2 * base + 2 * altezza;
    }

    @Override
    public double getArea() {
        return base * altezza;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null) return false;
        
        Rettangolo other = (Rettangolo) o;
        return this.base == other.base && this.altezza == other.altezza;
    }

    @Override
    public String toString() {
        return "Rettangolo: b: " + this.base + " h: " + this.altezza + "\nArea: " + getArea() + "\n";
    }
    
}