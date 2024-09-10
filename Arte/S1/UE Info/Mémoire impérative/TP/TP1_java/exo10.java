public class exo10 {
    public static double logm(int n, int m){
        double tmp = n;

        System.out.println("Le log de " + n + " en base " + m + " est : ");
        while(tmp > m) {
            tmp /= m;
            if((tmp == m) || (Math.floor(tmp) == m)) {
                tmp = Math.floor(tmp);
                System.out.println(tmp);
                return tmp;
            }
        }
        return 0.0;
    }

    public static void main(String[] args) {
        logm(17, 4);
    }

}