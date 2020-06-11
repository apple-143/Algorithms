package sorting;

import edu.princeton.cs.algs4.StdRandom;

import fundamentals.Stopwatch;
import sorting.Insertion;
import sorting.Selection;
//import sorting.Shell;
import sorting.Merge;
import sorting.Quick;
//import sorting.Heap;


public class SortCompare {
    public static double time(String alg, Double[] a) {
        Stopwatch timer = new Stopwatch();
        if (alg.equals("Insertion"))    Insertion.sort(a);
        if (alg.equals("Selection"))    Selection.sort(a);
//        if (alg.equals("Shell"))        Shell.sort(a);
        if (alg.equals("Merge"))        Merge.sort(a);
        if (alg.equals("Quick"))        Quick.sort(a);
//        if (alg.equals("Heap"))         Heap.sort(a);
        return timer.elapsedTime();
    }

    public static double timeRandomInput(String alg, int N, int T) {
        double total = 0.0;
        Double[] a = new Double[N];
        for (int t = 0; t < T; ++t) {
            for (int i = 0; i < N; ++i)
                a[i] = StdRandom.uniform();
            total += time(alg, a);
        }
        return total;
    }
}
