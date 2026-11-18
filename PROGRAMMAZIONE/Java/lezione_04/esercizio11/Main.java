
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try {
            int number;
            Scanner in = new Scanner(System.in);

            number = Integer.parseInt(in.nextLine());
            
        } catch (NumberFormatException e) {
            System.err.println("suc");
        }
    }
}