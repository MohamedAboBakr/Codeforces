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
       int a1  = in.nextInt();
       int a2  = in.nextInt();
       int a3  = in.nextInt();
       int a4  = in.nextInt();
       in.nextLine();
       String s = in.nextLine();
       long sum = 0;
      int[] index = new int[5]; 
       for(int i=0;i<s.length();i++){
            index[(Integer.parseInt(String.valueOf(s.charAt(i))))]++;         
       }
      sum += a1*index[1]+ a2*index[2] + a3*index[3] + a4*index[4];
      System.out.println(sum);
    }
}