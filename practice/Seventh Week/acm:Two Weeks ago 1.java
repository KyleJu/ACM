import java.util.Scanner;

public class acm {
    public static boolean[][] f;
    public static int length;
    public static long[][] wall;

    public static void walk(int x, int y) {
        if (x >= length || y >= length  || x <0 || y < 0) {
            return;
        }
        if (wall[x][y] == 1) {
            return;
        }
        if (f[x][y]) {
            return;
        }
        f[x][y] = true;
        walk(x+1, y);
        walk(x-1, y);
        walk(x, y+1);
        walk(x, y-1);
    }
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        length = scan.nextInt();
        wall = new long[length][length];
        long [][] w = new long[length][length];
        f = new boolean[length][length];
        scan.nextLine();
        for (int i =0; i < length; i++) {
            String input = scan.nextLine();
            for (int k =0; k <length; k ++) {
                String l = String.valueOf(input.charAt(k));
                if (l.equals("#")) {
                    wall[i][k] = 1;
                }
            }
        }
        w[0][0] = 1;
        for (int i =1; i < length; i ++) {
            if (wall[i][0] != 1) {
                w[i][0] =w[i-1][0];
            } else {
                w[0][i] = 0;
            }
            if (wall[0][i] != 1) {
                w[0][i] = w[0][i-1];
            } else {
                w[0][i] = 0;
            }
        }

        for (int i = 1; i < length; i++) {
            for (int k = 1; k < length; k ++) {
                if (wall[i][k] == 1) {
                    w[i][k] = 0;
                } else {
                    w[i][k] = (w[i-1][k] + w[i][k-1])%(1<<31 -1);
                }
            }
        }

        if (w[length-1][length-1] > 0) {
            System.out.println(w[length - 1][length - 1]);
        } else {
            walk(0,0);
            if (f[length-1][length-1]) {
                System.out.print("THE GAME IS A LIE");
            } else {
                System.out.print("INCONCEIVABLE");
            }
        }
    }
}
