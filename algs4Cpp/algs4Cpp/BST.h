#pragma once
#include"Queue.h"
#include<cassert>
#include<stdexcept>
#include<string>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<iostream>

namespace algs4Cpp {
	template<typename Key, typename Value> class BST {
	public:
		BST() = default;
		BST(const BST &) = delete;
		BST &operator=(const BST &) = delete;
		~BST() {
			delete root;
			root = nullptr;
		}

		class Node {
		public:
			Key key;
			Value val;
			Node *left = nullptr;
			Node *right = nullptr;
			size_t size;
		public:
			Node(const Key &_key, const Value &_val, size_t _size) :key(_key),val(_val),size(_size){}
			Node(const Node &) = delete;
			Node &operator=(const Node &) = delete;
			~Node() {
				delete left;
				left = nullptr;
				delete right;
				right = nullptr;
			}
		};

	private:
		Node *root = nullptr;

		int compare(const Key &lhs, const Key &rhs) const {
			if (lhs == rhs) return 0;
			if (lhs < rhs) return -1;
			else return 1;
		}


		size_t size(Node *x) const {
			if (!x) return 0;
			else return x->size;
		}

		Node *get(Node *x, const Key &key) const {
			if (!x) return nullptr;
			if (key < (x->key)) return get(x->left, key);
			else if(key>(x->key)) return get(x->right, key);
			else return x;
		}

		Node *put(Node *x, const Key &key, const Value &val) {
			if (!x) return new Node(key, val, 1);
			if (key < x->key) x->left = put(x->left, key, val);
			else if (key > x->key) x->right = put(x->right, key, val);
			else x->val = val;
			x->size = 1 + size(x->left) + size(x->right);
			return x;
		}

		Node *deleteMin(Node *x) {
			if (!(x->left)) {
				Node *ret = x->right;
				x->right = nullptr;
				delete x;
				x = nullptr;
				return ret;
			}

			x->left = deleteMin(x->left);
			x->size = size(x->left) + size(x->right) + 1;
			return x;
		}

		Node *deleteMax(Node *x) {
			if (!(x->right)) {
				Node *ret = x->left;
				x->left = nullptr;
				delete x;
				x = nullptr;
				return ret;
			}
			x->right = deleteMax(x->right);
			x->size = size(x->left) + size(x->right) + 1;
			return x;
		}

		Node *erase(Node *x, const Key &key) {
			if (!x) return nullptr;

			int cmp = compare(key, x->key);
			if (cmp<0) x->left = erase(x->left, key);
			else if (cmp>0) x->right = erase(x->right, key);
			else {
				if (!(x->right)) {
					Node *ret = x->left;
					x->left = nullptr;
					delete x;
					x = nullptr;
					return ret;
				}
				if (!(x->left)) {
					Node *ret = x->right;
					x->right = nullptr;
					delete x;
					x = nullptr;
					return ret;
				}
				Node *t = x;
				x = min(t->right);
				x = new Node(x->key, x->val, x->size);
				
				x->right = deleteMin(t->right);
				x->left = t->left;
				t->left = nullptr;
				t->right = nullptr;
				delete t;
				t = nullptr;
			}
			x->size = size(x->left) + size(x->right) + 1;
			return x;
		}

		 Node *min(Node *x) const {
			if (!(x->left)) return x;
			else return min(x->left);
		}

		 Node *max(Node *x) const {
			if (!(x->right)) return x;
			else return max(x->right);
		}

		 Node *floor(Node *x, const Key &key) const {
			if (!x) return nullptr;
			if (key == x->key) return x;
			if (key < x->key) return floor(x->left, key);
			Node *t = floor(x->right, key);
			if (!t) return t;
			else return x;
		}

		Node *ceiling(Node *x, const Key &key) const {
			if (!x) return nullptr;
			if (key == x->key) return x;
			if (key < x->key) {
				Node *t = ceiling(x->left, key);
				if (!t) return t;
				else return x;
			}
			return ceiling(x->right, key);
		}

		 Node *select(Node *x, size_t k) const {
			if (!x) return nullptr;
			size_t t= size(x->left);
			if (t > k) return select(x->left, k);
			else if (t < k) return select(x->right, k - t - 1);
			else return x;
		}

		size_t rank(Node *x, const Key &key) const {
			if (!x) return 0;
			int cmp = compare(key, x->key);
			if (cmp<0) return rank(x->left, key);
			else if (cmp>0) return 1 + size(x->left) + rank(x->right, key);
			else return size(x->left);
		}

		void keys(Node *x, algs4Cpp::Queue<Key> &queue, const Key &lo, const Key &hi) const {
			if (!x) return;
			int cmplo = compare(lo, x->key);
			int cmphi = compare(hi, x->key);
			if (cmplo<0) keys(x->left, queue, lo, hi);
			if (cmplo <= 0 && cmphi >= 0) queue.enqueue(x->key);
			if (cmphi >= 0) keys(x->right, queue, lo, hi);
		}

		int height(Node *x) const {
			if (!x) return -1;
			return 1 + std::max(height(x->left), height(x->right));
		}

	public:
		bool isEmpty() const {
			return size() == 0;
		}

		size_t size() const {
			return size(root);
		}


		bool contains(const Key &key) const {
			return get(key) != nullptr;
		}

		Value *get(const Key &key) const {
			Node *p = get(root, key);
			if (!p) return nullptr;
			else return &(get(root, key)->val);
		}

		void put(const Key &key, const Value &val) {
			root = put(root, key, val);
			assert(check());
		}



		void deleteMin() {
			if (isEmpty()) throw std::underflow_error("Symbol table underflow");
			root = deleteMin(root);
			assert(check());
		}


		void deleteMax() {
			if (isEmpty()) throw std::underflow_error("Symbol table underflow");
			root = deleteMax(root);
			assert(check());
		}

		void erase(const Key &key) {
			root = erase(root, key);
			assert(check());
		}

		Key *min() const {
			if(isEmpty()) throw std::underflow_error("calls min() with empty symbol table");
			return &(min(root)->key);
		}

	    Key *max() const {
			if(isEmpty()) throw std::underflow_error("calls max() with empty symbol table");
			return &(max(root)->key);
		}

		Key *floor(const Key &key) const {
			if (isEmpty()) throw std::underflow_error("calls floor() with empty symbol table");
			Node *x = floor(root, key);
			if (!x) return nullptr;
			else return &(x->key);
		}

	    Key *ceiling(const Key &key) const {
			if (isEmpty()) throw std::underflow_error("calls ceiling() with empty symbol table");
			Node *x = ceiling(root, key);
			if (!x) return nullptr;
			else return &(x->key);
		}

	    Key *select(size_t k) const {
			if (k >= size())
				throw std::invalid_argument("argument to select() is invalid: " + std::to_string(k));
			Node *x = select(root, k);
			return &(x->key);
		}

		size_t rank(const Key & key) const {
			return rank(root, key);
		}

		algs4Cpp::Queue<Key> keys() const {
			if (isEmpty()) return algs4Cpp::Queue<Key>();
			return keys(*min(), *max());
		}

		algs4Cpp::Queue<Key> keys(const Key &lo, const Key &hi) const {
			if(!(lo<=hi)) throw std::invalid_argument("invalid input range");
			algs4Cpp::Queue<Key> queue;
			keys(root, queue, lo, hi);
			return queue;
		}

		size_t size(const Key &lo, const Key &hi) const {
			if (!(lo <= hi)) throw std::invalid_argument("invalid input range");
			if (contains(hi)) return rank(hi) - rank(lo) + 1;
			else return  rank(hi) - rank(lo);
		}

		int height() const {
			return height(root);
		}

		algs4Cpp::Queue<Key> levelOrder() const{
			algs4Cpp::Queue<Key> keys;
			algs4Cpp::Queue<Node *> queue;
			queue.enqueue(root);
			while (!queue.isEmpty()) {
				Node *x = queue.dequeue();
				if (!x) continue;
				keys.enqueue(x->key);
				queue.enqueue(x->left);
				queue.enqueue(x->right);
			}
			return keys;
		}

	private:
		bool check() const {
			if (!isBST()) std::cout << "Not in symmetric order" << std::endl;
			if (!isSizeConsistent()) std::cout << "Subtree counts not consistent" << std::endl;
			if (!isRankConsistent()) std::cout << "Ranks not consistent" << std::endl;
			return isBST() & isSizeConsistent() & isRankConsistent();
		}

		bool isBST() const {
			return isBST(root,nullptr, nullptr);
		}

		bool isBST(Node *x, const Key *minP, const Key *maxP) const {
			if (!x) return true;
			if (minP && (compare(x->key, *minP) <= 0)) return false;
			if (maxP && (compare(x->key, *maxP) >= 0)) return false;
			return isBST(x->left, minP, &(x->key)) && isBST(x->right, &(x->key), maxP);
		}

		bool isSizeConsistent() const {
			return isSizeConsistent(root);
		}

		bool isSizeConsistent(Node *x) const {
			if (!x) return true;
			if (x->size != size(x->left) + size(x->right) + 1) return false;
			return isSizeConsistent(x->left) && isSizeConsistent(x->right);
		}

		bool isRankConsistent() const {
			for (size_t i = 0; i < size(); ++i) 
				if (i != rank(*select(i))) return false;
			for (const Key &key : keys()) 
				if (compare(key, *select(rank(key))) != 0) return false;
			return true;
			
		}

	public:
		static void mainTest(int argc = 0, char *argv[] = nullptr) {
			BST<std::string, int> st;
			std::vector<std::string> vec{ "c","e","a","f","b","d","h","g" };
			for (size_t i = 0; i != vec.size(); ++i) {
				std::string key = vec[i];
				st.put(key, i);
			}

			assert(st.contains("e"));

			for (const auto &s : st.levelOrder())
				std::cout << s << " " << *st.get(s) << std::endl;
			std::cout << std::endl;

			for (const auto &s : st.keys())
				std::cout << s << " " << *st.get(s) << std::endl;
			std::cout << std::endl;

			st.deleteMax();
			st.deleteMin();
			st.erase("e");
			assert(!st.contains("e"));

			for (const auto &s : st.levelOrder())
				std::cout << s << " " << *st.get(s) << std::endl;
			std::cout << std::endl;

			for (const auto &s : st.keys())
				std::cout << s << " " << *st.get(s) << std::endl;
			std::cout << std::endl;

		}

	};
}