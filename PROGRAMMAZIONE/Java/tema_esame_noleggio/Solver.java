import java.util.Scanner;

public class Solver {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Noleggio n = new Noleggio();
        String[] query;

        do {
            try {
                query = input.nextLine().trim().split(" ");

                switch (query[0]) {
                    case "ADDVEICOLO":
                        if (query.length < 7) throw new IllegalArgumentException();

                        // Per le virgolette dovrei usare lo StringBuilder se ho tempo lo metto
                        int last = 0;
                        StringBuilder marcaFill = new StringBuilder();
                        for (int i = 3; i < query.length; i++) {
                            last = i;
                            marcaFill.append(query[i].replace("\"", ""));
                            if (query[i].endsWith("\"")) break;
                            marcaFill.append(" ");
                        }

                        StringBuilder modelloFill = new StringBuilder();
                        for (int i = last+1; i < query.length; i++) {
                            last = i;
                            modelloFill.append(query[i].replace("\"", ""));
                            if (query[i].endsWith("\"")) break;
                            modelloFill.append(" ");
                        }

                        if (query.length <= last+2) throw new IllegalArgumentException();

                        if (query[1].equals("AUTO")) {
                            Auto aAdd = new Auto(Integer.parseInt(query[2]), marcaFill.toString(), modelloFill.toString(), Integer.parseInt(query[query.length-2]), Integer.parseInt(query[query.length-1]));
                            if (n.aggiungiVeicolo(aAdd)) {
                                System.out.println("\n" + aAdd);
                            } else {
                                System.err.println("\nERRORE: Veicolo NON valido.\n");
                                // Da veicolo NON valido anche nel caso di ID UGUALI <--
                            }
                        } else if (query[1].equals("MOTO")) {
                            Moto mAdd = new Moto(Integer.parseInt(query[2]), marcaFill.toString(), modelloFill.toString(), Integer.parseInt(query[query.length-2]), Integer.parseInt(query[query.length-1]));
                            
                            if (n.aggiungiVeicolo(mAdd)) {
                                System.out.println("\n" + mAdd);
                            } else {
                                System.err.println("\nERRORE: Veicolo NON valido.\n");
                            }
                        } else {
                            throw new IllegalArgumentException();
                        }

                        break;
                    case "ADDCLIENTE":
                        if (query.length < 3) throw new IllegalArgumentException();

                        StringBuilder nomeFill = new StringBuilder();
                        for (int i = 2; i < query.length; i++) {
                            nomeFill.append(query[i].replace("\"", ""));
                            if (query[i].endsWith("\"")) break;
                            nomeFill.append(" ");
                        }

                        Cliente cAdd = new Cliente(Integer.parseInt(query[1]), nomeFill.toString());
                        if (n.registraCliente(cAdd)) {
                            System.out.println("\n" + cAdd);
                        } else {
                            System.err.println("\nERRORE: Cliente NON valido.\n");
                        }
                        break;
                    case "NOLEGGIA":
                        if (query.length < 3) throw new IllegalArgumentException();
                        if (!(n.noleggiaVeicolo(Integer.parseInt(query[1]), Integer.parseInt(query[2])))) {
                            System.err.println("\nERRORE: Operazione NON riuscita.\n");
                        }
                        break;
                    case "RESTITUISCI":
                        if (query.length < 3) throw new IllegalArgumentException();
                        if (!(n.restituisciVeicolo(Integer.parseInt(query[1]), Integer.parseInt(query[2])))) {
                            System.err.println("\nERRORE: Operazione NON riuscita.\n");
                        }
                        break;
                    case "SORT":
                        n.sort();
                        n.print();
                        break;
                    case "END":
                        System.out.println("\nProgramma Terminato.\n");
                        input.close();
                        return;
                    default:
                        System.err.println("\nERRORE: Scelta NON valida.\n");
                }
            } catch (IllegalArgumentException e) {
                System.err.println("\nERRORE: Input NON valido.\n");
            }

            System.out.println();
        } while (input.hasNextLine());

        return;
    }
}