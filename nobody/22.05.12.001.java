import java.util.Scanner;

import javax.lang.model.util.ElementScanner6;
public class App {
    //存在bug
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        char[] ch = sc.nextLine().toCharArray();

        int ans = 0;
        int status = 0;     //状态<=0，则派出老鼠, 
        for(int i = 0; i < ch.length - 1; i++)
        {
            if(ch[i] == 'X')
            {
                if(status < 0)
                {
                    status++;
                    System.out.printf("U");
                }
                else if(status == 0)
                {
                    status = 1;
                    System.out.printf("U");
                } 
                else
                {
                    status--;
                    System.out.printf("-");
                }
            }
            else if(ch[i] == 'T')
            {
                if(status < 0)
                {
                    status++;
                    ans += 7;
                    System.out.printf("D");
                }
                else if(status == 0)
                {
                    status = 2;
                    ans += 7;
                    System.out.printf("D");
                }
                else 
                {
                    status--;
                    System.out.printf("-");
                }
            }
            else if(ch[i] == 'C')
            {
                if(status <= 0)
                {
                    status = -2;
                    ans -= 3;
                    System.out.printf("!");
                }
                else if(status == 0)
                {
                    status = -2;
                    ans -= 3;
                    System.out.printf("!");
                }
                else
                {
                    System.out.printf("-");;
                }
            }
        }
        System.out.printf("\n" + ans);
    }
}
