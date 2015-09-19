import java.util.Scanner;

public class acm {

    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int f = Scan.nextInt();
        int s = scan.nextInt();
        int g = scan.nextInt();
        int u = scan.nextInt();
        int d = scan.nextInt();
        int diff = u - d;
        boolean flag = false;
        int step = 0;
        if (g > s) {
            if ((g -s )%u == 0) {
                step += (g -s)/u;
            } else {
                s = (g-s) % u;
                if (s %diff == 0) {
                    step += step + (s/d) *2
                } else {
                    flag = true;
                }
            }
        } else {
            if ((g -s )%d == 0) {
                step += (g -s)/d;
            } else {
                s = (g-s) % d;
                if (s %diff == 0) {
                    step += step + (s/d) *2
                } else {
                    flag = true;
                }
            }
        }
        
        if (flag) {
            System.out.print("use the stairs");
        } else {
            System.out.println(step);

        }
    }

}
