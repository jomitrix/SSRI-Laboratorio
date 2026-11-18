public class RealSet extends IntegerSet {
    public RealSet() {
        super();
    }

    public boolean isPresent(double num) {
        return super.isPresent((int) Math.floor(num));
    }

    public void insertElement(double num) throws Exception {
        super.insertElement((int) Math.floor(num));
    }

    public void deleteElement(double num) throws Exception {
        super.deleteElement((int) Math.floor(num));
    }

    public static RealSet union(RealSet set1, RealSet set2) {
        if (set1 == null || set2 == null ) { throw new IllegalArgumentException("ERRORE: Non è possibile fare unioni di questi oggetti."); }

        RealSet setRes = new RealSet();

        for (int i = 0; i < SZ; i++) {
            if(set1.isPresent(i) || set2.isPresent(i)) { setRes.insertElement(i); } 
        }

        return setRes;
    }

    public static RealSet intersection(RealSet set1, RealSet set2) {
        if (set1 == null || set2 == null ) { throw new IllegalArgumentException("ERRORE: Non è possibile fare intersezioni di questi oggetti."); }

        RealSet setRes = new RealSet();

        for (int i = 0; i < SZ; i++) {
            if(set1.isPresent(i) && set2.isPresent(i)) { setRes.insertElement(i); } 
        }

        return setRes;
    }

    @Override
    public boolean isEqualTo(Object o) {
        if (this == o) return true;
        if (o == null) return false;

        RealSet other = (RealSet) o;
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