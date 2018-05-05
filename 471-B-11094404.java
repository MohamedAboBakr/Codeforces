import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n];
        int max =0,flag=0;
        for(int i=0;i<n;i++){
            a[i] = input.nextInt();
            b[i]=a[i];
            c[i]=i+1;
    }
        b=Bubble_sort(b);
       for(int i=0;i<n-1;i++){
            if(b[i]==b[i+1]) flag++;
            if (flag==2) break;
        }            
        if(flag<2) {
            System.out.println("NO");
            return;
        }
        c= Merge_sort(c,a);
         System.out.println("YES");
         Print(c);
        for(int i=0;i<n;i++){
            if(a[c[i]-1]==a[c[i+1]-1]){
                int temp = c[i];
                c[i]=c[i+1];
                c[i+1]=temp;
                Print(c);
                max++;
            }
            if(max ==2) break;
        }
        
    }
    public static void Print(int[] c){
        int len = c.length;
        for(int i=0;i<len;i++){
             System.out.printf("%d%s",c[i],(i==len-1)?"\n":" ");
        }
    }
        public static int[] Bubble_sort(int[] a){  
        for(int k=1; k<= a.length-1 ; k++){
            int flag =0 ;
            for(int i=0 ; i<= a.length - k - 1 ;i++){
                if(a[i]>a[i+1]){
                    int temp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = temp;
                    flag = 1;
                }
            }
            if(flag==0){
                break;
            }
        }
        return a;
       
    }
public static int[] Merge(int[] L,int[] R, int[] A,int[] c){
       int nl = L.length;
       int nr = R.length;
       int i=0,j=0,k=0;
       while(i<nl && j<nr){
           if(c[L[i]-1] < c[R[j]-1]) A[k++]=L[i++];
           else A[k++]=R[j++];
       }
       while(i<nl) A[k++]=L[i++];
       while(j<nr) A[k++]=R[j++]; 
       return A;
   }
   public static int[] Merge_sort(int[] A,int[] c){
       int n = A.length;
       int mid = n/2;
       if(n>=2){
       int[] left = new int[mid];
       int[] right = new int[n-mid];
       for(int i =0;i<mid ;i++) left[i] = A[i];
       for(int i =mid;i<A.length ;i++) right[i-mid] = A[i];
       Merge_sort(left,c);
       Merge_sort(right,c);
       Merge(left,right,A,c);    
       }
       return A;
   }
}