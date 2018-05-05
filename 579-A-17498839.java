import java.util.Scanner;

public class CodeForces {

	public static void main(String[] args) {

       int n = new Scanner(System.in).nextInt();
       int min = 0 ;
       while(n != 0){
    	   if(n % 2 == 1) {
    		   min++;
    		   n -= 1 ;
    	   }
    	   else {
    		   n /= 2 ;
    	   }
       }
       
       System.out.println(min);
        
	}
}