// object [] array = new object[]


import javafx.util.Pair;
import org.omg.Messaging.SYNC_WITH_TRANSPORT;

import javax.swing.plaf.synth.SynthTextAreaUI;
import java.util.*;

public class acm {

 //error1: watch out points range : 0 then output is 0
    // test edges cases
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int round = scan.nextInt();
        for (int q = 1; q <= round; q++) {
            System.out.print("Case #" + q + ": ");
            int num = scan.nextInt();
            if (num == 0) {
                System.out.print("0\n");
                continue;
            }
            int [][] array = new int[num][2];
            for (int i = 0; i < num ; i++) {
                array[i][0]= scan.nextInt();
                array[i][1]= scan.nextInt();
            }

            //case 1
            int max = 1;
            int[] h = new int[20000 +5];
            int[] v = new int[20000 +5];
            for (int k=0; k< array.length; k++) {
                if (array[k][0] < 0) {
                    v[Math.abs(array[k][0]) + 10001]++;
                } else {
                    v[array[k][0]]++;
                }
                if (array[k][1] < 0) {
                    h[Math.abs(array[k][1]) + 10001]++;
                } else {
                    h[array[k][1]]++;
                }
            }



  //error2 : hashing problem -> don't use double as key becasue bitshifting
            //public int hashCode() {
            //            long bits = doubleToLongBits(value);
            //            return (int)(bits ^ (bits >>> 32)); --- because it casted it
            //        }
            //divide by common factor and save it + displacement a,b,c

//            Will you ever try to get the values based on certain keys?
//
//            If yes, then the reasoning about "difficult to compare" applies and you should probably avoid such data structure (or always rely on tailMap / headMap / submap and fetch ranges of the map).
//
//                    If no (i.e. you'll typically just do for (Double key : map.keySet()) ... or iterate over the entrySet) then I would say you're fine using Double as keys.

 //error 3: only checking the coefficient of a is not enough, because parallel lines will be counted
            // add c

            //remedy for error1: choose 10 bits after decimal and cast it to int or use doubleToLongBits()? or subMap(fromKey, toKey) or a ,b ,c
            //remedy two: create fraction class a/10^n to avoid float
            //remedy for error2: using Euclidean algortihm to find gcm and use y = ax+b or use line by line (find all points across one line in each iteration)

            Arrays.sort(v);
            Arrays.sort(h);
            max = Math.max(v[v.length -1],h[h.length -1 ]);

// error4: should be 1
            int max2 = 1;
            for (int i = 0; i < array.length; i++) {
                HashMap<Pair<Pair<Integer,Integer>, Integer>, Integer> map = new HashMap<Pair<Pair<Integer, Integer>, Integer>, Integer>();
                for (int k = 0; k< array.length; k++) {
                    if (array[i][0] == array[k][0] || array[i][1] == array[k][1]|| i == k) {
                        continue;
                    } else {
                        int dy = array[i][1] - array[k][1];
                        int dx = array[i][0] - array[k][0];
                        int g = gcd (dx, dy);
                        //ac = ay-bx
                        int c = dx/g * array[i][1] - dy/g * array[i][0];

                        Pair<Pair<Integer, Integer>, Integer> key = new Pair<Pair<Integer,Integer>, Integer>(new Pair<Integer,Integer>(dx/g, dy/g), c);
                        if (map.containsKey(key)) {
                            map.put(key, map.get(key) + 1);
                        } else {
     // error5 : starting from two points !!!
                            map.put(key, 2);
                        }
                    }
                }
 //error6: find max in each iteration
               for (Pair<Pair<Integer, Integer>, Integer> e: map.keySet()) {
                   max2 = Math.max(map.get(e), max2);
               }
            }
            max = Math.max(max,max2);
            System.out.print(max);
            System.out.println();
        }

    }

    public static int gcd (int a, int b) {
        if (b==0) return a;
        else return gcd(b, a%b);
    }
}


