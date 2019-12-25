#ifndef CONNECTED_COMPONENT_TW_H_
#define CONNECTED_COMPONENT_TW_H_

#include "./graph.h"

/*TODO
*/
class CC {
private:
	bool * marked_;
	int count_;
	int * id_;

	void DFS(const Graph& G, int v) {
		marked_[v] = true;
		id_[v] = count_;
		for (auto it=G.Adj(v).begin(); it!=G.Adj(v).end(); ++it)
			if (!marked_[*it])
				DFS(G, *it);
	}

public:
	CC(const Graph& G) : count_(0) {
		marked_ = new bool[G.V()];
		for (int i=0; i<G.V(); ++i)
			marked_[i] = false;
		id_ = new int[G.V()];

		for (int i=0; i<G.V(); ++i) {
			if (!marked_[i]) {
				DFS(G, i);
				++count_;
			}
		}	
	}
	~CC() {
		delete[] marked_;
		delete[] id_;
	}

	bool Connected(const int& v, const int& w) {
		return id_[v] == id_[w];
	}

	int ID(const int& v) {
		return id_[v];
	}

	int Count() {
		return count_;
	}
};

#endif	// CONNECTED_COMPONENT_TW_H_
