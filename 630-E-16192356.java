import java.util.*;
public class CodeForces
{
    
    public static void main(String[] args)
	{
            
            Scanner in = new Scanner(System.in);
            long x1 , x2 , y1 , y2 , high1  , len1;
            x1 = in.nextInt();
            y1 = in.nextInt();
            x2 = in.nextInt();
            y2 = in.nextInt();
            
                high1 = (y2-y1)/2 + 1 ;
                len1 = (x2-x1) + 1 ;

                System.out.println(high1*len1 - len1/2);
            

}
}