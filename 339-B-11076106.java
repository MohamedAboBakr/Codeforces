import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        int[] a = new int[m];
       long min=0;
        a[0] = input.nextInt();
        min = a[0]-1;
        for(int i=1;i<m;i++){
            a[i] = input.nextInt();
            if(a[i]==a[i-1]) min+=0;
            else if(a[i]>a[i-1]) min+= a[i]-a[i-1];
            else{
                min+= (n+1)-a[i-1];
                min+= a[i]-1;
            }
        }
        System.out.printf("%d\n",min);
    }
}