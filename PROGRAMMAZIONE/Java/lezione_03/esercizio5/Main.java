import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Societa societa = new Societa("TechCorp", "Milano");

        // Aggiunta di dipendenti e manager predefiniti
        societa.aggiungiDipendente("Mario", "Rossi", 13, 9, 2005, 1500);
        societa.aggiungiDipendente("Luca", "Neri", 11, 3, 1995, 1500);
        societa.aggiungiDipendente("Manuele", "Verdi", 3, 1, 2000, 1500);
        societa.aggiungiDipendente("Giorgio", "Peni", 23, 7, 2001, 1600);
        societa.aggiungiDipendente("Edoardo", "Bianchi", 3, 1, 1989, 1500, 500);
        societa.aggiungiDipendente("Nicola", "Grigi", 1, 11, 1979, 1500, 1000);

        // Stampa dei dipendenti predefiniti
        
        System.out.println(societa);

        // Aggiunta di nuovi dipendenti e manager tramite input utente
        while (true) {
            System.out.println("Vuoi aggiungere un dipendente o un manager (d/m) o uscire (e)? ");
            String tipo = in.nextLine();

            if (tipo.equalsIgnoreCase("e")) {
                break;
            }

            System.out.print("Nome: ");
            String nome = in.nextLine();

            System.out.print("Cognome: ");
            String cognome = in.nextLine();

            System.out.print("Data di nascita (D/M/AAAA): \nD: ");
            int giornoNascita = in.nextInt();
            System.out.print("M: ");
            int meseNascita = in.nextInt();
            System.out.print("AAAA: ");
            int annoNascita = in.nextInt();

            System.out.print("Salario: ");
            double salario = in.nextDouble();

            if (tipo.equalsIgnoreCase("m")) {
                System.out.print("Bonus: ");
                double bonus = in.nextDouble();
                societa.aggiungiDipendente(nome, cognome, giornoNascita, meseNascita, annoNascita, salario, bonus);
            } else {
                societa.aggiungiDipendente(nome, cognome, giornoNascita, meseNascita, annoNascita, salario);
            }

            in.nextLine(); // consume newline
        }

        // Stampa dei dipendenti aggiornati
        System.out.println("Dipendenti aggiornati:");
        System.out.println(societa);

        in.close();
    }
}