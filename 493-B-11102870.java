import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
       int n = input.nextInt();
       long[] first = new long[n];
       long[] second = new long[n];
       int first_count=0,second_count=0;
       long first_sum=0,second_sum=0;
       long last=0,index;
       for(int i=0;i<n;i++){
           index = input.nextLong();
           if(index<0){
               second[second_count++]= -1*index;
               second_sum+= -1*index;
           }
           else {
               first[first_count++]=index;
               first_sum+=index;
           }
           if(i==n-1) last = index;          
       }
       if(first_sum > second_sum) System.out.println("first");
       else if(second_sum >first_sum) System.out.println("second");
       else{
           int min = Math.min(first_count,second_count);
           for(int i=0;i<min;i++){
               if(first[i]>second[i]){
                   System.out.println("first");
                   return;
               }
               else if(first[i]<second[i]){
                   System.out.println("second");
                   return;
               }
           }
           if(last<0)System.out.println("second");
           else System.out.println("first");
                 
       }      
    }
}