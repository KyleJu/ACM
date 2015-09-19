/* package whatever; // don't place package name! */

import java.util.*;
import java.io.*;


/* Name of the class has to be "Main" only if the class is public. */
public class A
{
    public static void main (String[] args)
    {   Scanner scan = new Scanner(System.in);
        String input = scan.next();
        int result = 0;
        int size = input.length();
        int[] array = new int[input.length()];
        for (int i = 0; i < size; i ++) {
            int n = Character.getNumericValue(input.charAt(i));
            result +=n;
            array[i] = n;
        }
        Arrays.sort(array);
        if (result % 3 != 0 || array[0]!=0) {
            System.out.println(-1);
            return;
        }

        int output = 0;
        for (int k = input.length(); k >0; k--) {
                System.out.print(array[k - 1]);
            
        }
    }
}