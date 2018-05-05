import java.util.Scanner;

public class Bar {

  
    public static void main(String[] args) {
        
        Scanner scr = new Scanner(System.in);
        int n = scr.nextInt() , num = 0;
        scr.nextLine();
        for(int i=0 ; i<n ;i++){
            String s = scr.nextLine();
            if(s.equals("ABSINTH") || s.equals("BEER") ||s.equals("BRANDY") || s.equals("CHAMPAGNE") ||  s.equals("GIN")|| s.equals("RUM")||s.equals("SAKE")||s.equals("TEQUILA")|| s.equals("VODKA")||s.equals("WHISKEY") || s.equals("WINE")){
                num ++;
            }
            else if(s.matches("[0-9]*")){
                if(Integer.parseInt(s) < 18) num++;
            }
        }
               System.out.println(num);
}
}