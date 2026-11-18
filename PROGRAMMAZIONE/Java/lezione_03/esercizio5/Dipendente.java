public class Dipendente extends Persona implements Comparable<Dipendente> {
    private double salario;

    public Dipendente(String nome, String cognome, int giornoNascita, int meseNascita, int annoNascita, double salario) {
        super(nome, cognome, giornoNascita, meseNascita, annoNascita);
        this.salario = salario;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    @Override
    public String toString() {
        return super.toString() + ", con salario di EUR " + salario;
    }

    @Override
    public int compareTo(Dipendente other) {
        return Double.compare(other.salario, this.salario);
    }
}