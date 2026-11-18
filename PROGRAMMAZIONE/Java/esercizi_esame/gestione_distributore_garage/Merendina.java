public class Merendina extends Prodotto {
    private final int calorie;

    public Merendina(String nome, int costo, int calorie) {
        super(nome, costo);
        if(calorie < 0) throw new IllegalArgumentException("\nERRORE: Le calorie NON possono essere negative.\n");
        this.calorie = calorie;
    }

    public int getCalorie() {
        return calorie;
    }

    @Override
    public String toString() {
        return super.toString() + " | Calorie: " + calorie +" kCal";
    }
}