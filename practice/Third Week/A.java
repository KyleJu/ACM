

import java.util.*;
import java.io.*;


/* Name of the class has to be "Main" only if the class is public. */
public class A
{
    public static String repeat(String str, int times) {
        return new String(new char[times]).replace("\0", str);
    }
    
    public static void main (String[] args)
    {   Scanner scan = new Scanner(System.in);
        ArrayList<Map<String, String>> numberPad = new ArrayList <Map <String, String>>();
        String[][] letters= {{}, {"a","b","c"}, {"d","e","f"}, {"g","h","i"},{"j","k","l"},{"m","n","o"},{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"}};
        String output = "";
        for (int i = 1; i <= 9; i ++) {
            int num = scan.nextInt();
            for (int k = 1; k <= (letters[num-1]).length; k ++) {
                Map<String,String> m = new HashMap<String,String>();
                String numStr = String.valueOf(i);
                m.put(letters[num-1][k-1], repeat(numStr,k));
                numberPad.add(m);
            }
        }
        scan.nextLine();
        String input = scan.nextLine();
        for (int x=0; x < input.length(); x++) {
            String l = String.valueOf(input.charAt(x));
            for (int i = 0; i < numberPad.size(); i ++){
                if (numberPad.get(i).containsKey(l)) {
                    if (output.length() == 0) {
                        output += numberPad.get(i).get(l);
                    } else if (output.charAt(output.length() - 1)==(numberPad.get(i).get(l).charAt(0))) {
                        output += "#" + numberPad.get(i).get(l);
                    } else {
                        output += numberPad.get(i).get(l);
                    }
                    break;
                }
            }
        }

        System.out.print(output);
    }
}