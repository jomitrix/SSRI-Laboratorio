public class Linea {
    private Vett punto1;
    private Vett punto2;

    public Linea(Vett punto1, Vett punto2) {
        this.punto1 = punto1;
        this.punto2 = punto2;
    }

    public double lunghezza() {
        return Math.sqrt(Math.pow(punto2.getX() - punto1.getX(), 2) + Math.pow(punto2.getY() - punto1.getY(), 2));
    }
}