package lezione2.esercizio2;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Inserisci stringa\n> ");
        String stringa = scanner.nextLine().toUpperCase();

        System.out.println(stringa);

        System.out.println("Primo carattere = " + stringa.charAt(0) + stringa.charAt(stringa.length()-1));
        
        scanner.close();
    }
}