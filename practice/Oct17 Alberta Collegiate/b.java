import java.util.*;
import java.text.DecimalFormat;

public class b{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int test = scan.nextInt();
		while( test --> 0) {
			int r = scan.nextInt();
			int d = scan.nextInt();
			int h = r-d;
			double sphere = (4.0/3)*Math.PI * r*r*r;
			double cap = Math.PI *h*h/(3.0)*(3*r-h);
			System.out.println(new DecimalFormat("#0.00").format(sphere - cap));

		}
	}
}