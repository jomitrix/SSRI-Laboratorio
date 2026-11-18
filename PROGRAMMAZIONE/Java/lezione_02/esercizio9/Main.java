public class Main {
    private static final int NUMERO_FACCE  = 20;
    private static final int N_LANCI = 200;

    public static void main(String[] args) {
        try {
            Dado dado = new Dado(NUMERO_FACCE );
            int[] countResult = new int[NUMERO_FACCE ];
            
            for (int i = 0; i < N_LANCI; i++) {
                int temp = dado.lancia() - 1;
                countResult[temp]++;
            }

            for (int i = 0; i < NUMERO_FACCE ; i++) {
                System.out.println("Faccia " + (i+1) + ": " + countResult[i] + " occorrenze");
            }


        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
 
    }
}