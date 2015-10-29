import java.util.*;

public class c{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		while (scan.hasNext()) {
			String s = scan.next();
			int res = 0;

			for (int i = 0; i < s.length(); i ++) {
				char c = s.charAt(i);
				if ( i%3 == 0) {
					if ((c!= 'P') && (c != 'p')) res++;

				}

				if (i %3 == 1) {
					if ((c != 'e')&& (c != 'E')) res ++;
				}

				if (i %3 == 2) {
					if ((c != 'r') && (c!= 'R')) res++;
				}
			}

			System.out.println(res);
		}
	}
}