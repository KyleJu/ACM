import java.util.*;
import java.io.*;

public class c{
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		int level = 0;
		int n = Integer.parseInt(reader.readLine());
		int[] a = new int[(int)Math.pow(10, 6)+30];
		String[] temp = reader.readLine().split(" ");
		for (int i= 0; i < n ; i ++) {
			String s = temp[i];
			a[Integer.parseInt(s)]++;
		}

		int cv = 0;
		for (int i = 0; i <= Math.pow(10,6)+ 29; i ++) {
			level+= (cv+a[i])%2;
			cv = (cv +a[i])/2;
		}

		System.out.println(level);
	}
}