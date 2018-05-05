import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
       int num = input.nextInt();
       input.nextLine();
       String[] list = new String[num];
       for(int i=0; i<num ; i++){
           list[i] = input.nextLine();
           if(list[i].length() > 10){
               StringBuilder st = new StringBuilder();
               st.append(list[i].charAt(0)).append(list[i].length()-2).append(list[i].charAt(list[i].length()-1));
         list[i] =  list[i].replace(list[i], st.toString());
           }
         
       }
       for(int j =0; j<num ;j++){
           System.out.println(list[j]);
       }
    }
}