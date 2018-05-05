import java.util.*;
public class CodeForces
{
	
    
   static  int n , num = 0 ;
    static String s ;
   
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
                in.nextLine();
                s = in.nextLine();
                
                char[] c  = s.toCharArray();
                Arrays.sort(c);
                int b =0 , g=0 , r = 0;
                int i=0;
                
                while(i<n && c[i] == 'B'){
                    b++;
                    i++;
                }
                while(i<n && c[i] == 'G'){
                    g++;
                    i++;
                }
                
                while(i<n && c[i] == 'R'){
                    r++;
                    i++;
                }
                
                
                if(b>0 && g>0 && r>0){
                    System.out.println("BGR");
                    return ;
                }
                
                if(b>0 && g==0 && r==0){
                    System.out.println("B");
                    return ;
                }
                if(g>0 && b==0 && r==0){
                    System.out.println("G");
                    return ;
                }
                
                if(r>0 && g==0 && b==0){
                    System.out.println("R");
                    return ;
                }
                
                if(r==0 && g>1 && b>1){
                    System.out.println("BGR");
                    return ;
                }
                
                if(b==0 && g>1 && r>1){
                    System.out.println("BGR");
                    return ;
                }
                
                if(g==0 && b>1 && r>1){
                    System.out.println("BGR");
                    return ;
                }
                
                if(g==0 && b==1 && r>1){
                    System.out.println("BG");
                    return ;
                    
                }
                if(g==0 && b>1 && r==1){
                    System.out.println("GR");
                    return ;
                    
                }
                if(g==0 && b==1 && r==1){
                    System.out.println("G");
                    return ;    
                }
                
                 
                if(b==0 && g==1 && r>1){
                    System.out.println("BG");
                    return ;
                    
                }
                if(b==0 && g>1 && r==1){
                    System.out.println("BR");
                    return ;
                    
                }
                if(b==0 && g==1 && r==1){
                    System.out.println("B");
                    return ;    
                }
                
                 
                if(r==0 && b==1 && g>1){
                    System.out.println("BR");
                    return ;
                    
                }
                if(r==0 && b>1 && g==1){
                    System.out.println("GR");
                    return ;
                    
                }
                if(r==0 && b==1 && g==1){
                    System.out.println("R");
                    return ;    
                }
	}
        

}