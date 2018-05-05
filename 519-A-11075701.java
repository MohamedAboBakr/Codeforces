import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
       String[] s = new String[8];
        int white = 0,black = 0;
        for(int i=0;i<8;i++){
         s[i] = input.nextLine();
        }
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
              char o = s[i].charAt(j);
             switch(Character.toLowerCase(o)){
                 case 'q':{
                     if(o == 'q') black+=9;
                     else white+=9;
                       break;}
                 case 'r':{
                     if(o== 'r') black+=5;
                     else white+=5;
                     break;}
                 case 'b':{
                     if(o== 'b') black+=3;
                     else white+=3;
                     break;}
                 case 'n':{
                     if(o == 'n') black+=3;
                     else white+=3;
                     break;}
                 case 'p':{
                     if(o== 'p') black+=1;
                     else white+=1;
                     break;}
                 default : {}   
             }
        }
        }
        if(black > white) System.out.println("Black");
        else if (white>black)System.out.println("White");
        else System.out.println("Draw");
    }
}