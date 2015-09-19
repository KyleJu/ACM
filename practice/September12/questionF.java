import java.lang.reflect.Array;
import java.text.DecimalFormat;
import java.util.*;


//convert string problem to int problem or
// when it first with ? it only has two cases
public class acm {
    // 0 represents even and odd represents odd
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int round = scan.nextInt();
        // when use i = 1; i <=!!!!
        // char is single quotation
        HashSet<Character> vowels = new HashSet<Character>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'y'));
        //you need give extra space to turn nextInt() to nextLine();
        scan.nextLine();
        for (int i = 1; i <= round; i ++) {
            System.out.print("String #" + i + ": ");
            // read the question, it says no more than 64
            long answer;
            
            //make sure to use long for both
            long i1 = 1;
            long i2 = 1;
            String s = scan.nextLine();
            char[] array = s.toCharArray();
            for (int k =0; k < s.length(); k ++) {
                //start with vowels
                if (array[k] == '?') {
                   i1 *= (k%2==0)? 6:20;
                } else if (vowels.contains(array[k]) != (k%2 == 0)) {
                    i1=0;
                    break;
                }
            }
            for (int k =0; k < array.length; k ++) {
                //start with consonants
                if (array[k] == '?') {
                    i2 *= (k%2==0)? 20:6;
                } else if (vowels.contains(array[k]) != (k%2 == 1)) {
                    i2=0;
                    break;
                }
            }
            answer = i1 + i2;
            System.out.println(answer);

        }
    }
//7
//orooji
//al?
//a?i
//g?ha
//a?u?
//?????????????????
//arup
}