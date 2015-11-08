import java.util.*;


public class a {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int b = 'a';
		int[][] st = new int[1000][26];
		int[] me = new int[1000];
		Arrays.fill(me, -1);
		for (int i = 0 ; i < n; i ++) {
			String s = sc.next();
			int c =0;
			for (int j = 0; j < s.length(); j++) {
				if (st[i][s.charAt(j) - b] == 0) c++;
				st[i][s.charAt(j) - b]++;
			}
			if (c<=2) me[i] = c;
		}
		int res = 0;
			for (int i = 0; i < 26; i++) {
				for (int j = i + 1; j <26; j++) {
					int temp = 0;
					for (int x = 0; x < n; x++) {
						if (me[x] ==2 &&(st[x][i]==0 || st[x][j]==0)) continue;
						if (me[x] != -1 ) {
							temp += st[x][i] + st[x][j];
							//System.out.println(st[x][i] + " " + st[x][j]);
						}
					}
					res = Math.max(temp,res);	
				}
			}

			System.out.println(res);

	}
}