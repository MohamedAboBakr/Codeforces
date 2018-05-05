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
        int n = input.nextInt();
        input.nextLine();
        String a = input.nextLine();
        String b = input.nextLine();
        int min =0,value=0;
        for(int i=0;i<n;i++){
            
            value = Math.abs(Integer.parseInt(String.valueOf(a.charAt(i)))- Integer.parseInt(String.valueOf(b.charAt(i))));
            min += Math.min(value,10-value);
        }
        System.out.printf("%d\n", min);
       
    }
    
}