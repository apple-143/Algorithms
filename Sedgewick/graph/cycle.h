#ifndef CYCLE_TW_H_
#define CYCLE_TW_H_

#include "./graph.h"

/*TODO
*/
class Cycle {
private:
	bool * marked_;
	bool has_cycle_;

	void DFS(const Graph& G, int v, int w) {
		marked_[v] = true;
		for (auto it=G.Adj(v).begin(); it!=G.Adj(v).end(); ++it) {
			if (!marked_[*it])
				DFS(G, *it, v);
			else if (*it != w)
				has_cycle_ = true;
		}
	}

public:
	Cycle(const Graph& G) : has_cycle_(false) {
		marked_ = new bool[G.V()];
		for (int i=0; i<G.V(); ++i)
			marked_[i] = false;

		for (int i=0; i<G.V(); ++i)
			if (!marked_[i])
				DFS(G, i, i);
	}
	~Cycle() {
		delete[] marked_;
	}

	bool HasCycle() {
		return has_cycle_;
	}
};

#endif	// CYCLE_TW_H_
