

public class Auto {
    private final String modello;
    private String targa;

    public Auto (String modello, String targa) throws NumberFormatException, IllegalArgumentException {
        this.modello = modello;
        if (Integer.parseInt(targa) < 100 || Integer.parseInt(targa) > 999) throw new IllegalArgumentException("\nERRORE: Formato targa NON valido.\n");
        this.targa = targa;
    }

    public String getModello() {
        return modello;
    }
    
    public String getTarga() {
        return targa;
    }

    @Override
    public String toString() {
        return "Targa: " + targa + " - Modello: " + modello;
    }
    
}