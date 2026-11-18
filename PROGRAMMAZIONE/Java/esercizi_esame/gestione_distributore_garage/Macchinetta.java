import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Macchinetta {
    private final List<Prodotto> listaProdotti;

    public Macchinetta() {
        listaProdotti = new ArrayList<>();
    }

    public boolean aggiungiProdotto(Prodotto p) {
        return listaProdotti.add(p);
    }

    Merendina compraMerendina(int soldi, int calorie) {
        for (Prodotto p : listaProdotti) {
            if (p instanceof Merendina merendina) {
                if (merendina.getCosto() <= soldi && merendina.getCalorie() <= calorie) {
                    listaProdotti.remove(p);
                    return merendina;
                }
            }
        }

        return null;
    }

    Bevanda compraBevanda(int soldi, int volume) {
        for (Prodotto p : listaProdotti) {
            if (p instanceof Bevanda bevanda) {
                if (bevanda.getCosto() <= soldi && bevanda.getVolume() >= volume) {
                    listaProdotti.remove(p);
                    return bevanda;
                }
            }
        }

        return null;
    }

    void sort() {
        Collections.sort(listaProdotti);
    }

    void print() {
        System.out.println("Disponibilità:");
        for (Prodotto p : listaProdotti) {
            System.out.println(p);
        }
    }
}