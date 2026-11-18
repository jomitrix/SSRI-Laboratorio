public class Figura {
    private Cerchio cerchio1;
    private Cerchio cerchio2;
    private Segmento segmento1;
    private Segmento segmento2;
    private Segmento segmento3;

    public Figura(Cerchio c1, Cerchio c2, Segmento s1, Segmento s2, Segmento s3) {
        this.cerchio1 = c1;
        this.cerchio2 = c2;
        this.segmento1 = s1;
        this.segmento2 = s2;
        this.segmento3 = s3;
    }

    public boolean cerchiConcentrici() {
        return cerchio1.isConcentric(cerchio2);
    }

    public boolean lineeIntersecate() {
        // Placeholder: sempre false per semplicità
        return false;
    }

    public boolean formanoTriangolo() {
        double l1 = segmento1.lunghezza();
        double l2 = segmento2.lunghezza();
        double l3 = segmento3.lunghezza();
        return (l1 + l2 > l3) && (l1 + l3 > l2) && (l2 + l3 > l1);
    }

    public TriangleType tipoTriangolo() {
        if (!formanoTriangolo()) {
            return TriangleType.NONE;
        }
        double l1 = segmento1.lunghezza();
        double l2 = segmento2.lunghezza();
        double l3 = segmento3.lunghezza();
        if (l1 == l2 && l2 == l3) {
            return TriangleType.EQUILATERO;
        } else if (l1 == l2 || l1 == l3 || l2 == l3) {
            return TriangleType.ISOSCELE;
        } else {
            return TriangleType.SCALENO;
        }
    }
}
