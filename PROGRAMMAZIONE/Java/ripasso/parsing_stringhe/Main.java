import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        StringBuilder a = new StringBuilder();
        Scanner input = new Scanner(System.in);

        String[] query = input.nextLine().trim().split(" ");
        String first = query[0];
        int last = 0;

        for (int i = 1; i < (query.length); i++) {
            last = i;
            a.append(query[i].replace("\"", ""));
            if(query[i].endsWith("\"")) break;
            a.append(" ");
        }
        if (last == query.length-1) System.out.println("\nERRORE\n");
        String end = query[query.length-1];
        System.out.println(first + a.toString() + end);
    }
}