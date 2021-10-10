// Java program to demonstrate BufferedReader
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Solution {
    public static String myFunc(String word) {

      int l = word.length();
      if (l == 1) {
        return "IMPOSSIBLE";
      }
      char [] charArray = word.toCharArray();
      char [] myArray = new char[l];
      for (int i=0; i < l; i++) {
         myArray[i] = charArray[(i+1) % l];
      }
      char prev = myArray[0];
      int i = 1;
      while (i < l) {
        if (prev != myArray[i]) {
          break;
        } else {
          prev = myArray[i];
        }
        i += 1;
      }
      if (i == l) {
        return "IMPOSSIBLE";
      }
      return new String(myArray);
    }

    public static void main(String[] args)
        throws IOException
    {
        // Enter data using BufferReader
        BufferedReader reader = new BufferedReader(
            new InputStreamReader(System.in));

        // Reading data using readLine
        int n = Integer.parseInt(reader.readLine());
        String word = "";
        String[] words = new String[n];
        for (int i=0; i < n; i++) {
          word = reader.readLine();
          words[i] = word;
        }
        for (int i = 0; i < n; i++) {
            System.out.printf("Case #%d: %s\n", i+1, myFunc(words[i]));
        }
      }
}
