import java.util.*;

public class e{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t =sc.nextInt();
		while (t-->0) {
			int n = sc.nextInt();
			Two[] twos = new Two[n];
			for (int i = 0; i < n; i++) {
				double x = sc.nextDouble();
				double y = sc.nextDouble();
				twos[i] = new Two(x,y);
			}
			Arrays.sort(twos, new Comparator<Two>(){
				@Override 
				public int compare(Two x, Two y) {
					if(x.a == y.a) return (y.b - x.b >0)? 1:-1;
					return (x.a - y.a >0)? 1:-1;
				}
			});
			int[] memo = new int[n +5];
			for (int i = 0; i <n; i++) {
				memo[i] = 1;
			}
			int res = 1;
			for (int i = 1; i <n; i++) {
				for (int j = 0; j < i; j++) {
					if (twos[j].b > twos[i].b && twos[j].a < twos[i].a) {
						memo[i] = Math.max(memo[i], 1+ memo[j]);
						res = Math.max(res, memo[i]);
					}
				}
			}
			System.out.println(res);
		}
	}
	static class Two{
		public double a;
		public double b;
		public Two(double x, double y) {
			a = x;
			b = y;
		}
	}
}