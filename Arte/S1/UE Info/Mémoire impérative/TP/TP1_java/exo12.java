public class exo12 {
    public static void main(String[] args) {
        
        int i = 0;
        while ((i*i*i <= 1548) && ((i+1)*(i+1)*(i+1) <= 1548)) {
            i += 1;
            if ((i*i*i <= 1548) && ((i+1)*(i+1)*(i+1) > 1548)) {
                System.out.println("L'int i tel que i³ <= 1548 < (i+1)³ est : " + i);
            }
        }
    }
}