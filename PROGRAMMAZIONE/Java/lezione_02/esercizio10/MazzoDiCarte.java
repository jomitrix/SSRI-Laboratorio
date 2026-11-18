import  java.security.SecureRandom;

public class MazzoDiCarte {
    static final int N_CARTE = 52;
    private static final SecureRandom rand = new SecureRandom();
    Carta[] mazzo;

    public MazzoDiCarte() {
        mazzo = new Carta[N_CARTE];
        int i = 0;
        while (i < N_CARTE) {
            for (Semi seme : Semi.values())
                for (Valori valore : Valori.values())
                    if (i < N_CARTE) { mazzo[i++] = new Carta(seme, valore); }
        }
    }

    public void mescola() {
        for (int i = 0; i < N_CARTE-2; i++) {
            int shift = rand.nextInt(N_CARTE - i) + i;
            Carta app = mazzo[i];
            mazzo[i] = mazzo[shift];
            mazzo[shift] = app;
        }
    }

    @Override
    public String toString() {
        String result = "";
        for (Carta el : mazzo) {
            result += el.toString() + "\n";
        }

        return result;
    }
}