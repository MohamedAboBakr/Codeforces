import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
    int n,m,index;
    double div=1.0;
    n = input.nextInt();
    m = input.nextInt();
    int[] a = new int[n];
    index = n;
    for(int i=0;i<n;i++){
        a[i] = input.nextInt();
        if(m < a[i]){ 
            if(Math.ceil((double)a[i]/m) >= div){
            index = i+1;
            div = Math.ceil((double)a[i]/m);
            }
        }
    }
    System.out.printf("%d\n",index);
    }
}