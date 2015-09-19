// object [] array = new object[]


import java.util.*;

public class acm {
    ///error: graphs[x][lList.get(cNum)] mistake!!!! forget to use lList.get(cNum)!!!!!!!!
    public static void main(String[] args) {
        //induction
        // 1 if there is a paht from i to j
        // 0 otherwise
        Scanner scan = new Scanner(System.in);
        int round = scan.nextInt();
        while (round > 0) {
            int n = scan.nextInt();
            List<Integer> lList= new LinkedList<Integer>();
            // intializing n+1 so indices are matching
            int[][] graphs = new int[n+ 1][n + 1];
            for (int x = 1; x <=n;  x ++) {
                for (int y = 1; y <= n ; y ++) {
                    graphs[x][y] = scan.nextInt();
                }
            }

            //start with 0;
            lList.add(1);
            for(int x= 2; x <=n; x ++) {
                ListIterator<Integer> e = lList.listIterator();
                boolean flag = false;
                while(e.hasNext()) {
                    int cNum = e.nextIndex();
                    if (graphs[x][lList.get(cNum)] == 1 ) {
                        e.add(x);
                        flag = true;
                        break;
                    }
                    e.next();
                }
                if (!flag) {
                    lList.add(lList.size(), x);
                }
            }

            for (int i = 0; i < n; i ++ ) {
                System.out.print(lList.get(i) + " " );
            }
            System.out.println();
            round --;
        }

    }
}
//2
//4
//0 1 1 0
//0 0 0 1
//0 1 0 0
//1 0 1 0
//3
//0 1 1
//0 0 1
//0 0 0

//    public static  TreeMap<Integer, Integer>[] matrix;
//    public static ArrayDeque<Integer> queue = new ArrayDeque<Integer>();
//    public static int[] taken;
//    public static int[] result;
//    public static void main(String[] args) {
//        Scanner scan = new Scanner(System.in);
//        int n = scan.nextInt();
//        matrix = new TreeMap[2*n + 1];
//        taken = new int [2*n + 1];
//        result = new int[2*n + 1];
//
//        //start form the first element
//        queue.offer(1);
//        for (int i = 2; i< (2*n +1); i ++) {
//            queue.offer(i);
//            for (int k = 1; k <= i -1; k ++) {
//                int strength = scan.nextInt();
//
//                if (matrix[i] != null) {
//                    matrix[i].put(strength, k);
//                } else {
//                    TreeMap<Integer,Integer> m1 = new TreeMap<Integer, Integer>();
//                    m1.put(strength,k);
//                    matrix[i] = m1;
//                }
//
//                if (matrix[k] != null) {
//                    matrix[k].put(strength, i);
//                } else {
//                    TreeMap<Integer,Integer> m1 = new TreeMap<Integer, Integer>();
//                    m1.put(strength,i);
//                    matrix[k] = m1;
//                }
//            }
//        }
////
//        for (int i = 1; i <= 2*n; i ++) {
//            for (Map.Entry<Integer,Integer> e: matrix[i].entrySet()) {
//                System.out.print(e.getKey() + ":" + e.getValue() + " ");
//            }
//            System.out.println();
//        }
//
//        //matching
//        while (queue.peek() != null) {
//            int i = queue.poll();
//            System.out.println(i);
//            for (int k = 1; k <= matrix[i].size(); k++) {
//                Map.Entry<Integer, Integer> e = matrix[i].lastEntry();
//                if (taken[e.getValue()] != 0) {
//                    //taken
//                    int newS = e.getKey();
//                    if (newS > taken[e.getValue()]) {
//                        //swtiching
//                        queue.offerLast(result[e.getValue()]);
////                        if (result[i] != 0) {
////                            //reset
////                            queue.offerLast(result[i]);
////                            result[result[i]] = 0;
////                            taken[result[i]] = 0;
////                        }
//                        result[i] = e.getValue();
//                        taken[i] = e.getKey();
//                        taken[e.getValue()] = e.getKey();
//                        result[e.getValue()] = i;
//
//                        matrix[i].pollLastEntry();
//                        break;
//
//                    } else if (newS == taken[e.getValue()]) {
//                        matrix[i].pollLastEntry();
//                        break;
//                    }
//                    else{
//                        //next round
//                        matrix[i].pollLastEntry();
//                    }
//                } else {
////                    if (result[i] != 0) {
////                        //reset the currently matching one
////                        queue.offerLast(result[i]);
////                        result[result[i]] = 0;
////                        taken[result[i]] = 0;
////                    }
//                    result[i] = e.getValue();
//                    taken[i] = e.getKey();
//                    taken[e.getValue()] = e.getKey();
//                    result[e.getValue()] = i;
//                    matrix[i].pollLastEntry();
//                    break;
//                }
//            }
//        }
//
//        for (int i =1; i <= 2*n; i ++) {
//            System.out.print(result[i] + " ");
//        }
//        System.out.println();

