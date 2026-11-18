public class Main {
    public static void main(String[] args) {
        try {
            int[] v = new int[2];
            v[2] = 3;
        } catch (IndexOutOfBoundsException e) {
            System.err.println("Ciucc");
        }
    }
}