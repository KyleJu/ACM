/* package whatever; // don't place package name! */

import java.util.*;
import java.io.*;


/* Name of the class has to be "Main" only if the class is public. */
public class B 
{
    public static void main (String[] args)
    {   Scanner scan = new Scanner(System.in);
        int size = scan.nextInt();
        int maxX = -1;
        int maxY = -1;
        int minX = 101;
        int minY = 101;
        for (int i = 1 ; i <= size; i++) {
            int input = scan.nextInt();
            if (input >maxX) {
                maxX = input;
            }
            if (input < minX) {
                minX = input;
            }
            int y = scan.nextInt();

            if ( y > maxY) {
                maxY = y;
            }
            if (y < minY) {
                minY = y;
            }
        }
        if (maxX - minX > maxY - minY) {
            System.out.println((maxX - minX) * (maxX - minX));

        } else {
            System.out.println((maxY - minY) * (maxY - minY));

        }
    }
}