import java.util.Scanner;

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int [][] a =
        {
            {48,32},
            {49,44,46,63,33},
            {50,65,66,67},
            {51,68,69,70},
            {52,71,72,73},
            {53,74,75,76},
            {54,77,78,79},
            {55,80,81,82,83},
            {56,84,85,86},
            {57,87,88,89,90},
        };
        String[] str = sc.nextLine().split(" ");

        for(int i = 0; i < str.length; i++)
        {
            if(str[i].length() == 1)
            {
                System.out.printf("%c",a[Integer.parseInt(str[i])][0]);
                continue;
            }
            int y = str[i].length();
            int x = Integer.parseInt(str[i].substring(y - 2, y - 1));
            y = (y-1) % a[x].length;
            System.out.printf("%c",a[x][y]);
        }
        System.out.printf("\n");
    
    }
}