import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args){
       Scanner input = new Scanner(System.in);
       long n = input.nextLong();
       int m = input.nextInt();
    if(m==0){
     System.out.println("YES");
   return;
}
       long[] a = new long[m];
       for(int i=0;i<m;i++){
           a[i] = input.nextLong();
       }
       a= Merge_sort(a);
       if(a[0]==1 || a[m-1]==n){
           System.out.println("NO");
           return;
       }
       for(int i=0;i<m-2;i++){
           if(a[i]+2 == a[i+2]){
               System.out.println("NO");
           return;
           }
       }
       System.out.println("YES");
}
public static long[] Merge(long[] L,long[] R, long[] A){
       int nl = L.length;
       int nr = R.length;
       int i=0,j=0,k=0;
       while(i<nl && j<nr){
           if(L[i] < R[j]){
              
               A[k++]=L[i++];
               
           }
           else{
         
               A[k++]=R[j++];
           }
       }
       while(i<nl){
           A[k++]=L[i++];
       }
       while(j<nr){         
           A[k++]=R[j++];
       } 
       return A;
   }
   
   // then we make mergesort method that divide the array(problem) into subproblems and marge the left and the right parts
   
   public static long[] Merge_sort(long[] A){
       int n = A.length;
       int mid = n/2;
       if(n>=2){
      long[] left = new long[mid];
       long[] right = new long[n-mid];
       for(int i =0;i<mid ;i++){
           left[i] = A[i];
          
       }
       for(int i =mid;i<A.length ;i++){
         
            right[i-mid] = A[i];
       }
       Merge_sort(left);
       Merge_sort(right);
       Merge(left,right,A);
       
       }
       return A;
   } 
}