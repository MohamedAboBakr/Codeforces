import java.util.*;


public class CodeForces
{
        private static long[] numbers;
        private static long[] helper;
        private static int number;
   //  static InputStreamReader isr = new InputStreamReader(System.in);
   //  static BufferedReader br = new BufferedReader(isr);
    public static void main(String[] args) 
	{
              Scanner in = new Scanner(System.in);
              int n  = in.nextInt();
              long[] a = new long[n];
              for(int i=0 ; i<n ; i++){
                  a[i] = in.nextInt();
              }
              int max = 1 ;
              sort(a);
              long time = a[0] ;
               for(int i=1 ; i<n ;  i++){
                   if(a[i] >= time){
                       max++;
                       time += a[i] ;
                   }

               }
               
               System.out.println(max);
              
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
      helper[i] = numbers[i];
    }

    int i = low;
    int j = middle + 1;
    int k = low;

    while (i <= middle && j <= high) {
      if (helper[i] <= helper[j] ) {
        numbers[k] = helper[i];
        i++;
      } else {
        numbers[k] = helper[j];
        j++;
      }
      k++;
    }
    while (i <= middle) {
      numbers[k] = helper[i];
      k++;
      i++;
    }
    while (j <= high) {
      numbers[k] = helper[j];
      k++;
      j++;
    }
  }
}