// object [] array = new object[]


import java.util.*;

public class acm {
    ///error: graphs[x][lList.get(cNum)] mistake!!!! forget to use lList.get(cNum)!!!!!!!!
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int round = scan.nextInt();
        while (round > 0) {
            int num = scan.nextInt();
            int [] array = new int[num];
            for (int i = 0; i < num ; i ++) {
                array[i] = scan.nextInt();
            }
            Arrays.sort(array);

            int point = 0;
            for (int i = 1; i < num ; i ++ ) {
                if (array[i] > array[i-1]) {
                    //different length
                    System.out.println((array[i] - array[i-1]) + " " + (i));
                    point = i;
                }
            }
            System.out.println();
            round--;
        }


    }
}


