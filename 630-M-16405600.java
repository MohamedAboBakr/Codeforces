import java.util.*;
public class CodeForces
{
    
    public static void main(String[] args)
	{
            
            Scanner in = new Scanner(System.in);
            long angle = in.nextLong();
            if(angle < 0 ) angle = 360 - (Math.abs(angle)%360);
            else angle = angle%360;
            
            if(angle == 0 || angle == 360) System.out.println(0);
            else if( angle <= 45 || angle >= 315) System.out.println(0);
            else if( angle <= 135) System.out.println(1);
            else if( angle <= 225) System.out.println(2);
            else if( angle < 315) System.out.println(3);
        }

}