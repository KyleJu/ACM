import java.util.*;
import java.io.*;
import java.text.DecimalFormat;

public class a {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int ts = sc.nextInt();
		while (ts --> 0) {
			List<Integer> l = new ArrayList<Integer>();
			int r = sc.nextInt();
			for (int i = 0; i < r; i ++) {
				l.add(sc.next().length());
			}
			System.out.println(new DecimalFormat("#0.000").format(solve(l)));
		}
	}


	public static double solve(List<Integer> l) {
		//base case
		// l is empty: finish choosing
		if (l.size() == 0) return 1.0;

		// if any index of l is 0, it should not happen

		for (int i: l){
			if (i == 0) return 0.0;
		}

		double ans = 0.0;
		int bm = 1 << (l.size());
		//
		for (int b = 1; b < bm; b++) {
			double tem = 1.0;
			List<Integer> ln = new ArrayList<Integer>();
				for (int j = 0; j <l.size(); j++) {

					// check specific bit -> if it is not 0 after operations
					if ((b & 1<<j) != 0) {
						tem*= (double) 1.0/(double)l.get(j);
					} else {
						int sl = l.get(j);
						tem *= (double)(sl -1.0)/(double)sl;
						ln.add(sl-1);
					}
				}
			ans += tem*solve(ln);
		}
		return ans;
	}
}