public class Cerchio {
    private Vett centro;
    private double raggio;
    private double circonferenza, area;

    Cerchio(Vett centro, double raggio) {
        this.centro = new Vett(centro);
        this.raggio = raggio;
        circonferenza = 2 * Math.PI * raggio;
        area = Math.PI * Math.pow(raggio, 2);
    }

    Cerchio(Cerchio altroCerchio) {
        this.centro = new Vett (altroCerchio.getCentro());
        this.raggio = altroCerchio.getRaggio();
    }

    Vett getCentro() {
        return centro;
    }

    double getRaggio() {
        return raggio;
    }

    double getCirconferenza() {
        return circonferenza;
    }

    double getArea() {
        return area;
    }

    boolean isConcentric(Cerchio altroCerchio) {
        return this.centro.getX() == altroCerchio.centro.getX() && this.centro.getY() == altroCerchio.centro.getY();
    }

    boolean contains(Cerchio altroCerchio) {
        double distanzaCentri = this.centro.distanza(altroCerchio.centro);
        return distanzaCentri + altroCerchio.raggio <= this.raggio;
    }

    boolean equals(Cerchio altroCerchio) {
        return this.centro.equals(altroCerchio.getCentro()) && this.raggio == altroCerchio.getRaggio();
    }

    Cerchio copy() {
        return new Cerchio(this);
    }
}
