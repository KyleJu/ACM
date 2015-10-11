import java.util.*;

public class acm {
    private static boolean[] seen = new boolean[400];
    private static Map<String, Integer> adjin;
    private static Map<String, List<String> > adjs;
    public static void dfs(String name) {
        if (seen[adjin.get(name)] == true) return;
        seen[adjin.get(name)] = true;
        if (adjs.get(name) != null) {
            for (String s : adjs.get(name)) {
                dfs(s);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int num = scan.nextInt();

        List<String> programs = new ArrayList<String>();
        adjs = new HashMap<String, List<String>>();
        adjin = new HashMap<String, Integer>();

        scan.nextLine();
        for (int i =0; i < num; i ++) {
            String[] s = scan.nextLine().trim().split(" ");
            String[] ad = scan.nextLine().trim().split(" ");

            //Add all programs
            String name = s[0];
            if (s[0].substring(s[0].indexOf("::")).equals("::PROGRAM")) {
               // System.out.println(name);
                programs.add(name);
            }
            //map string to int for seen
            adjin.put(name, i);

            for (int k = 0; k <Integer.parseInt(s[1]); k++) {
                if (adjs.containsKey(ad[k]))  {
                    adjs.get(ad[k]).add(name);
                } else {
                    List<String> l = new ArrayList<String>();
                    l.add(name);
                    adjs.put(ad[k], l);
                }
            }

        }
        //System.out.println(programs.size());

        for (String s : programs) {
           // System.out.println(s);
            dfs(s);
        }
        int count = 0;
        for (int i = 0; i<400; i++) {
            if (seen[i]) count++;
        }
        System.out.println(num-count);

    }

}