import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

// problem:
// you don't need Scan.nextLine()
// watch out for new line on the bottom denominations!"\n\n"
// java doesn' supprot iteration --
//for int n :array not "in" 

//public class acm {
//    public static void main (String[] args) {
//    
//    }
//}
public class acm {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int interation = Scan.nextInt();
        while (for z=0; z; interation; z++) {
            int r = scan.nextInt();
            int c = scan.nextInt();
            int[][] array = int[r][c];
            int s = 0;
            for (int i = 0; i < r; i ++) {
                for (int k = 0; k < c; k ++) {
                    if ((i+k)%2 == 0) {
                        s -= Scan.nextInt();
                    } else {
                        s += Scan.nextInt();
                    }
                }
            }
            if (s ==0) {
                System.out.print("Case #" + z +1 +": YES");
            } else {
                System.out.print("Case #" + z + 1 +": NO");
            }

        }
    }
}