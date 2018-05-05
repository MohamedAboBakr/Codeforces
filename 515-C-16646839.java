import java.util.*;

public class CodeForces
{
        static int[] digits_count ;
   //  static InputStreamReader isr = new InputStreamReader(System.in);
   //  static BufferedReader br = new BufferedReader(isr);
    public static void main(String[] args) 
	{
              Scanner in = new Scanner(System.in);
              int n  = in.nextInt();
              long a = in.nextLong();
              digits_count = new int[8];
              long digit ;
              while(a != 0){
                  digit = a%10;
                  factorization(digit);
                  a /= 10 ;
              }
              
              for(int i=7 ; i>= 2 ; i--){
                  for(int j = 0 ; j<digits_count[i] ; j++){
                      System.out.print(i);
                  }
              }
              System.out.println();
        }
    
    
  static void factorization(long digit){
      if(digit < 2) return  ;
      else if(digit == 2) digits_count[2] ++ ;
      else if(digit == 3) digits_count[3]++;
      else if(digit == 4){
          digits_count[2] += 2 ;
          digits_count[3] ++;
      }
      else if(digit == 5) digits_count[5] ++;
      else if(digit == 6){
          digits_count[3]++;
          digits_count[5]++;
      }
      else if(digit == 7) digits_count[7] ++;
      else if(digit == 8){
          digits_count[2] += 3;
          digits_count[7] ++;
      }
      else {
         digits_count[3] += 2 ;
         digits_count[2] ++;
         digits_count[7] ++;
      }
  } 
}