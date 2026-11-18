public class IntegerSet {
    protected  static final int SZ = 101;
    private boolean[] set;


    public IntegerSet() {
        set = new boolean[SZ];
        for (int i = 0; i < SZ; i++) {
            set[i] = false;
        }
    }

    public boolean isPresent(int num) {
        if (num < 0 || num > 100) { return false; }
        return set[num];
    }

    public void insertElement(int num) {
        if (num < 0 || num > 100) { throw new IllegalArgumentException("ERRORE: Il valore NON fa parte del set."); }
        
        set[num] = true;
    }

    public void deleteElement(int num) {
        if (num < 0 || num > 100) { throw new IllegalArgumentException("ERRORE: Il valore NON fa parte del set."); }
        
        set[num] = false;
    }

    public static IntegerSet union(IntegerSet set1, IntegerSet set2) throws Exception {
        if (set1 == null || set2 == null ) { throw new IllegalArgumentException("ERRORE: Non è possibile fare unioni di questi oggetti."); }

        IntegerSet setRes = new IntegerSet();

        for (int i = 0; i < SZ; i++) {
            if(set1.isPresent(i) || set2.isPresent(i)) { setRes.insertElement(i); } 
        }

        return setRes;
    }

    public static IntegerSet intersection(IntegerSet set1, IntegerSet set2) throws Exception {
        if (set1 == null || set2 == null ) { throw new IllegalArgumentException("ERRORE: Non è possibile fare intersezioni di questi oggetti."); }

        IntegerSet setRes = new IntegerSet();

        for (int i = 0; i < SZ; i++) {
            if(set1.isPresent(i) && set2.isPresent(i)) { setRes.insertElement(i); } 
        }

        return setRes;
    }

    @Override
    public String toString() {
        String app = "[ ";
        boolean check = false;

        for (int i = 0; i < SZ; i++) {
            if (set[i] == true) { app += (i + " "); check = true; }
        }

        if(!check) { app += "-- "; }

        app += "]";

        return app;
    }

    public boolean isEqualTo(Object o) {
        if (this == o) return true;
        if (o == null) return false;

        IntegerSet other = (IntegerSet) o;
        for (int i = 0; i < SZ; i++) {
            if (this.isPresent(i) != other.isPresent(i)) return false;
        }

        return true;
    }

    @Override
    public boolean equals(Object o) {
        return isEqualTo(o);
    }
}