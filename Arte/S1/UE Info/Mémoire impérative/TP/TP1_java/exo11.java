public class exo11 {
    public static Integer somme(int n){
        int res = (n*(n+1))/2;
        System.out.println("La somme de tout les entiers de 0 à " + n + " est : " + res);
        return (res);
    }
    public static void main(String[] args) {
        
        Integer n = Integer.valueOf(args[0]);
        if (n < 10) {
            System.out.println("Le nombre choisi est inférieur à 10 donc le calcul sera éfféctué avec n = 10\n");
            somme(10);
        }
        else {
            somme(n);
        }

    }
}