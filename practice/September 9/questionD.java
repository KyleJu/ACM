import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

public class acm {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        TreeMap<String, HashSet<String>> map = new TreeMap<>();
        int n = scan.nextInt();
        while (n >0) {
            String f = scan.next();
            String l = scan.next();
            String c = scan.next();
            String name = f + " " + l;
            if (map.get(c).size() >0 ) {
                map.add(name);
            } else {
                HashSet<String> set = new HashSet<String>();
                set.add(name);
                map.put(c, set);
            }
            n--;
        }
//        for (Map.Entry<String, HashSet<String>> entry : map.entrySet()) {
//            System.out.println(entry.getKey() + " " + entry.getValue().size());
//        }
        for (String course: map.keySet()) {
            System.out.println(course + " " + map.get(course).size());
        }
    }
}

//or (Map.Entry<KeyType, ValueType> entry : map.entrySet()) {
//System.out.println(entry.getKey()+" : "+entry.getValue());
//}
