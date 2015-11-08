import java.util.*;


public class u{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		while (t-->0) {
			Set<String> s = new HashSet<String>();
			int c = 0;
			int n = scan.nextInt();
			String[] s1 = new String[n];
			String[] s2 = new String[n];
			for (int i = 0; i < n; i ++) {
				s1[i] = scan.next();
			}
			for (int i = 0; i < n;i++) {
				s2[i] = scan.next();
			}

			for (int i = 0; i < n; i ++) {
				s.add(s1[i]);
				s.add(s2[i]);	
				c++;
				if (s.size() == c) {
					System.out.print(c);
					if (i != n-1) {
						System.out.print(" ");
					}
					c = 0;
					s.clear();
				}
			}
			System.out.println();
		}
	}
}