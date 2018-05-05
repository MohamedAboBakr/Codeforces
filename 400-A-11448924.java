import java.util.Scanner;
import java.util.Arrays;

/**
 *
 * @author win7
 */
public class Lifecodechef{

    /**
     * @param args the command line arguments
     */
    
    static int[] a = {1,2,3,5,11};
    static int[] b = {5,3,2,1,0};
    static int[] result = {0,0,0,0,0};
    private static String vowel = "IE A O U Y";
    public static void main(String[] args)  throws java.lang.Exception{
        // TODO code application logic here
           Scanner in = new Scanner(System.in);
           int t = in.nextInt();
           in.nextLine();
           for(int i=0;i<t;i++){
               String s  = in.nextLine();
             if(s.indexOf("X") == -1){
                 System.out.println(0);
                 continue;
             }
             game(s);
             System.out.printf("%d 1x12",count(result)+1);
             Print(result);
             Arrays.fill(result,0);
             System.out.println();
           }
           
           
    }
 public static void game(String s){
       for(int i=0;i<5;i++){
           
           for(int j=0;j<b[i]+1;j++){
                int curr = b[i]+1+j,flag=0;
                if(s.charAt(j) != 'X') continue;
               for(int k=0;k<a[i];k++){
                  
                   if(s.charAt(curr) != 'X') {
                          flag =1;
                          break;
                   } 
                   curr+= b[i]+1;
                    
               }
               if(flag ==0){
                  result[i] = 1;
                  break;
               }
               flag = 0;
               
              
           }
            
           
       }
    
 }   
 public static int count(int[] w){
       int sum =0;
       for(int i=0;i<5;i++) if(w[i]==1) sum++;
       return sum;
 }
 public static void Print(int[] w){
     for(int i=0;i<5;i++){
       if(w[i] ==1) System.out.printf(" %dx%d",a[i]+1,b[i]+1);
     }
 }
}