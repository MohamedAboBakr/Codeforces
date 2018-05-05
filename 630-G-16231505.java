import java.util.*;
public class CodeForces
{
    
    public static void main(String[] args)
	{
            
            Scanner in = new Scanner(System.in);
            long n = in.nextLong();
            long ans = 0;
            ans = get_combinatorics(n+4,5) * get_combinatorics(n+2,3) ;
            System.out.println(ans);
        }
    
    static long get_combinatorics(long n , long r){
        long result = 1 , x = n , y = n-r  ;
        int flag = 0 ;
        List<Long> divis = new ArrayList<>();
        for(long i= r ; i>1 ; i--){
            divis.add(i);
        }
        while(x>y){
            result *= x ;
            for(int i=0 ; i<divis.size() ; i++){
                if(result % divis.get(i) == 0){
                    result /= divis.get(i);
                    divis.remove(i);
                }
            }
            x-- ;
        }
        return result;
    }
}