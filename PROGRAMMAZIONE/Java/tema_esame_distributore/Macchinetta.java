import java.util.ArrayList;
import java.util.Collections;
import java.lang.StringBuilder;

public class Macchinetta {
    private ArrayList<Prodotto> prodotti;

    public Macchinetta() {
        prodotti = new ArrayList<>();
    }

    public void aggiungiProdotto(Prodotto prod) {
        prodotti.add(prod);
    }

    public Merendina compraMerendina(int soldi, int calorie) {
        for (int i = 0; i < prodotti.size(); i++) {
            if (prodotti.get(i) instanceof Merendina && prodotti.get(i).getCosto() <= soldi && ((Merendina) prodotti.get(i)).getCalorie() <= calorie) {
                Merendina comprata = (Merendina) prodotti.get(i);
                prodotti.remove(i);
                return comprata;
            }
        }
        return null;
    }

    public Bevanda compraBevanda(int soldi, int volume) {
        for (int i = 0; i < prodotti.size(); i++) {
            if (prodotti.get(i) instanceof Bevanda && prodotti.get(i).getCosto() <= soldi && ((Bevanda) prodotti.get(i)).getVolume() >= volume) {
                Bevanda comprata = (Bevanda) prodotti.get(i);
                prodotti.remove(i);
                return comprata;
            }
        }

        return null;
    }

    public void printSort() {
        Macchinetta copy = this;
        Collections.sort(copy.prodotti);
        System.out.println(copy.toString());
    }
 
    @Override
    public String toString() {
        StringBuilder result = new StringBuilder("");
        for (Prodotto el : prodotti) {
            if (el instanceof Merendina) {
                result.append( ((Merendina) el).toString());
            } else {
                result.append( ((Bevanda) el).toString() );
            }

            result.append("\n");
        }

        return result.toString();
    }
}