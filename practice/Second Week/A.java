/* package whatever; // don't place package name! */

import java.util.*;
import java.io.*;


/* Name of the class has to be "Main" only if the class is public. */
public class A
{
    public static void main (String[] args)
    {   Scanner scan = new Scanner(System.in);
        int size = scan.nextInt();
        int[] answerArray = new int[size];
        int previous = 0;
        for (int i = 1 ; i <= size; i++) {
            int input = scan.nextInt();
            int answer = input * i - previous;
            previous += answer;
            answerArray[i-1] = answer;
        }
        if (size == 0) {
            System.out.println(0);
        }
        for (int i = 1; i <= size; i ++) {
            System.out.print(answerArray[i -1] + " ");
        }
    }
}