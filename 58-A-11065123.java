import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
       String word = input.nextLine();
       String test = ".*h+.*e+.*l+.*l+.*o+.*";
       if(word.matches(test)) System.out.println("YES");
       else System.out.println("NO");
    }
}