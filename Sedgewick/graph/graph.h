#ifndef GRAPH_TW_H_
#define GRAPH_TW_H_

#include "./bag.h"
#include <string>


/*TODO
	- Adj
	- ToString
	- destructor

done
	- constructor
	- AddEdge
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
	}
};

#endif	// GRAPH_TW_H_
