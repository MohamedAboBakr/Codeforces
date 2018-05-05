import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String s = input.next();
        char[] count = new char[200001];
        count = s.toCharArray();
        int n = input.nextInt();
        int[] search = new int[s.length()/2];
        int get;
        while(n!=0){
            get = input.nextInt();
            search[get-1]++;
            n--;
        }
        int sum =0; /* to determined any character will be changed after swapping and any one will be the same after swapping */
        for(int i=0;i<s.length()/2;i++){
            sum+=search[i];
            if(sum %2 == 1){
                char temp = count[i];
                count[i] = count[s.length()-i-1];
                count[s.length()-i-1] = temp;
            }
        }
        System.out.println(count);
}
}