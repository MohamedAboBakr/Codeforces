import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int max =0,flag=0;
        for(int i=0;i<n;i++){
            a[i] = input.nextInt();
            if(a[i]>max)max=a[i];
        }
        a=Merge_sort(a);
         if(a[0]==a[n-1]){
             System.out.printf("%d\n%d\n",1,a[0]);
             return;
        }
        int k=0,s=1;
        b[0]=a[0];
        int i;
        for(i=1; i<n && a[i]<max ;i++){
            if(a[i]>a[k]){
                b[s++]=a[i];
                a[k]=-1;
                k=i;
            }             
        }
        a[k]=-1;
        b[s++]=max;
        if(s<n){
            int min =max;
            for(int j=i-1;j>0;j--){
                if(a[j]<min && a[j] != -1){
                    b[s++]=a[j];
                    min=a[j];
                }
            }
        }
        System.out.printf("%d\n",s);
        for(int j=0;j<s;j++){
            System.out.printf("%d%s",b[j],(j== s-1)?"\n":" ");
        }
    }
public static int[] Merge(int[] L,int[] R, int[] A){
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
   public static int[] Merge_sort(int[] A){
       int n = A.length;
       int mid = n/2;
       if(n>=2){
       int[] left = new int[mid];
       int[] right = new int[n-mid];
       for(int i =0;i<mid ;i++) left[i] = A[i];
       for(int i =mid;i<A.length ;i++) right[i-mid] = A[i];
       Merge_sort(left);
       Merge_sort(right);
       Merge(left,right,A);      
       }
       return A;
   } 
}