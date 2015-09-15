import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

public class acm {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int iteration = scan.nextInt();
        for (int z=1 ; z < iteration + 1; z++) {
            int r = scan.nextInt();
            int c = scan.nextInt();
            int s = 0;
            for (int i = 0; i < r; i ++) {
                for (int k = 0; k < c; k ++) {
                    if ((i+k)%2 == 0) {
                        s -= scan.nextInt();
                    } else {
                        s += scan.nextInt();
                    }
                }
            }
            if (s ==0) {
                System.out.print("Case #" + z +": YES\n\n");
            } else {
                System.out.print("Case #" + z+": NO\n\n");
            }

        }
    }

}
