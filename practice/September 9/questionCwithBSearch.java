import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

// try debuggin by using print line
// error: iteration on the wrong letter
// binary reserach starts from n-1 !!!!!!! for size

public class acm {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
        int sum = 0;
        int[] paint = new int[n];
        int[] need = new int[m];
        for (int i = 0; i < n; i ++) {
            paint[i] = scan.nextInt();
        }
        for (int k = 0; k < m; k ++) {
            need[k] = scan.nextInt();
        }
        Arrays.sort(paint);
        Arrays.sort(need);
        for (int i = 0; i < m; i ++) {
            int target = need[i];
            int found =  bSearch(0,n -1 ,target, paint);
            sum += found - target;
        }
        System.out.print(sum);
    }
    public static int bSearch(int left, int right, int t, int[] array) {
        int middle = (left + right)/ 2;
        if (right < left) {
            return array[left];
        } else {
            if (array[middle] > t) {
                return bSearch(left, middle - 1, t, array);
            } else if (array[middle] < t){
                return bSearch(middle + 1, right,t, array);
            } else {
                return t;
            }
        }
    }


}
