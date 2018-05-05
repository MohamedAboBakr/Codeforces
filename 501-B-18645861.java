import java.util.*;
import java.lang.*;
import java.io.*;

public class Math
{
	public static void main (String[] args)
	{
		Scanner in = new Scanner(System.in);
		int q = in.nextInt();
		in.nextLine();
		List<String> used = new ArrayList<>();
		List<String> using = new ArrayList<>();
		Map<String ,  String> map = new HashMap<>();
		int n=0 ;
		for(int i=0 ; i<q ; i++){
			String s = in.nextLine();
		    String[] arr = s.split(" ");
		    String old = arr[0] , neww = arr[1];
			
			if(!using.contains(old)){
				 if(!used.contains(neww) && !using.contains(neww)){
				 	map.put(neww,old); n++;
				 	used.add(old);
				 	using.add(neww);
				 }
			}
			
			else{
				 if(!used.contains(neww) && !using.contains(neww)){
				 	map.put(neww,map.remove(old)); 
				 	using.add(neww);
				 }
			}
			 
		}
		
		System.out.println(n);
		for (String key : map.keySet()) {
            System.out.println(map.get(key) + " " + key);
} 
	}  
	
	
}