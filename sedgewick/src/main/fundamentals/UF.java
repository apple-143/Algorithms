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

class QuickUnionUF extends UF {
    public QuickUnionUF(int N) {
        super(N);
    }

    public int find(int p) {
        while (p != id[p]) p = id[p];
        return p;
    }

    public void union(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) return;

        id[i] = j;
        --count;
    }
}

class WeightedQuickUnionUF extends UF {
    protected int[] sz;

    public WeightedQuickUnionUF(int N) {
        super(N);

        sz = new int[N];
        for (int i = 0; i < N; ++i) sz[i] = 1;
    }

    public int find(int p) {
        while (p != id[p]) p = id[p];
        return p;
    }

    public void union(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) return;

        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        }
        else {
            id[j] = i;
            sz[i] += sz[j];
        }

        --count;
    }
}





















