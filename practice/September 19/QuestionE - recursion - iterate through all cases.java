// object [] array = new object[]

import java.text.DecimalFormat;
import java.util.*;

public class acm {
    // game by game iteration - taking into consideration of all possibilities and if win -> 1, lose ->0
    // error: int division return int -> same as objective c!!!
    private static int op;
    private static int w;
    private static int l;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int round = scan.nextInt();
        while (round > 0) {
            scan.nextLine();
            // watch out if inputs are lines or just input. if byline, advance line (use hasNextLine(). next()or nextInt() don't advance) otherwise use hasNext()
            scan.nextLine();
            op = scan.nextInt();
            w = scan.nextInt();
            l = scan.nextInt();

            //start from first iteration s =20, a - Canucks win, b - opp win
            //iterate thorugh all case but get rid of the losing cases
            System.out.println(new DecimalFormat("#0.00000").format(prob(20, op, 4, 4)));
            round --;
        }
    }

    public static double prob(int s, int o, int a, int b) {
        //a reaches 0 canucks ->win // b reaches 0, op win
        if (a == 0) return 1.0;
        if (b == 0) return 0.0;
        //
        return ((double)s/(s+o))*prob(20+w,o,a-1,b) + ((double)o/(s+o))*prob(20-l, o, a, b-1);
    }

}


