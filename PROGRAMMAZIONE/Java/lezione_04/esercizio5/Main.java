import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String nomeFile;
        int n;
        ArrayList<Triangolo> triangoli = new ArrayList<>();

        System.out.print("Inserisci nome file: ");
        nomeFile = in.nextLine();

        try {
            File read = new File(nomeFile);
            Scanner readFile = new Scanner(read);
            n = Integer.parseInt(readFile.nextLine());
            for (int i = 0; i < n; i++) {
                String[] buff;
                buff = readFile.nextLine().split(" ");
                triangoli.add(new Triangolo(
                    new Vett(Double.parseDouble(buff[0]), Double.parseDouble(buff[1])),
                    new Vett(Double.parseDouble(buff[2]), Double.parseDouble(buff[3])),
                    new Vett(Double.parseDouble(buff[4]), Double.parseDouble(buff[5])))
                    );
            }
            readFile.close();

            for (int i = 0; i < triangoli.size(); i++) {
                System.out.println(triangoli.get(i).toString());
            }

            int countDegen = 0;
            double mediaAree = 0;
            int indiceDiAreaMin = 0;

            double min = Double.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                if (triangoli.get(i).isDegen()) { countDegen++; }

                mediaAree += triangoli.get(i).calcolaArea();

                if (!(triangoli.get(i).isDegen())) {
                    if (triangoli.get(i).calcolaArea() < min) { min = triangoli.get(i).calcolaArea(); indiceDiAreaMin = i; }
                }
            }
            mediaAree /= n;
            
            Collections.sort(triangoli);
            System.out.println("1) Numero triangoli: " + n);
            System.out.println("2) Numero triangoli degeneri: " + countDegen);
            System.out.println("3) Media aree triangoli: " + mediaAree);
            System.out.println("4) Indice di area min: " + indiceDiAreaMin);

            System.out.println();

            for (int i = 0; i < triangoli.size(); i++) {
                System.out.println(triangoli.get(i).toString());
            }
        } catch (FileNotFoundException e) {
            System.out.println("ERRORE: Il file NON esiste.");
        }
    }
}