import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
           long n= input.nextLong();
           long[] a = new long[(int)n];
           for(int i=0;i<n;i++){
               a[i] = input.nextLong();
           }
           a = Merge_sort(a);
           long sum=0;
           for(int i=0;i<n;i++){
               sum+= Math.abs(i+1-a[i]);
           }
           System.out.printf("%d\n",sum);
}
 public static long[] Merge(long[] L,long[] R, long[] A){
       int nl = L.length;
       int nr = R.length;
       int i=0,j=0,k=0;
       while(i<nl && j<nr){
           if(L[i] < R[j]) A[k++]=L[i++];
           else A[k++]=R[j++];
       }
       while(i<nl) A[k++]=L[i++];
       while(j<nr) A[k++]=R[j++]; 
       return A;
   }
   
   public static long[] Merge_sort(long[] A){
       int n = A.length;
       int mid = n/2;
       if(n>=2){
      long[] left = new long[mid];
       long[] right = new long[n-mid];
       for(int i =0;i<mid ;i++) left[i] = A[i];
       for(int i =mid;i<A.length ;i++) right[i-mid] = A[i];
       Merge_sort(left);
       Merge_sort(right);
       Merge(left,right,A);
       
       }
       return A;
   }
}