import java.text.DecimalFormat;
import java.util.*;

public class acm {
    public static void main (String[] args) {
        Scanner s = new Scanner(System.in);
        while (s.hasNext()) {
            double a = s.nextDouble();
            double b = s.nextDouble();
            double c = s.nextDouble();
            double d = s.nextDouble();
            double m = s.nextDouble();
            double t = s.nextDouble();
            double target = t / m;
            double left = 0;
            double right = 500;
            double middle = left + right / 2;
            double val = Math.pow(middle, 3) * a + Math.pow(middle, 2) * b + c * middle + d;

            while (Math.abs(val - target) >= Math.pow(10, -6)) {
                if (val > target) {
                    right = middle;
                } else {
                    left = middle;
                }
                middle = (left + right) / 2;
                val = Math.pow(middle, 3) * a + Math.pow(middle, 2) * b + c * middle + d;
            }

            System.out.println(new DecimalFormat("#0.00").format(((int) (middle * 100)) / 100.0));

        }
    }
}
