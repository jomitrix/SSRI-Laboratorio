import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Solver {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Persona> listaPersone = new ArrayList<>();
        Garage garage = new Garage();
        int size;

        System.out.print("Quante persone si vogliono inserire? > ");
        try {
            size = Integer.parseInt(scanner.nextLine());
            if (size <= 0) throw new IllegalArgumentException();
        } catch (NumberFormatException | IllegalArgumentException e) {
            System.err.println("\nERRORE: Il numero di persone NON è valido\n");
            return;
        }

        for (int i = 0; i < size; i++) {
            System.out.println("Persona " + (i + 1));
            System.out.print("Nome: ");
            String nomeIn = scanner.nextLine();
            System.out.print("Modello auto: ");
            String modelloIn = scanner.nextLine();
            System.out.print("Targa auto: ");
            String targaIn = scanner.nextLine();

            boolean targaPresente = false;
            for (Persona p : listaPersone) {
                if (targaIn.equals(p.getAuto().getTarga())) {
                    System.err.println("\nERRORE: Questa targa è delle macchina di un'altra persona.\n");
                    targaPresente = true;
                    break;
                }
            }
            if (targaPresente) continue;

            try {
                listaPersone.add(new Persona(nomeIn, new Auto(modelloIn, targaIn)));
            } catch (IllegalArgumentException e) {
                System.err.println(e.getMessage());
                return;
            }
        }

        while (true) {
            System.out.println("Gestione Garage\n---------------\n- \"E <nome persona>\" (parcheggia macchina di <persona>)\n- \"U <nome persona>\" (rimuovi macchina di <persona>)\n- \"F\" (chiudi programma)\n> ");
            String input = scanner.nextLine().trim();
            String[] query = input.split(" ");

            if (query.length == 0) {
                System.err.println("\nERRORE: Input vuoto.\n");
                continue;
            }

            boolean personaTrovata = false;

            switch (query[0]) {
                case "E":
                case "U":
                    if (query.length < 2) {
                        System.err.println("\nERRORE: Nome non specificato.\n");
                        continue;
                    }
                    for (Persona p : listaPersone) {
                        if (query[1].equals(p.getNome())) {
                            if (query[0].equals("E")) {
                                p.parcheggia(garage);
                            } else {
                                p.rimuoviAuto(garage);
                            }
                            personaTrovata = true;
                            break;
                        }
                    }
                    if (!personaTrovata) {
                        System.err.println("\nERRORE: Persona NON trovata.\n");
                    }
                    break;
                case "F":
                    System.out.println("Programma Terminato");
                    scanner.close();
                    return;
                default:
                    System.err.println("\nERRORE: Scelta NON valida.\n");
                    break;
            }
        }
    }
}
