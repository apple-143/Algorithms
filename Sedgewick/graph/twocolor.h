#ifndef TWO_COLOR_TW_H_
#define TWO_COLOR_TW_H_

#include "./graph.h"

/*TODO
*/
class TwoColor {
private:
	bool * marked_;
	bool * color_;
	bool is_two_colorable_;

	void DFS(const Graph& G, int v) {
		marked_[v] = true;
		for (auto it=G.Adj(v).begin(); it!=G.Adj(v).end(); ++it) {
			if (!marked_[*it]) {
				color_[*it] = !color_[v];
				DFS(G, *it);
			}
			else if (color_[*it] == color_[v])
				is_two_colorable_ = false;
		}
	}

public:
	TwoColor(const Graph& G) : is_two_colorable_(true) {
		marked_ = new bool[G.V()];
		color_ = new bool[G.V()];
		for (int i=0; i<G.V(); ++i) {
			marked_[i] = false;
			color_[i] = false;
		}

		for (int i=0; i<G.V(); ++i)
			if (!marked_[i])
				DFS(G, i);
	}
	~TwoColor() {
		delete[] marked_;
	}

	bool IsBipartite() {
		return is_two_colorable_;
	}
};

#endif	// TWO_COLOR_TW_H_
