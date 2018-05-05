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
     int[] n = new int[4];
     int min =0;
        for(int i=0;i<4;i++)
     {
         n[i] = input.nextInt();
     }
        Arrays.sort(n);
     for(int i=1;i<4;i++)
     {
       
             if(n[i] ==n[i-1]) min++;
         
     }
       System.out.printf("%d\n",min);
    }
    
}