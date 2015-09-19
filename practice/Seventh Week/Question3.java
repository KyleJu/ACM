import java.util.Scanner;

/**
 * Created by xifengju on 15-07-11.
 */
public class acm {

    public static void main (String[] args)
    {
        Scanner scan = new Scanner(System.in);
        int size = scan.nextInt();
        int result = size;
        scan.nextLine();
        for (int i =0; i < size; i ++) {
            String input = scan.nextLine();
            boolean r= true;
            for (int k =0; k < input.length() - 1; k++) {
                String c = String.valueOf(input.charAt(k));
                String d = String.valueOf(input.charAt(k + 1));
                if (c.equals("C") && d.equals("D")) {
                    r = false;

                }
            }
            if (!r) {
                result--;
            }
        }

        System.out.println(result);
    }

}
