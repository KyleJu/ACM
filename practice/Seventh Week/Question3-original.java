
import java.util.*;
import java.io.*;

public class B 
{
    public static void main (String[] args)
    {
        Scanner scan = new Scanner(System.in);
        int size = scan.nextInt();
        int result = 0;
        scan.nextLine();
        for (int i =0; i < size; i ++) {
            String input = scan.nextLine();
            for (int k =0; k < input.length() - 1; k++) {
                String c = String.valueOf(input.charAt(k))
                String d = String.valueOf(input.charAt(k + 1));
                if (c.equals("C") && d.equals("D")) {
                    result++;
                    return;
                }
            }
        }
        
        System.out.println(result));
    }
}