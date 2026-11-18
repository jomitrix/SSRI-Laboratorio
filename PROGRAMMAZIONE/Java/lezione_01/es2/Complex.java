public class Complex {
    private double a;
    private double b;

    Complex() {
        a = 0;
        b = 0;
    }

    Complex(double a, double b) {
        this.a = a;
        this.b = b;
    }

    double re() {
        return a;
    }

    double im() {
        return b;
    }

    double mod() {
        return Math.sqrt(Math.pow(a, 2) * Math.pow(b, 2));
    }

    Complex coniug() {
        return new Complex(a, -b);
    }
}
