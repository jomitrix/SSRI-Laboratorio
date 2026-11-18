import java.util.Scanner;

public class Solver {
    public static void main(String[] args) {
        Biblioteca b = new Biblioteca();
        Scanner input = new Scanner(System.in);
        String[] query;
        boolean menu = true;
        int idL, idU, last;
        StringBuilder titolo, autore, nome;
        

        while (menu) {
            query = input.nextLine().trim().split(" ");
            try {
                switch (query[0]) {
                    case "ADDLIBRO":
                        if (query.length < 4) { throw new Exception(); }
                        idL = Integer.parseInt(query[1]);
                        titolo = new StringBuilder();

                        last = 0;

                        for(int i = 2; i < query.length; i++) {
                            last = i;
                            titolo.append(query[i].replace("\"", ""));
                            titolo.append(" ");
                            if (query[i].endsWith("\"")) break;
                        }

                        if (last+1 == query.length) {
                            throw new Exception();
                        }

                        autore = new StringBuilder();
                        for(int i = last+1; i < query.length; i++) {
                            autore.append(query[i].replace("\"", ""));
                            autore.append(" ");
                            if (query[i].endsWith("\"")) break;
                        }

                        Libro addL = new Libro(idL, titolo.toString().trim(), autore.toString().trim());
                        if (b.aggiungiLibro(addL)) {
                            System.out.println(addL.toString());
                        } else {
                            throw new Exception();
                        }
                        break;
                    case "ADDCLIENTE":
                        if (query.length < 3) { throw new Exception(); }

                        idU = Integer.parseInt(query[1]);

                        nome = new StringBuilder();

                        for(int i = 2; i < query.length; i++) {
                            nome.append(query[i].replace("\"", ""));
                            nome.append(" ");
                            if (query[i].endsWith("\"")) break;
                        }

                        Utente addU = new Utente(idU, nome.toString().trim());
                        if (b.registraUtente(addU)) {
                            System.out.println(addU.toString());
                        } else {
                            throw new Exception();
                        }
                        break;
                    case "PRESTA":
                        if (query.length < 3) { throw new Exception(); }

                        Libro resP;

                        if ((resP = b.prestaLibro(Integer.parseInt(query[1]), Integer.parseInt(query[2]))) == null) {
                            System.err.println("\nOperazione NON riuscita.\n");
                        } else {
                            System.out.println(resP.toString());
                        }
                        break;
                    case "RESTITUISCI":
                        if (query.length < 3) { throw new Exception(); }

                        Libro resR;

                        if ((resR = b.restituisciLibro(Integer.parseInt(query[1]), Integer.parseInt(query[2]))) == null) {
                            System.err.println("\nOperazione NON riuscita.\n");
                        } else {
                            System.out.println(resR.toString());
                        }
                        break;
                    case "END":
                        System.out.println("\nProgramma Terminato.");
                        menu = false;
                        break;
                    default:
                        System.err.println("\nERRORE: Scelta NON valida.\n");
                }
            } catch (NumberFormatException e) {
                System.err.println("\nERRORE: Numero non valido.\n");
            } catch (Exception e) {
                System.err.println("\nERRORE: Input NON valido.\n");
            }
        }
    }
}