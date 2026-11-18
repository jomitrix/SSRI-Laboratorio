import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        Matrix m1 = new Matrix(2, 2);
        for (int i = 0; i < m1.rows(); i++) {
            for (int j = 0; j < m1.columns(); j++) {
                System.out.printf("Inserisci valore alla r%d e c%d -> ", i+1, j+1);
                m1.setValore(i, j, input.nextInt());
            }
        }

        Matrix m2 = new Matrix(2, 2);
        for (int i = 0; i < m1.rows(); i++) {
            for (int j = 0; j < m1.columns(); j++) {
                System.out.printf("Inserisci valore alla r%d e c%d -> ", i+1, j+1);
                m2.setValore(i, j, input.nextInt());
            }
        }

        Matrix ms = m1.sum(m2);
        ms.print();
        ms = m1.multiply(m2);
        ms.print();
        ms = m1.scalar(3);
        ms.print();
    }
}
