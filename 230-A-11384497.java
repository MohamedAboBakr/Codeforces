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
            int s = in.nextInt();
           int n = in.nextInt();
           int[][] a = new int[2][n];
          for(int i=0;i<n;i++){
            a[0][i] = in.nextInt();
            a[1][i] = in.nextInt();
          }
         a = Merge_sort(a);
         for(int i=0;i<n;i++){
              if(s<=a[0][i]){
                   System.out.println("NO");
                   return;
              }
              s+= a[1][i];
         
         }
         System.out.println("YES");
    }
public static int[][] Merge(int[][] L,int[][] R, int[][] A){
       int nl = L[0].length;
       int nr = R[0].length;
       int i=0,j=0,k=0;
       while(i<nl && j<nr){
           if(L[0][i] < R[0][j]){
               A[0][k]=L[0][i];
               A[1][k++]=L[1][i++];
           }
           else{
               A[0][k]=R[0][j];
               A[1][k++]=R[1][j++];
           }
       }
       while(i<nl){
               A[0][k]=L[0][i];
               A[1][k++]=L[1][i++];
       }
       while(j<nr){
               A[0][k]=R[0][j];
               A[1][k++]=R[1][j++];
       } 
       return A;
   }

 public static int[][]  Merge_sort(int[][] A){
       int n = A[0].length;
       int mid = n/2;
       if(n>=2){
       int[][] left = new int[2][mid];
       int[][] right = new int[2][n-mid];
       for(int i =0;i<mid ;i++){
           left[0][i] = A[0][i];
           left[1][i] = A[1][i];
       }
       for(int i =mid;i<A[0].length ;i++){
           right[0][i-mid] = A[0][i];
           right[1][i-mid] = A[1][i];
       }
       Merge_sort(left);
       Merge_sort(right);
       Merge(left,right,A);
       
       }
       return A;
   }
}