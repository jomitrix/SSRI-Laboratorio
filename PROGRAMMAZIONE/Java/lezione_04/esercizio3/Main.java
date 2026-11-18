import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try {
        if (args.length != 2) { throw new IllegalArgumentException("ERRORE: Parametri File NON validi.\nUso: \"java Main.java <file_da_leggere> <file_da_scrivere>\""); }

        File writeCheck = new File(args[1]);
        Scanner in = new Scanner(System.in);

        if (!writeCheck.createNewFile()) {
            System.out.println("Il file " + args[1] + " esiste già, si intende sovrascriverlo? (y/N)");
            if (in.nextLine().charAt(0) != 'y') { System.out.println("L'operazione è stata annullata."); return; }
        }

        FileReader read = new FileReader(args[0]);
        FileWriter write = new FileWriter(args[1]);

        int character;
        while ((character = read.read()) != -1) {
            write.write(character);
        }
        System.out.println("Il file è stato scritto con successo!");


        } catch (IllegalArgumentException e) {
            e.getMessage();
        } catch (FileNotFoundException e) {
            System.out.println("ERRORE: Il file \"" + args[0] + "\" NON esiste.");
        } catch (IOException e) {
            System.out.println("ERRORE: Il file \"" + args[1] + "\" NON esiste.");
        }
    }
}