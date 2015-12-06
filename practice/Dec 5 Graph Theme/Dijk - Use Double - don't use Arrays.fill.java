import java.util.*;
import java.text.DecimalFormat;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		DecimalFormat d = new DecimalFormat("##.000000");
		while (sc.hasNext()) {
			int n = sc.nextInt();
			if (n ==0) return;
			int m = sc.nextInt();

			ArrayList<Integer>[] adjs = new ArrayList[n + 1];
			HashMap<Integer, Float>[] cost = new HashMap[n + 1];
			// learn you lession
			for (int i = 0; i < adjs.length; i++) {
				adjs[i] = new ArrayList<Integer>();
				cost[i] = new HashMap<Integer, Float>();
			}
			final double[] path = new double[n+1];
			for (int i  =0 ; i< m; i ++) {
				int f = sc.nextInt();
				int t = sc.nextInt();
				int p = sc.nextInt();
				//	System.out.println(f + " "  + t + " " + p);
				adjs[f].add(t);
				adjs[t].add(f);
				cost[f].put(t,(float)p);
				cost[t].put(f,(float)p);

			}

			// for (int kk: adjs[2]) {
			// 	System.out.print(kk);
			// }
			// System.out.println("****");

			PriorityQueue<Integer> q = new PriorityQueue<Integer>(n, new Comparator<Integer>() {
				@Override
				public int compare(Integer o1, Integer o2) {
					return Double.compare(path[o2],path[o1]);
				}
			});

			Arrays.fill(path, 0.0);
			path[1] = 1.0;
			q.offer(1);
			while (q.peek() != null) {

				int i = q.poll();
				//System.out.println(i);
				for (int des: adjs[i]) {
					if (des == 1) continue;
					//System.out.println(i + "  "  + des + " " +  path[i] * (cost[i].get(des)/100.0f) + " " + path[des]);
					if (path[i] * (cost[i].get(des)/100.0) > path[des]) {
						//System.out.println(des);
							path[des] = path[i] * (cost[i].get(des)/100.0);
							if (q.contains(des)) q.remove(des);
							q.offer(des);
					}
				}
			}

			System.out.println((d.format(path[n]*100)) + " percent");
		}

	}
}