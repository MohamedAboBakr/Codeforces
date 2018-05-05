import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int c1 = input.nextInt();
        int c2 = input.nextInt();
        int c3 = input.nextInt();
        int c4 = input.nextInt();
        int a = input.nextInt();
        int b = input.nextInt();
        int Sum1=0,Sum2=0;
        int sum1=0,sum2=0;
        for(int i=0;i<a;i++){
            int x = input.nextInt();
            sum1+=x;
            sum2+= Math.min(c2, x*c1);
        }
        Sum1 = Math.min(Math.min(sum2,sum1*c1),c3);
        sum1=sum2=0;
        for(int i=0;i<b;i++){
            int x = input.nextInt();
              sum1+=x;
            sum2+= Math.min(c2, x*c1);
        }
        Sum2 = Math.min(Math.min(sum2,sum1*c1),c3);
        System.out.printf("%d\n",Math.min(Sum1+Sum2,c4));
    }
}