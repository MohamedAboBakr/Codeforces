import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
   String w = input.nextLine();
   StringBuilder word = new StringBuilder(w);
   char a = word.charAt(0);
   if(w.matches("[a-z].*")){
       word.setCharAt(0,(char)(a-32));
   }
   System.out.println(word.toString());
    }
}