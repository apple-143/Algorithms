#ifndef DEPTH_FIRST_PATH_TW_H_
#define DEPTH_FIRST_PATH_TW_H_

#include "./graph.h"

/*TODO
*/
class DepthFirstPaths {
private:
	bool * marked_;
	int * edge_to_;
	const int s_;

	void DFS(const Graph& G, int v) {
/*
		marked[v] = true;
		++count;
		for (auto it=G.Adj(v).begin(); it!=G.Adj(v).end(); ++it)
			if (!marked[*it])
				DFS(G, *it);
*/
	}

public:
	DepthFirstPaths(const Graph& G, int s) : s_(s) {
		marked_ = new bool[G.V()];
		edge_to_ = new int[G.V()];

		for (int i=0; i<G.V(); ++i)
			marked[i] = false;
		DFS(G, s);
	}
	~DepthFirstPaths() {
		delete[] marked_;
		delete[] edge_to_;
	}

	bool Marked(const int& v) {
/*
		return marked[v];
*/
	}

	int Count() {
/*
		return count;
*/
	}
};

#endif	// DEPTH_FIRST_PATH_TW_H_
