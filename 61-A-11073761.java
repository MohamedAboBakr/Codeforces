import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a = input.nextLine();
        String b = input.nextLine();
        char[] a_list = a.toCharArray();
        char[] b_list = b.toCharArray();
        for(int i=0;i<a.length();i++){
            if(a_list[i] != b_list[i]) a_list[i] = '1';
            else a_list[i] ='0';
        }
        System.out.println(String.valueOf(a_list));
         
    }
}