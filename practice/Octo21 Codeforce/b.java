import java.util.*;

public class b {
	public static List<Integer> primes = new ArrayList<Integer>();
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		primes.add(2);
		long t = scan.nextLong();
		if (t==1 || t ==2|| t == 3) {
			System.out.println(t);
			return;
		}
		p(t);

		long res =1;
		for (int n : primes) {
			if (t%n == 0) {
				res *= n;
				t = t/n;
				while (t%n == 0) t= t/n;
				//System.out.println(t);
				//sSystem.out.println(primes);
			} 
		}

		System.out.println(res*t); 
	}
	public static void p(long n) {
		for (int i = 3; i <= Math.sqrt(n); i+=2) {
			boolean flag = false;
			for (int k : primes) {
				if (i%k == 0) {
					flag = true;
					break;
				}
			}

			if(!flag) primes.add(i);
		}
		
	}

}