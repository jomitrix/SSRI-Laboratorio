public class Main {
    public static void main(String[] args) {
        try {
            // Test 1: Creazione con dimensione massima specificata
            UniqueArrayList list1 = new UniqueArrayList(5);
            System.out.println(list1.toString());
            list1.add("Goku");
            System.out.println(list1.toString());
            list1.add('a');
            System.out.println(list1.toString());
            list1.add(1);
            System.out.println(list1.toString());
            list1.add(new Character('d'));
            System.out.println(list1.toString());
            list1.add("Pelon");
            System.out.println(list1.toString());
            list1.add(5);
            System.out.println(list1.toString());
            list1.add(69);
            System.out.println(list1.toString());

        } catch (Exception e) {
            System.out.println("Errore: " + e.getMessage());
        }
    }
}
