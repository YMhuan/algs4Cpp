#pragma once
#pragma warning (disable : 4996)
#include<memory>
#include<cassert>

namespace algs4Cpp {
	template<typename Item> class ResizingArrayBag {
	private:
		std::allocator<Item> alloc;
		Item *a = alloc.allocate(2);
		int nmemory = 2;
		Item *b = a;
		int n=0;

	public:
		ResizingArrayBag() = default;
		ResizingArrayBag(const ResizingArrayBag &) = delete;
		ResizingArrayBag &operator=(const ResizingArrayBag &) = delete;
		~ResizingArrayBag(){
			while (b != a)
				alloc.destroy(--b);
			alloc.deallocate(a, nmemory);
		}

		bool isEmpty() const {
			return n == 0;
		}

		int size() const {
			return n;
		}


		void resize(int capacity) {
			assert(capacity >= n);
			Item * const temp = alloc.allocate(capacity);
			std::uninitialized_copy_n(a, n, temp);
			while (b != a) alloc.destroy(--b);
			alloc.deallocate(a, nmemory);
			a = temp;
			b = a + n;
			nmemory = capacity;
		}

		void add(const Item &item) {
			if (n == nmemory) resize(2 * nmemory);
			alloc.construct(b++, item);
			++n;
		}

		class iterator {
		private:
			Item *pos;
		public:
			iterator(Item *p) :pos(p) {

			}

			iterator &operator++() {
				++pos;
				return *this;
			}

			bool operator!=(const iterator &other) const {
				return pos != other.pos;
			}

			Item &operator*() const {
				return *pos;
			}
		};

		iterator begin() const {
			return iterator(a);
		}

		iterator end() const {
			return iterator(b);
		}

	public:
		static void mainTest(int argc = 0, char *argv[] = nullptr) {
			ResizingArrayBag<Item> bag;
			for (int i = 0; i != 5; ++i) {
				bag.add(Item());
			}
		}
	};
}