///* package whatever; // don't place package name! */
//
import java.util.*;
import java.io.*;

public class A {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int size = scan.nextInt();
        int target = scan.nextInt();
        int[] h = new int[100001];
        int[] v = new int[100001];
        int[] d = new int[200005];
        int[] rd = new int[200005];
        int a = 0;
        for (int i = 0; i < size; i ++) {
            int temp = 0;
            int x = scan.nextInt();
            int y = scan.nextInt();
            h[x]++;
            v[y]++;
            if (y - x> 0) {
                d[y - x] ++;
                temp = d[y-x];
                
            } else {
                d [100001 + x - y]++;
                temp = d[100001 + x - y];
            }
            rd[x+y]++;
            if (h[x] == target||v[y]==target|| temp == target || rd[y+x]==target) {
                a = i + 1;
                System.out.print(a);
                return;
            }
        }
        if (a ==0) {
            System.out.print("-1");
        }
        
    }
}