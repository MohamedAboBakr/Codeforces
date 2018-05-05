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
           int[] a = new int[12];
           
           
              int sum = 0;
              for(int i=0;i<12;i++){
                   a[i] = in.nextInt();
                   sum+= a[i];
              }
           if(n==0) System.out.println(0);
           else{
                if(sum<n) System.out.println(-1);
                else{
                     
                    Arrays.sort(a);
                    sum =0;int min=0;
                    for(int i=0;i<12;i++){
                       sum+= a[12-i-1];
                       if(sum>= n){
                        System.out.printf("%d\n",i+1);
                         return;
                       }  
                    }
                
                }
           
           }
    }
}