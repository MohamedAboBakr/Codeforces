import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
          long n= input.nextLong();
          long[] a = new long[(int)n];
          for(int i=0;i<n;i++) a[i] = input.nextLong();
          a = Merge_sort(a);
          long l=0,m=0,sum =0,flag=0;
          for(int i= 0;i<n-1;i++){
              if(a[i]==a[i+1]){
                  if(flag==1){
                      sum+= a[i]*l;
                      flag = 0;
                  }
                  else{
                  l=a[i];
                  flag = 1;
                  }
                  i+=1;
                  continue;
              }
              a[i]-=1;
             if(a[i]==a[i+1]){
                  if(flag==1){
                      sum+= a[i]*l;
                      flag = 0;
                  }
                  else{
                  l=a[i];
                  flag = 1;
                  }
                  i+=1;
                  continue;
              }             
          }
         
           System.out.printf("%d\n",sum);
}

 public static long[] Merge(long[] L,long[] R, long[] A){
       int nl = L.length;
       int nr = R.length;
       int i=0,j=0,k=0;
       while(i<nl && j<nr){
           if(L[i] > R[j]) A[k++]=L[i++];
           else A[k++]=R[j++];
       }
       while(i<nl) A[k++]=L[i++];
       while(j<nr) A[k++]=R[j++]; 
       return A;
   }
   
   // then we make mergesort method that divide the array(problem) into subproblems and marge the left and the right parts
   
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