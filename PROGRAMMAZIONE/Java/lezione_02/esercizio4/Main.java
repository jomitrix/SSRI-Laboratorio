package lezione2.esercizio4;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Stringa originale: ");
        String input = scanner.nextLine();
        System.out.println("Stringa invertita: " + invertita(input));
    }

    public static String invertita(String input) {
        char[] arr = new char[input.length()];

        for (int i = 0; i < input.length(); i++) {
            arr[i] = input.charAt(input.length() - 1 - i);
        }

        return new String(arr);
    }
}
