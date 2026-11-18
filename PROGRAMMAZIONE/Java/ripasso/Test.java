import java.security.SecureRandom;

public class Test {
    public static void main(String[] args) {
        SecureRandom rand = new SecureRandom();

        System.out.println((rand.nextDouble() * 10));
    }
}