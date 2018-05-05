import java.util.*;
public class CodeForces
{
    
    public static void main(String[] args)
	{
            
            Scanner in = new Scanner(System.in);
            long sum = 0 ;
            int n = in.nextInt();
            in.nextLine();
            long[] rows = new long[n];
            long[] cols = new long[n];
            String[] cake = new String[n];
            for(int i = 0; i<n ; i++){
                cake[i] = in.nextLine();
            }
            
            for(int i=0 ; i<n ; i++){
                for(int j=0 ; j<n ; j++){
                    if(cake[i].charAt(j) == 'C'){
                        rows[i]++;
                        cols[j]++;
                    }
                }
            }
            
            for(int i=0 ; i<n ; i++){
                sum += get_combinatorics(rows[i],2);
                sum += get_combinatorics(cols[i],2);
            }
            System.out.println(sum);
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