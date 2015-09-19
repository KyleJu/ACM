import java.util.Scanner;
2
3 3 2
200 10 399
300 8 499
400 12 499
2 5 10
9 10 199
8 20 99

/**
 * Created by xifengju on 15-07-11.
 */
public class acm {
    public static void main (String[] args) {
        
    }

//    public static void main (String[] args)
//    {
//        Scanner scan = new Scanner(System.in);
//        int size = scan.nextInt();
//        int result = size;
//        scan.nextLine();
//        for (int i =0; i < size; i ++) {
//            String input = scan.nextLine();
//            boolean r= true;
//            for (int k =0; k < input.length() - 1; k++) {
//                String c = String.valueOf(input.charAt(k));
//                String d = String.valueOf(input.charAt(k + 1));
//                if (c.equals("C") && d.equals("D")) {
//                    r = false;
//
//                }
//            }
//            if (!r) {
//                result--;
//            }
//        }
//
//        System.out.println(result);
//    }
//
//    public static void main (String[] args) {
//        Scanner scan = new Scanner(System.in);
//        long testCase = scan.nextInt();
//        int nodeNum = scan.nextInt();
//        int[][] array = new int[nodeNum][nodeNum];
//        for (int k = 0; k < nodeNum - 1; k ++) {
//            int x = scan.nextInt();
//            int y = scan.nextInt();
//            int d = scan.nextInt();
//            array[x][y] = d;
//        }
//        int sum = 0;
//        for (int i = 0; i < nodeNum -1 ;i ++) {
//            for (int k = i + 1; k< nodeNum -1 ; k ++) {
//                sum +=array[i][k] * (nodeNum - k)* k;
//            }
//        }
//        System.out.println(sum);
//    }
}
