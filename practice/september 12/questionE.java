import java.lang.reflect.Array;
import java.text.DecimalFormat;
import java.util.*;


public class acm {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int round = scan.nextInt();
        double pi = 3.14159265358979;
        while (round > 0) {
            double l = scan.nextInt();
            double r = scan.nextInt();
            DecimalFormat df = new DecimalFormat("#.00");
            if (Math.sqrt(2)*l <= 2.0 *r) {
                System.out.println(df.format(Math.pow(l,2)));
            } else if (2.0* r <= l ){
                System.out.println(df.format(pi * Math.pow(r, 2)));
            } else {
                double hLength = l /2;
                double tArea = Math.sqrt(Math.pow(r, 2)- Math.pow(hLength, 2)) * hLength;

                double angle = Math.acos(hLength/r);
                double arcAngle = (pi /2.0) - 2.0*angle;
                double arcArea = arcAngle * Math.pow(r, 2) /2.0;
                System.out.println(df.format((arcArea + tArea) * 4.0));
            }
            round --;
        }
    }
}