import java.util.Arrays;

public class UniqueArrayList {
    private final Object[] arr; // Array di oggetti generici
    private final int size;
    private int count = 0;

    // Costruttore con dimensione massima
    public UniqueArrayList(int size) {
        if (size <= 0) {
            throw new IllegalArgumentException("La dimensione deve essere maggiore di zero.");
        }
        this.size = size;
        this.arr = new Object[size];
    }

    // Costruttore da array di oggetti
    public UniqueArrayList(Object[] arr) throws Exception {
        if (arr == null) {
            throw new IllegalArgumentException("L'array non può essere null.");
        }
        this.size = arr.length;
        this.arr = new Object[this.size];
        for (Object el : arr) {
            this.add(el); // Aggiunge elementi unici
        }
    }

    // Metodo per aggiungere un elemento
    public int add(Object el) throws Exception {
        if (el == null) {
            throw new IllegalArgumentException("L'elemento non può essere null.");
        }
        if (count >= size) {
            throw new Exception("L'ArrayList è pieno.");
        }
        for (int i = 0; i < count; i++) {
            if (arr[i].equals(el)) {
                return 0; // Duplicato, non aggiunto
            }
        }
        arr[count++] = el; // Aggiunge l'elemento unico
        return 1;
    }

    // Restituisce l'elemento alla posizione specificata
    public Object elemAt(int pos) throws IndexOutOfBoundsException {
        if (pos < 0 || pos >= count) {
            throw new IndexOutOfBoundsException("Indice Lista NON valido.");
        }
        return arr[pos];
    }

    // Restituisce il numero di elementi unici nella lista
    public int elemCount() {
        return count;
    }

    // Restituisce una rappresentazione stringa della lista
    @Override
    public String toString() {
        return Arrays.toString(Arrays.copyOf(arr, count));
    }
}
