import java.util.*;

public class acm{

    // use k as i
    // return; problem
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        while(test --> 0) {
            List<Integer>[] path = new List[4];
            for (int i = 0 ; i<4; i++) {
                path[i] = new ArrayList<Integer>();
            }
            String s = scan.next();
            s = s.toLowerCase();

            for (int i= 0; i <s.length(); i++) {
                char c = s.charAt(i);
                if (c == 'p') {
                    path[0].add(i);
                }

                if (c == 'a') {
                    path[1].add(i);
                    //System.out.println(i);
                }

                if (c == 't') {
                    path[2].add(i);
                   // System.out.println(i);
                }

                if (c == 'h') {
                    path[3].add(i);
                    //System.out.println(i);
                }
            }
            boolean flag = false;
            int res = Integer.MAX_VALUE;
            for (int i : path[0]) {
                int min = i;
                int temp = i;
                int max = -1;
                for (int k = 1; k < 4; k++) {
                    int r = Collections.binarySearch(path[k], temp);
                    r = (r + 1) * -1;
                    if (r >= path[k].size()) {
                        flag = true;
                        break;
                    }
                    max = Math.max(max, path[k].get(r));
                    temp = path[k].get(r);
                }
                if (flag) break;
                res = Math.min(res, max - min + 1);
            }
            if (res == Integer.MAX_VALUE) {
                System.out.println(-1);}
             else {
                System.out.println(res);
            }

        }
    }
}