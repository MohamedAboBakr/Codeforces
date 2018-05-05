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
    public static void main(String[] args)  throws java.lang.Exception{
        // TODO code application logic here
           Scanner input = new Scanner(System.in);
           String[] match = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
          int k = input.nextInt();
          input.nextLine();
          String s = input.nextLine();
          int flag = 0;
          for(int i=0;i<8;i++){
              if(match[i].length() != k) continue;
              for(int j=0;j<k;j++){
                  if(s.charAt(j) == '.') continue;
                  if(s.charAt(j) != match[i].charAt(j)){
                      flag= 1;
                      break;
                  }
              }
              if(flag ==0){
                  System.out.println(match[i]);
                  return;
              }
              flag =0;
          }
       
    }
}