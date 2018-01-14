#pragma once

namespace algs4Cpp {
	template<typename Item> class LinkedBag {
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
		size_t n = 0;

	public:
		LinkedBag() = default;
		LinkedBag(const LinkedBag &) = delete;
		LinkedBag &operator=(const LinkedBag &) = delete;
		~LinkedBag() {
			while (first) {
				Node *oldfirst = first;
				first = oldfirst->next;
				delete oldfirst;
			}
		}

		bool isEmpty() const {
			return first == nullptr;
		}

		size_t size() const {
			return n;
		}

		void add(const Item &item) {
			Node *oldfirst = first;
			first = new Node;
			first->item = item;
			first->next = oldfirst;
			++n;
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

		bool operator==(const LinkedBag &that) const {
			if (size() == that.size()) return false;
			for (auto it1 = begin(), it2 = hat.begin(); it1 != end() && it2 != that.end(); ++it1, ++it2) {
				if (*it1 != *it2) return false;
			}
			return true;
		}

		bool operator!=(const LinkedBag &that) const {
			return !(*this == that);
		}

	public:
		static void mainTest(int argc = 0, char *argv[] = nullptr) {
			LinkedBag<Item> LinkedBag;
			for (int i = 0; i != 5; ++i) {
				LinkedBag.add(Item());
			}
		}
	};
}