public class VettTri extends Vett {
    private double z;

    protected VettTri(double x, double y, double z) {
        super(x, y);
        this.z = z;
    }

    protected VettTri(VettTri other) {
        super(other);
        this.z = other.z;
    }

    protected double getZ() {
        return z;
    }

    protected void move(double x, double y, double z) {
        super.move(x, y);
        this.z = z;
    }

    protected double distance(VettTri other) {
        return Math.sqrt(
            Math.pow(this.getX() - other.getX(), 2) +
            Math.pow(this.getY() - other.getY(), 2) +
            Math.pow(this.z - other.z, 2));
    }

    @Override
    protected double originDistance() {
        return Math.sqrt(Math.pow(getX(), 2) + Math.pow(getY(), 2) + Math.pow(z, 2));
    }

    protected boolean equals(VettTri other) {
    if (this == other) return true;
        if (other == null) return false;
        
        return Double.compare(super.getX(), other.getX()) == 0 &&
               Double.compare(super.getY(), other.getY()) == 0 &&
               Double.compare(this.z, other.z) == 0;
    }

}