public class Frazione {
    private int num;
    private int den;

    Frazione (int num, int den) {
        if (den == 0) { throw new IllegalArgumentException("Il Denominatore non può essere 0"); }

        this.num = num;
        this.den = den;
    }

    Frazione (Frazione altra) {
        this.num = altra.num;
        this.den = altra.den;
    }

    public int getNum() {
        return this.num;
    }

    public int getDen() {
        return this.den;
    }

    public Frazione somma(Frazione altra) {
        return new Frazione(this.num * altra.den + altra.num * this.den, this.den * altra.den);
    }

    public Frazione sottrazione(Frazione altra) {
        return new Frazione(this.num * altra.den - altra.num * this.den, this.den * altra.den);
    }

    public Frazione moltiplicazione(Frazione altra) {
        return new Frazione(this.num * altra.num, this.den * altra.den);
    }

    public Frazione divisione(Frazione altra) {
        return new Frazione(this.num * altra.den, this.den * altra.num);
    }

    public Frazione semplifica() {
        int mcd = mcd(this.num, this.den);

        return new Frazione(this.num/mcd, this.den/mcd);
    }

    public int confronto(Frazione altra) {
        float ris = (float)this.num / this.den - (float)altra.num / altra.den;
        if (ris < 0) {
            return 1;
        } if (ris > 0) {
            return 2;
        } else {
            return 0;
        }

    }

    @Override
    public String toString() {
        return this.num + "/" + this.den;
    }

    public boolean equals(String altra) {
        if (altra == null) { return false; }
        Frazione appoggio = new Frazione(this);
        
        if (appoggio.toString().equals(altra)) { return true; }
        
        return appoggio.semplifica().toString().equals(altra);
    }

    public Frazione inversa() {
        if (this.num == 0) { throw new ArithmeticException("NON si può fare l'inverso di una frazione con numeratore 0"); }
        return new Frazione(this.den, this.num);
    }

    private int mcd(int a, int b) {
        if (b == 0) return a;
        return mcd(b, a % b);
    }
}
