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
    public static void main(String[] args)  throws java.lang.Exception{
        // TODO code application logic here
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        int q = input.nextInt();
        int[][] a = new int[n][m];
        int[] score = new int[n];
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              a[i][j]= input.nextInt();            
          }
    }
        int count =0,x=0;
         for(int i=0;i<n;i++){
             x=0;count =0;
          for(int j=0;j<m;j++){
                   if(a[i][j] == 1) count++;   
                   else{
                       x = Math.max(x, count);
                       count =0;
                   }
          }
         x = Math.max(x, count);
         score[i] = x;
         
    }
         for(int i =0;i<q;i++){
             int e  = input.nextInt() -1;
             int f  = input.nextInt() -1;
             a[e][f] = Math.abs(a[e][f]-1);
             x=count=0;
              for(int j=0;j<m;j++){
                   if(a[e][j] == 1) count++;   
                   else{
                       x = Math.max(x, count);
                       count =0;
                   }
          }
          x = Math.max(x, count);      
          score[e] = x;
          int max =0;
          for(int k=0;k<n;k++){
              if(score[k] > max) max = score[k];
          }
          System.out.printf("%d\n",max);
             
         }
    }
}