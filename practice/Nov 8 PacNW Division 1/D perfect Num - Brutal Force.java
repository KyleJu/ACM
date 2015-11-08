import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.List;
import java.util.Scanner;
import java.util.*;
 
public class D {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        while (in.hasNext()) {
            int n = in.nextInt();
            if (n == -1) return;
            List<Integer> l = new ArrayList<Integer>();
            int t = n;
            for (int i = 1 ; i < n; i ++) {
                if (n%i==0) {
                    l.add(i);
                    t -=i;
                }
            }
             
            if (t!=0) {
                System.out.println(n + " is NOT perfect.");
            } else {
                System.out.print(n + " = ");
                for (int i = 0; i < l.size(); i++){
                    if (i ==l.size() -1) {
                    System.out.print(l.get(i));
                    System.out.println();
                    break;
                    }
                    System.out.print(l.get(i)+ " + ");
                }
            }
        }
         
    }
     
}
