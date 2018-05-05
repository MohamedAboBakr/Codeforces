import java.util.*;
public class CodeForces
{
    
    public static void main(String[] args)
	{
            
            Scanner in = new Scanner(System.in);
            int n = in.nextInt();
            char[] gender = new char[n];
            int[][] days = new int[n][2];
            for(int i=0 ; i<n ; i++){
                gender[i] = in.next().charAt(0);
                days[i][0] = in.nextInt();
                days[i][1] = in.nextInt();
            }
            
            int max = 0 , male = 0 , female = 0;
            for(int i=1 ; i<= 366 ; i++){
                male = 0 ; female = 0 ;
                for(int j=0  ; j<n ; j++){
                    if(days[j][0]<=i && days[j][1]>=i){
                       
                        if(gender[j] == 'M') male++;
                        else female++;
                    }
                }
                max = (max > Math.min(male,female)*2) ? max : Math.min(male,female)*2 ;
            }
            
            System.out.println(max);
        }
    
    
}