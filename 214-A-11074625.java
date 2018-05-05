import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        int min = Math.min(n, m);
        int max = Math.max(n, m);
        int count =0;
        for(int i = 0; i<=min ;i++){
            if(Math.sqrt(min-i)+(i*i) == max) count++;
        }
         System.out.printf("%d\n",count);
    }
}