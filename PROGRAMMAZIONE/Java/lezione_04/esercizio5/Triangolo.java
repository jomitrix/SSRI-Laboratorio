public class Triangolo implements Comparable<Triangolo> {
    private Vett puntoA;
    private Vett puntoB;
    private Vett puntoC;

    public Triangolo(Vett puntoA, Vett puntoB, Vett puntoC) {
        this.puntoA = puntoA;
        this.puntoB = puntoB;
        this.puntoC = puntoC;
    }

    public double calcolaArea() {
        double latoAB = new Linea(puntoA, puntoB).lunghezza();
        double latoBC = new Linea(puntoB, puntoC).lunghezza();
        double latoCA = new Linea(puntoC, puntoA).lunghezza();
        double semiPerimetro = (latoAB + latoBC + latoCA) / 2;
        return Math.sqrt(semiPerimetro * (semiPerimetro - latoAB) * (semiPerimetro - latoBC) * (semiPerimetro - latoCA));
    }

    public boolean isDegen() {
        return calcolaArea() == 0.0;
    }

    public int compareTo(Triangolo other) {
        return Double.compare(this.calcolaArea(), other.calcolaArea());
    }

    public String toString() {
        return "Triangolo: " + puntoA.toString() + "; " +  puntoB.toString() + "; " +  puntoC.toString() + "\n Area: " + calcolaArea();
    }
}