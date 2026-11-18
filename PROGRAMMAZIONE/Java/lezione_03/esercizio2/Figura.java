abstract class Figura implements Comparable<Figura> {
    abstract double getPerimetro();
    abstract double getArea();

    public int compareTo(Figura other) {
        return Double.compare(this.getArea(), other.getArea());
    }
}