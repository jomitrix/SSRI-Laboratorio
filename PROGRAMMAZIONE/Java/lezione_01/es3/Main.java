class Main {
    public static void main(String[] args) {
        Vett centro1 = new Vett(0, 0);
        Vett centro2 = new Vett(1, 1);
        Cerchio c1 = new Cerchio(centro1, 5);
        Cerchio c2 = new Cerchio(centro2, 3);

        Segmento s1 = new Segmento(new Vett(0, 0), new Vett(4, 0));
        Segmento s2 = new Segmento(new Vett(0, 0), new Vett(0, 3));
        Segmento s3 = new Segmento(new Vett(4, 0), new Vett(0, 3));

        Figura figura = new Figura(c1, c2, s1, s2, s3);

        System.out.println("Cerchi concentrici? " + figura.cerchiConcentrici());
        System.out.println("Linee che si intersecano? " + figura.lineeIntersecate());
        System.out.println("Formano un triangolo? " + figura.formanoTriangolo());
        System.out.println("Tipo di triangolo: " + figura.tipoTriangolo());
    }
}
