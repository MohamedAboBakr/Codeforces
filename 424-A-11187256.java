import java.util.Scanner;
public class N_Queens_Problem {
    public static int num_x = 0;
    public static int num_X = 0;
    public static void main(String[] args) {
      Scanner input = new Scanner(System.in);
      int len = input.nextInt();
      input.nextLine();
      StringBuilder s = new StringBuilder(input.nextLine());
      int set = len/2;
     
      System.out.printf("%d\n", count(s,len-1,set));
      System.out.println(s);
      
    }
  public static int count(StringBuilder a,int length,int set){
        if(length == -1) return 0;
        if(a.charAt(length) == 'x'){
            num_x++;
            if(num_x > set){
                
                num_x--;
                a.setCharAt(length,'X');
                num_X++;
                return 1+count(a, length-1,set);
            }
        }
        if(a.charAt(length) == 'X'){
            num_X++;
            if(num_X > set){
                
                num_X--;
                a.setCharAt(length,'x');
                num_x++;
                 return 1+count(a, length-1,set);
            }
        }
         return count(a, length-1,set);
    }
}