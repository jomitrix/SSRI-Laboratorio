import java.util.ArrayList;
import java.util.List;

public class Garage {
    private final List<Auto> lista;

    public Garage() {
        lista = new ArrayList<>();
    }

    public boolean aggiungiAuto(Auto auto) {
        for (Auto a : lista) {
            if (a.getTarga().equals(auto.getTarga())) {
                System.err.println("\nERRORE: Esiste già una macchina targata \"" + auto.getTarga() +"\" nel garage.\n");
                return false;
            }
        }

        if(lista.add(auto)) {
            System.out.println("\nAuto parcheggiata con successo.\n");
            return true;
        }

        return false;
    }

    public boolean  rimuoviAuto(Auto auto) {
        for (Auto el : lista) {
            if (el.getTarga().equals(auto.getTarga())) {
                if (lista.remove(el)) {
                    System.out.println("\nAuto rimossa con successo.\n");
                    return true;
                }
            }
        }

        System.err.println("\nERRORE: L'auto NON è presente nel garage.\n");
        return false;
    }

    public void visualizzaAuto() {
        System.out.println("Lista Garage:");
        int i = 0;
        for (Auto el : lista) {
            i++;
            System.err.println(i + ") " + el.toString());
        }

        if (i == 0) System.out.println("Il garage è vuoto.");
    }
}