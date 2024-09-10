public class exo14 {
    public static void main(String[] args) {
        Integer n;
        n = Integer.valueOf(args[0]);
        for(int i = 0; i < n; i++) {
            if ((i == 0) || (i == n-1)) {
                for(int j = 0; j < n; j++){
                    System.out.print("* ");
                    if (j==n-1){
                        System.out.println("");
                    }
                }
            }
            else {
                for(int j = 0; j < n; j++){
                    if (j == 0) {
                        System.out.print("* ");
                    }
                    else if(j == n-1) {
                        System.out.println("*");
                    }
                    else {
                        System.out.print("  ");
                    }
                }
            }
        }
    }
}