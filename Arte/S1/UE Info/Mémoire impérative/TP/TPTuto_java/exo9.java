public class exo9 {
    public static void main(String[] args) {
        Integer tmp, x;
        x = Integer.valueOf(args[0]);
        System.out.println("Table de " + x);
        for(int i=0; i<11; i++) {
            tmp = i*x;
            System.out.println(x + " * " + i + " = " + tmp);
        
        }
    }
}