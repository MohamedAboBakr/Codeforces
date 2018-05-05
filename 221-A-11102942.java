import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
       int n = input.nextInt();
       System.out.printf("%d%s",n,(n==1)?"\n":" ");
       for(int i=1;i<=(n-1);i++){
           System.out.printf("%d%s",i,(i== n-1)?"\n":" ");
       }
    }
}