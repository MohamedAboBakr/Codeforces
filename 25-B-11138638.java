import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args){
       Scanner input = new Scanner(System.in);
       int n = input.nextInt();
       input.nextLine();
    StringBuilder s = new StringBuilder(input.nextLine());
     if(n <4 ) {
         System.out.println(s);
        return;
     }
     if(n%2 ==0){
         for(int i=2;i< s.length();i+=3){
             s.insert(i,'-');
         }
     }
     else {
         s.insert(3,'-');
         for(int i=6;i< s.length();i+=3){
             s.insert(i,'-');
         }
     }
       System.out.println(s);
}
}