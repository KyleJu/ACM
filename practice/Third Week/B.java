/* package whatever; // don't place package name! */

import java.util.*;
import java.io.*;


/* Name of the class has to be "Main" only if the class is public. */
public class B 
{
    public static void main (String[] args)
    {		  Scanner scan = new Scanner(System.in);
        int size = scan.nextInt();
        Set<String> inputSet = new HashSet<String>();
        for (int i = 0; i < size *2 - 1; i++) {
            String name = scan.next();
            if(inputSet.contains(name)) {
                inputSet.remove(name);
            } else {
                inputSet.add(name);
            }
        }
        String[] y = inputSet.toArray(new String[0]);
        System.out.print(y[0]);
        
    }
}