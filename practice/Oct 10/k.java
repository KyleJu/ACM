import java.util.Scanner;

public class acm {
    // 1 is not prime number!!!!!
    // watch out output no vs false;
    public static void main(String[] args) {
        Scanner san = new Scanner(System.in);
        long n  = san.nextLong();
       if (n== 1) {
           System.out.println("no");
           return;
       }
        boolean f1= checkPrime(n);
        boolean f2 = reve(n);
        if (f1&f2) {
            System.out.println("yes");
        } else {
            System.out.println("no");
        }

    }

    private static boolean reve(long n ) {
        long res = 0;
        while (n >0) {
            long x = n%10;
            if (x == 3|| x ==4||x == 7) {
                return false;
            }
            if (x==6){
                x=9;
            } else if (x== 9) {
                x = 6;
            }
            res = res*10 + x;
            n = n/10;
        }
        //System.out.println(res);
        return checkPrime(res);
    }

    private static boolean checkPrime(long n) {
        if (n ==2) return true;
        if (n%2 == 0) return false;
        for (int i = 3; i <= Math.sqrt(n); i +=2) {
            if (n%i == 0) {
                return false;
            }
        }
        return true;
    }

}