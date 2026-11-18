import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Nome File: ");
        File file = new File(input.nextLine());

        Scanner read;

        try {
            read = new Scanner(file);
        } catch (FileNotFoundException e) {
            System.err.println("ERRORE: Il file NON esiste.");
            return;
        }

        int n = 0;

        try {
            if (read.hasNextLine()) {
                n = Integer.parseInt(read.nextLine());
                for (int i = 0; i < n && read.hasNextLine(); i++) {
                    String buffer = read.nextLine().trim();                    
                }
            }
        } catch (NumberFormatException e) {
            System.err.println("ERRORE: Il file NON è formattato correttamente");
            return;
        }
        read.close();
    }
}