import java.util.Scanner;
import java.util.Arrays;
public class Binarysearch {
    public static void main(String[] args){
       Scanner input = new Scanner(System.in);
     long a[] = new long[3];
     a[0] = input.nextLong();
     a[1] = input.nextLong();
     a[2] = input.nextLong();
     Arrays.sort(a);
       long sum = (a[0]+a[1]+a[2])/3;
       if(sum> (a[0]+a[1])) System.out.printf("%d\n",a[0]+a[1]);
       else System.out.printf("%d\n",sum);
}
}