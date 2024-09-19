public class exo15 {

    public static  double gravite(int m1, int m2, int d) {
        double G = 6.67*Math.pow(10, -1);
        double res = (G*m1*m2)/d*d;
        return (res);
    }
    

    public static void main(String[] args) {
        double res = gravite(2,4,10);
        System.out.println("Le résultat est : " + res);
    }
}