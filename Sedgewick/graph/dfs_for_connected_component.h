#ifndef CONNECTED_COMPONENT_TW_H_
#define CONNECTED_COMPONENT_TW_H_

#include "./graph.h"

/*TODO
*/
class CC {
private:
/*
	bool * marked_;
	int count_;
*/

	void DFS(const Graph& G, int v) {
/*
		marked_[v] = true;
		++count_;
		for (auto it=G.Adj(v).begin(); it!=G.Adj(v).end(); ++it)
			if (!marked_[*it])
				DFS(G, *it);
*/
	}

public:
	CC(const Graph& G) {
/*
		marked_ = new bool[G.V()];
		for (int i=0; i<G.V(); ++i)
			marked_[i] = false;
		DFS(G, s);
*/
	}
	~CC() {
/*
		delete[] marked_;
*/
	}

	bool Marked(const int& v) {
/*
		return marked_[v];
*/
	}

	int Count() {
/*
		return count_;
*/
	}
};

#endif	// CONNECTED_COMPONENT_TW_H_
