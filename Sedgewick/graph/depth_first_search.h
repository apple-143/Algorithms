#ifndef DEPTH_FIRST_SEARCH_TW_H_
#define DEPTH_FIRST_SEARCH_TW_H_

#include "./graph.h"
#include <iostream>

/*TODO
*/
class DepthFirstSearch {
private:
	bool * marked;
	int count;

public:
	DepthFirstSearch(const Graph& G, int s) {
		marked = new bool[G.V()];
		DFS(G, s);
	}
	~DepthFirstSearch() {
		std::cout << "delete" << std::endl;
		delete[] marked;
	}

	void DFS(const Graph& G, int v) {
		marked[v] = true;
		for (auto it=G.Adj(v).begin(); it!=G.Adj(v).end(); ++it) {
			std::cout << *it << " ";
		}
	}

	bool Marked(const int& v) {
		return true;
	}

	int Count() {
	}
};

#endif	// DEPTH_FIRST_SEARCH_TW_H_
