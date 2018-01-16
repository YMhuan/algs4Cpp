#pragma once
#include"StdRandom.h"
#include<vector>
#include<cassert>
#include<algorithm>

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
			if (a.size() == 0) return;
			StdRandom::shuffle(a);
			sort(a, 0, a.size() - 1);
			assert(isSorted(a));
		}

		static void sort(std::vector<Item> &a, size_t lo, size_t hi) {
			using std::swap;
			if (hi <= lo || hi >= a.size()) return;
			size_t lt = lo, gt = hi;
			Item v = a[lo];
			size_t i = lo + 1;
			while (i <= gt) {
				if (a[i] < v) swap(a[lt++], a[i++]);
				else if (a[i] > v) swap(a[i], a[gt--]);
				else ++i;
			}

			sort(a, lo, lt - 1);
			sort(a, gt + 1, hi);
			assert(isSorted(a, lo, hi));
		}

		static void mainTest(int argc = 0, char* argv[] = nullptr) {
			std::vector<int> a{ 5,4,3,2,1,6,7,8,9 };
			Quick3way<int>::sort(a);
		}
	};
}