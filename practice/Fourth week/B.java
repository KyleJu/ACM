/* package whatever; // don't place package name! */

import java.util.*;
import java.io.*;


/* Name of the class has to be "Main" only if the class is public. */
public class B 
{
    public static void main (String[] args)
    {   Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
        int p = scan.nextInt();
        int[] options = new int[100002];
        int[] visit = new int[100002];
        for (int i = 0; i < n; i ++) {
            int f = scan.nextInt();
            int h = scan.nextInt();
            if (options[h] == 0) {
                options[h] = f;
            }
        }
        
        int output = 0;
        while (true){
            if (options[p] == 0)
                break;
            if (visit[p] == 1){
                output = -1;
                break;
            }
            visit[p] = 1;
            p = options[p];
            output++;
        }
        System.out.println(output);
        scan.close();
    }
}