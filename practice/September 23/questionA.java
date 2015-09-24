// object [] array = new object[]

import java.text.DecimalFormat;
import java.util.*;

public class acm {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int num = scan.nextInt();
        if (num == 1) {
            System.out.println(1);
            return;
        }
        int[] array = new int[num];
        for (int k = 0; k< num; k++) {
            array[k] = scan.nextInt();
        }
        int result = 0;
        int count = 1;
        for (int i =1; i < array.length; i++) {

            if (array[i] >= array[i-1]) {
                count++;
            } else {
                count = 1;
            }
            result = Math.max(count, result);
        }
        System.out.println(result);
    }
}


