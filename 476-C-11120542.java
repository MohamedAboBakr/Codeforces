import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
           long n= input.nextLong();
           long m= input.nextLong();
           long sum = 0,val = 1000000007;
           if(m==1){
               System.out.println(0);
               return;
           }
           long one  = n*(n+1)/2;
           long two = m*(m-1)/2;
           one = one%val;
           one = one * m;
           one  = one + n;
           one = one%val;
           two = two % val;
          System.out.printf("%d\n",(one*two)%val);
}
}