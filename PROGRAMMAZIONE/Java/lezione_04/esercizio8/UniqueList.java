import java.util.ArrayList;
import java.util.List;

public class UniqueList<T> {
    List<T> list;
    int count;

    public UniqueList() {
        list = new ArrayList<>();
        count = 0;
    }

    public boolean add(T elem) throws IllegalArgumentException {
        if (elem == null) { throw new IllegalArgumentException("ERRORE: L'elemento è NULL."); }

        if (list.contains(elem) == true) {
            list.add(elem);
            count++;
            return true;
        } else {
            return false;
        }
    }

    public T elemAt(int index) {
        return list.get(index);
    }

    public int elemCount() {
        return count;
    }

    public T lastInserted() {
        return list.get(count-1);
    }

    @Override
    public String toString() {
        return list.toString();
    }
}