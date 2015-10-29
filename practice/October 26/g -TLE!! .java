import java.util.*;

public class g{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		while(scan.hasNext()) {
			int g = scan.nextInt();
			int[][] garden = new int[10000 +5][10000 +5];
			for (int i = 0; i < g; i ++) {
				int x = scan.nextInt();
				int y = scan.nextInt();
				garden[x][y]++;
			}

			int sp = scan.nextInt();
			int[] s = new int[(3*sp)];
			for (int i = 0; i < 3*sp; i ++) {
				s[i] = scan.nextInt();
			}

			for (int i =0; i < s.length; i= i+3) {
				int x1 = s[i];
				int y1 = s[i+1];
				int ra = s[i+2];
				for (int j = Math.max(x1 - ra, 0); j <=Math.min(x1+ ra, 10000); j++) {
					for (int k = Math.max(y1 - ra,0); k <= Math.min(y1 +ra, 10000); k++) {
						if (dis(j,k,x1,y1,ra)) {
							g -=garden[j][k];
							garden[j][k] = 0;
						}
					}
				}
			}

			System.out.println(g);

		}
	}

	public static boolean dis (int x, int y, int x1, int y1, double ra) {
		int dx = x - x1;
		int dy = y - y1;
		return ra*ra >= dx*dx +dy*dy;
	}
}