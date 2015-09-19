import java.lang.reflect.Array;
import java.text.DecimalFormat;
import java.util.*;

// keep on track of the previous minimum
*****************
//bl = min(bl, pl);
//bs = min(bs, ps);
*****************
//#include <iostream>
//#include <algorithm>
//
//#define OZ (5*16)
//
//using namespace std;
//
//typedef long long LL;
//
//int main() {
//int t, d, x, s;
//
//cin >> t;
//
//while (t--) {
//cin >> d >> x >> s;
//LL bl = 1000, bs = 1000, cost = 0, rem = 0;
//
//for (int i = 0; i < d; ++i) {
//LL num, pl, ps;
//cin >> num >> pl >> ps;
//
//bl = min(bl, pl);
//bs = min(bs, ps);
//
//LL bags = (s*num - rem + OZ-1)/OZ;
//
//rem = (rem + OZ*bags - s*num)%OZ; //the mod probably is not necessary
//
//cost += x*num*bl + bags*bs;
//}
//
//cout << cost << endl;
//}
//
//}


public class acm {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int round = scan.nextInt();
        while (round > 0) {
            int d = scan.nextInt();
            int l = scan.nextInt();
            int s = scan.nextInt();
            int lLevel = 0;
            int sLevel = 0;
            int sum = 0;
            int [] cArray = new int[d];
            int [] lArray = new int[d];
            int [] sArray = new int[d];

            for (int i = 0; i < d; i ++) {
                cArray[i] = scan.nextInt();
                lArray[i] = scan.nextInt();
                sArray[i] = scan.nextInt();
            }

            for (int i =0; i < d; i ++) {
                int dailyL = cArray[i] * l;
                int dailyS = cArray[i] * s;
                //lemon
                if (lLevel < dailyL) {
                    for (int k = i; k <d; k++) {
                        if (lArray[i]<=lArray[k]) {
                            lLevel += cArray[k] * l;
                            // error : I used k as i
                            sum += cArray[k] * l * lArray[i];
                        } else {
                            break;
                        }
                    }
                }
                //sugar
                int level = sLevel;
                for (int k = i; k <d; k ++) {
                    int need = cArray[k] * s;
                    // be careful about this part - i used the wrong price and dont do level -=need and put level < need inside
                    if (sArray[i] <= sArray[k]) {
                        if (level < need) {
                            while (level < need) {
                                level += 80;
                                sLevel += 80;
                                sum += sArray[i];
                            }
                        }
                            level -= need;
                    } else {
                        break;
                    }
                }

                lLevel -= dailyL;
                sLevel -= dailyS;

            }
            System.out.println(sum);
            round--;
        }
    }

//            2 3 3 2
//            200 10 399 300 8 499 400 12 499 2 5 10
//            9 10 199 8 20 99
}