
import java.security.SecureRandom;

public class Main {
    public static void main(String[] args) throws Exception {
        SecureRandom rand = new SecureRandom();
        RealSet set1 = new RealSet();
        RealSet set2 = new RealSet();
        RealSet set3 = new RealSet();
        
        for (int i = 0; i < 10; i++) {
                double eq = rand.nextDouble() * 101;
                set1.insertElement(eq);
                set2.insertElement(eq);
                set3.insertElement(rand.nextDouble(101));
        }
        set1.insertElement(1);
        set2.insertElement(1);

        System.out.println(set1.toString());
        //System.out.println(set2.toString());
        System.out.println(set3.toString());

        System.out.println("");
        set1.deleteElement(1);
        set2.deleteElement(1);

        System.out.println(set1.toString());
        //System.out.println(set2.toString());
        System.out.println(set3.toString());

        System.out.println("\nset1-2" + set1.isEqualTo(set2) + "\nset1-3" + set1.isEqualTo(set3) + "\n");

        System.out.println("union 1-3: " + RealSet.union(set1, set3).toString());
        System.out.println("intersection 1-3: " + RealSet.intersection(set1, set3).toString());
    }
}