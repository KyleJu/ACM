import java.lang.reflect.Array;
import java.util.Comparator;
import java.util.Scanner;
import java.util.Arrays;

public class acm {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int tc = scan.nextInt();
        while (tc > 0) {
            tc--;
            int i = scan.nextInt();
            int[][] pairs = new int[i][2];
            for (int k = 0; k < i; k++) {
                int x = scan.nextInt();
                int y = scan.nextInt();
                pairs[k][0] = x;
                pairs[k][1] = y;
            }
            Arrays.sort(pairs, new Comparator<int[]>() {
                @Override
                public int compare(int[] o1, int[] o2) {
                    return Integer.compare(o2[0], o1[0]);
                }
            });
            long result = 0;
            int[][] temp;
            for (int k = 0; k < i; k ++) {
                temp = pairs;
                Arrays.sort(temp, k, i - 1, new Comparator<int[]>() {
                    @Override
                    public int compare(int[] o1, int[] o2) {
                        return Integer.compare(o2[1], o1[1]);
                    }
                });
                int index = Arrays.asList(temp).indexOf(pairs[k]);
                result = result + (i - 1 - index);
            }
            System.out.print(result);

        }
    }

}
