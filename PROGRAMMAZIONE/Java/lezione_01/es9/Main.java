public class Main {
    public static void main(String[] args) {
        Frazione frazione = new Frazione(20, 4);
        Frazione altra = new Frazione(20, 4);
        String test = "5/1";

        frazione = new Frazione(frazione.semplifica());

        System.out.println(frazione.toString());
        System.out.println(altra.toString());

        System.out.println(frazione.confronto(altra));

        System.out.println(altra.equals(test));

        System.out.println(frazione.inversa().toString());


    }
}
