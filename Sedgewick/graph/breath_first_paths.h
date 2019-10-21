#ifndef BREATH_FIRST_PATH_TW_H_
#define BREATH_FIRST_PATH_TW_H_

#include <list>
#include "./graph.h"

/*TODO
*/
class BreathFirstPaths {
private:
	bool * marked_;
	int * edge_to_;
	const int s_;

	void BFS(const Graph& G, int v) {
		marked_[v] = true;

/*
		for (auto it=G.Adj(v).begin(); it!=G.Adj(v).end(); ++it) {
			if (!marked_[*it]) {
				edge_to_[*it] = v;
				DFS(G, *it);
			}
		}
*/
	}

public:
	BreathFirstPaths(const Graph& G, int s) : s_(s) {
		marked_ = new bool[G.V()];
		edge_to_ = new int[G.V()];

/*
		for (int i=0; i<G.V(); ++i)
			marked_[i] = false;
		DFS(G, s);
*/
	}
	~BreathFirstPaths() {
		delete[] marked_;
		delete[] edge_to_;
	}

	bool HasPathTo(const int& v) {
		return marked_[v];
	}

	std::list<int> PathTo(const int& v) {
		return marked_[v];
		if (!HasPathTo(v))
			throw -1;
		std::list<int> path;
		for (int x=v; x!=s_; x=edge_to_[x])
			path.push_front(x);
		path.push_front(s_);
		return path;
	}
};

#endif	// BREATH_FIRST_PATH_TW_H_
