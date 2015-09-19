/* package whatever; // don't place package name! */

import java.util.*;
import java.io.*;


/* Name of the class has to be "Main" only if the class is public. */
public class A
{
    public static void main (String[] args)
    {    Scanner scan = new Scanner(System.in);
        int size = scan.nextInt();
        int[] counter = new int[100000];
        Set<Integer> set = new HashSet<Integer>();
        for (int i = 0; i < size; i ++) {
            int input = scan.nextInt();
            set.add(input);
            counter[input] ++;
        }
        Integer[] arr = set.toArray(new Integer[0]);
        int count = 1;
        int num = set.size();
        int left = 0;
        int right = num-1;
        Arrays.sort(arr);
        while (true) {
            if (num < 3) {
                break;
            }
            counter[arr[left]]--;
            counter[arr[left + 1]]++;
            count++;
            if (counter[arr[left]] == 0) {
                left++;
                num--;
            }
            
            if (num < 3) {
                break;
            }
            
            counter[arr[right]]--;
            counter[arr[right - 1]]++;
            count ++;
            if (counter[arr[right]] == 0) {
                right--;
                num--;
            }
        }
        if (count % 2 == 0) {
            System.out.print("Mirko" + "\n");
        } else {
            System.out.print("Slavko" + "\n");
        }
        
        System.out.print(arr[left] + " ");
        System.out.print(arr[right]+"\n");
        
        
        scan.close();
        
    }
    
}