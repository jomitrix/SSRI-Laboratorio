import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try {
        if (args.length != 1) {
            throw new IllegalArgumentException("ERRORE: Inserire un parametro valido.\nUtilizzo \"java Main.java <nome_file>\"");
        }

        File read = new File(args[0]);
        Scanner fileRead = new Scanner(read);

        while (read.canRead() && fileRead.hasNextLine()) {
            System.out.println(fileRead.nextLine());
        }

        } catch (IllegalArgumentException e) {
            System.err.println(e.getMessage());
        } catch (FileNotFoundException e) {
            System.err.println("ERRORE: Il file NON esiste.");
        }
    }
}