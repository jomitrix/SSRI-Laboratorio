public class Manager extends Dipendente {
    private double bonus;

    public Manager(String nome, String cognome, int giornoNascita, int meseNascita, int annoNascita, double salario, double bonus) {
        super(nome, cognome, giornoNascita, meseNascita, annoNascita, salario+bonus);
        this.bonus = bonus;
    }

    public double getBonus() {
        return bonus;
    }

    public void setBonus(double bonus) {
        setSalario(getSalario() - this.bonus + bonus);
        this.bonus = bonus;
        
    }

    public double getSalarioParz() {
        return getSalario() - bonus;
    }

    @Override
    public String toString() {
        return super.toString() + ", di cui bonus: " + bonus;
    }
}