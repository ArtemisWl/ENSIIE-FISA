public class exo19 {

    public static void triangle(int n) {
        int base = 2*n - 1;
        for(int i = 0; i < n; i++) {
            if (i == 0) {
                for(int j = 0; j < base; j++) {
                    System.out.print("*");
                    if (j == base - 1) {
                        System.out.println("");
                    }
                }    
            }
            else {
                for(int j = 0; j < base; j++) {
                    if( j == 0 || j == base -1 || j == base) {
                        System.out.print("*");
                        if(j == base -1 || j == base) {
                            System.out.println("");
                        }
                    }
                    else {
                        System.out.print(" ");
                    }
                }
            }
            base -= 2;
        }
    }

    public static void main(String[] args) {
        triangle(4);
    }
}