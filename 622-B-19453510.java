import java.util.*;
public class B
{

	public static void main(String[] args)
	{
            Scanner in = new Scanner(System.in);
            String s = in.nextLine();
            int h = Integer.parseInt(s.split(":")[0]);
            int m = Integer.parseInt(s.split(":")[1]);
            int a = in.nextInt();

            int h2 = ((((a/60)%24)+h)%24 + (a%60 + m)/60)%24 ;
            int m2 = (a%60 + m )%60 ;
            System.out.printf("%02d:%02d\n",h2,m2);


        }
}