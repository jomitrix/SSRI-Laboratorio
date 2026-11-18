import java.util.Scanner;

public class Solver {
    public static void main(String[] args) {
        try {
            Macchinetta macchinetta = new Macchinetta();
            int saldo = 0;
            Scanner in = new Scanner(System.in);
            String line;
            
            while (in.hasNextLine()) {
                line = in.nextLine();
                String[] requests = line.trim().split(" ");

                switch (requests[0]) {
                    case "B":
                        macchinetta.aggiungiProdotto(new Bevanda(Integer.parseInt(requests[2]), requests[1], Integer.parseInt(requests[3])));
                        break;
                    case "M":
                        macchinetta.aggiungiProdotto(new Merendina(Integer.parseInt(requests[2]), requests[1], Integer.parseInt(requests[3])));
                        break;
                    case "S":
                        int soldi = Integer.parseInt(requests[1]);
                        if (soldi < 0) {
                            throw new IllegalArgumentException("Saldo negativo non consentito!");
                        }
                        saldo += soldi;
                        break;
                    case "CB":
                        Bevanda bevanda = macchinetta.compraBevanda(saldo, Integer.parseInt(requests[1]));
                        if (bevanda != null) {
                            saldo -= bevanda.getCosto();
                            System.out.println("Ho bevuto " + bevanda.getNome());
                        } else {
                            System.out.println("Impossibile comprare la bevanda.");
                        }
                        break;
                    case "CM":
                        Merendina merendina = macchinetta.compraMerendina(saldo, Integer.parseInt(requests[1]));
                        if (merendina != null) {
                            saldo -= merendina.getCosto();
                            System.out.println("Ho mangiato " + merendina.getNome());
                        } else {
                            System.out.println("Impossibile comprare la merendina.");
                        }
                        break;
                    case "SORT":
                        macchinetta.printSort();
                        break;
                    case "F":
                        System.out.println("Programma Terminato.");
                        return;
                    default:
                        System.out.println("Comando non valido.");
                }
            }
        } catch (Exception e) {
            System.out.println("ERRORE: " + e.getMessage());
        }
    }
}
