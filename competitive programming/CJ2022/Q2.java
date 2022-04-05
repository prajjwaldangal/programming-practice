import java.util.*;

public class Q2 {

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
        reader.close();
        
        int start, end;
        for (t = 0; t < T; t++) {
            System.out.printf("Case #%d:", t+1);
            // get mins for each color type
            ArrayList <ArrayList<Integer>> testCase = all.get(t);
            List <Integer> temp = Arrays.asList(testCase.get(0).get(0), 
                                            testCase.get(1).get(0), 
                                            testCase.get(2).get(0));
            int min_C = Collections.min(temp);
            temp = Arrays.asList(testCase.get(0).get(1), 
                                testCase.get(1).get(1), 
                                testCase.get(2).get(1));
            int min_M = Collections.min(temp);
            temp = Arrays.asList(testCase.get(0).get(2), 
                                testCase.get(1).get(2), 
                                testCase.get(2).get(2));
            int min_Y = Collections.min(temp);
            temp = Arrays.asList(testCase.get(0).get(3), 
                                testCase.get(1).get(3), 
                                testCase.get(2).get(3));
            int min_K = Collections.min(temp);
            // System.out.printf("%d, %d, %d, %d\n", min_C, min_M, min_Y, min_K);
            // run loops for each combination thereafter for the reduced space
            int max_C = min_C;
            int max_M = min_M;
            int max_Y = min_Y;
            int max_K = min_K;
            int NEEDED = (int) Math.pow(10, 5);
            List <Integer> sol = new ArrayList<Integer>();
            // System.out.printf("Size of sol: %d\n", sol.size());
            for (int c = 0; c < max_C; c++) {
                if (c == NEEDED) {
                    sol.add(c);
                    sol.add(0);
                    sol.add(0);
                    sol.add(0);
                    break;
                }
                for (int m = 0; m < max_M; m++) {
                    if (c + m == NEEDED) {
                        sol.add(c);
                        sol.add(m);
                        sol.add(0);
                        sol.add(0);
                        break;
                    }
                    
                    for (int y = 0; y < max_Y; y++) {
                        if (c + m + y == NEEDED) {
                            sol.add(c);
                            sol.add(m);
                            sol.add(y);
                            sol.add(0);
                            break;
                        }
                        start = 0;
                        end = max_K;
                        int k;
                        while (start < end) {
                            k = start + (end - start) / 2;
                            if (c + m + y + k == NEEDED) {
                                sol.add(c);
                                sol.add(m);
                                sol.add(y);
                                sol.add(k);
                                break;
                            } else if (c + m + y + k < NEEDED) {
                                start = k + 1;
                            } else {
                                end = k - 1;
                            }
                        }
                        if (sol.size() == 4) 
                            break;
                    }
                    if (sol.size() == 4) 
                        break;
                }
                if (sol.size() == 4) 
                    break;
            }
            for (int i = 0; i < 4; i++) {
                if (sol.size() != 4) {
                    System.out.printf(" Impossible");
                    break;
                }
                System.out.printf(" %d", sol.get(i));
            }
            System.out.printf("\n");
        }
    }
}

/**
 * 1000000 1000000 0       0
   0       1000000 1000000 1000000
   999999  999999  999999  999999
 */