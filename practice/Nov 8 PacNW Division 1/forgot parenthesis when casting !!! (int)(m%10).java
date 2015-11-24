import java.util.*;
import java.io.*;
public class a{
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		while (sc.hasNext()) {
			long i = sc.nextLong();
			boolean[] seen = new boolean[10];
			Arrays.fill(seen, false);
			int counter = 10;
			long m = i;
			int res = 1;
			while (true) {
				while (m >0) {
					int id = (int)(m%10); ///!!!! parenthesis!!!! for mod (int)m %10 is different from (int)(m%10)
					if (!seen[id]) {
						counter --;
						seen[id] = true;
					}
					m = m/10;
				}
				if (counter == 0) break;
				res++;
				m = i * res; // if i is int and m is long. --> problem!!!! set i as long to start with int * int will still be int
			}

			System.out.println(res);
		}
	}
}