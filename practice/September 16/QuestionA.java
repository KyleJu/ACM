import java.awt.*;
import java.lang.reflect.Array;
import java.text.DecimalFormat;
import java.util.*;

//
//public class acm {
//    public static int i;
//    public static final String s= "dd";
//    public static void main (String[] args) {
//        Scanner scan = new Scanner(System.in);
//        int round = scan.nextInt();
//        while (round > 0)  {
//            Point p = new Point(3,3);
//            final int [][] td = new int [100][100];
//            PriorityQueue<Point> q = new PriorityQueue<Point>(10000, new Comparator<Point>() {
//                @Override
//                public int compare(Point o1, Point o2) {
//                    return td[o1.x][o1.y] - td[o2.x][o2.y];
//                }
//            });
//        }
//    }
//}

public class acm {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        char[] array = Integer.toBinaryString(t).toCharArray();
        int count = 0;
        for (int i = 0; i < array.length; i ++) {
            if (array[i] == '1') {
                count++;
            }
        }
        System.out.println(count);
    }
}