import java.util.*;

public class Solution {
    public static class VisitedNode {
        boolean visited;
        int currMax;
    }
    public static List <Integer> findInitiatorIndices(List <Integer> P, int N) {
        List <Integer> myIndices = new ArrayList <Integer> (N);
        List <Integer> seen = new ArrayList <Integer> (N);
        for (int i = 0; i < N; i++) {
            seen.add(P.get(i));
        }
        for (int i = 1; i <= N; i++) {
            if (!seen.contains(i)) {
                myIndices.add(i-1);
            }
        }
        return myIndices;
    }
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        int T = reader.nextInt();
        int t = 0;
        
        for (;t < T; t++) {
            int N = reader.nextInt();
            List <Integer> F = new ArrayList <Integer> (N);
            List <Integer> P = new ArrayList <Integer> (N);
            for (int i = 0; i < N; i++) {
                F.add(reader.nextInt());
            }
            for (int i = 0; i < N; i++) {
                P.add(reader.nextInt());
            }
            List <Integer> initiatorIndices = findInitiatorIndices(P, N);
            int currIndex = 0;
            int maxFun = 0;
            List <VisitedNode> visited = new ArrayList<VisitedNode>();
            for (int i = 0; i < N; i++) {
                VisitedNode newNode = new VisitedNode();
                newNode.currMax = 0;
                newNode.visited = false;
                visited.add(newNode);
            }
            for (int i = 0; i < initiatorIndices.size(); i++) {
                currIndex = initiatorIndices.get(i);
                List <Integer> chain = new ArrayList <Integer> ();
                while (currIndex != -1) {
                    if (visited.get(currIndex).visited == true) {
                        if (visited.get(currIndex).currMax < F.get(currIndex)) {
                            chain.add(F.get(currIndex));
                            VisitedNode newNode = new VisitedNode();
                            newNode.currMax = F.get(currIndex);
                            newNode.visited = true;
                            visited.set(currIndex, newNode);
                        }
                    } else {
                        chain.add(F.get(currIndex));
                        VisitedNode newNode = new VisitedNode();
                        newNode.currMax = F.get(currIndex);
                        newNode.visited = true;
                        visited.set(currIndex, newNode);
                    }
                    
                    currIndex = P.get(currIndex)-1;
                }
                maxFun += Collections.max(chain);
            }
            System.out.printf("Case #%d: %d\n", t+1, maxFun);
        }
        reader.close();
    }
}