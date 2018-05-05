import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
   String w = input.nextLine();
   String d = input.nextLine();
  if(w.equalsIgnoreCase(d)) System.out.println(0);
  else{
      int s = w.toLowerCase().compareTo(d.toLowerCase());
      if(s<0) System.out.println(-1);
      else System.out.println(1);
  }
  
    }
}