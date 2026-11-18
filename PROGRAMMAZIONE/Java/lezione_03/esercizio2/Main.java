
import java.security.SecureRandom;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        SecureRandom rand = new SecureRandom();
        Figura[] figure = new Figura[10];

        try {
            for (int i = 0; i < 10; i++) {
                if (rand.nextBoolean()) {
                    double base = 1 + rand.nextDouble() * 10;
                    double altezza = 1 + rand.nextDouble() * 10;
                    figure[i] = new Rettangolo(base, altezza);
                } else {
                    double lato = 1 + rand.nextDouble() * 10;
                    figure[i] = new Quadrato(lato);
                }
            }

            System.out.println("Non ordinato:\n" + Arrays.toString(figure));
            

            Arrays.sort(figure);

            System.out.println("Ordinato:\n" + Arrays.toString(figure));

            
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }
    }
}