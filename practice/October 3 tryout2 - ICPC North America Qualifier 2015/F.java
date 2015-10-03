import com.sun.corba.se.impl.oa.toa.TOA;
import org.omg.Messaging.SYNC_WITH_TRANSPORT;

import javax.xml.soap.SAAJMetaFactory;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.Scanner;

public class tryout {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        scan.nextLine();
        while(test > 0) {
            test --;
            int a =  (int) 'a';
            int b = (int) 'z';
            int A= (int) 'A';
            int B = (int ) 'Z';
           // System.out.println(a +" " + b + " " + A + " " + B);
            String s = scan.nextLine();
            int[] check = new int[26];
            for (int i =0; i <s.length(); i ++) {
                int c = (int)s.charAt(i);
                if ((c >=a && c <=b) || (c>=A && c<=B)) {
                    if (c <a) {
                        //cap
                        check[c-A]++;
                    } else {
//                        System.out.println(c);
                        //non cap
                        check[c-a]++;
                    }
                }
            }

            boolean first = false;
            boolean p = true;
            for (int i = 0; i < 26; i ++) {
                if (check[i] == 0) {
                    if (!first) {
                        System.out.print("missing ");
                    }
                    first =true;
                    p = false;
                    System.out.print((char) (i+a));
                }
            }
            System.out.println();
            if (p) {
                System.out.println("pangram");
            }
        }
    }
}

