// object [] array = new object[]


import java.util.*;

public class acm {
    ///error: (1) minute eror : clock should be 06
    // error: last case error: if drytime < washing time then last iteration, add the dry time
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        while (scan.hasNext()) {
            int load = scan.nextInt();
            int[] array = new int[load];
            if (load !=0) {
                for (int i = 0; i < load; i++) {
                    array [i] = scan.nextInt();
                }
                Arrays.sort(array);
                int sum = 30;
                int totalD = 0;
                int totalW = 0;
                for (int i = array.length -1 ; i > 0 ; i --) {
                    totalD += array[i];
                    totalW += 30;
                    if (array[i] > 30) {
                        sum += array[i];
                    } else {
                        if (totalD >= totalW) {
                            sum += array[i];
                        } else {
                            sum += 30;
                        }
                    }
                }

                //last dry time: add it no matter what
                sum += array[0];

                int x = sum;
                int h = sum / 60;
                //time error if 6 shoudl be 06
                int min = x %60;
                if (min <10) {
                    System.out.println(h + ":" + "0" + min);
                } else {
                    System.out.println(h + ":" + min);
                }
            } else {
                break;
            }
        }

    }
}


//1
//        20
//        2
//        60 15 10
//        60 60 60 60 60 60 60 60 60 60
//        0
