#pragma once
#include"StdRandom.h"
#include<vector>
#include<cassert>
#include<algorithm>

namespace algs4Cpp {
	template<typename Item> class Quick {
	public:
		Quick(const Quick &) = delete;
		Quick &operator=(const Quick &) = delete;
		~Quick() = delete;

	private:
		static void sort(std::vector<Item> &a, size_t lo, size_t hi) {
			if (hi <= lo || hi>=a.size()) return;
			size_t j = partition(a, lo, hi);
			sort(a, lo, j - 1);
			sort(a, j + 1, hi);
			assert(isSorted(a, lo, hi));
		}

		static size_t partition(std::vector<Item> &a, size_t lo, size_t hi) {
			assert(lo < hi);
			using std::swap;
			size_t i=lo;
			size_t j = hi + 1;
			Item v = a[lo];
			while (true) {
				while (a[++i] < v)
					if (i == hi) break;

				while (v < a[--j])
					if (j == lo) break;

				if (i >= j) break;
				swap(a[i], a[j]);
			}
			swap(a[lo], a[j]);
			return j;
		}

		static bool isSorted(const std::vector<Item> &a) {
			return isSorted(a, 0, a.size() - 1);
		}

		static bool isSorted(const std::vector<Item> &a, size_t lo, size_t hi) {
			for (size_t i = lo + 1; i <= hi; ++i) {
				if (a[i] < a[i - 1]) return false;
			}
			return true;
		}

	public:
		static void sort(std::vector<Item> &a) {
			if (a.size() == 0) return;
			StdRandom::shuffle(a);
			sort(a, 0, a.size() - 1);
			assert(isSorted(a));
		}

		static Item select(std::vector<Item> a, size_t k) {
			if (k >= a.size())
				throw std::invalid_argument("index is not between 0 and " + std::to_string(a.size()) + ": " + std::to_string(k));
			StdRandom::shuffle(a);
			size_t lo = 0, hi = a.size() - 1;
			while (hi > lo) {
				size_t i = partition(a, lo, hi);
				if (i > k) hi = i - 1;
				else if (i < k) lo = i + 1;
				else return a[i];
			}
			return a[k];
				
		}

		static void mainTest(int argc = 0, char* argv[] = nullptr) {
			std::vector<int> a{ 5,4,3,2,1,6,7,8,9 };
			Quick<int>::sort(a);
			int k= Quick<int>::select(a, 4);
			assert(k == 5);
		}

	};
}