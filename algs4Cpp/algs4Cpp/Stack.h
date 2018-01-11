#pragma once
#include<cassert>
#include<stdexcept>

namespace algs4Cpp {
	template<typename Item> class Stack {
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
		int n = 0;

	public:
		Stack() {
			assert(check());
		}
		Stack(const Stack &) = delete;
		Stack &operator=(const Stack &) = delete;
		~Stack() {
			while (first) {
				Node *oldfirst = first;
				first = oldfirst->next;
				delete oldfirst;
			}
		}

		bool isEmpty() const {
			return first == nullptr;
		}

		int size() const {
			return n;
		}

		void push(const Item &item) {
			Node *oldfirst = first;
			first = new Node;
			first->item = item;
			first->next = oldfirst;
			++n;
			assert(check());
		}

		Item pop() {
			checkEmpty();
			Item item = first->item;
			Node *oldfirst = first;
			first = oldfirst->next;
			delete oldfirst;
			--n;
			assert(check());
			return item;
		}

		Item peek() {
			checkEmpty();
			return first->item;
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

		bool operator==(const Stack &that) const {
			if (size() == that.size()) return false;
			for (auto it1 = begin(), it2 = hat.begin(); it1 != end() && it2 != that.end(); ++it1, ++it2) {
				if (*it1 != *it2) return false;
			}
			return true;
		}

		bool operator!=(const Stack &that) const {
			return !(*this == that);
		}

	private:
		bool check() {
			if (n < 0) {
				return false;
			}
			if (n == 0) {
				if (first != nullptr) return false;
			}
			else if (n == 1) {
				if (first == nullptr) return false;
				if (first->next != nullptr) return false;
			}
			else {
				if (first == nullptr) return false;
				if (first->next == nullptr) return false;
			}

			int numberOfNodes = 0;
			for (Node *x = first; (x != nullptr) && (numberOfNodes <= n); x = x->next) {
				++numberOfNodes;
			}
			if (numberOfNodes != n) return false;
			return true;

		}

		void checkEmpty() const {
			if (isEmpty()) throw std::underflow_error("Queue underflow");
		}

	public:
		static void mainTest(int argc = 0, char *argv[] = nullptr) {
			Stack<Item> stack;

			for (int i = 0; i != 5; ++i) {
				stack.push(Item());
			}

			Item x = stack.pop();
		}

	};
}