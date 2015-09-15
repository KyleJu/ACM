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
        while (iteration > 0) {
            int s = Scan.nextInt();
            int[] array = new int[s];
            for (int i = 0; i < s; i ++) {
                array[i] = Scan.nextInt();
            }
            Arrays.sort(array);
            boolean flag = false;
            for (int k = 1; k < s; k ++) {
                if (array[k] < 2 * array[k -1]) {
                    flag = true;
                }
            }
            System.out.print("Denominations: ");
            for(int n : array) {
                System.out.print(n + " ");
            }
            if (flag) {
                System.out.print ("\nBad coin denominations!\n\n");
            } else {
                System.out.print ("\nGood coin denominations!\n\n");
            }
            iteration--;

        }

    }

}
