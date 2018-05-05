import java.util.*;
public class CodeForces
{
    
    public static void main(String[] args)
	{
            
            Scanner in = new Scanner(System.in);
            String s = in.nextLine();
            String result = solve(s);
            System.out.println(result);
        }
    
    public static String solve(String s){
        List<Integer> AB = new ArrayList<>();
        List<Integer> BA = new ArrayList<>();
        
        int len = s.length();
        for(int i = 0 ; i<= len-2 ; i++){
            if(s.charAt(i) == 'A' && s.charAt(i+1) == 'B') AB.add(i);
            else if(s.charAt(i) == 'B' && s.charAt(i+1) == 'A') BA.add(i);
        }
        
        if(AB.isEmpty() || BA.isEmpty())       return "NO";
        if(AB.size() >= 2 && BA.size() >= 2)  return "YES";
        if(AB.size() == 1){
            for(int i : BA){
                if(Math.abs(AB.get(0)- i) != 1) return "YES";
            }
            return "NO";
        }
        
        if(BA.size() == 1){
            for(int i : AB){
                if(Math.abs(BA.get(0)- i) != 1) return "YES";
            }
            return "NO";
        }
        return "NO" ;
    }

}