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
        while(test>0) {
            test--;
            String message = scan.nextLine();
            int length = message.length();
            int k = (int)Math.sqrt((double)length - 0.001) + 1;
            int d = (int)Math.pow(k, 2) - length;
            while (d >0) {
                message = message + "*";
                d--;
            }
            //System.out.println(message);
            char[][] array = new char[k][k];
            for (int i =0; i < k; i ++) {
                for (int l = 0; l < k; l++) {
                    array[i][l] = message.charAt((i*(k)) +l);
                }
            }

//            for (int i = 0 ;i < k; i++) {
//                System.out.println();
//            }

            for (int i = 0; i< k; i ++) {
                for (int l = 0; l < k; l++ ) {
                    if (array[k-1-l][i]!= '*') {
                        System.out.print(array[k-1-l][i]);
                    }
                }
            }
            System.out.println();
        }

    }
}

