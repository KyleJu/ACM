
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;

public class acm {
    public static int[] trops;
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int a = scan.nextInt();
        int b = scan.nextInt();
        BigInteger c = new BigInteger("10");
        BigInteger d = c.pow(a -1);
        BigInteger b1 = new BigInteger(Integer.toString(b));
        if (a == 1) {
            if (b == 10) {
                System.out.println(-1);
                return;
            } else {
                System.out.println(b);
                return;
            }
        }
        System.out.println(b1.subtract(d.divideAndRemainder(b1)[1]).add(d));

    }
}


