import java.util.*;

public class Main{
	public static int n;
	public static int k;
	public static float[][] memo;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		memo = new float[551][550*6 + 1];
		memo[0][0] = 1.0f;
		for (int x = 1; x < 551; x ++) {
			for (int y = 1; y < (550*6 +1); y++) {
				for (int z = 1; z <=6; z++) {
					if ((y - z)<0) continue;
					memo[x][y] += memo[x-1][y-z]/6; 
				}
			}
		}
		while (test --> 0) {
			n = sc.nextInt();
			k = sc.nextInt();

			if (k > 550 * 6 ||  n > 550) {
				System.out.println(0);
			} else {
				System.out.println((int)(memo[n][k] * 100));
			}
		}
	}
}

