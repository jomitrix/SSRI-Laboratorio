import java.security.SecureRandom;

public class Dado {
    

    private final int n_facce;
    private static final SecureRandom rand = new SecureRandom();
    public Dado(int n_facce) throws Exception {
        if (n_facce < 1) { throw new IllegalArgumentException("ERRORE: Numero facce NON valido."); }
        this.n_facce = n_facce;
    }

    public int lancia() {
        return rand.nextInt(n_facce) + 1;
    }

    public static int lancioStatico(int numeroFacce) {
        if (numeroFacce < 1) {throw new IllegalArgumentException("ERRORE: Numero facce NON valido."); }
        return rand.nextInt(numeroFacce) + 1;
    }

    public int getFacce() {
        return n_facce;
    }

}