
import java.security.SecureRandom;

/*
A partire dal metodo scritto in C, implementate una funzione che effettui un
BubbleSort di un array di tipo Object in Java. Potete implementarlo come metodo
statico o definendo una classe wrapper che faccia da contenitore per un oggetto
generico. Testare con un main.
*/

public class Main {
    public static void main(String[] args) {
        SecureRandom rand = new SecureRandom();
        Integer[] list = new Integer[20];
        for (int i = 0; i < 20; i++) {
            list[i] = rand.nextInt(100) + 1;
        }
        System.out.print("[\t");
        for (int i = 0; i < 20; i++) {
            System.out.print(list[i] + ",\t");
        }
        System.out.print("]\n");

        sort(list);

        System.out.print("[\t");
        for (int i = 0; i < 20; i++) {
            System.out.print(list[i] + ",\t");
        }
        System.out.print("]\n");
    }

    public static <T extends Comparable<T>> void sort(T[] arr) {
        boolean sorted;
        do { 
            sorted = true;
            for (int i = 0; i < arr.length - 1; i++) {
                if (arr[i].compareTo(arr[i+1]) > 0) {
                    T app = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = app;

                    sorted = false;
                }
            }
        } while (!sorted);
    }
}