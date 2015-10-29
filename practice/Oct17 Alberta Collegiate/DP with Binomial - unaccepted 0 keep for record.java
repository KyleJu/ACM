import java.util.*;


public class D{
	public static long[][] bTable = new long[61][61];
	public static long[][] memo;
	public static int[] nu;
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int tcase = scan.nextInt();
		while (tcase --> 0) {
			bTa();
			int nclub = scan.nextInt();
			int bnum = scan.nextInt();
			nu = new int[nclub];
			int tot = 0;
			for (int i =0; i <nclub; i ++) {
				nu[i] = scan.nextInt();
				tot+= nu[i];
			}
			memo = new long[65][65];
			for (int i=0; i <65; i ++) {
				Arrays.fill(memo[i],-1);
			}
			double res = 0.0;
			res = dp(bnum, nclub-1)/(bTable[tot][bnum]);
			System.out.println(res);
		}
	}

	public static double dp(int n, int c) {
		if (n<c) return 0;
		if (c ==0) return 1;
		if (memo[n][c] !=-1) return memo[n][c];
		long res = 0;
		for (int i = 1; i <= Math.min(n, nu[c]); i++) {
			res +=dp(n-i, c-1)*bTable[nu[c]][i];
		}
		return res;
	}

	public static void bTa() {
		for (int i= 0; i < 61; i++) {
			bTable[i][0] =1;
		}

		for (int i = 1 ; i < 61; i ++) {
			for (int j = 1; j < 61; j ++) {
				bTable[i][j] = bTable[i-1][j-1] + bTable[i-1][j];
			}
		}
	}
}