
import java.security.SecureRandom;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        SecureRandom rand = new SecureRandom();
        int calc = in.nextInt();
        try { calc /= rand.nextInt(4); }
        catch (ArithmeticException e) {
            System.out.println("ERRORE: Divisione per 0.");
        }

    }
}