import java.util.Scanner;

public class acm {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int[] a = new int[scan.nextInt()];
        for (int i = 0; i < a.length; i ++) {
            a[i] = scan.nextInt();
        }

        for (int i = 0; i < a.length; i ++) {
            for (int k = i+1; k < a.length; k++) {
                if (a[k] - a[i] <0) {

                    System.out.println("no");
                    return;
                }
            }
        }

        System.out.println("yes");
    }
}