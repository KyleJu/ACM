import java.util.*;

public class Main{
	public static char[][] m;
	public static int[][] cost;
	public static int[] hx = {0,0,1,1,1,-1,-1,-1};
	public static int[] vy = {1,-1,0,1,-1,0,1,-1};
	public static int w;
	public static int h;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int ca = 0;
		while (sc.hasNext()) {
			h = sc.nextInt();
			w = sc.nextInt();
			if (h == 0 && w == 0) {
				return;
			}
			if (h == 0|| w== 0) {
			  System.out.println("Case " + ++ca + ": 0");
			  continue;
			}
			m = new char[h][w];
			cost = new int[h][w];
			for (int i = 0 ; i < h; i ++) {
				String te = sc.next();
			 	 for (int j = 0; j < w; j++) {
			 	 	m[i][j] = te.charAt(j);
			 	 	//System.out.println(m[i][j]);
			 	 }
			}
			//System.out.println("test 0");
			for (int i = 0; i < h; i++) {
				Arrays.fill(cost[i], -1);
			}
			int res  = 0;
			//System.out.println("test 11");
			for (int i = 0; i < h; i ++) {
				for (int j = 0; j < w; j++) {
					if (m[i][j] != 'A') continue;
					res = Math.max(res, dp(i,j));
				}
			}
			System.out.println("Case " + ++ca + ": " + res);
		}
	}

	public static int dp(int y, int x) {
					//System.out.println("test 2");
		if (cost[y][x] != -1) return cost[y][x];
		int res = 1;
		for (int i = 0; i < 8; i++) {
			int tx = x + hx[i];
			int ty = y + vy[i];
			if ( tx <0 || tx>=w || ty <0|| ty>=h) continue;
			if ((int)m[ty][tx] == (int)m[y][x] + 1) {
				res = Math.max(res, 1+ dp(ty,tx)); 
			}
		}
		cost[y][x] = res;
		return res;
	}

}