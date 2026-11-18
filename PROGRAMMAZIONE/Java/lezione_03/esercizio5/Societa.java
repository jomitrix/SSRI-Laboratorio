import java.util.ArrayList;
import java.util.Collections;

public class Societa {
    private String nome;
    private String locazione;
    private ArrayList<Dipendente> personale = new ArrayList<>();
    private int countDipend;

    public Societa(String nome, String locazione) {
        this.nome = nome;
        this.locazione = locazione;
        countDipend = 0;
    }

    public void aggiungiDipendente(String nome, String cognome, int giornoNascita, int meseNascita, int annoNascita, double salario) {
        aggiungiDipendente(nome, cognome, giornoNascita, meseNascita, annoNascita, salario, 0);
    }

    public void aggiungiDipendente(String nome, String cognome, int giornoNascita, int meseNascita, int annoNascita, double salario, double bonus) {
        if (bonus != 0) {
            personale.add(new Manager(nome, cognome, giornoNascita, meseNascita, annoNascita, salario, bonus));
        } else {
            personale.add(new Dipendente(nome, cognome, giornoNascita, meseNascita, annoNascita, salario));
        }

        countDipend++;
    }

    public String getNome() {
        return nome;
    }

    public String getLocazione() {
        return locazione;
    }

    public int getNumeroDipendenti() {
        return countDipend;
    }

    @Override
    public String toString() {
        String app = "Società " + nome + "di " + locazione + "\nLista Dipendenti:\n";
        Collections.sort(personale);

        for (Dipendente el : personale) {
            app += el.toString() + "\n";
        }
        return app;
    }
}