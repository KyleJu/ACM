import java.lang.reflect.Array;
import java.util.*;

//quick way to input - print in the very beginning
//find the quick way to print
//position of my linkedhashset - should be inside of the loop


public class acm {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int round = scan.nextInt();
        while (round > 0) {
            LinkedHashSet<Integer> set = new LinkedHashSet<Integer>();
            for (int i = 0; i < 10; i ++) {
                set.add(scan.nextInt());
            }
            for (int i : set) {
                System.out.print(i + " ");
            }
            System.out.print("\n");
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


}
