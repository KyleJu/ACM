///* package whatever; // don't place package name! */
//
import java.util.*;
import java.io.*;


public class A {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int[] array = new int[8];
        for (int i =0; i < 8; i ++ ) {
            int n = scan.nextInt();
            array[i] = n;
        }
        int output = 0;
        for (int i=0; i <8; i ++) {
            int sum = 0;
            for (int k = 0; k < 4; k++) {
                int index = i + k;
                sum += array[index%8];
            }
            if (sum > output) {
                output = sum;
            }
        }
        
        System.out.print (output);
    }
}