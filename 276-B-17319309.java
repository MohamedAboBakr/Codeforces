import java.util.*;
import java.math.BigInteger;
public class Main {

  	
	
	public static void main(String[] args) {
		Scanner in  = new Scanner(System.in);
		String s = in.nextLine();
		int len = s.length();
		int[] chars = new int[26];
		for(int i=0 ; i<len ; i++){
			chars[s.charAt(i)-'a']++;
		}
		
		int extra =  0 , flag = 0;
		for(int i=0 ; i<26 ; i++){
			//System.out.println(chars[i]);
			if(chars[i] % 2 == 1 && flag == 0) flag = 1;
			else if(chars[i] % 2 == 1 && flag == 1){
				extra++;
			}
		}
		
		
		if(extra % 2 == 0) System.out.println("First");
		else System.out.println("Second");
			
}
}