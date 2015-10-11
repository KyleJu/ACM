import java.util.Scanner;

public class acm {
    public static void main(String[] args) {
        Scanner scan=  new Scanner(System.in);
        int num = scan.nextInt();
        int steps = scan.nextInt();
        int width = scan.nextInt();
        int max = scan.nextInt();
        int[][] array = new int[num][width];
        for (int i =0; i < num; i++) {
            for (int k = 0; k < width; k++) {
                array[i][k] = scan.nextInt();
            }
        }
        int[] milling = new int [width];
        for (int i =0; i<steps; i++) {
            for (int k = 0; k <width; k++) {
                milling[k] = Math.max(milling[k], scan.nextInt());
            }
        }
        for (int i =0; i < num; i++) {
            for (int k = 0; k < width; k++) {
                System.out.print(Math.min(array[i][k], max - milling[k]) + " ");
            }
            System.out.println();
        }


    }

}