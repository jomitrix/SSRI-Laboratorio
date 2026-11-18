public class Linea {
    private Vett a;
    private Vett b;

    Linea(Vett a, Vett b) {
        this.a = new Vett(a);
        this.b = new Vett(b);
    }

    Linea(Linea altraLinea) {
        this.a = new Vett(altraLinea.getA());
        this.b = new Vett(altraLinea.getB());
    }

    double distanzaPunti() {
        return a.distanza(b);
    }

    boolean equals(Linea altraLinea) {
        return a.equals(altraLinea.getA()) && b.equals(altraLinea.getB());
    }

    Linea copy() {
        return new Linea(this);
    }

    Vett getA() {
        return a;
    }

    Vett getB() {
        return b;
    }
}
