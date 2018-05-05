import java.util.Arrays;
import java.util.Scanner;
/**
 *
 * @author p
 */
public class Codeforces {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner input = new Scanner(System.in);
   String name1 = input.nextLine();
   String name2 = input.nextLine();
   String pill = input.nextLine();
   String all = name1+ name2;
   char[] a = all.toCharArray();
   char[] b = pill.toCharArray();
   Arrays.sort(a);
   Arrays.sort(b);
   if(Arrays.equals(a,b)) System.out.println("YES");
   else System.out.println("NO");
    }
    
}