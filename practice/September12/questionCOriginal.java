import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;


public class acm {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int round = scan.nextInt();
        for (int k = 0; k <= round; k ++)) {
            int sNum = scan.nextInt();
            int bNUm = scan.nextInt();
            System.out.println("Practice #" + k +": " + sNum + " " + bNUm +"\n");
            int group = scan.nextInt();
            while (group > 0) {
                int p = scan.nextInt();
                if (p >= bNUm) {
                    while (p >= bNUm) {
                        bNUm = bNUm * 2;
                    }
                }
                System.out.println(p + " " + (bNUm - p));
                group --;
            }
            println();
        }
    }
}

Sample Input:
2
20 60
8 15 10 20 18
9 12
2 10
15 100
4 1 2 3 5