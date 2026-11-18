public class Segmento {
    private Vett a;
    private Vett b;

    Segmento(Vett a, Vett b) {
        this.a = new Vett(a);
        this.b = new Vett(b);
    }

    Segmento(Segmento altroSegmento) {
        this.a = new Vett(altroSegmento.getA());
        this.b = new Vett(altroSegmento.getB());
    }

    double lunghezza() {
        return a.distanza(b);
    }

    boolean equals(Segmento altroSegmento) {
        return a.equals(altroSegmento.getA()) && b.equals(altroSegmento.getB());
    }

    Segmento copy() {
        return new Segmento(this);
    }

    Vett getA() {
        return a;
    }

    Vett getB() {
        return b;
    }
}
