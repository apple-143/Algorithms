#ifndef GRAPH_TW_H_
#define GRAPH_TW_H_

#include "./bag.h"
#include <string>

/*TODO
*/

class Graph {
private:
	const int kV_;
	int E_;
	Bag<int> * adj_;

public:
	Graph (const int& V) : kV_(V), E_(0) {
		adj_ = new Bag<int>[V];
	}
	~Graph () {
		delete[] adj_;
	}

	int V () { return kV_; }
	int E () { return E_; }

	void AddEdge (int v, int w) {
		adj_[v].Add(w);
		adj_[w].Add(v);
		E_++;
	}

	Bag<int>& Adj (int v) {
		return adj_[v];
	}

	std::string ToString () {
		std::string s = std::to_string(kV_) + " vertices, " + std::to_string(E_) + " edges\n";

		for (int v=0; v<kV_; ++v) {
			s += std::to_string(v) + ": ";
			for (Bag<int>::iterator w = this->Adj(v).begin(); w != this->Adj(v).end(); ++w)
				s += std::to_string(*w) + ' ';
			s += '\n';
		}

		return s;
	}
};

#endif	// GRAPH_TW_H_
