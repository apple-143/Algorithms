#ifndef SYMBOL_GRAPH_TW_H_
#define SYMBOL_GRAPH_TW_H_

#include <string>
#include "./red_black_binary_search_tree.h"
#include "./graph.h"

typedef RedBlackBST<std::string, int> ST;

/*TODO
*/
class SymbolGraph {
private:
	ST st;

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
	SymbolGraph(const Graph& G) {
/*
		marked_ = new bool[G.V()];
		for (int i=0; i<G.V(); ++i)
			marked_[i] = false;

		for (int i=0; i<G.V(); ++i)
			if (!marked_[i])
				DFS(G, i, i);
*/
	}
	SymbolGraph(std::string filename, std::string delim) {
	}

	~SymbolGraph() {
	}

	bool Contains(std::string key) {
	}

	int Index(std::string key) {
	}

	std::string Name(int v) {
	}

	Graph G() {
	}
};

#endif	// SYMBOL_GRAPH__TW_H_
