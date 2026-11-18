public class Contatore {
    int a;
    
    Contatore() {
        a = 0;
    }

    Contatore(int a) {
        a = this.a;
    }

    void inc() {
        a += 1;
    }

    void reset() {
        a = 0;
    }
}