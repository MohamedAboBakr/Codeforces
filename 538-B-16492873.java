import java.util.*;
public class CodeForces
{
    static int flag = 1000000 ;
    public static void main(String[] args)
	{
            
            Scanner in = new Scanner(System.in);
            String n = in.nextLine();
            int[] quasibinary = new int [n.length()];
            int max  = 0 ;
            for(int i = 0 ; i<n.length() ; i++){
                quasibinary[i] = n.charAt(i) - '0' ;
                max = (max > quasibinary[i] ) ? max : quasibinary[i] ;
            }
            
            System.out.println(max);
            int flag = 0;
            for(int i=0  ; i<max ; i++){
                flag = 0;
                for(int j=0 ; j<n.length(); j++){
                    if(quasibinary[j] > 0 ){
                        System.out.printf("1");
                        quasibinary[j] -= 1 ;
                        flag = 1;
                    }
                    else if(quasibinary[j] == 0){
                        if(flag == 1 )  System.out.printf("0");
                    }
                }
                
                 System.out.printf(" ");
            }
            
             System.out.println();
        }


}