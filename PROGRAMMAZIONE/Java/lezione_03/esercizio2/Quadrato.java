public class Quadrato extends Rettangolo {
    public Quadrato(double lato) throws Exception {
        super(lato, lato);
    }

    public double getLato() {
        return super.getBase();
    }

    public void setLato(double lato) {
        setBase(lato);
        setAltezza(lato);
    }

    @Override
    public double getPerimetro() {
        return 4 * base;
    }

    @Override
    public String toString() {
        return "Quadrato: l: " + super.getBase() + "\nArea: " + getArea() + "\n";
    }
    
}