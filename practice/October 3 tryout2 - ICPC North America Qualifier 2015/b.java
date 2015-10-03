import com.sun.corba.se.impl.oa.toa.TOA;
import org.omg.Messaging.SYNC_WITH_TRANSPORT;

import javax.xml.soap.SAAJMetaFactory;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedHashMap;
import java.util.Scanner;

public class tryout {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        scan.nextLine();
        while(test>0) {
            test--;
            int r = scan.nextInt();
            int s = scan.nextInt();
            int x = scan.nextInt();
            int y = scan.nextInt();
            int w = scan.nextInt();
            double p = (double)(s-r+1)/s;
            double pn = 1 - p;
            double win = 0;
            int  i = x;
            while(i <= y) {
                int top = factorial(y,i);
                int bottom = factorial(i,i);
                win += ((double)top/bottom) * Math.pow(p,i) * Math.pow(pn, y - i);
                i++;
            }
            if (win*(double)w >(double)1) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }
    }

    public static int factorial(int c, int count) {
        int r = 1;
        while (count >= 1) {
            r *=c;
            count--;
            c --;
        }
        return r;

    }


}

