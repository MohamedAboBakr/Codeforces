import java.math.BigInteger;
import java.util.Scanner;
public class Math {
	
     public static void main(String[] args){
    	 
    	 Scanner in = new Scanner(System.in);
    //	 long t , w , b;
    	 String s ;
    	 s = in.nextLine();
    	 String[] arr = s.split(" ");
    	 BigInteger b1 = new BigInteger(arr[0]);
    	 BigInteger b2 = new BigInteger(arr[1]);
    	 BigInteger b3 = new BigInteger(arr[2]);
    	 BigInteger min = b2.min(b3);
    	 BigInteger ans = BigInteger.ZERO ;
    	 // 321076647734423976 7 7
    	 BigInteger div = b2.divide(b2.gcd(b3)).multiply(b3);
    	 BigInteger t = b1.divide(div);
  
    	 ans = ans.add(t.multiply(min));
   
    	 
    	 ans = ans.add(min.subtract(BigInteger.ONE).min(b1.mod(div)));
    	 
    	 BigInteger Gcd = b1.gcd(ans);
    	 ans = ans.divide(Gcd);
    	 b1 = b1.divide(Gcd);
    	 
    	 System.out.println(ans.toString() + "/" + b1.toString());
    	 
     }
     
 
}