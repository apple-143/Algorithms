#ifndef SYMBOL_GRAPH_TW_H_
#define SYMBOL_GRAPH_TW_H_

#include <fstream>
#include <iostream>
#include <string>
#include "./red_black_binary_search_tree.h"
#include "./graph.h"

using ST = RedBlackBST<std::string, int>;

/*TODO
*/
class SymbolGraph {
private:
	ST * st;
	std::string * keys;
	Graph * g;

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
	SymbolGraph() {
/*
		marked_ = new bool[G.V()];
		for (int i=0; i<G.V(); ++i)
			marked_[i] = false;

		for (int i=0; i<G.V(); ++i)
			if (!marked_[i])
				DFS(G, i, i);
*/
	}
	SymbolGraph(const char * filename, const char delim) {
		std::ifstream in(filename);
		if (!in.is_open())
			throw -1;

		st = new ST();

		std::string s, tmp;
		std::vector<std::string> a;
		size_t start;
		size_t pos;
		while (in) {
			a.clear();
			getline(in, s);

			start = 0;
			while ((pos = s.find(delim, start)) != std::string::npos) {
				if (!(start == pos)) {
					tmp = s.substr(start, pos-start);
					a.push_back(tmp);
				}
				start = pos+1;
			}
			if (start != s.size())
				a.push_back(s.substr(start, s.size()-start));

			for (int i=0; i<a.size(); ++i) {
				if (!st->Contains(a[i]))
					st->Put(a[i], st->Size());
			}
		}

		//st->PrintTree();
		st->PrintTreeStructure();

		//keys = new std::string[st->Size()];
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
