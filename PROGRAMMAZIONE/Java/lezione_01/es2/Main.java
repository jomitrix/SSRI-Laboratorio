public class Main {
    public static void main(String[] args) {
        double a = 5.34;
        double b = 3.21;

        Complex comp = new Complex(a, b);
        Complex compConiug = comp.coniug();

        System.out.println("Parte Reale: " + comp.re());
        System.out.println("Parte Immaginaria: " + comp.im());
        System.out.println("Modulo: " + comp.mod());
        System.out.println("Coniugato: " + compConiug.re() + compConiug.im() + "i");

    }
}
