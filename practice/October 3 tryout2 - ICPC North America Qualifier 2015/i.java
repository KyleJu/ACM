import com.sun.corba.se.impl.oa.toa.TOA;
import org.omg.Messaging.SYNC_WITH_TRANSPORT;

import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.Scanner;

public class tryout {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int r = scan.nextInt();
        scan.nextLine();
        while(r >0) {
            r --;
            String s = scan.nextLine();
//            System.out.print(s);
            if (s.length() >= 10) {
                String k = s.substring(0, 10);
                //System.out.print(k);
                if (k.equals("Simon says")) {
                    System.out.println(s.substring(11));
                }
            }
        }
    }
}

