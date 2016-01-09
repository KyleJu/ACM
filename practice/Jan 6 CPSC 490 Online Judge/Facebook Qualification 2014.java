import java.util.*;

public class fb{
	public static int[][] m = new int[25][25];
	public static boolean[][] check;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int t1 = 1; t1 <=t; t1++) {	
			int l = sc.nextInt();
			check = new boolean[l+5][l+5];
			//System.out.print("Case#" + t1 + ":");
			for (int i = 0 ; i<l; i++) {
				Arrays.fill(m[i], 0);
			}
			for (int i = 0; i < l; i++) {
				String r = sc.next();
				for(int k = 0 ; k <l; k++) {
					if (r.charAt(k) == '.') {
						m[i][k] = 0;
					} else {
						m[i][k] = 1;
					}
				}
			}
			boolean isBFS = false;
			boolean res = false;
			for (int i = 0 ; i < l; i++) {
				for (int k = 0; k < l; k++) {
					if (check[i][k]) continue;
					if ((m[i][k]== 1) && isBFS) {
						res = false;
						break;
					}
					if (m[i][k] == 0) continue;
					res = bfs(i, k, l);
					//system.out.println(res);
					if (!res) break;
					isBFS = true;
				}
			}
			if (res) System.out.print("Case#" + t1 + ":" + "YES\n");
			else System.out.print("Case#" + t1 + ":" + "NO\n");
		}
	}
	//just do a size check brutal force h and v
	public static boolean bfs(int i, int k, int l) {
		int size = 0;
		while(true) {
			//out of range problems and new square
			if (i+size>=l || k +size >= l||m[i+size][k] != 1) break;
			for (int x = 0; x <=size; x++) {
				for (int y = 0 ; y <=size; y++) {
					if (m[i+x][k+y]==0) return false;
					check[i+x][k+y] = true;
				}
			}
			size++;
		}
		return true;
	}
}