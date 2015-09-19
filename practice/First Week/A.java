/* package whatever; // don't place package name! */

import java.util.*;
import java.io.*;


/* Name of the class has to be "Main" only if the class is public. */
public class A
{
    public static void main (String[] args)
    {		  Scanner scan = new Scanner(System.in);
        int size = scan.nextInt();
        int[] array = {-1, -1, -1, -1, -1, -1};
        int[] array1 = {-1, -1, -1, -1, -1, -1};
        for (int i = 1 ; i <= size; i++) {
            int input = scan.nextInt();
                array[input - 1] = i;
                array1[input - 1]++;
            }
        
        int u = 5;
        while (u >= 0) {
            if (array1[u] == 0) {
                System.out.println(array[u]);
                return;
            }
            u--;
        }
        System.out.println("none");
        
    }
}