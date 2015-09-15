import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;


public class acm {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        LinkedHashSet<Integer> set = new LinkedHashSet<Integer>();
        int round = scan.nextInt();
        for (round >0 ) {
            for (int i = 0; i < 10; i ++) {
                set.add(scan.nextInt());
            }
            System.out.println(set);
            boolean mack = set.contains(18);
            boolean zack = set.contains(17);
            if (mack && zack) {
                System.out.println("both");
            } else if (mack) {
                System.out.println("mack");
            } else if (zack) {
                System.out.println ("zack");
            } else {
                System.out.println ("none");
            }
            round --;
        }
    }
    
    
    4
    11 99 88 17 19 20 12 13 33 44 11 12 13 14 15 16 66 88 19 20 20 18 55 66 77 88 17 33 44 11 12 23 34 45 56 67 78 89 91 18

}
