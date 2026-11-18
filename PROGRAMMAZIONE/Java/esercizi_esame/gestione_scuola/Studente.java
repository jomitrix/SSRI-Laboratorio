import java.util.*;

public class Studente {
    private final String nome;
    private int saldo;
    List<Corso> corsi;

    public Studente(String nome, int saldo) {
        this.nome = nome;
        this.saldo = saldo;
        corsi = new ArrayList<>();
    }

    public boolean  iscriviAlCorso(Corso corso) {
        if (saldo >= corso.getCostoIscrizione() && corso.iscrivi()) {
            saldo -= corso.getCostoIscrizione();
            corsi.add(corso);
            return true;
        }
        return false;
    }

    public void mostraCorsiIscritti() {
        System.out.println("I corsi che frequenta " + nome + ":\n");
        for(Corso c : corsi) {
            System.err.println(c.toString());
        }
    }

    public void aggiugiSoldi(int soldi) {
        saldo+=soldi;
    }

    public String getNome() {
        return nome;
    }

    @Override
    public String toString() {
        return nome + " - Saldo: € " + saldo;
    }
}