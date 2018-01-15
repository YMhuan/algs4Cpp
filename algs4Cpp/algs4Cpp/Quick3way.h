#pragma once
#include"StdRandom.h"
#include<vector>
#include<cassert>

namespace algs4Cpp {
	template<typename Item> class Quick3way {
	public:
		Quick3way(const Quick3way &) = delete;
		Quick3way &operator=(const Quick3way &) = delete;
		~Quick3way() = delete;

	private:
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
			StdRandom::shuffle(a);
			sort(a, 0, a.size() - 1);
			assert(isSorted(a));
		}

		static void sort(std::vector<Item> &a, size_t lo, size_t hi) {
		
		}
	};
}