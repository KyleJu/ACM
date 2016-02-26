import java.util.*;
import java.math.BigInteger;

public class main{
	public static int n1 = 0;
	public static int k = 0;
	public static Integer[] arr;
	public static BigInteger[][] memo = new BigInteger[255][255];
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()) {
			for (int i = 0; i < 255;i++) {
				for (int j = 0; j < 255;j++){
					memo[i][j] = new BigInteger("-1");
				}
			}
			n1 = sc.nextInt();
			arr = new Integer[n1];
			k = sc.nextInt();
			for (int i = 0; i < n1; i++) {
				int temp = sc.nextInt();
				arr[i] = temp;
			}
			 Arrays.sort(arr, new Comparator<Integer>(){
			 	@Override 
			 	public int compare(Integer o1, Integer o2) {
			 		return o2.compareTo(o1);
			 	}
			 });
			// for (int i = 0; i < n; i++) {
			// 	System.out.println(arr[i]);
			// }
			BigInteger s = dp(n1-1, k);
			System.out.println(s);
		}
	}

	public static BigInteger dp(int n, int k1) {
		if(k1-1>n) return new BigInteger("0");
		if (n ==-1 && k1 ==0) return new BigInteger("1");
		if (n<0) return new BigInteger("0");
		if (k1==0) return new BigInteger("1");
		if (memo[n][k1].compareTo(new BigInteger("-1")) != 0) return memo[n][k1];
		// colum
		BigInteger res = new BigInteger("0");
		//k-1 .. K - k is the nmber of columbs that you remove 
		BigInteger res1 = res.add(dp(n-1, k1));
		BigInteger mul = new BigInteger(Integer.toString(arr[n] - (k-k1)));
		//System.out.println(mul + " " + res + " herhe " + n + " " + k1);
		BigInteger temp = dp(n-1,k1-1).multiply(mul);
		BigInteger res2 = res1.add(temp);
		//System.out.println(temp + " temp");
		//System.out.println(mul + " " + res + " " + n + " " + k1);
		memo[n][k1] = res2;
		return res2;
	}
}