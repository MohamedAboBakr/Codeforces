import java.util.Scanner;
import java.util.Arrays;
public class Binarysearch {
    public static void main(String[] args){
       Scanner input = new Scanner(System.in);
       long n = input.nextLong();
       long r = input.nextLong();
       long avg = input.nextLong();
       long min_mark = n*avg,sum=0;
       long[][] a = new long[2][(int)n];
       for(int i=0;i<n;i++){
           a[1][i] = input.nextLong();
           a[0][i] = input.nextLong();
           sum+= a[1][i];
       }
       if(sum>= min_mark){
           System.out.println(0);
           return;
       }
       a = Merge_sort(a);
       long def=0,min=0,wanted = min_mark-sum;
       for(int i=0;i<n;i++){
           def = r- a[1][i];
           if(def>=wanted){
               min+= wanted*a[0][i];
               break;
           }
           min+=def*a[0][i];
           wanted-=def;
       }
       System.out.printf("%d\n",min);
}
 public static long[][] Merge(long[][] L,long[][] R, long[][] A){
       int nl = L[0].length;
       int nr = R[0].length;
       int i=0,j=0,k=0;
       while(i<nl && j<nr){
           if(L[0][i] < R[0][j]){
               A[1][k]=L[1][i];
               A[0][k++]=L[0][i++];
               
           }
           else{
               A[1][k]=R[1][j];
               A[0][k++]=R[0][j++];
           }
       }
       while(i<nl){
           A[1][k]=L[1][i];
           A[0][k++]=L[0][i++];
       }
       while(j<nr){
           A[1][k]=R[1][j];
           A[0][k++]=R[0][j++];
       } 
       return A;
   }
   
   // then we make mergesort method that divide the array(problem) into subproblems and marge the left and the right parts
   
   public static long[][] Merge_sort(long[][] A){
       int n = A[0].length;
       int mid = n/2;
       if(n>=2){
      long[][] left = new long[2][mid];
       long[][] right = new long[2][n-mid];
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