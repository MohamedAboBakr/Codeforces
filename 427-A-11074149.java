import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] a = new int[n];
        int untreated =0;
        int free =0;
        for(int i=0;i<n;i++){
            a[i] = input.nextInt();
            if(a[i]>0) free+=a[i];
            else{
                if(free==0) untreated++;
                else free--;
            }
        }
        System.out.printf("%d\n",untreated);
         
    }
}