public class Main {
    public static void main(String[] args) {
        Contatore cont = new Contatore();

        System.out.println("Prima " + cont.a);
        cont.inc();
        System.out.println("Seconda " + cont.a);
    }
}
