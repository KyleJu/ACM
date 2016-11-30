import java.util.*;
import java.math.BigInteger;
public class D{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		BigInteger a1 = sc.nextBigInteger();
		BigInteger a2 = sc.nextBigInteger();
		BigInteger a3 = sc.nextBigInteger();
		BigInteger a4 = sc.nextBigInteger();
		Boolean f = (a1.compareTo(a3) == 0);
		StringBuilder sb = new StringBuilder();
		BigInteger a0 = new BigInteger("0");
		BigInteger a11 = new BigInteger("1");
		while(a1.compareTo(a11) >0 
			|| a2.compareTo(a0) > 0
			|| a3.compareTo(a0) > 0
			|| a4.compareTo(a11) >0) {
			//System.out.println(a1 + " " + a2);

			if(a1.compareTo(a2) >0) {
			 a1 =  a1.subtract(a2);
			 a3 = a3.subtract(a4);
			 sb.append(0);
			} else {
				a2 = a2.subtract(a1);
				a4 = a4.subtract(a3);
				sb.append(1);
			}
		}
		System.out.println(sb.reverse().toString());
	}
}
