public class exo20 {
    
    
    public static int abs(int n){
        if (n >= 0){
            return n;
        }
        else {
            return -n;
        }
    }

    public static void norme1(int n) {
        int t = 2 * n + 1; 
        for (int i = 0; i < t; i++) {
            for (int j = 0; j < t; j++) {
                if (abs(i - n) + abs(j - n) <= n) {
                    System.out.print("*");
                } else {
                    System.out.print(" ");
                }
            }
            System.out.println("");
        }
    }
        
    public static void main(String[] args) {
        Integer n = Integer.valueOf(args[0]);
        norme1(n);
    }
}