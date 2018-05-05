import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
       long a = input.nextLong();
       long b = input.nextLong();
        long sum=0;
       if(a==b) System.out.println("infinity");
      
       else{
           if(a-b<b) System.out.println(0);
           else{
               long base = a-b;
               
                 for(long i = 1 ;i<=Math.sqrt(base);i++){
                   if(base%i==0){
                       if(i>b)sum++;
                       if(base/i > b && base/i!=i) sum++;
                   }
               }
               System.out.printf("%d\n",sum);
           }
       }        
    }
}