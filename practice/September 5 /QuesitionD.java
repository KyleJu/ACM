import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

// problem:
// you don't need Scan.nextLine()
// watch out for new line on the bottom denominations!"\n\n"
// java doesn' supprot iteration --
//for int n :array not "in" 

public class acm {
    public static void main (String[] args) {
        Scanner Scan = new Scanner(System.in);
        int iteration = Scan.nextInt();
        while (iteration >0) {
            int i = Scan.nextInt();
            boolean t = findPrime(i);
            if (t) {
                System.out.print("Input value: " + i + "\n");
                System.out.print("Would you believe it; it is a prime!\n\n");
            } else {
                int max = i + 1;
                int min = i - 1;
                while (!findPrime(max)) {
                    max++;
                }
                while(!findPrime(min)) {
                    min--;
                }
                int d =  Math.max(max - i, i - min);
                System.out.print("Input value: " + i + "\n");
                System.out.print("Missed it by that much (" + d + ")!\n\n");
            }
            iteration --;
        }
    }

    public static boolean findPrime (int i) {
        int root = Math.sqrt(i);
        boolean flag = true;
        for (int k = 2; k < root; k ++) {
            if (i%k == 0) {
                flag = false;
            }
            return flag;
        }
    }
}
