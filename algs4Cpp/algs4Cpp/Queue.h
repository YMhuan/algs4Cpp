#pragma once
#include<stdexcept>
#include<string>

namespace algs4Cpp {
	template<typename Item> class Queue {
	private:
		class Node {
		public:
			Item item;
			Node *next = nullptr;
		public:
			Node() = default;
			Node(const Node &) = delete;
			Node &operator=(const Node &) = delete;
			~Node() = default;
		};

		Node* first = nullptr;
		Node* last = nullptr;
		int n = 0;

	public:
		Queue() = default;

		bool isEmpty() const {
			return first == nullptr;
		}

		int size() const {
			return n;
		}

		Item peek() const {
			check();
			return first.item;
		}

		void enqueue(Item item) {
			Node* oldlast = last;
			last = new Node;
			last->item = item;
			if (isEmpty()) first = last;
			else oldlast->next = last;
			++n;
		}

		Item dequeue() {
			check();
			Item item = first->item;
			first = first->next;
			--n;
			if (isEmpty()) last = nullptr;
			return item;
		}

		class iterator {
		private:
			Node *pos;
		public:
			iterator(Node *p) :pos(p) {
			}

			iterator &operator++() {
				pos = pos->next;
				return *this;
			}

			bool operator!=(const iterator &other) const {
				return pos != other.pos;
			}

			Item &operator*() const {
				return pos->item;
			}
		};

		iterator begin() const {
			return iterator(first);
		}

		iterator end() const {
			return iterator(nullptr);
		}

		bool operator==(const Queue &that) const {
			if (size() == that.size()) return false;
			for (auto it1 = begin(), it2 = hat.begin(); it1 != end() && it2 != that.end(); ++it1, ++it2) {
				if (*it1 != *it2) return false;
			}
			return true;
		}

		bool operator!=(const Queue &that) const {
			return !(*this == that);
		}


	private:
		void check() const {
			if (isEmpty()) throw std::underflow_error("Queue underflow");
		}
	};
}