import java.util.Scanner;

public class Main{

    public static void main(String[] args){

     Scanner input = new Scanner(System.in);
     String s = input.nextLine();
     if(s.indexOf('H')== -1 && s.indexOf('Q')==-1 && s.indexOf('9')==-1 && s.indexOf("++[a-zA-Z]")==-1 &&s.indexOf("[a-zA-Z]\\+\\+")==-1) System.out.println("NO");

      
      else System.out.println("YES");
}


}