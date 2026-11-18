import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        try {
            Password pass = new Password(input);
            System.out.println("Password valida.");
        } catch (Exception e) { 
            System.out.println("Errore: " + e.getMessage()); 
        }
    }
}
