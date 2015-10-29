import java.util.*;
public class b{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		while(scan.hasNext()) {
			int n = scan.nextInt();
			List<String> l = recur(n);
			for (String s : l) {
				for (int i = 0; i < s.length(); i++) {
					System.out.print(s.charAt(i) + " ");
				}
				System.out.println();
			}

		}
	}

		public static List<String> recur(int n) {
			List<String> nl = new ArrayList<String>();
			if (n == 1) {
				nl.add("1");
				return nl;
			}
			if (n == 2) {
				nl.add("12");
				nl.add("21");
				return nl;
			}

			List<String> l = recur(n-1);
			for (int i = 0 ; i < l.size(); i++) {
				String s = l.get(i);
				for (int j=0;j<s.length()+1; j++) {
					if (i%2 == 0) {
						String s1 = s.substring(0,s.length() - j) + n + s.substring(s.length() - j);
						nl.add(s1);
					} else {
						
						String s1 = s.substring(0,j) + n + s.substring(j);
						nl.add(s1);
					}
				}
			}

			return nl;
		}
}