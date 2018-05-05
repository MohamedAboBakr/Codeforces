import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class CodeForces
{
        private static long[] numbers;
        private static long[] helper;
        private static int number;
   // static InputStreamReader isr = new InputStreamReader(System.in);
   //  static BufferedReader br = new BufferedReader(isr);
   //  static PrintWriter pt = new PrintWriter(System.out);
     static Scanner in = new Scanner(System.in);  
       
    public static void main(String[] args) throws IOException 
	{
           
            long n = in.nextLong();
            long sum = 0 ;
            long[] a = new long[(int)n];
            BigInteger numerator , denominator , summ;
            numerator = new BigInteger("0");
            denominator = new BigInteger(Long.toString(n));
            summ = BigInteger.ZERO;
            for(int i =0 ; i<n ; i++){
                a[i] = in.nextLong();
                sum += a[i];
            }
            numerator =  numerator.add(new BigInteger(Long.toString(sum)));

            long add = 0 , subtract = (n-1)*-1;
            sort(a);
            long curr_sum ;
            for(int i=0 ; i<n  ;i++){
                curr_sum = (a[i]*(add + subtract))*2;
                subtract ++;
                add ++ ;
                summ =  summ.add(new BigInteger(Long.toString(curr_sum)));
            }
               // summ = summ.multiply(new BigInteger(Long.toString(2*(n-1))));
                
           numerator =  numerator.add(summ);
           long gcd = gcm(numerator.longValue() , denominator.longValue());
            System.out.println(numerator.divide(new BigInteger(Long.toString(gcd))).toString() + " " + denominator.divide(new BigInteger(Long.toString(gcd))).toString());
        }

 public static long gcm(long a, long b) {
      return b == 0 ? a : gcm(b, a % b);
}
  public static void sort(long[] values) {
    numbers = values;
    number = values.length;
    helper = new long[number];
    mergesort(0, number - 1);
  }

  private static void mergesort(int low, int high) {
  
    if (low < high) {
     
      int middle = low + (high - low) / 2;
      
      mergesort(low, middle);
     
      mergesort(middle + 1, high);
     
      merge(low, middle, high);
    }
  }

  private static void merge(int low, int middle, int high) {

      for (int i = low; i <= high; i++) {
      helper[i] = numbers[i];
      
    }

    int i = low;
    int j = middle + 1;
    int k = low;

    while (i <= middle && j <= high) {
      if (helper[i] <= helper[j] ) {
        numbers[k] = helper[i];
        numbers[k] = helper[i];
        i++;
      } else {
        numbers[k] = helper[j];
        numbers[k] = helper[j];
        j++;
      }
      k++;
    }
    while (i <= middle) {
      numbers[k] = helper[i];
      numbers[k] = helper[i];
      k++;
      i++;
    }
    while (j <= high) {
      numbers[k] = helper[j];
      numbers[k] = helper[j];
      k++;
      j++;
    }
  }
}