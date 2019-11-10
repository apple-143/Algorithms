#ifndef TWO_COLOR_TW_H_
#define TWO_COLOR_TW_H_

#include "./graph.h"

/*TODO
*/
class TwoColor {
private:
/*
	bool * marked_;
	bool has_cycle_;
*/

/*
	void DFS(const Graph& G, int v, int w) {
		marked_[v] = true;
		for (auto it=G.Adj(v).begin(); it!=G.Adj(v).end(); ++it) {
			if (!marked_[*it])
				DFS(G, *it, v);
			else if (*it != w)
				has_cycle_ = true;
		}
	}
*/

public:
	TwoColor(const Graph& G) : has_cycle_(false) {
/*
		marked_ = new bool[G.V()];
		for (int i=0; i<G.V(); ++i)
			marked_[i] = false;

		for (int i=0; i<G.V(); ++i)
			if (!marked_[i])
				DFS(G, i, i);
*/
	}
	~TwoColor() {
/*
		delete[] marked_;
*/
	}

	bool HasCycle() {
/*
		return has_cycle_;
*/
	}
};

#endif	// TWO_COLOR_TW_H_
