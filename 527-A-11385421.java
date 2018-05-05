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
        Scanner input = new Scanner(System.in);
         long a = input.nextLong();
         long b = input.nextLong();
        long sum = 0;
         while(a%b !=0){
             sum += a/b;
             long temp = b;
             b = a%b;
             a = temp;
         }
         sum += a/b;
         System.out.println(sum);
    }
}