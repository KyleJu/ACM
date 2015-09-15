import java.lang.reflect.Array;
import java.util.*;

// try debuggin by using print line
// error: iteration on the wrong letter
// binary reserach starts from n-1 !!!!!!! for size

public class acm {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int round = scan.nextInt();
        while (round >0 ) {
            int[] array = new int[6];
            for (int i =0; i < 6; i ++) {
                int n = scan.nextInt();
                array[i] = n;
                System.out.print(n + " ");
            }
            System.out.print("\n");
            boolean color = false;
            boolean count = false;

            int USA = 0;
            int Ra = 0;
            for (int i =0; i < 3; i ++) {
                USA += array[i];
                Ra += array[i + 3];
            }
            if (USA > Ra) {
                count = true;
            }

            for (int i = 0; i < 3; i ++) {
                if (array[i] > array[ i + 3]) {
                    color = true;
                    break;
                } else if (array[i] == array[i + 3]) {

                } else {
                    break;
                }
            }

            if (color && count) {
                System.out.println("both");
            } else if (color) {
                System.out.println("color");
            } else if (count) {
                System.out.println("count");
            } else {
                System.out.println("none");
            }
            round --;
        }
    }


}
