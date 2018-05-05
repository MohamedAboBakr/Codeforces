import java.util.Arrays;
import java.util.Scanner;
/**
 *
 * @author p
 */
public class Codeforces {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
       int n = in.nextInt();
        int x = in.nextInt();
        int sum =0;
        for(int i=0;i<n;i++){
            sum+= in.nextInt();
        }
        sum = Math.abs(sum);
        System.out.printf("%.0f\n",Math.ceil((double)sum/x));
    }
}