package sorting;

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.In;

import sorting.BasicSorting;
import sorting.Selection;
import sorting.Insertion;

class BasicSortingtest {
    public static void main(String[] args) {
        BasicSorting sort = new BasicSorting();

        String[] a = StdIn.readAllStrings();

        if (args[0].equals("selection"))        Selection.sort(a);
        else if (args[0].equals("insertion"))   Insertion.sort(a);
        else {
            System.out.println("choose the algorithm: selection, insertion");
            return;
        }

        assert sort.isSorted(a) : "Not properly sorted";
        sort.show(a);
    }
}
