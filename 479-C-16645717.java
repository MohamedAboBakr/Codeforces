import java.util.*;

public class CodeForces
{
        private static int[][] numbers;
        private static int[][] helper;
        private static int number;
   //  static InputStreamReader isr = new InputStreamReader(System.in);
   //  static BufferedReader br = new BufferedReader(isr);
    public static void main(String[] args) 
	{
              Scanner in = new Scanner(System.in);
              int n  = in.nextInt();
              int[][] a = new int[2][n] ;
              int min ;
              
              for(int i=0 ; i<n ; i++){
                  a[0][i] = in.nextInt();
                  a[1][i] = in.nextInt();

              }
              
              sort(a);
              min = a[1][0];
              for(int i=1 ; i<n ; i++){
                  if(a[1][i] >= min){
                      min = a[1][i] ;
                  }else min = a[0][i] ;
              }
              
              System.out.println(min);
        }
    
    
   
  public static void sort(int[][] values) {
    numbers = values;
    number = values[0].length;
    helper = new int[2][number];
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
      helper[0][i] = numbers[0][i];
      helper[1][i] = numbers[1][i];
    }

    int i = low;
    int j = middle + 1;
    int k = low;

    while (i <= middle && j <= high) {
      if (helper[0][i] < helper[0][j]  || (helper[0][i] == helper[0][j] && helper[1][i] < helper[1][j])) {
        numbers[0][k] = helper[0][i];
        numbers[1][k] = helper[1][i];
        i++;
      } else {
        numbers[0][k] = helper[0][j];
        numbers[1][k] = helper[1][j];
        j++;
      }
      k++;
    }
    while (i <= middle) {
      numbers[0][k] = helper[0][i];
      numbers[1][k] = helper[1][i];
      k++;
      i++;
    }
    while (j <= high) {
      numbers[0][k] = helper[0][j];
      numbers[1][k] = helper[1][j];
      k++;
      j++;
    }
  }
}