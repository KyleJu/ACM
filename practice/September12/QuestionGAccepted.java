import java.lang.reflect.Array;
import java.text.DecimalFormat;
import java.util.*;

// error: the condition should bb (n-1)^2  as long as there exists a path from (1,1) to (n,n)s
public class acm {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int round = scan.nextInt();
        for (int i = 1; i <=round; i ++) {
            int d = scan.nextInt();
            int n = scan.nextInt();
            if (Math.pow((n -1),2) + 1 >= d) {
                int step = (2*n-2)*d;
                System.out.println("Grid #" + i + ": " + step + "\n");
            } else {
                System.out.println("Grid #" + i + ": " + "impossible\n");
            }

        }
    }

//            3
//            2 2
//            100 8
//            3 100
}