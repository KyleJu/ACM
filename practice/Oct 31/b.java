import java.util.*;

public class b{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int test = scan.nextInt();
		while (test --> 0) {
			int[] ar = new int[1001];
			int n = scan.nextInt();
			for (int i = 0; i < n; i ++) {
				ar[scan.nextInt()]++;
			}
			int res = 0;
			int max = 0;
			for (int i = 1; i < 1001; i ++) {
				if (ar[i] >max) {
					max = ar[i];
					res = i;
				}
			}

			System.out.println(res);
		}
	}
}