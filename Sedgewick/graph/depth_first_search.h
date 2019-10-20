#ifndef DEPTH_FIRST_SEARCH_TW_H_
#define DEPTH_FIRST_SEARCH_TW_H_

#include "./graph.h"

/*TODO
*/
class DepthFirstSearch {
private:
	bool * marked_;
	int count_;

	void DFS(const Graph& G, int v) {
		marked_[v] = true;
		++count_;
		for (auto it=G.Adj(v).begin(); it!=G.Adj(v).end(); ++it)
			if (!marked_[*it])
				DFS(G, *it);
	}

public:
	DepthFirstSearch(const Graph& G, int s) : count_(0) {
		marked_ = new bool[G.V()];
		for (int i=0; i<G.V(); ++i)
			marked_[i] = false;
		DFS(G, s);
	}
	~DepthFirstSearch() {
		delete[] marked_;
	}

	bool Marked(const int& v) {
		return marked_[v];
	}

	int Count() {
		return count_;
	}
};

#endif	// DEPTH_FIRST_SEARCH_TW_H_
