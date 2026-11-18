import java.util.ArrayList;
import java.util.List;

public class Biblioteca {
    private final List<Libro> listaLibri;
    private final List<Utente> listaUtenti;

    public Biblioteca() {
        listaLibri = new ArrayList<>();
        listaUtenti = new ArrayList<>();
    }

    public boolean registraUtente(Utente u) {
        for (Utente el : listaUtenti) {
            if (el.getId() == u.getId()) return false;
        }

        return listaUtenti.add(u);
    }

    public boolean aggiungiLibro(Libro l) {
        for (Libro el : listaLibri) {
            if (el.getId() == l.getId()) return false;
        }

        return listaLibri.add(l);
    }

    public Libro prestaLibro(int idLibro, int idUtente) {
        Utente u = null;
        Libro l = null;

        for (Utente el : listaUtenti) {
            if (el.getId() == idUtente) {
                u = el;
            }
        }

        for (Libro el : listaLibri) {
            if (el.getId() == idLibro) {
                l = el;
            }
        }

        if (u != null & l != null) {
            if ((u.prendiLibro(l)) && (listaLibri.remove(l))) return l;
        }

        return null;
    }
    
    public Libro restituisciLibro(int idLibro, int idUtente) {
        Utente u = null;
        Libro l = null;

        for (Utente el : listaUtenti) {
            if (el.getId() == idUtente) {
                u = el;
            }
        }

        if (u != null) {
            l = u.ritornaLibro(idLibro);
            if (l != null) {
                aggiungiLibro(l);
            }
        }
        return l;
    }
}