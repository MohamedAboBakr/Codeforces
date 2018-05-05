import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
       long n = input.nextLong();
       long rem;
       if(n==0) {
           System.out.println("O-|-OOOO");
           return;
       }
       while(n!=0){
           char[] go_dama = {'O','-'};
           char[] ichi_damas = {'-','O','O','O','O'};
           rem = n%10;
           if(rem>=5){
              go_dama[0] = '-';
               go_dama[1] = 'O';           
           }
           Draw(ichi_damas,rem%5);
           System.out.printf("%c%c|%c%c%c%c%c\n",go_dama[0],go_dama[1],ichi_damas[0],ichi_damas[1],ichi_damas[2],ichi_damas[3],ichi_damas[4]);
           n/=10;
       }
}
  public static void Draw(char[] a,long b){
        if(b==0) return;
        else{
            a[0]='O';
            a[(int)b]='-';
            return;
        }
    }
}