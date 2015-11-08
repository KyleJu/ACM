import java.util.*;

public class c {
	public static void main(String[] args) {	
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		while (t-->0) {
			int n = scan.nextInt();
			double[] w = new double[n];
			double[] c = new double[n];
			for (int i =0; i <n ;i ++) {
				w[i] = scan.nextDouble();
				c[i] = scan.nextDouble();
			}

			int res = 1;
			int[] r = new int[n];
			Arrays.fill(r, 1);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < i; j++) {
					if (w[i]>w[j] && c[i]<c[j]) {
						r[i] = Math.max(1 + r[j], r[i]);
						res = Math.max(res,r[i]);
					}
				}
			}

			System.out.println(res);
		}
	}
}