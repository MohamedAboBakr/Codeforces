import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String test = input.nextLine();
        StringBuilder test2 = new StringBuilder(test);
        for(int i=0 ;i< test2.length();i++){
            char character = test2.charAt(i);
            if(Isvowl(character)){ test2.delete(i, i+1);
            i--;
            }
            else {
                test2.insert(i, '.'); 
                i++;
                if((int)character <= 90){
                    test2.setCharAt(i,(char)(character +32));
                }
            }
        }
        System.out.printf("%s\n", test2);
    }
    public static boolean Isvowl(char a){
        if(a== 'U' || a== 'A' || a== 'E' || a== 'I' || a== 'O' || a== 'o' || a== 'i' || a== 'e' || a== 'u' || a== 'a' || a== 'y' || a=='Y'){
            return true;
        }
        return false;
    } 
}