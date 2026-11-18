public class Merendina extends Prodotto {
    private int calorie;

    public Merendina(int costo, String nome, int calorie) {
        super(costo, nome);
        this.calorie = calorie;
    }

    public int getCalorie() {
        return calorie;
    }

    @Override
    public String toString() {
        return getNome() + " (" + calorie + " kCal) : EUR " + getCosto();
    }
}