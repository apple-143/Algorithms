#ifndef GRAPH_TW_H_
#define GRAPH_TW_H_

#include "./bag.h"
#include <string>

/*TODO
	- contorl AddEdge same vertice
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

	int V () const { return kV_; }
	int E () const { return E_; }

	void AddEdge (const int& v, const int& w) {
		adj_[v].Add(w);
		adj_[w].Add(v);
		E_++;
	}

	Bag<int>& Adj (const int& v) const {
		return adj_[v];
	}

	std::string ToString () {
		std::string s = std::to_string(kV_) + " vertices, " + std::to_string(E_) + " edges";

		for (int v=0; v<kV_; ++v) {
			s += '\n';
			s += std::to_string(v) + ": ";
			for (Bag<int>::iterator w = this->Adj(v).begin(); w != this->Adj(v).end(); ++w)
				s += std::to_string(*w) + ' ';
		}

		return s;
	}
};

#endif	// GRAPH_TW_H_
