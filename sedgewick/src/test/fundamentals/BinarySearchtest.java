package fundamentals;

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.In;

import java.util.Arrays;

import fundamentals.BinarySearch;


public class BinarySearchtest {
    public static void main(String[] args)
    {
        In in = new In(args[0]);
        int[] whitelist = in.readAllInts();
        Arrays.sort(whitelist);
        while (!StdIn.isEmpty())
        {
            int key = StdIn.readInt();
            if (BinarySearch.rank(key, whitelist) == -1)
                StdOut.println(key);
        }
    }
}
