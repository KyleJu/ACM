///* package whatever; // don't place package name! */
//
import java.util.*;
import java.io.*;


public class A {
    private int[][] wall;
    private static int result;
    private int length;
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        result = 0;
        length = scan.nextInt();
        wall = new int[h][h];
        scan.nextLine();
        for (int i =0; i < lenght; i++) {
            String input = scan.nextLine();
            for (int k =0; k <length; k ++) {
                String l = String.valueOf(input.charAt(k));
                if (l.equals("#")) {
                    wall[i][k] = 1;
                }
            }
        }
        walk(0,0);
        System.out.println(result);
    }
    
    private void walk(int x, int y) {
        if (x + 1 == length && y + 1 == length) {
            result ++;
        } else {
            if (x < length && wall[x+1][y] != 1) {
                walk[x+1][y];
            }
            
            if (y < length && wall[x][y+1]) {
                walk[x][y+1];
            }
        }
    }
}