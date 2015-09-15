import java.lang.reflect.Array;
import java.util.*;

public class acm {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int round = scan.nextInt();
        for (int k  = 1; k <= round; k ++) {
            int sNum = scan.nextInt();
            int bNUm = scan.nextInt();
            System.out.print("Practice #" + k +": " + sNum + " " + bNUm +"\n");
            int group = scan.nextInt();
            while (group > 0) {
                int p = scan.nextInt();
                if (p >= bNUm) {
                    while (p >= bNUm) {
                        bNUm = bNUm * 2;
                    }
                }
                bNUm = (bNUm - p);
                System.out.println(p + " " + bNUm);
                group --;
            }
            System.out.println();
        }
    }
}
