public class Vett {
    private double x, y;

    protected Vett(double x, double y) {
        this.x = x;
        this.y = y;
    }

    protected Vett(Vett other) {
        this.x = other.x;
        this.y = other.y;
    }

    protected double getX() {
        return x;
    }

    protected double getY() {
        return y;
    }

    protected void move(double x, double y) {
        this.x = x;
        this.y = y;
    }
    
    protected double distance(Vett other) {
        return Math.sqrt(
            Math.pow(this.x - other.x, 2) +
            Math.pow(this.y - other.y, 2));
    }

    protected double originDistance() {
        return Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
    }

    protected boolean equals(Vett other) {
        if (this == other) return true;
        if (other == null) return false;
        
        return Double.compare(this.x, other.x) == 0 &&
               Double.compare(this.y, other.y) == 0;
    }
    
    @Override
    public String toString() {
        return "(" + this.x + "; " + this.y + ")";
    }
}