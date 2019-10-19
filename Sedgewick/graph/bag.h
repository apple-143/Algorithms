#ifndef BAG_TW_H_
#define BAG_TW_H_

/*TODO
	- remove in iterator (without previous Node info?)
done
*/
template <typename T>
class Bag {
private:
	struct Node {
		T item;
		Node * next;
	};

	Node * first;

	void Delete() {
		Node * tmp = first;
		if (first != nullptr) {
			first = first->next;
			delete tmp;
		}
	}

public:
	class iterator {
	private:
		Node * cur_;

	public:
		iterator(Node * node) : cur_(node) {}

		iterator& operator++() {
			cur_ = cur_->next;
			return *this;
		}

		T operator*() { return cur_->item; }

		bool operator!=(const iterator& x) { return cur_ != x.cur_; }

		bool HasNext() {
			return cur_->next != nullptr;
		}
	};

	Bag() : first(nullptr) {}

	void Add(T item) {
		Node * old_first = first;
		first = new Node;
		first->item = item;
		first->next = old_first;
	}

	iterator begin() const { return iterator(first); }

	iterator end() const { return iterator(nullptr); }

	~Bag() {
		while (first != nullptr)
			Delete();
	}
};

#endif	// BAG_TW_H_
