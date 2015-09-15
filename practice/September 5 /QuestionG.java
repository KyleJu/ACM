import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

// 100 whatever
// 10^3 O(n^2)
// 10 ^4,5,6 (nlogn)
// 10^
//int sqrt = (int) Math.sqrt(number) + 1;
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
                int d =  Math.min(max - i, i - min);
                System.out.print("Input value: " + i + "\n");
                System.out.print("Missed it by that much (" + d + ")!\n\n");
            }
            iteration --;
        }
    }

    public static boolean findPrime (int i) {
        // important ******//
        int sqrt = (int) Math.sqrt(i) + 1;
        boolean flag = true;
        for (int k = 2; k < sqrt; k ++) {
            if (i%k == 0) {
                flag = false;
                break;
            }
        }
        return flag;
    }

}
