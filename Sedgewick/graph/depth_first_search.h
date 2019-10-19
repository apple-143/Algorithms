#ifndef DEPTH_FIRST_SEARCH_TW_H_
#define DEPTH_FIRST_SEARCH_TW_H_

#include "./graph.h"

/*TODO
*/
class DepthFirstSearch {
private:
	bool * marked;
	int count;

	void DFS(const Graph& G, int v) {
		marked[v] = true;
		++count;
		for (auto it=G.Adj(v).begin(); it!=G.Adj(v).end(); ++it)
			if (!marked[*it])
				DFS(G, *it);
	}

public:
	DepthFirstSearch(const Graph& G, int s) : count(0) {
		marked = new bool[G.V()];
		for (int i=0; i<G.V(); ++i)
			marked[i] = false;
		DFS(G, s);
	}
	~DepthFirstSearch() {
		delete[] marked;
	}

	bool Marked(const int& v) {
		return marked[v];
	}

	int Count() {
		return count;
	}
};

#endif	// DEPTH_FIRST_SEARCH_TW_H_
