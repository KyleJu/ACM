// object [] array = new object[]

import java.text.DecimalFormat;
import java.util.*;

public class acm {
    public static int[] trops;
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int red = scan.nextInt();
        int blue = scan.nextInt();
        System.out.println(Math.min(red, blue) + " " + (Math.max(red,blue) -Math.min(red, blue))/2);

    }
}




