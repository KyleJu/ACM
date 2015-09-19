import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;



//error : while not for
public class acm {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int round = scan.nextInt();
        while (round >0 ) {
            int[] array = new int[6];
            for (int i =0; i < 6; i ++) {
                array[i] = scan.nextInt();
                System.out.print(i + " ");
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
                } else if (array[i] = array[i + 3]) {
                    
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


5
10 5 15 10 1 0 10 5 15 10 6 10 12 5 10 5 20 30 10 0 15 10 5 30 10 5 15 10 5 15
