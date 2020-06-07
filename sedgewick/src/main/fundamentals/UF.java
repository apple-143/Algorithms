package fundamentals;

abstract class UF {
    protected int[] id;
    protected int count;

    public UF(int N) {
        count = N;
        id = new int[N];
        for (int i = 0; i < N; ++i)
            id[i] = i;
    }

    public int count() { return count; }

    public boolean connected(int p, int q) { return find(p) == find(q); }

    abstract public int find(int p);
    abstract public void union(int p, int q);
}


class QuickFindUF extends UF {
    public QuickFindUF(int N) {
        super(N);
    }

    public int find(int p) { return id[p]; }

    public void union(int p, int q) {
        int pID = find(p);
        int qID = find(q);

        if (pID == qID) return;

        for (int i = 0; i < id.length; ++i)
            if (id[i] == pID) id[i] = qID;
        count--;
    }
}
