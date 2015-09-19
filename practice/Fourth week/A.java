/* package whatever; // don't place package name! */

import java.util.*;
import java.io.*;


/* Name of the class has to be "Main" only if the class is public. */
public class A
{
    public static void main (String[] args)
    {   Scanner scan = new Scanner(System.in);
        int[] output = {0,0,0,0,0,0,0,0};
        String[][] keyboards = {{"1","Q", "A", "Z"}, {"2", "W","S","X"},{"3","E","D","C"},{"4","5","R","T","F","G","V","B"},{"6", "7", "Y","U","H","J","N","M"}, {"8","I","K",","}, {"9","O","L","."},{"0","-","=","P","[","]",";","'","/"}};
        String input = scan.nextLine();
        for (int x=0;x<input.length();x++) {
            String l = String.valueOf(input.charAt(x));
            for (int i =0; i < keyboards.length;i ++) {
                String [] f = keyboards[i];
                if(Arrays.asList(f).contains(l)) {
                    output[i]++;
                    break;
                }
            }
        }
        
        for (int i = 0; i < output.length; i ++) {
            System.out.print(output[i]+"\n");
        }
    }
}