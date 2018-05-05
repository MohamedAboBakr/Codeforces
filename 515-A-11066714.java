import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
  long a,b,s;
  a= input.nextLong();
  b= input.nextLong();
  s= input.nextLong();
  long dis = Math.abs(a)+Math.abs(b);
  if(s<dis) System.out.println("NO");
  else {
      long rest = s-(Math.abs(a)+Math.abs(b));
      if( rest%2 == 0.0)
      System.out.println("YES");
      else 
      System.out.println("NO");  
  }
  }
}