import java.util.Scanner;


public class Hello {

   public static void main(String[] args) {
      // Stampa una riga e va a capo.
      System.out.println("Hello, World!");
      // Stampa una riga e non va a capo).
      System.out.print("Hello, World!");
      // Stampa una riga con formattazione.
      System.out.printf("Hello, %s!\n", "World");

      // Creiamo un oggetto scanner
      @SuppressWarnings("resource")
      Scanner scan = new Scanner(System.in);  
      // Leggi un intero
      System.out.println("Ora inserisci un intero.");
      int i = scan.nextInt();
      System.out.printf("Hai inserito, %d.\n", i);      

   }
}