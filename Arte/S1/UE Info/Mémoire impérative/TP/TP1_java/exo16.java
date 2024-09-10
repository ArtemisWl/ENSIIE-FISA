public class exo16 {
    public static double perim(double r) {
        double res = 2*3.14*r;
        return res;
    }
    
    public static double air(double r) {
        double res = 3.14*r*r; 
        return res;
    }
    
    public static void airV(double r, double h) {
        double volume = air(r)*h; 
        double airC = 2*air(r) + perim(r)*h;
        System.out.println("\"L'air et le volume d'un cylindre de rayon "+ r +" et de hauteur "+ h +" sont de : "+ airC+" et "+ volume);
    }
    
    public static void main(String[] args) {
        airV(4, 2);
    }
}