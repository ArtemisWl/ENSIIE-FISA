public class exo17 {

    public static void table(int x) {
        int tmp;
        System.out.println("Table de " + x + " : ");
        for(int i=0; i<11; i++) {
            tmp = i*x;
            System.out.println(x + " * " + i + " = " + tmp);
        }
    }
    
    public static double logm(int n, int m){
        double tmp = n;
        System.out.print("Le log de " + n + "en base " + m + " est :");
        while(tmp > m) {
            tmp /= m;
            if((tmp == m) || (Math.floor(tmp) == m)) {
                tmp = Math.floor(tmp);
                System.out.println(tmp);
                return (double)tmp;
            }
        }
        return 0.0;
    }
    public static void main(String[] args) {
        table(4);
        logm(17,4);
    }
}