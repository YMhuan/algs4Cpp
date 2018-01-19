#pragma once
#pragma warning (disable : 4996)
#undef max
#include<memory>
#include<functional>
#include<vector>
#include<cassert>
#include<initializer_list>
#include<stdexcept>

namespace algs4Cpp {
	template<typename Key> class MaxPQ {
	private:
		std::allocator<Key> alloc;
		size_t nmemory = 2;
		Key *a = alloc.allocate(nmemory);
		Key *b = a+1;
		size_t n = 0;
		std::function<bool(const Key &, const Key &)> less;

	private:
		template<typename Iter>
		void constructHelper(Iter beg, Iter end) {
			Iter it = beg;
			while (it != end) {
				alloc.construct(b++, *it++);
			}
			for (size_t k = n / 2; k >= 1; --k)
				sink(k);
		}

		void free() {
			while (b != a)
				if (b != a + 1) alloc.destroy(--b);
				else --b;
				alloc.deallocate(a, nmemory);
		}

		void swim(size_t k) {
			using std::swap;
			while (k > 1 && less(a[k / 2], a[k])) {
				swap(a[k], a[k / 2]);
				k /= 2;
			}
		}

		void sink(size_t k) {
			using std::swap;
			while (2 * k <= n) {
				size_t j = 2 * k;
				if (j < n && less(a[j], a[j + 1])) j++;
				if (!less(a[k], a[j])) break;
				swap(a[k], a[j]);
				k = j;
			}
		}

		bool isMaxHeap() const {
			return isMaxHeap(1);
		}

		bool isMaxHeap(size_t k) const {
			if (k > n) return true;
			size_t left = 2 * k;
			size_t right = 2 * k + 1;
			if (left <= n && less(a[k], a[left])) return false;
			if (right <= n && less(a[k], a[right])) return false;
			return isMaxHeap(left) && isMaxHeap(right);
		}

	public:
		MaxPQ(const std::function<bool(const Key &, const Key &)> func = std::less<Key>{})
			:less(func){
		}
		MaxPQ(const MaxPQ &rhs):nmemory(rhs.nmemory),n(rhs.n),less(rhs.less) {
			std::uninitialized_copy_n(rhs.a + 1, n, a + 1);
			b = a + 1 + n;
		}
		MaxPQ &operator=(const MaxPQ &) = delete;
		~MaxPQ() {
			free();
		}

		MaxPQ(size_t initCapacity, const std::function<bool(const Key &, const Key &)> func = std::less<Key>{})
			:nmemory(initCapacity + 1), less(func) {
		}

		MaxPQ(const std::vector<Key> &keys, const std::function<bool(const Key &, const Key &)> func = std::less<Key>{})
			:nmemory(keys.size() + 1), n(keys.size()), less(func) {

			constructHelper(keys.begin(), keys.end());
			assert(isMaxHeap());
		}

		MaxPQ(const std::initializer_list<Key> &keys, const std::function<bool(const Key &, const Key &)> func = std::less<Key>{})
			:nmemory(keys.size() + 1), n(keys.size()),less(func) {

			constructHelper(keys.begin(), keys.end());
			assert(isMaxHeap());
		}

		bool isEmpty() const {
			return n == 0;
		}

		size_t size() const {
			return n;
		}

		Key max() const {
			if (isEmpty()) throw std::underflow_error("Priority queue underflow");
			return a[1];
		}

		void resize(size_t capacity) {
			assert(capacity > n);
			Key * const temp = alloc.allocate(capacity);
			std::uninitialized_copy_n(a+1, n, temp+1);
			free();
			a = temp;
			b = a + 1 + n;
			nmemory = capacity;
		}

		void insert(const Key &x) {
			if (n == nmemory - 1) resize(2 * nmemory);
			alloc.construct(b++, x);
			++n;
			swim(n);
			assert(isMaxHeap());
		}

		Key delMax() {
			using std::swap;
			if(isEmpty()) throw std::underflow_error("Priority queue underflow");
			Key max = a[1];
			swap(a[1], a[n--]);
			sink(1);
			alloc.destroy(--b);
			if ((n > 0) && (n == (nmemory - 1) / 4)) resize(nmemory / 2);
			assert(isMaxHeap());
			return max;
		}

		class iterator {
		private:
			Key *pos;
		public:
			iterator(Key *p) :pos(p) {}

			iterator &operator++() {
				++pos;
				return *this;
			}

			bool operator!=(const iterator &other) const {
				return pos != other.pos;
			}

			Key &operator*() const {
				return *pos;
			}
		};

		iterator begin() const {
			return iterator(a);
		}

		iterator end() const {
			return iterator(b);
		}

		std::vector<Key> keys() {
			std::vector<Key> ret;
			ret.reserve(n);
			MaxPQ<Key> tmp(*this);
			while(!tmp.isEmpty())
				ret.push_back(tmp.delMax());
			return ret;
		}


	public:
		static void mainTest(int argc = 0, char *argv[] = nullptr) {
			MaxPQ<int> pq({ 1,2,3,4,5,6,7,8,9 });
			assert(pq.size() == 9);

			int x = pq.delMax();
			assert(x == 9);

			pq.insert(10);
			assert(pq.max() == 10);

			MaxPQ<int> pq2(pq);
		}
	};
}