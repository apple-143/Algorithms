#ifndef DEPTH_FIRST_PATH_TW_H_
#define DEPTH_FIRST_PATH_TW_H_

#include <list>
#include "./graph.h"

/*TODO
*/
class DepthFirstPaths {
private:
	bool * marked_;
	int * edge_to_;
	const int s_;

	void DFS(const Graph& G, int v) {
		marked_[v] = true;

		for (auto it=G.Adj(v).begin(); it!=G.Adj(v).end(); ++it) {
			if (!marked_[*it]) {
				edge_to_[*it] = v;
				DFS(G, *it);
			}
		}
	}

public:
	DepthFirstPaths(const Graph& G, int s) : s_(s) {
		marked_ = new bool[G.V()];
		edge_to_ = new int[G.V()];

		for (int i=0; i<G.V(); ++i)
			marked_[i] = false;
		DFS(G, s);
	}
	~DepthFirstPaths() {
		delete[] marked_;
		delete[] edge_to_;
	}

	bool HasPathTo(const int& v) {
		return marked_[v];
	}

	std::list<int> PathTo(const int& v) {
		if (!HasPathTo(v))
			throw -1;
		std::list<int> path;
		for (int x=v; x!=s_; x=edge_to_[x])
			path.push_front(x);
		path.push_front(s_);
		return path;
	}
};

#endif	// DEPTH_FIRST_PATH_TW_H_
