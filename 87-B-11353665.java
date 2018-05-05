import java.util.Scanner;
import java.util.Arrays;
/**
 *
 * @author win7
 */
public class Lifecodechef{

    /**
     * @param args the command line arguments
     */
    private static String vowel = "IE A O U Y";
    public static void main(String[] args)  throws java.lang.Exception{
        // TODO code application logic here
           Scanner input = new Scanner(System.in);
         int n = input.nextInt();
         input.nextLine();
         String[][] database = new String[2][n];
         String[] f = new String[3];
         //String type="",kind ,variable;
         for(int i=0;i<n;i++){
            f[0] = input.next();         
            f[1] = input.next();
           if(f[0].equals("typedef")){  
            f[2] = input.next();
           }
           else f[2] = null;
        modify(f[0],f[1],f[2],database);
       
             input.nextLine();
         }
    }
   public static void modify(String kind,String one,String two,String[][] db){
        String test = validate(one,db);
        if(kind.equals("typeof")){
            System.out.println(test);
            return;
        }
        int flag = 0,i=0;
        while(db[0][i] != null){
            if(db[0][i].equals(two)){
                db[1][i] = test;
                flag = 1;
            }
            i++;
        }
        if(flag==0){
            db[0][i] = two;
            db[1][i] = test;
        }
    }
    public static String validate(String s,String[][] db){
        String test  = s.replaceAll("&","");
        test = test.replaceAll("\\*","");
         String result = "";
         if(test.equals("errtype")) result = "errtype";
         else if(test.equals("void")) result = s;
            else {
             int i=0;
             while(db[0][i] != null){
                                                                   
              //   System.out.printf("%s\n",db[0][i]);
                //  System.out.printf("%s\n",db[1][i]);
                 if(test.equals(db[0][i])) result = db[1][i];
                 i++;
             }
             if(result.equals("")) result = "errtype";
             else{
                 result = s.replaceAll(test,result);
             }
         }
         String value = "";
         if(result.matches(".*errtype.*")) value = "errtype";
         else{
             while(result.matches(".*\\&void\\*.*")){
                result =  result.replaceFirst("\\&void\\*","void");
                                                              //     System.out.printf("%s  777\n",result);
             }
             if(result.matches(".*\\&void")) result = "errtype";
             value = result;
         }
         return value;
    }
}