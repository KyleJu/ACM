// object [] array = new object[]


import javafx.util.Pair;
import org.omg.Messaging.SYNC_WITH_TRANSPORT;

import javax.swing.plaf.synth.SynthTextAreaUI;
import java.text.DecimalFormat;
import java.util.*;

public class acm {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int round = scan.nextInt();
        while (round > 0) {
            double p = scan.nextDouble();
            double s = 0;
            DecimalFormat format = new DecimalFormat("#0.00000");
            // proof:
            //3c3 *ppp*qqqq*(p^2 +2pq(p^2+2pq(p^2+2pq(...))))
            //=20pppqqq (p^2 +2P^3q + 4P^2P^2*q^2 +8p^3q^3*p^2 ..)
            // set k = 2pq -> limit = 1/(1-k) -> p^2(1/(1-2pq)
           System.out.println(format.format(Math.pow(p,4) +4*Math.pow(p,4)*(1-p) + 10*Math.pow(p,4)*(1-p)*(1-p) +20*Math.pow(p*(1-p),3)*(p*p/(1-2*p*(1-p)))));
            round--;
        }
    }
}


