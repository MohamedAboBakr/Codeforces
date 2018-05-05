import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
   int n = input.nextInt();
       input.nextLine();
       String a =input.nextLine();
        if(n < 26){
           System.out.println("NO");
               return;}
       
       for(int i=65;i<= 90 ;i++){
           if(!(a.contains(String.valueOf((char)i)) || a.contains(String.valueOf((char)(i+32))))) 
           {
               System.out.println("NO");
               return;
           }
       }
        System.out.println("YES");     
    }
}