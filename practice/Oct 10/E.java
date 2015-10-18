import java.util.*;

public class acm {
    public static Map<Integer, Integer>[] cost;
    public static Set<Integer>[] adjs;
    public static int[] dist;
    public static List<Integer>[] pre;
    public static void main(String[] args) {
        //cost
        Scanner scan = new Scanner(System.in);
        while (scan.hasNext()) {
            int n = scan.nextInt();
            int m = scan.nextInt();
            int k = scan.nextInt();
            cost = new HashMap[n+1];
            dist = new int[n+1];
            pre = new ArrayList[n+1];
            adjs = new HashSet[n +1];

            Arrays.fill(dist, Integer.MAX_VALUE);
            if (n==1 || m==0||k ==1) {
                System.out.println("false");
            }

            TreeSet<Integer> tSet = new TreeSet<Integer>(new Comparator<Integer>() {
                @Override
                public int compare(Integer o1, Integer o2) {
                    return dist[o1] - dist[o2];
                }
            });

            int[] sp = new int[k];
            for (int i = 0 ; i < k; i ++) {
                sp[i] = scan.nextInt();
            }
            dist[sp[0]] = 0;

            for (int i = 0; i < m; i ++) {
                int node = scan.nextInt();
                int end = scan.nextInt();
                int cos = scan.nextInt();

                if (adjs[node] != null) {
                    adjs[node].add(end);
                } else {
                    adjs[node] = new HashSet<Integer>();
                    adjs[node].add(end);
                }
                if (cost[node] != null) {
                    cost[node].put(end, cos);
                } else {
                    cost[node] = new HashMap<Integer, Integer>();
                    cost[node].put(end, cos);
                }

            }
            // start
            tSet.add(sp[0]);
            while(!tSet.isEmpty()) {
                int f = tSet.pollFirst();
                Map<Integer, Integer> map = cost[f];
                if (adjs[f] == null) continue;
                for (int i: adjs[f]) {
                    int newD  = dist[f] + map.get(i);
                    if (newD < dist[i]) {
                        dist[i] = dist[f] + map.get(i);
                        if (pre[i] != null) {
                            pre[i].clear();
                            pre[i].add(f);
                        } else {
                            pre[i] = new ArrayList<Integer>();
                            pre[i].add(f);
                        }
                    } else if (newD == dist[i]) {
                        pre[i].add(f);
                    }
                    tSet.add(i);
                }
            }

            int z = sp[sp.length -1];
            while (true) {
                if (pre[z] == null) {
                    System.out.println("no");
                    break;
                }
                if (pre[z].size()  == 1) {
                    z = pre[z].get(0);
                } else {
                    System.out.println("yes" + pre[z].size());
                    break;
                }
            }

        }

    }
}