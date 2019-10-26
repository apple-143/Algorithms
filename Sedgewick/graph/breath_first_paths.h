#ifndef BREATH_FIRST_PATH_TW_H_
#define BREATH_FIRST_PATH_TW_H_

#include <queue>
#include <list>
#include "./graph.h"

/*TODO
*/
class BreathFirstPaths {
private:
	bool * marked_;
	int * edge_to_;
	const int s_;

	void BFS(const Graph& G, int s) {
		std::queue<int> queue;
		marked_[s] = true;
		queue.push(s);

		while (!queue.empty()) {
			s = queue.front();
			queue.pop();
			for (auto it=G.Adj(s).begin(); it!=G.Adj(s).end(); ++it) {
				if (!marked_[*it]) {
					marked_[*it] = true;
					queue.push(*it);
					edge_to_[*it] = s;
				}
			}
		}
	}

public:
	BreathFirstPaths(const Graph& G, int s) : s_(s) {
		marked_ = new bool[G.V()];
		edge_to_ = new int[G.V()];
		for (int i=0; i<G.V(); ++i)
			marked_[i] = false;
		BFS(G, s);
	}
	~BreathFirstPaths() {
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

#endif	// BREATH_FIRST_PATH_TW_H_
