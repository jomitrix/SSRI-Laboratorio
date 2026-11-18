import java.util.Scanner;

public class Solver {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Macchinetta m = new Macchinetta();
        int saldo = 0;
        String[] query;

        do {
            System.out.print("Menu\n-----\n- B nome costo volume\n- M nome costo calorie\n- S soldi\n- CB volume\n- CM calorie\n- F\n> ");

            try {
                query = input.nextLine().trim().split(" ");

                switch (query[0]) {
                    case "B":
                        if (query.length < 4) throw new IllegalArgumentException();
                        String nomeB = query[1];
                        int costoB = Integer.parseInt(query[2]);
                        int volumeB = Integer.parseInt(query[3]);

                        Bevanda b = new Bevanda(nomeB, costoB, volumeB);
                        if (m.aggiungiProdotto(b)) {
                            System.out.println("\nAggiunto: " + b +"\n");
                        } else {
                            System.err.println("\nERRORE: Prodotto NON valido.\n");
                        }
                        break;
                    case "M":
                        if (query.length < 4) throw new IllegalArgumentException();
                        String nomeM = query[1];
                        int costoM = Integer.parseInt(query[2]);
                        int calorieM = Integer.parseInt(query[3]);

                        Merendina mer = new Merendina(nomeM, costoM, calorieM);
                        if (m.aggiungiProdotto(mer)) {
                            System.out.println("\nAggiunto: " + mer +"\n");
                        } else {
                            System.err.println("\nERRORE: Prodotto NON valido.\n");
                        }
                        break;
                    case "S":
                        if (query.length < 2) throw new IllegalArgumentException();
                        if (Integer.parseInt(query[1]) <= 0) throw new IllegalArgumentException();

                        saldo += Integer.parseInt(query[1]);

                        System.out.println("\nSaldo aggiornato: " + saldo + "\n");
                        break;
                    case "CB":
                        if (query.length < 2) throw new IllegalArgumentException();

                        int cVolume = Integer.parseInt(query[1]);

                        Bevanda bComprata = m.compraBevanda(saldo, cVolume);

                        if (bComprata != null) {
                            System.out.println("\nBevuto: " + bComprata +"\n");
                            saldo -= bComprata.getCosto();
                        }

                        break;
                    case "CM":
                        if (query.length < 2) throw new IllegalArgumentException();

                        int cCalorie = Integer.parseInt(query[1]);

                        Merendina mComprata = m.compraMerendina(saldo, cCalorie);

                        if (mComprata != null) {
                            System.out.println("\nMangiato: " + mComprata +"\n");
                            saldo -= mComprata.getCosto();
                        }
                        break;
                    case "SORT":
                        m.sort();
                        m.print();
                        break;
                    case "F":
                        System.out.println("\nProgramma Terminato.");
                        input.close();
                        return;
                    default:
                        System.err.println("\nERRORE: Scelta NON valida.\n");
                }
            } catch (IllegalArgumentException e) {
                System.out.println("\nERRORE: Input Malformato o Dati NON validi.\n");
            }
        } while (input.hasNextLine());
    }
}
