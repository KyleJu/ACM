
import java.util.*;
import java.io.*;

public class A {
    public static void main (String[] args) {
        Scanner scan = new Scanner (System.in);
        int isRight = 1;
        int h = scan.nextInt();
        int w = scan.nextInt();
        int[][] wall = new int[h + 1][2];
        scan.nextLine();
        wall[0][0] = 1001;
        wall[0][1] = -1;
        for (int i =1; i < h+1; i ++) {
            String input = scan.nextLine();
            int left = 1001;
            int right = -1;
            for (int k = 0; k < w; k ++) {
                String l = String.valueOf(input.charAt(k));
                if (l.equals("J")) {
                    if (left > k) {
                        left = k;
                    }
                    if (right < k) {
                        right = k;
                    }
                    //  System.out.print(input);
                }
            }
            wall[i][0] = left;
            wall[i][1] = right;
        }
        wall[h][0] = 0;
        wall[h][1] = 0;
//        for (int i =0; i < h +1; i ++) {
//            System.out.print(wall[i][0] + " ");
//            System.out.print(wall[i][1] + "\n");
//        }
        //
        int pos = 0;
        int step = 0;
        int last = 0;
        for (int i = 0; i <h; i ++) {
            if (wall[h-i][1] == -1) {
                if (i%2 == 0) {
                    int s = Math.abs(Math.max(wall[h-i][1],wall[h-1-i][1]) - pos);
                        step += s;
                    pos = Math.max(wall[h-i][1],wall[h-1-i][1]);
                } else {
                    int s = Math.abs(pos - Math.min(wall[h-i][0],wall[h-1-i][0]));
                    step += s;
                    pos = Math.min(wall[h-i][0],wall[h-1-i][0]);
                }
                last = i;
            }
        }
        step = step + last;
        System.out.print(step);
    }
    
}