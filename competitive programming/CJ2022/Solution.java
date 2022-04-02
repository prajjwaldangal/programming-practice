import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        int T = reader.nextInt();
        int C, M, Y, K;
        ArrayList <ArrayList<ArrayList<Integer>>> all = new ArrayList <ArrayList<ArrayList<Integer>>>(T);
        int t =0;
        while (t < T) {
            ArrayList <ArrayList<Integer>> testCase = new ArrayList <ArrayList<Integer>>();
            for (int i = 0; i < 3; i++) {
                ArrayList <Integer> printer = new ArrayList <Integer> ();
                C = reader.nextInt();
                M = reader.nextInt();
                Y = reader.nextInt();
                K = reader.nextInt();
                printer.add(C);
                printer.add(M);
                printer.add(Y);
                printer.add(K);
                testCase.add(printer);
            }
            all.add(testCase);
            t += 1;
        }
        System.out.printf("\n\n");
        for (t = 0; t < T; t++) {
            for (int i = 0; i < 3; i++) {
                for (int j =0; j < 4; j++) {
                    System.out.printf("%d ", all.get(t).get(i).get(j));
                }
                System.out.printf("\n");
            }
        }
    }
}