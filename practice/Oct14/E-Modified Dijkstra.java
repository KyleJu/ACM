import javafx.util.Pair;

import java.awt.*;
import java.util.*;

public class acm {

    // mistake edge(p.x + mov[i]) >=0  not just equal
    // it only gets update it when the newcost is smaller so it won't be repeating
    // "E" case becasue it goes back - continue
    public static Map<Character, Integer> cost;
    public static int[][] dis;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int r= scan.nextInt();
        while(r --> 0) {
            int k = scan.nextInt();
            int w = scan.nextInt();
            int h = scan.nextInt();
            cost = new HashMap<Character,Integer>();
            for (int i = 0; i < k; i++) {
                char s = scan.next().charAt(0);
                int c = scan.nextInt();
                cost.put(s,c);
            }
            dis = new int[h][w];
            char[][] matrix = new char[h][w];

            PriorityQueue<Point> pq = new PriorityQueue<Point>(h * w, new Comparator<Point>() {
                @Override
                public int compare(Point o1, Point o2) {
                    return dis[o1.x][o1.y] - dis[o2.x][o2.y];
                }
            });
            for (int i =0; i<h; i++) {
                char[] ca = scan.next().toCharArray();
                for (int j = 0; j < w; j++) {
                    matrix[i][j]  = ca[j];
                    if (ca[j] == 'E'){
                        dis[i][j] = 0;
                        pq.offer(new Point(i,j));
                    } else {
                        dis[i][j] = Integer.MAX_VALUE;
                    }
                }
            }
            int[] mov = {1, -1};
            while(pq.peek() != null) {
                Point p = pq.poll();
                //System.out.println("popped");
                for (int i = 0; i< 2; i++) {
                    //System.out.println(i);
                    if ((p.x + mov[i]) >=0 && (p.x +mov[i])<h) {
                         int newx= p.x + mov[i];
                       // System.out.println( p.x + " " + mov[i] + " " + newx + " " + p.y +  " " + matrix[newx][p.y]);
                        if (matrix[newx][p.y] == 'E') continue;
                        int newCost= dis[p.x][p.y] + cost.get(matrix[newx][p.y]);
                        if (newCost < dis[newx][p.y]) {
                            dis[newx][p.y] = newCost;
                            pq.offer(new Point(newx, p.y));
                        }
                    }
                }

                for (int i = 0; i< 2; i++) {
                    if ((p.y + mov[i]) >=0 && (p.y +mov[i])<w) {
                        int newy= p.y + mov[i];
                        if (matrix[p.x][newy] == 'E') continue;
                        int newCost= dis[p.x][p.y] + cost.get(matrix[p.x][newy]);
                        if (newCost < dis[p.x][newy]) {
                            dis[p.x][newy] = newCost;
                            pq.offer(new Point(p.x, newy));
                        }
                    }
                }
            }

//            for (int i = 0; i < h; i++) {
//                for (int j = 0; j< w; j ++) {
//                    System.out.print(dis[i][j] + " ");
//                }
//                System.out.println();
//            }

            int res = Integer.MAX_VALUE;
            for (int i = 0; i < h; i ++) {
                //System.out.println(dis[i][0]);
                res = Math.min(dis[i][0], res);
                res = Math.min(dis[i][w-1], res);
            }

            for (int j = 0; j < w; j++) {
               // System.out.println(dis[0][j]);
                res = Math.min(dis[0][j] ,res);
                res = Math.min(dis[h-1][j] ,res);
            }
            System.out.println(res);
         }

    }
}