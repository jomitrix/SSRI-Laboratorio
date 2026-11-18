import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class Noleggio {
    List<Veicolo> listaVeicoli;
    List<Cliente> listaClienti;

    public Noleggio() {
        listaVeicoli = new ArrayList<>();
        listaClienti = new ArrayList<>();
    }

    public boolean aggiungiVeicolo(Veicolo veicolo) {
        for (Veicolo v : listaVeicoli) {
            if (v.getId() == veicolo.getId()) return false;
        }
        return listaVeicoli.add(veicolo);
    }

    public boolean registraCliente(Cliente cliente) {
        for (Cliente c : listaClienti) {
            if (c.getId() == cliente.getId()) return false;
        }
        return listaClienti.add(cliente);
    }

    public boolean noleggiaVeicolo(int idVeicolo, int idCliente) {
        Veicolo vNol = null;
        Cliente cNol = null;

        for (Veicolo v : listaVeicoli) {
            if (v.getId() == idVeicolo) {
                vNol = v;
                break;
            }
        }

        for (Cliente c : listaClienti) {
            if (c.getId() == idCliente) {
                cNol = c;
                break;
            }
        }

        if (vNol != null && cNol != null) {
            System.out.println("\n" + cNol);
            System.out.println("\n" + vNol);
            return (cNol.noleggia(vNol) && listaVeicoli.remove(vNol));
        }

        return false;
        
    }

    boolean restituisciVeicolo(int idVeicolo, int idCliente) {
        Veicolo vNol = null;
        Cliente cNol = null;

        for (Cliente c : listaClienti) {
            if (c.getId() == idCliente) {
                cNol = c;
                break;
            }
        }

        if (cNol != null) {
            vNol = cNol.ritorna(idVeicolo);
            System.out.println("\n" + cNol);
            System.out.println("\n" + vNol);
            if (vNol != null) {
                return aggiungiVeicolo(vNol);
            }
        }

        return false;
    }

    public void sort() {
        Collections.sort(listaVeicoli);
    }

    public void print() {
        System.out.println("\nLista\n");
        for (Veicolo el : listaVeicoli) {
            System.out.println(el);
        }
    }
}