// object [] array = new object[]

import org.omg.Messaging.SYNC_WITH_TRANSPORT;

import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;

public class acm {
    public static void main (String[] args) {
        Scanner scan  = new Scanner(System.in);
        int n = scan.nextInt();
        //System.out.println((int)((Math.pow(27,n) - Math.pow(7,n))% (Math.pow(10,9) - 7))) ;
        System.out.println(new BigInteger("27").pow(n).subtract(new BigInteger("7").pow(n)).divideAndRemainder(new BigInteger(Integer.toString((int)Math.pow(10,9) +7)))[1]);
        // at least n - t in common
    }
}




