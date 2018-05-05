import java.util.Scanner;
import java.util.Arrays;
import java.io.*;
/**
 *
 * @author win7
 */
public class Lifecodechef{

   public static void main(String[] args)  throws java.lang.Exception{
     
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // line = br.readLine();
        // TODO code application logic here
         Scanner in = new Scanner(System.in);
        int length = in.nextInt();
        // in.nextLine();
         
        int[][] a = new int[2][length];
        int[] b = new int[length];
         for(int i=0;i<length;i++){
             a[0][i] = in.nextInt();
             b[i] = a[0][i];
         }
         Arrays.sort(a[0]);int k=1;
         for(int i= length-1;i>=0;i--){
             a[1][i] = k;
             if(i < length -1 && a[0][i] == a[0][i+1]){
                a[1][i] = a[1][i+1];
             
             }
             k++;
         }
         for(int i=0;i<length;i++){
                for(int j=0;j<length;j++){
                    if(b[i] == a[0][j]){
                        System.out.printf("%d%s",a[1][j],(i==length-1)?"\n":" ");
                        a[0][j] = -1;
                        break;
                    }
                }
         }
    }

}