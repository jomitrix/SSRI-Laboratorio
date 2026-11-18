public class Persona {
    private final String nome;
    private final Auto auto;

    public Persona(String nome, Auto auto) {
        this.nome = nome;
        this.auto = auto;
    }

    public String getNome() {
        return nome;
    }

    public Auto getAuto() {
        return auto; 
    }

    public boolean parcheggia(Garage garage) {
        return garage.aggiungiAuto(auto);
    }

    public boolean rimuoviAuto(Garage garage) {
        return garage.rimuoviAuto(auto);
    }

    @Override
    public String toString() {
        return nome + " con macchina: " + auto.getModello();
    }

}