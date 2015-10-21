import java.util.*;

public class a {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int test = scan.nextInt();
		while (test --> 0) {

			long num = scan.nextLong();
			// if (num == 1) {
			// 	System.out.println(1);
			// 	return;
			// }
			long level = 1;
			long t = 1;
			while (t < num) {
				level++;
				t += ((1+level)*level)/2;
			}
			long count = 0;
			while (num >0) {
				num -= ((1+level)*level)/2;
				level --;
				count++;
			}

			System.out.println(count);
		}
	}
}