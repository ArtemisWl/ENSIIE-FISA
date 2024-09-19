public class exo13 {

    public static int pow2(int n) {
        int res=1;
        for (int i = 0; i<=n; i++) {
            res *= 2;
        }
        return res;
    }

    public static void main(String[] args) {
        int i = 0;
        while (pow2(i)<=147483647) {
            if (147483647 < pow2(i+1)) {
                System.out.println("La puissance de 2 maximale est : " + i);
                break;
            }
            else {
                i += 1;
            }
        }
    }
}