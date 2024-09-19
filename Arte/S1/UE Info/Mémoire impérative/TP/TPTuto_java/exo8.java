public class exo8 {
    public static void main(String[] args) {
        double x, y, res;
        x = 3.14;
        y = 2.71;
        res = x - y;
        if ((res >= 0 && res < 0.001) || (res < 0 && res > 0.001)) {
            System.out.println("Les chiffres entrées sont égaux");      
        }
        else {
            System.out.println("Les chiffres entrées ne sont pas égaux");
        }
    }
}