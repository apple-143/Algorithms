package sorting;

import java.lang.UnsupportedOperationException;

import edu.princeton.cs.algs4.StdOut;

class BasicSorting {
    public static void sort(Comparable[] a) {
        System.out.println("not implemented");
        return;
    }

    protected static boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }

    protected static void exch(Comparable[] a, int i, int j) {
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    protected static void show(Comparable[] a) {
        for (int i = 0; i < a.length; ++i)
            StdOut.print(a[i] + " ");
        StdOut.println();
    }

    protected static boolean isSorted(Comparable[] a) {
        for (int i = 1; i < a.length; ++i)
            if (less(a[i], a[i-1])) return false;
        return true;
    }
}

class Selection extends BasicSorting {
    public static void sort(Comparable[] a) {
        int N = a.length;
        for (int i = 0; i < N; ++i) {
            int minIdx = i;
            for (int j = i+1; j < N; ++j) {
                if (less(a[j], a[minIdx])) minIdx = j;
            }
            exch(a, i, minIdx);
        }
    }
}

class Insertion extends BasicSorting {
    public static void sort(Comparable[] a) {
        int N = a.length;
        for (int i = 1; i < N; ++i) {
            for (int j = i; j > 0 && less(a[j], a[j-1]); --j)
                exch(a, j, j-1);
        }
    }
}
