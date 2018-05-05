import java.util.*;

public class CodeForces {
    
    // C. Pearls in a Row
    public static void main(String[] args) {
        Scanner  input = new Scanner(System.in);
        int n  = input.nextInt() , size = 0;
        int[] arr = new int[n];
        for(int i = 0 ; i < n ; i++){
           arr[size] = 1;
           size = check_arr(arr , size);
           size++;
        }
        
        //System.out.println(size);
        for(int i = 0 ; i< size ; i++){
            System.out.printf("%d%s",arr[i],(i==size-1)?"\n":" ");
        }
    }
    
    public static int check_arr( int[] a , int size){
        if(size == 0) return 0;
            while(size > 0&& a[size] == a[size-1]){
                a[size] = 0;
                a[size - 1] += 1;
                size --;
            
        }
        return size;
    }
    
}