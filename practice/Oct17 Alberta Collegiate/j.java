import java.util.*;

public class j {
	public static void main (String[] args) {
		Scanner scan  = new Scanner(System.in);
		int test = scan.nextInt();
		while(test --> 0) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			String o = scan.next();
			boolean f1 =  (a>b) && o.equals(">");
			boolean f2 = (a<b)&& o.equals("<");
			if (f1|| f2) {
				System.out.println("Ready");
			} else {
				System.out.println("Reboot");
			}
		}
	}
}