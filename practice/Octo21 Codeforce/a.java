import java.util.*;

public class a {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int c = scan.nextInt();
		int min = Integer.MAX_VALUE;
		int res = 0;
		while (c -->0) {
			int m = scan.nextInt();
			min = Math.min(min, scan.nextInt());
			res += min*m;
		}

		System.out.println(res);
	}
}