import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        int a = input.nextInt();
        int b = input.nextInt();
        int min = n*a;
        if(m>n){
            if(b<min) System.out.printf("%d\n",b);
            else System.out.printf("%d\n",min);
        }
        else{
           double check = Math.ceil((double)n/m)*b;
            if(check < min) min = (int)check;
            int test;
            for(int i=1 ; i*m <= n ;i++){
                test = b*i + (n-i*m)*a;
                if(test<min) min = test;
            }
 System.out.printf("%d\n",min);
        }
            
    }
}