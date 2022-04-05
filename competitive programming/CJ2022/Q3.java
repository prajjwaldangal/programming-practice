import java.util.*;
public class Solution {

    public static int getStrghtVal(List<Integer> S, int N) {
        int seq = 1;
        Collections.sort(S);
        for (int i = 1; i < N;) {
            if (S.get(i) > seq) {
                seq += 1;
            }
            i += 1;
        }
        return seq;
    }
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        int T = reader.nextInt();
        int t = 0;
        int N;
        ArrayList<Integer> out = new ArrayList<>(T);
        while (t < T) {
            N  = reader.nextInt();
            ArrayList<Integer> S = new ArrayList<>(N);
            for (int i =0; i < N; i++) {
                S.add(reader.nextInt());
            }
            out.add(getStrghtVal(S, N));
            t += 1;
        }
        reader.close();
        for (int i = 0; i < T; i++) {
            System.out.printf("Case #%d: %d\n", i+1, out.get(i));
        }
    }
}
