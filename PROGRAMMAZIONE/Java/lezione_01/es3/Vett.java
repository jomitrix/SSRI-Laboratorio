public class Vett {
    private double x, y;

    Vett() {
        this.x = 0;
        this.y = 0;
    }

    Vett(double x, double y) {
        this.x = x;
        this.y = y;
    }

    Vett(Vett altroPunto) {
        this.x = altroPunto.getX();
        this.y = altroPunto.getY();
    }

    void move(double xMove, double yMove) {
        this.x += xMove;
        this.y += yMove;
    }

    double distanzaOrigine() {
        return Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
    }

    double distanza(Vett otherPoint) {
        double distanceX = this.x - otherPoint.x;
        double distanceY = this.y - otherPoint.y;

        return Math.sqrt(Math.pow(distanceX, 2) + Math.pow(distanceY, 2));
    }

    boolean equals(Vett altroPunto) {
        return this.x == altroPunto.getX() && this.y == altroPunto.getY();
    }

    Vett copy() {
        return new Vett(this);
    }

    double getX() {
        return this.x;
    }

    double getY() {
        return this.y;
    }

    void setX(double x) {
        this.x = x;
    }

    void setY(double y) {
        this.y = y;
    }
}
