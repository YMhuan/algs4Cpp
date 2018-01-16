#pragma once
#include<cassert>
#include<stdexcept>

namespace algs4Cpp {
	template<typename Key, typename Value> class BST {
	public:
		BST() = default;
		BST(const BST &) = delete;
		BST &operator=(const BST &) = delete;
		~BST() = default;

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
			~Node() = default;
		};

	private:
		Node *root;

		Value *getPtr(const Key &key) const {
			return getPtr(root, key);
		}

		Value *getPtr(Node *x, const Key &key) const {
			if (!x) return nullptr;
			if (key < (x->key)) return getPtr(x->left, key);
			else if(key>(x->key)) return getPtr(x->right, key);
			else return &(x->val);
		}

		Node *deleteMin(Node *x) {
			if (!(x->left)) {
				Node *ret = x->right;
				delete x;
				return ret;
			}

			x->left = deleteMin(x->left);
			x->size = size(x->left) + size(x->right) + 1;
			return x;
		}

		Node *deleteMax(Node *x) {
			if (!(x->right)) {
				Node *ret = x->left;
				delete x;
				return ret;
			}
			x->right = deleteMax(x->right);
			x->size = size(x->left) + size(x->right) + 1;
			return x;
		}

		Node *erase(Node *x, const Key &key) {
			if (!x) return nullptr;

			if (key < x->key) x->left = delete(x->left, key);
			else if (key > x->key) x->right = delete(x->right, key);
			else {
				if (!(x->right)) {
					Node *ret = x->left;
					delete x;
					return ret;
				}
				if (!(x->left)) {
					Node *ret = x->right;
					delete x;
					return ret;
				}
				Node *t = x;
				x = min(t->right);
				x->right = deleteMin(t->right);
				x->left = t->left;
				delete t;
			}
			x->size = size(x.left) + size(x.right) + 1;
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

	public:
		bool isEmpty() const {
			return size == 0;
		}

		size_t size() const {
			return size(root);
		}

		size_t size(Node *x) const {
			if (x) return 0;
			else return x.size;
		}

		bool contains(const Key &key) const {
			return getPtr(key) != nullptr;
		}

		Value get(const Key &key) const {
			Value *pret= getPtr(key);
			if (!pret) throw std::invalid_argument("No such key exists");
			return *pret;
		}

		void put(const Key &key, const Value &val) {
			root = put(root, key, val);
			assert(check());
		}

		Node *put(Node *x, const Key &key, const Value &val) {
			if (!x) return new Node(key, val, 1);
			if (key < x->key) x.left = put(x->left, key, val);
			else if (key > x->key) x.right = put(x->right, key, val);
			else x->val = val;
			x->size = 1 + size(x->left) + size(x->right);
			return x;
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

		Key min() const {
			if(isEmpty()) throw std::underflow_error("calls min() with empty symbol table");
			return min(root)->key;
		}

		Key max() const {
			if(isEmpty()) throw throw std::underflow_error("calls max() with empty symbol table");
			return max(root)->key;
		}

		Key floor(const Key &) const {
			if (isEmpty()) throw std::underflow_error("calls floor() with empty symbol table");
			Node *x = floor(root, key);
			if(!x) throw std::invalid_argument("No such key exists");

		}
	};
}