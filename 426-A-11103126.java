import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
       int n = input.nextInt();
       int x = input.nextInt();
       int a[] = new int[n];
       for(int i=0;i<n;i++){
           a[i] = input.nextInt();
       }
       a= Bubble_sort(a);
       int sum=0;
       for(int i=0;i<(n-1);i++) sum+=a[i];
       System.out.printf("%s\n",(sum<= x)?"YES":"NO");
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
}