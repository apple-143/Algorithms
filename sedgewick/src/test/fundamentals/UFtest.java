package fundamentals;

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.In;

import fundamentals.UF;
import fundamentals.QuickFindUF;
import fundamentals.QuickUnionUF;
import fundamentals.Stopwatch;

class UFtest {
    public static void main(String[] args) {
        int N = StdIn.readInt();

        UF uf;
        if (args[0].equals("qf"))        uf = new QuickFindUF(N);
        else if (args[0].equals("qu"))   uf = new QuickUnionUF(N);
        else if (args[0].equals("wu"))   uf = new WeightedQuickUnionUF(N);
        else {
            System.out.println("choose the algorithm: qf, qu, wu");
            return;
        }

        Stopwatch sw = new Stopwatch();
        while (!StdIn.isEmpty()) {
            int p = StdIn.readInt();
            int q = StdIn.readInt();
            if (uf.connected(p, q)) continue;
            uf.union(p, q);
            //StdOut.println(p + " " + q);
        }
        StdOut.println(uf.count() + " components");
        System.out.println(sw.elapsedTime());
    }
}
