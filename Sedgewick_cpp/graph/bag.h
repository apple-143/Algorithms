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

	Node * first_;

	void Delete() {
		Node * tmp = first_;
		if (first_ != nullptr) {
			first_ = first_->next;
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

	Bag() : first_(nullptr) {}

	void Add(T item) {
		Node * old_first = first_;
		first_ = new Node;
		first_->item = item;
		first_->next = old_first;
	}

	iterator begin() const { return iterator(first_); }

	iterator end() const { return iterator(nullptr); }

	~Bag() {
		while (first_ != nullptr)
			Delete();
	}
};

#endif	// BAG_TW_H_
