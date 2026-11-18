
import java.util.*;

public class Scuola {
    List<Corso> listaCorsi;

    public Scuola() {
        listaCorsi = new ArrayList<>();
    }

    public void aggiungiCorso(Corso corso) {
        listaCorsi.add(corso);
    }

    public void mostraCorsiDisponibili() {
        System.out.println("Corsi disponibili:");
        for (Corso c : listaCorsi) {
            System.out.println(c.toString());
        }
    }
}