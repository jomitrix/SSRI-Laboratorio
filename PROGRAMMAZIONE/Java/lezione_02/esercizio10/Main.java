public class Main {
    public static void main(String[] args) {
        MazzoDiCarte mazzo = new MazzoDiCarte();

        System.out.println(mazzo.toString());
        System.out.println("--------------------------------------\n");
        mazzo.mescola();
        System.out.println(mazzo.toString());
    }
}