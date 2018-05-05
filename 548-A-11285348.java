import java.util.Scanner;
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
        String s = input.nextLine();
      
        int k = input.nextInt();
        int len = s.length();
        if(len%k !=0){
            System.out.println("NO");
            return;
        }
        int len2 = len/k;
        int start =0;
        for(int i=0;i<k;i++){
            if(!(Ispol(s.substring(start,start+len2)))) {
                System.out.println("NO");
                return;
            }
            start+= len2;
        }
        
        System.out.println("YES");
    }
    public static boolean Ispol(String a){
        int len = a.length();
        for(int i=0;i<len/2;i++){
            if(a.charAt(i) != a.charAt(len-i-1)) return false;
        }
        return true;
    }
}