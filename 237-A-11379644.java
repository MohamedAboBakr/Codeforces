import java.util.Scanner;
import java.util.Arrays;

/**
 *
 * @author win7
 */
public class Lifecodechef{

    /**
     * @param args the command line arguments
     */
    private static String vowel = "IE A O U Y";
    public static void main(String[] args)  throws java.lang.Exception{
        // TODO code application logic here
           Scanner in = new Scanner(System.in);
           int n = in.nextInt();
           int[][] a = new int[n][2]; 
           int max = 0,k=0;
           for(int i=0;i<n;i++){
               a[i][0] = in.nextInt();
               a[i][1] = in.nextInt();
           }
           if(n==1){
                System.out.printf("%d\n",1);
                return;
           }
           for(int i=0;i<n-1;i++){
                if(a[i][0]==a[i+1][0] && a[i][1]==a[i+1][1]) k++;
                else{
                     if(k+1 >max) max = k+1;
                     k=0;
                }
           }
           if(k+1 >max) max = k+1;
           System.out.printf("%d\n",max);
    }
}