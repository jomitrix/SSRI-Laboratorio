import java.util.ArrayList;
import java.util.List;

public class Utente {
    private int id;
    private final String nome;
    private final List<Libro> libriInPrestito;

    public Utente(int id, String nome) {
        this.id = id;
        this.nome = nome;
        libriInPrestito = new ArrayList<>();
    }

    public int getId() {
        return id;
    }    

    public String getNome() {
        return nome;
    }

    public boolean prendiLibro(Libro l) {
        for (Libro el : libriInPrestito) {
            if (el.getId() == l.getId()) return false;
        }

        return libriInPrestito.add(l);
    }

    public Libro ritornaLibro(int idLibro) {
        for (Libro el : libriInPrestito) {
            if (el.getId() == idLibro)  {
                libriInPrestito.remove(el);
                return el;
            }
        }

        return null;
    }

    @Override
    public String toString() {
        return id + " | " + nome;
    }

}