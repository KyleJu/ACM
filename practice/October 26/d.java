import java.util.*;

public class d {
	public static void main(String[] args) {	
		Scanner scan = new Scanner(System.in);
		while (scan.hasNext()) {
			int q = scan.nextInt();
			int r = scan.nextInt();
			int[] memo  = new int[(int)Math.pow(10, 5) + 2000];
			for (int i = 0; i < q; i ++) {
				int n = scan.nextInt();
				memo[n] += 1;
				memo[n + 1000] += -1;
			}
			int max = Integer.MIN_VALUE;
			int sum = 0;
			for (int i = 0; i < memo.length; i ++) {
				sum += memo[i];
				max = Math.max(max, sum);
			}

			int res = (int)(max-0.1)/r + 1;
			System.out.println(res);
		}
	}
}