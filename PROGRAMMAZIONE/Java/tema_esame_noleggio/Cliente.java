import java.util.List;
import java.util.ArrayList;

public class Cliente {
    private int id;
    private String nome;
    List<Veicolo> veicoliNoleggiati;

    public Cliente(int id, String nome) {
        this.id = id;
        this.nome = nome;
        veicoliNoleggiati = new ArrayList<>();
    }

    public int getId() {
        return id;
    }

    public String getNome() {
        return nome;
    }

    public boolean noleggia(Veicolo v) {
        return veicoliNoleggiati.add(v);
    }

    public Veicolo ritorna(int idVeicolo) {
        for (Veicolo v : veicoliNoleggiati) {
            if (idVeicolo == v.getId()) {
                veicoliNoleggiati.remove(v);
                return v;
            }
        }
        return null;
    }

    public String toString() {
        return id + " | " + nome;
    }
}