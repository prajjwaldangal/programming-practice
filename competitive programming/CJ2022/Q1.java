import java.util.Arrays;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static StringBuffer fillStrings (int char_count, int indx) {
        StringBuffer myBuffer = new StringBuffer(char_count);
        boolean flag = false;
        if (indx % 2 == 0) {
            flag = true;
        }
        for (int c = 0; c < char_count / 2; c++) {
            if (flag) {
                myBuffer.append('+');
                myBuffer.append('-');
            } else {
                myBuffer.append('|');
                myBuffer.append('.');
            }
        }
        if (flag) {
            myBuffer.append('+');
        } else {
            myBuffer.append('|');
        }
        return myBuffer;
    }

    public static void setStrings (int R, int C, int indx) {
        StringBuffer myStringBuffer = new StringBuffer(2*C+1);
        boolean flag = false;
        if (indx == 0 || indx == 1) {
            flag = true;
        } 
        if (flag) {
            myStringBuffer.append('.');
            myStringBuffer.append('.');
            myStringBuffer.append(fillStrings(2*C-1, indx));
        } else {
            myStringBuffer.append(fillStrings(2*C+1, indx));
        }
        System.out.println(myStringBuffer.toString());
        return;
    }
    
    // takes a set of R, C values per test case
    public static void printMatrix(int R, int C) {
        for (int i = 0; i < 2*R+1; i ++) {
            setStrings(R, C, i);
        }
    }
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        int T = reader.nextInt();
        int i = 0;
        int R, C;
        ArrayList <ArrayList<Integer>> dims = new ArrayList<ArrayList<Integer>> (T);
        while (i < T) {
            R = reader.nextInt();
            C = reader.nextInt();
            ArrayList<Integer> myList = new ArrayList<Integer>(2);
            myList.add(R);
            myList.add(C);
            dims.add(myList);
            i += 1;
        }
        reader.close();
        for (i = 0; i < T; i++) {
            System.out.printf("Case #%d:\n", i+1);
            printMatrix(dims.get(i).get(0), dims.get(i).get(1));
        }
    }
}
