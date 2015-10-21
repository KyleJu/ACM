import java.util.*;

public class g {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		int t=  scan.nextInt();
		while (t --> 0) {
			int a = scan.nextInt();
			int[][] m = new int[a][a];
			for (int i = 0; i < a; i++) {
				String s = scan.next();
				for (int j = 0; j < a; j++) {
					if (s.charAt(j) == 'E') {
						m[i][j] = 1;
					} else {
						m[i][j] = 0;
					}
				}
			}
			int max = -1;
			for (int i = 1; i < a; i++) {
				for (int j = 1; j< a; j++) {
					if (m[i][j] == 1) {
						m[i][j] = 1 + Math.min(m[i-1][j], Math.min(m[i-1][j-1], m[i][j-1]));
						max = Math.max(max, m[i][j]); 
					} else {
						m[i][j] = 0;
					}
				}
			}

			System.out.println(max);

		}
	}
}