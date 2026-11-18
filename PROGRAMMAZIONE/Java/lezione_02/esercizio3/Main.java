package lezione2.esercizio3;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Stringa Input: ");
        String stringa = scanner.nextLine();

        String newStringa = stringa.charAt(stringa.length() - 1) + stringa.substring(1, stringa.length() - 1) + stringa.charAt(0);

        System.out.println("Stringa Output: " + newStringa);
        scanner.close();
    }
}